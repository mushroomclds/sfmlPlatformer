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
                                static_cast<float>(this->data_->getSize().y - WIDTH_OFFSET))),
      platformLeft_(new Platform(this->data_,
                                 this->data_->getSize().x / 4,
                                 PLATFORM_WIDTH,
                                 0.F,
                                 static_cast<float>(this->data_->getSize().y) / 2)),
      platformRight_(new Platform(this->data_,
                                  this->data_->getSize().x / 4,
                                  PLATFORM_WIDTH,
                                  (static_cast<float>(this->data_->getSize().x)
                                   - (static_cast<float>(this->data_->getSize().x) / 4)),
                                  static_cast<float>(this->data_->getSize().y) / 2)),
      endGame_(false),
      ev_() /*,
      enemy_(new Enemy(this->data_))*/
{           // constructor definition
  for (int i = 0; i < 10; i++) {
    auto* enemy = new Enemy(this->data_, sf::Vector2f(10.f + i, 10.f + i), i);
    enemys_.push_back(enemy);
  }
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
  this->player_->Update();
  for (auto* itr : enemys_) {
    itr->Update();
  }
  this->CheckCollisions();
}

void Game::Render() {  // renders all variables to the screen, last thing done.
  this->data_->clear();

  // render stuff here
  platformObj_->DrawPlatform(*this->data_);    // sending at ptr bc shared ptr
  platformLeft_->DrawPlatform(*this->data_);   // sending at ptr bc shared ptr
  platformRight_->DrawPlatform(*this->data_);  // sending at ptr bc shared ptr
  player_->DrawPlayer(*this->data_);
  for (auto* itr : enemys_) {
    itr->DrawPlayer(*this->data_);
  }
  this->data_->display();
}

/*=============================================================================
|
=============================================================================*/

void Game::CheckCollisions() {
  //check if player is on platform to keep it there.
  if (Collision::CheckPlayerPlatformCollison2(this->player_->GetPlayer(),
                                              this->platformObj_->GetPlatform())) {
    LOG << "0";
    this->player_->SetOnPlatform(true);
  }
  else if (Collision::CheckPlayerPlatformCollison2(this->player_->GetPlayer(),
                                                   this->platformLeft_->GetPlatform())) {
    LOG << "1";
    this->player_->SetOnPlatform(true);
  }
  else if (Collision::CheckPlayerPlatformCollison2(this->player_->GetPlayer(),
                                                   this->platformRight_->GetPlatform())) {
    LOG << "2";
    this->player_->SetOnPlatform(true);
  }
  else {
    LOG << "3";
    this->player_->SetOnPlatform(false);
  }
  //check if player intersects platform which will put player on top of platform
  if (Collision::CheckPlayerPlatformCollison(this->player_->GetPlayer(),
                                             this->platformObj_->GetPlatform())) {
    std::cout << "collided" << this->platformObj_->GetPlatform().getPosition().y << std::endl;
    this->player_->Collided(static_cast<int>(this->platformObj_->GetPlatform().getPosition().y));
    this->player_->SetOnPlatform(true);
  }
  if (Collision::CheckPlayerPlatformCollison(this->player_->GetPlayer(),
                                             this->platformLeft_->GetPlatform())) {
    std::cout << "collided" << this->platformLeft_->GetPlatform().getPosition().y << std::endl;
    this->player_->Collided(static_cast<int>(this->platformLeft_->GetPlatform().getPosition().y));
    this->player_->SetOnPlatform(true);
  }
  if (Collision::CheckPlayerPlatformCollison(this->player_->GetPlayer(),
                                             this->platformRight_->GetPlatform())) {
    std::cout << "collided" << this->platformRight_->GetPlatform().getPosition().y << std::endl;
    this->player_->Collided(static_cast<int>(this->platformRight_->GetPlatform().getPosition().y));
    this->player_->SetOnPlatform(true);
  }
  //////////////////////////
  for (auto* itr : enemys_) {

    if (Collision::CheckPlayerPlatformCollison2(itr->GetPlayer(),
                                                this->platformObj_->GetPlatform())) {
      LOG << "0";
      itr->SetOnPlatform(true);
    }
    else if (Collision::CheckPlayerPlatformCollison2(itr->GetPlayer(),
                                                     this->platformLeft_->GetPlatform())) {
      LOG << "1";
      itr->SetOnPlatform(true);
    }
    else if (Collision::CheckPlayerPlatformCollison2(itr->GetPlayer(),
                                                     this->platformRight_->GetPlatform())) {
      LOG << "2";
      itr->SetOnPlatform(true);
    }
    else {
      LOG << "3";
      itr->SetOnPlatform(false);
    }
    //check if player intersects platform which will put player on top of platform
    if (Collision::CheckPlayerPlatformCollison(itr->GetPlayer(),
                                               this->platformObj_->GetPlatform())) {
      std::cout << "collided" << this->platformObj_->GetPlatform().getPosition().y << std::endl;
      itr->Collided(static_cast<int>(this->platformObj_->GetPlatform().getPosition().y));
      itr->SetOnPlatform(true);
    }
    if (Collision::CheckPlayerPlatformCollison(itr->GetPlayer(),
                                               this->platformLeft_->GetPlatform())) {
      std::cout << "collided" << this->platformLeft_->GetPlatform().getPosition().y << std::endl;
      itr->Collided(static_cast<int>(this->platformLeft_->GetPlatform().getPosition().y));
      itr->SetOnPlatform(true);
    }
    if (Collision::CheckPlayerPlatformCollison(itr->GetPlayer(),
                                               this->platformRight_->GetPlatform())) {
      std::cout << "collided" << this->platformRight_->GetPlatform().getPosition().y << std::endl;
      itr->Collided(static_cast<int>(this->platformRight_->GetPlatform().getPosition().y));
      itr->SetOnPlatform(true);
    }
  }
}