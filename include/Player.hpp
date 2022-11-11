#pragma once

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <ctime>
#include <iostream>
#include <memory>

class Player {
 public:
  explicit Player(const std::shared_ptr<sf::RenderWindow>& data);
  ~Player() = default;

  void DrawPlayer(sf::RenderTarget& target);
  void Update(sf::Keyboard::Key key);
  void Gravity();
  void Collided();
  sf::RectangleShape GetPlayer();

 private:
  std::shared_ptr<sf::RenderWindow> data_;  // need make shared (?)

  sf::RectangleShape player_;
};