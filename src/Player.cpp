#include "../lib/Player.hpp"

#include "../lib/DEFINITIONS.hpp"
#pragma clang diagnostic ignored "-Wswitch"

Player::Player(std::shared_ptr<sf::RenderWindow> data) : data(data) {
  this->player.setFillColor(sf::Color::Green);
  this->player.setSize(sf::Vector2f(PLAYER_SIZE, PLAYER_SIZE));
  this->player.setPosition(this->data->getSize().x / 2, this->data->getSize().y / 2);
  std::cout << "shared ptr count: " << data.use_count() << std::endl;
}

void Player::DrawPlayer(sf::RenderTarget& target) {
  target.draw(this->player);
}

void Player::Update(sf::Keyboard::Key key) {
  switch (key) {
    case sf::Keyboard::W:
      this->player.move(0.F, -MOVE_SPEED_ALL);
      break;
    case sf::Keyboard::A:
      this->player.move(-MOVE_SPEED_ALL, 0.F);
      break;
    case sf::Keyboard::S:
      this->player.move(0.F, MOVE_SPEED_ALL);
      break;
    case sf::Keyboard::D:
      this->player.move(MOVE_SPEED_ALL, 0.F);
      break;
    case sf::Keyboard::Space:
      this->player.move(2.F, 0.F);
      break;
  }
}
void Player::Gravity() {
  this->player.move(0.F, GRAVITY);
}

sf::RectangleShape Player::GetPlayer() {
  return this->player;
}

void Player::Collided() {
  this->player.setPosition(this->player.getPosition().x, this->data->getSize().y - 10 - this->player.getSize().x);
  this->player.setFillColor(sf::Color::White);
}