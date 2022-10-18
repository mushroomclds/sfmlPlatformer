#pragma once

#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/Window.hpp>

#include <ctime>
#include <iostream>
#include <memory>

#include "Platform.hpp"

class Game{
    private:
        sf::VideoMode videoMode; //defines a video mode 
        sf::RenderWindow *window; //window target for 2D drawing, uses video mode
        bool endGame;
        sf::Event ev; //defines a system event and its parameters


        std::shared_ptr<sf::RenderWindow> data = std::make_shared<sf::RenderWindow>();
        Platform *platformObj;

        void initWindow();
        void initVariables();

    public:
        Game();
        ~Game();

        //Accessors

        
        //Modifiers


        //Functions 

        void update();
        void render();

        const bool running() const;
        void pollEvents();
};
