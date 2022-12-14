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

class Enemy : public Player {

 public:
  virtual ~Enemy() = default;
  explicit Enemy(const std::shared_ptr<sf::RenderWindow>& data)
      : Player(data, sf::Vector2f(30.f, 30.f)) {
  }
  virtual void Update();
  virtual void CheckBounds();

  void MoveEnemyLeft();
  void MoveEnemyRight();
  void MoveEnemy();

 private:
  std::shared_ptr<sf::RenderWindow> data_;
  bool initialMove_ = true;
  bool moveRight_   = false;
  bool moveLeft_    = false;
};