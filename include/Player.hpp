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
#include "SFML/Graphics/Texture.hpp"

class Player {
 public:
  explicit Player(const std::shared_ptr<sf::RenderWindow>& data,
                  sf::Vector2f playerSize_ = sf::Vector2f(PLAYER_SIZE, PLAYER_SIZE));
  ~Player() = default;

  void DrawPlayer(sf::RenderTarget& target);
  void Update();
  void Gravity();
  void Collided(int y);
  sf::RectangleShape GetPlayer();
  void SetOnPlatform(bool plat);
  void CheckBounds();

  sf::RectangleShape player_;

 private:
  std::shared_ptr<sf::RenderWindow> data_;  // need make shared (?)

  float setPlayerX_;  //center x
  float setPlayerY_;  //center y
  float x_             = 0;
  float y_             = 0;
  float velocityX_     = 0;
  float velocityY_     = 0;
  float accelerationX_ = 1;
  float accelerationY_ = 1;

  sf::Vector2f playerSize_;

  int jumpCounter_ = 0;

  bool onPlatform_;

  sf::Texture* texture = nullptr;
};