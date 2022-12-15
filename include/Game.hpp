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
#include "Enemy.hpp"

class Game {
 private:
  // sf::VideoMode videoMode; //defines   video mode
  // sf::RenderWindow *window; //window target for 2D drawing, uses  video mode
  bool endGame_;
  sf::Event ev_;  // defines a system event and its parameters

  std::shared_ptr<sf::RenderWindow> data_;  // shared pointer deletes
                                            // itself
  Platform* platformObj_;
  Platform* platformLeft_;
  Platform* platformRight_;
  Player* player_;
  std::vector<Enemy*> enemys_;

  Collision collision_;

 public:
  explicit Game(std::shared_ptr<sf::RenderWindow> data);
  ~Game();

  // Accessors

  // Modifiers

  // Functions

  void Update();
  void Render();
  void InitWindow();
  void CheckCollisions();

  bool Running() const;
  void PollEvents();
};
