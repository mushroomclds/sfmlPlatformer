#pragma once

#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/Window.hpp>

#include <ctime>
#include <memory>
#include <iostream>

class Platform{

    public:
        Platform(std::shared_ptr<sf::RenderWindow> data);
        ~Platform();

        void drawPlatform(sf::RenderTarget& target);
        void update();

    private:
        std::shared_ptr<sf::RenderWindow> data;

        sf::CircleShape circleObj;

};