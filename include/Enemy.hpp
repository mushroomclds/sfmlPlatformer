#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <ctime>
#include <iostream>
#include <memory>
#include "../include/Player.hpp"
#include "SFML/Graphics/Text.hpp"
#include "SFML/Graphics/Texture.hpp"

class Enemy : public Player {

 public:
  virtual ~Enemy() = default;
  explicit Enemy(const std::shared_ptr<sf::RenderWindow>& data, sf::Vector2f size_, int speed)
      : Player(data, size_), speed_(speed) {
  }
  virtual void Update();
  virtual void CheckBounds();

  void MoveEnemyLeft();
  void MoveEnemyRight();
  void MoveEnemy();

 private:
  std::shared_ptr<sf::RenderWindow> data_;
  sf::Vector2f size_;
  bool initialMove_ = true;
  bool moveRight_   = false;
  bool moveLeft_    = false;

  int speed_ = 0;
};