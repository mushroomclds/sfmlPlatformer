#include <utility>

#include "../include/Game.hpp"
#include "../include/DEFINITIONS.hpp"
/*=============================================================================
|                         Constructor/Deconstructor
=============================================================================*/
Game::Game(std::shared_ptr<sf::RenderWindow> data)
    : data_(std::move(data)),
      player_(new Player(this->data_)),
      platformObj_(new Platform(this->data_)),

      endGame_(false),
      ev_() {  // constructor definition
}

Game::~Game() {  // deconstrutor definition
  // delete this->data;
  LOG << "shared ptr count at Game destructor: " << this->data_.use_count();
}
/*============================================================================= 
|                          Initialize functions
=============================================================================*/

void Game::InitWindow() {
  // this->videoMode = sf::VideoMode(800, 600);
  // this->window = new sf::RenderWindow(this->videoMode, "Game",
  // sf::Style::Close | sf::Style::Titlebar); //render window needed to draw
  // on
  this->data_->create(sf::VideoMode(VIDEOMODE_WIDTH, VIDEOMODE_HEIGHT),
                      "title",
                      sf::Style::Close | sf::Style::Titlebar);
  LOG << "Original data ptr win size: " << data_->getSize().x << " x "
      << data_->getSize().y;
}
/*=============================================================================
|                          Game System Run & Update
=============================================================================*/
bool Game::Running() const {
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
  if (Collision::CheckPlayerPlatformCollison(this->player_->GetPlayer(),
                                             this->platformObj_->GetPlatform())) {
    std::cout << "collided" << this->platformObj_->GetPlatform().getPosition().y
              << std::endl;
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