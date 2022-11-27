#include <utility>

#include "../include/Game.hpp"
#include "../include/DEFINITIONS.hpp"
#include "SFML/Window/Keyboard.hpp"
/*=============================================================================
|                         Constructor/Deconstructor
=============================================================================*/
Game::Game(std::shared_ptr<sf::RenderWindow> data)
    : data_(std::move(data)),
      player_(new Player(this->data_)),
      platformObj_(new Platform(this->data_,
                                this->data_->getSize().x,
                                PLATFORM_WIDTH,
                                0.F,
                                this->data_->getSize().y - WIDTH_OFFSET)),
      platformLeft_(new Platform(this->data_,
                                 this->data_->getSize().x / 4,
                                 PLATFORM_WIDTH,
                                 0.F,
                                 this->data_->getSize().y / 2)),
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
  LOG << "Original data ptr win size: " << data_->getSize().x << " x " << data_->getSize().y;
}
/*=============================================================================
|                          Game System Run & Update
=============================================================================*/
bool Game::Running() const {
  return this->data_->isOpen();
}

#pragma clang diagnostic ignored "-Wswitch"
void Game::PollEvents() {                      // checks if window was/is closed and
  while (this->data_->pollEvent(this->ev_)) {  //grabs events from stack ?
    switch (this->ev_.type) {
      case sf::Event::Closed:
        this->data_->close();
        break;
      case sf::Event::KeyPressed:
        if (ev_.key.code == sf::Keyboard::Escape) this->data_->close();
    }
  }
}

void Game::Update() {  // update game variables before rendered
  this->PollEvents();
  if (Collision::CheckPlayerPlatformCollison2(this->player_->GetPlayer(),
                                              this->platformObj_->GetPlatform())) {
    this->player_->setOnPlatform(true);
  }
  else if (Collision::CheckPlayerPlatformCollison2(this->player_->GetPlayer(),
                                                   this->platformLeft_->GetPlatform())) {
    this->player_->setOnPlatform(true);
  }
  else {
    this->player_->setOnPlatform(false);
  }
  this->player_->Update();
  if (Collision::CheckPlayerPlatformCollison(this->player_->GetPlayer(),
                                             this->platformObj_->GetPlatform())) {
    std::cout << "collided" << this->platformObj_->GetPlatform().getPosition().y << std::endl;
    this->player_->Collided(this->platformObj_->GetPlatform().getPosition().y);
    this->player_->setOnPlatform(true);
  }
  if (Collision::CheckPlayerPlatformCollison(this->player_->GetPlayer(),
                                             this->platformLeft_->GetPlatform())) {
    std::cout << "collided" << this->platformLeft_->GetPlatform().getPosition().y << std::endl;
    this->player_->Collided(this->platformLeft_->GetPlatform().getPosition().y);
    this->player_->setOnPlatform(true);
  }
  // if (this->platformLeft_->GetPlatform().getPosition().y
  //         - (this->player_->GetPlayer().getPosition().y + this->player_->GetPlayer().getSize().y)
  //     == 0) {
  //   this->player_->setOnPlatform(true);
  // }
  // else {
  //   this->player_->setOnPlatform(false);
  // }
}

void Game::Render() {  // renders all variables to the screen, last thing done.
  this->data_->clear();

  // render stuff here
  platformObj_->DrawPlatform(*this->data_);   // sending at ptr bc shared ptr
  platformLeft_->DrawPlatform(*this->data_);  // sending at ptr bc shared ptr
  player_->DrawPlayer(*this->data_);
  this->data_->display();
}

/*=============================================================================
|
=============================================================================*/