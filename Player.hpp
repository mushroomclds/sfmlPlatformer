#pragma once

#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/Window.hpp>

#include <ctime>
#include <memory>
#include <iostream>

class Player{

    public:
        Player(std::shared_ptr<sf::RenderWindow> data);
        ~Player() = default;

        void drawPlayer(sf::RenderTarget& target);
        void update(sf::RenderTarget& target);

    private:
        std::shared_ptr<sf::RenderWindow> data = std::make_shared<sf::RenderWindow>(); //need make shared (?)

        sf::RectangleShape player;

};