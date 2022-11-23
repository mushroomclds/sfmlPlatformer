#include "../include/Player.hpp"

#include "../include/DEFINITIONS.hpp"
#pragma clang diagnostic ignored "-Wswitch"

Player::Player(const std::shared_ptr<sf::RenderWindow>& data) : data_(data) {
  LOG << "Player data win size: " << data_->getSize().x << " x " << data_->getSize().y;
  this->player_.setFillColor(sf::Color::Green);
  this->player_.setSize(sf::Vector2f(PLAYER_SIZE, PLAYER_SIZE));
  this->setPlayerX_ = static_cast<float>(this->data_->getSize().x) / HALF_WIN_SIZE;
  this->setPlayerY_ = static_cast<float>(this->data_->getSize().y) / HALF_WIN_SIZE;
  this->player_.setPosition(this->setPlayerX_, this->setPlayerY_);
  LOG << "shared ptr count: " << data.use_count();
}

void Player::DrawPlayer(sf::RenderTarget& target) {
  target.draw(this->player_);
}

void Player::Update(sf::Keyboard::Key key) {
  switch (key) {
    case sf::Keyboard::W:
      this->player_.move(0.F, -MOVE_SPEED_ALL);
      break;
    case sf::Keyboard::A:
      this->player_.move(-MOVE_SPEED_ALL, 0.F);
      break;
    case sf::Keyboard::S:
      this->player_.move(0.F, MOVE_SPEED_ALL);
      break;
    case sf::Keyboard::D:
      this->player_.move(MOVE_SPEED_ALL, 0.F);
      break;
    case sf::Keyboard::Space:
      x_         = this->player_.getPosition().x;
      y_         = this->player_.getPosition().y;
      velocityY_ = -25;

      velocityX_ += accelerationX_;
      velocityY_ += accelerationY_;

      x_ += velocityX_;
      y_ += velocityY_;
      this->player_.setPosition(x_, y_);
      LOG << this->player_.getPosition().x << this->player_.getPosition().y;
      // this->player_.move(JUMP, 0.F);
      break;
  }
}
void Player::Gravity() {
  // this->player_.move(0.F, GRAVITY);
  x_ = this->player_.getPosition().x;
  y_ = this->player_.getPosition().y;
  const int platCoordY =
      static_cast<float>(this->data_->getSize().y) - WIDTH_OFFSET - this->player_.getSize().y;
  if (y_ < platCoordY) {     //If you are above ground
    velocityY_ += gravity_;  //Add gravity
    velocityX_ += accelerationX_;
    velocityY_ += accelerationY_;
    x_ += velocityX_;
    y_ += velocityY_;
    this->player_.setPosition(x_, y_);
  }
  else if (y_ > platCoordY) {                   //If you are below ground
    this->player_.setPosition(x_, platCoordY);  //put player back up
  }
  LOG << "player posy" << y_ << " Platform coordY" << platCoordY;

  // velocityY_ = 5;
  LOG << this->player_.getPosition().y;
}

sf::RectangleShape Player::GetPlayer() {
  return this->player_;
}

void Player::Collided() {
  this->player_.setPosition(this->player_.getPosition().x,
                            static_cast<float>(this->data_->getSize().y) - WIDTH_OFFSET
                                - this->player_.getSize().x);
  this->player_.setFillColor(sf::Color::White);
}