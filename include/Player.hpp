#pragma once

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <ctime>
#include <iostream>
#include <memory>

#include "DEFINITIONS.hpp"
#include "Collision.hpp"

class Player {
 public:
  explicit Player(const std::shared_ptr<sf::RenderWindow>& data);
  ~Player() = default;

  void DrawPlayer(sf::RenderTarget& target);
  void Update();
  void Gravity();
  void Collided(int y);
  sf::RectangleShape GetPlayer();
  void SetOnPlatform(bool plat);

 private:
  std::shared_ptr<sf::RenderWindow> data_;  // need make shared (?)

  sf::RectangleShape player_;

  float setPlayerX_;  //center x
  float setPlayerY_;  //center y
  float x_             = 0;
  float y_             = 0;
  float velocityX_     = 0;
  float velocityY_     = 0;
  float accelerationX_ = 1;
  float accelerationY_ = 1;

  bool onPlatform_;
};