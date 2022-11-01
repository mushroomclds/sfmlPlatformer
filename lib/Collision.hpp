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

    bool checkPlayerPlatformCollison(sf::RectangleShape player,
                                     sf::RectangleShape platform);
};
