#pragma once

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <ctime>
#include <iostream>
#include <memory>

class Platform {
 public:
  explicit Platform(std::shared_ptr<sf::RenderWindow> data,
                    unsigned int length,
                    int width,
                    float posX,
                    float posY);
  ~Platform() = default;

  void DrawPlatform(sf::RenderTarget& target);
  void Update();

  sf::RectangleShape GetPlatform();

 private:
  std::shared_ptr<sf::RenderWindow> data_;  // need make shared (?)

  sf::RectangleShape rectPlat_;
};