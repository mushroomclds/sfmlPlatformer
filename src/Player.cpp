#include "../include/Player.hpp"
#include <cmath>

#include "../include/DEFINITIONS.hpp"
#include "SFML/Window/Keyboard.hpp"
#pragma clang diagnostic ignored "-Wswitch"

Player::Player(const std::shared_ptr<sf::RenderWindow>& data, sf::Vector2f playerSize_)
    : data_(data), onPlatform_(false) {
  LOG << "Player data win size: " << data_->getSize().x << " x " << data_->getSize().y;
  this->player_.setFillColor(sf::Color::Green);
  this->player_.setSize(playerSize_);
  this->setPlayerX_ = static_cast<float>(this->data_->getSize().x) / HALF_WIN_SIZE;
  this->setPlayerY_ = static_cast<float>(this->data_->getSize().y) / HALF_WIN_SIZE;
  this->player_.setPosition(this->setPlayerX_, this->setPlayerY_);
  LOG << "shared ptr count: " << data.use_count();
}

void Player::DrawPlayer(sf::RenderTarget& target) {
  target.draw(this->player_);
}

void Player::Update() {
  bool log = false;
  this->Gravity();
  this->CheckBounds();
  x_ = this->player_.getPosition().x;
  y_ = this->player_.getPosition().y;
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
    this->player_.move(0.F, -MOVE_SPEED_ALL);
    log = true;
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
    velocityX_ = -MOVE_SPEED_ALL;
    velocityX_ -= accelerationX_;
    x_ += velocityX_;
    this->player_.setPosition(x_, y_);
    // this->player_.move(-MOVE_SPEED_ALL, 0.F);
    log = true;
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
    if (this->onPlatform_) {
      this->player_.setPosition(x_, y_ + PLATFORM_WIDTH + this->player_.getSize().y);
    }
    // this->player_.move(0.F, MOVE_SPEED_ALL);
    log = true;
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
    velocityX_ = MOVE_SPEED_ALL;
    velocityX_ += accelerationX_;
    x_ += velocityX_;
    this->player_.setPosition(x_, y_);
    // this->player_.move(MOVE_SPEED_ALL, 0.F);
    log = true;
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
    this->jumpCounter_++;
    LOG << "counter: " << this->jumpCounter_;
    if (this->onPlatform_) {
      this->jumpCounter_ = 0;
    }
    if (this->jumpCounter_ <= DOUBLE_JUMP_MAX) {
      this->onPlatform_ = false;
      velocityY_        = -JUMP;
      velocityY_ -= accelerationY_;
      y_ += velocityY_;
      this->player_.setPosition(x_, y_);
      log = true;
      this->player_.setFillColor(sf::Color::Blue);
    }
    else {
      this->player_.setFillColor(sf::Color::Red);
    }
  }
  if (log) {
    LOG << "After move: "
        << " PlayerX " << this->player_.getPosition().x << " | PlayerY "
        << this->player_.getPosition().y;
  }
}

void Player::Gravity() {
  // this->player_.move(0.F, GRAVITY);
  x_ = this->player_.getPosition().x;
  y_ = this->player_.getPosition().y;
  const int platCoordY =
      static_cast<float>(this->data_->getSize().y) - WIDTH_OFFSET - this->player_.getSize().y;
  if (!(this->onPlatform_)) {  //If you are above ground, y_ < platCoordY
    velocityY_ += GRAVITY;     //Add gravity
    velocityY_ += accelerationY_;
    y_ += velocityY_;
    this->player_.setPosition(x_, y_);
  }
  // else if (y_ > platCoordY) {                   //If you are below ground
  //   this->player_.setPosition(x_, platCoordY);  //put player back up
  // }
  LOG << "After gravity:"
      << " PlayerY " << y_ << " | PlatformY " << platCoordY;
}

void Player::Collided(int y) {
  LOG << "Collided: " << y;
  x_ = this->player_.getPosition().x;
  y_ = this->player_.getPosition().y;
  this->player_.setPosition(x_, y - this->player_.getSize().y);
  LOG << 590 - (this->player_.getPosition().y + this->player_.getSize().y);
  this->player_.setFillColor(sf::Color::Blue);
}

sf::RectangleShape Player::GetPlayer() {
  return this->player_;
}

void Player::SetOnPlatform(bool plat) {
  this->onPlatform_ = plat;
}

void Player::CheckBounds() {
  float xPos = this->player_.getPosition().x;
  float yPos = this->player_.getPosition().y;
  if (this->player_.getPosition().x < 0) {
    this->player_.setPosition(0, yPos);
  }
  if (this->player_.getPosition().y < 0) {
    this->player_.setPosition(xPos, 0);
  }
  if (this->player_.getPosition().y > VIDEOMODE_HEIGHT) {
    this->player_.setPosition(xPos, VIDEOMODE_HEIGHT - this->player_.getSize().y - PLATFORM_WIDTH);
  }
  if (this->player_.getPosition().x + this->player_.getSize().x > VIDEOMODE_WIDTH) {
    this->player_.setPosition(VIDEOMODE_WIDTH - this->player_.getSize().x, yPos);
  }
}