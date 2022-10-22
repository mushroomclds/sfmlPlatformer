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
    Platform(std::shared_ptr<sf::RenderWindow> data);
    ~Platform() = default;

    void drawPlatform(sf::RenderTarget &target);
    void update();

  private:
    std::shared_ptr<sf::RenderWindow> data;   // need make shared (?)

    sf::RectangleShape rectPlat;
};