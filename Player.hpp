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
        void update(sf::Keyboard::Key key);

    private:
        std::shared_ptr<sf::RenderWindow> data; //need make shared (?)

        sf::RectangleShape player;

};