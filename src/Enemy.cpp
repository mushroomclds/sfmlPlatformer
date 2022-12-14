#include "../include/Player.hpp"
#include "../include/Enemy.hpp"
#include "SFML/Graphics/RectangleShape.hpp"

void Enemy::Update() {
  this->Gravity();
  this->CheckBounds();
  this->MoveEnemy();
}
void Enemy::MoveEnemy() {
  if (moveLeft_) {
    this->MoveEnemyLeft();
  }
  if (moveRight_) {
    this->MoveEnemyRight();
  }
}
void Enemy::MoveEnemyLeft() {

  //   sf::RectangleShape enemy = this->GetPlayer();

  //   enemy.move(5.f, 0.f);

  this->player_.move(-5.f, 0.f);
}
void Enemy::MoveEnemyRight() {

  //   sf::RectangleShape enemy = this->GetPlayer();

  //   enemy.move(5.f, 0.f);

  this->player_.move(5.f, 0.f);
}

void Enemy::CheckBounds() {

  if (this->initialMove_) {
    // this->MoveEnemyLeft();
    this->moveRight_ = true;
  }

  float xPos = this->player_.getPosition().x;
  float yPos = this->player_.getPosition().y;
  if (this->player_.getPosition().x < 0) {  //left border
    this->player_.setPosition(0, yPos);
    // this->MoveEnemyRight();
    this->moveRight_ = true;
    this->moveLeft_  = false;

    // this->initialMove_ = false;
  }
  else if (this->player_.getPosition().y < 0) {  //top border
    this->player_.setPosition(xPos, 0);
  }
  else if (this->player_.getPosition().y > VIDEOMODE_HEIGHT) {  //bottom border
    this->player_.setPosition(xPos, VIDEOMODE_HEIGHT - this->player_.getSize().y - PLATFORM_WIDTH);
  }
  else if (this->player_.getPosition().x + this->player_.getSize().x
           > VIDEOMODE_WIDTH) {  //right border
    this->player_.setPosition(VIDEOMODE_WIDTH - this->player_.getSize().x, yPos);
    // this->MoveEnemyLeft();
    this->moveLeft_    = true;
    this->moveRight_   = false;
    this->initialMove_ = false;
  }
}