#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <ctime>
#include <iostream>
#include <memory>

#include "Collision.hpp"
#include "Platform.hpp"
#include "Player.hpp"

class Game {
 private:
  // sf::VideoMode videoMode; //defines   video mode
  // sf::RenderWindow *window; //window target for 2D drawing, uses  video mode
  bool endGame_;
  sf::Event ev_;  // defines a system event and its parameters

  std::shared_ptr<sf::RenderWindow> data_ = std::make_shared<sf::RenderWindow>();  // shared pointer deletes
                                                                                   // itself
  Platform* platformObj_;
  Player* player_;

  Collision collision_;

  void InitWindow();
  void InitVariables();

 public:
  Game();
  ~Game();

  // Accessors

  // Modifiers

  // Functions

  void Update();
  void Render();

  const bool Running() const;
  void PollEvents();
};
