#include "../lib/Game.hpp"
#include "../lib/DEFINITIONS.hpp"
/*=============================================================================
|                         Constructor/Deconstructor
=============================================================================*/
Game::Game() {  // constructor definition
  this->InitVariables();
  this->InitWindow();
  platformObj_ = new Platform(this->data_);  // make shape(s) in own class and draw it
  player_      = new Player(this->data_);
}

Game::~Game() {  // deconstrutor definition
  // delete this->data;
  std::cout << "shared ptr count at Game destructor: " << this->data_.use_count() << std::endl;
}
/*============================================================================= 
|                          Initialize functions
=============================================================================*/
void Game::InitVariables() {
  this->endGame_ = false;
}

void Game::InitWindow() {
  // this->videoMode = sf::VideoMode(800, 600);
  // this->window = new sf::RenderWindow(this->videoMode, "Game",
  // sf::Style::Close | sf::Style::Titlebar); //render window needed to draw
  // on
  this->data_->create(sf::VideoMode(VIDEOMODE_WIDTH, VIDEOMODE_HEIGHT),
                      "title",
                      sf::Style::Close | sf::Style::Titlebar);
  std::cout << data_->getSize().x << "--- " << data_->getSize().y << std::endl;
}
/*=============================================================================
|                          Game System Run & Update
=============================================================================*/
const bool Game::Running() const {
  return this->data_->isOpen();
}

#pragma clang diagnostic ignored "-Wswitch"
void Game::PollEvents() {  // checks if window was/is closed and
  while (this->data_->pollEvent(this->ev_)) {
    switch (this->ev_.type) {
      case sf::Event::Closed:
        this->data_->close();
        break;
      case sf::Event::KeyPressed:
        if (ev_.key.code == sf::Keyboard::Escape) this->data_->close();
        if (ev_.key.code == sf::Keyboard::W) {
          this->player_->Update(ev_.key.code);
        }
        if (ev_.key.code == sf::Keyboard::A) {
          this->player_->Update(ev_.key.code);
        }
        if (ev_.key.code == sf::Keyboard::S) {
          this->player_->Update(ev_.key.code);
        }
        if (ev_.key.code == sf::Keyboard::D) {
          this->player_->Update(ev_.key.code);
        }
        break;
    }
  }
}

void Game::Update() {  // update game variables before rendered
  this->PollEvents();
  this->player_->Gravity();
  if (this->collision_.checkPlayerPlatformCollison(this->player_->GetPlayer(), this->platformObj_->GetPlatform())) {
    std::cout << "collided" << this->platformObj_->GetPlatform().getPosition().y << std::endl;
    this->player_->Collided();
  }
  std::cout << "done " << std::endl;
}

void Game::Render() {  // renders all variables to the screen, last thing done.
  this->data_->clear();

  // render stuff here
  platformObj_->DrawPlatform(*this->data_);  // sending at ptr bc shared ptr
                                             // (?)

  player_->DrawPlayer(*this->data_);

  this->data_->display();
}

/*=============================================================================
|
=============================================================================*/