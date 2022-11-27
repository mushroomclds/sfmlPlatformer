#pragma once

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <ctime>
#include <iostream>
#include <memory>

class Collision {
 public:
  Collision();
  ~Collision() = default;

  static bool CheckPlayerPlatformCollison(const sf::RectangleShape& player,
                                          const sf::RectangleShape& platform);

  static bool CheckPlayerPlatformCollison2(const sf::RectangleShape& player,
                                           const sf::RectangleShape& platform);
};
