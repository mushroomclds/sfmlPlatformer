#include "Player.hpp"

#include "DEFINITIONS.hpp"

Player::Player(std::shared_ptr<sf::RenderWindow> data) : data(data) {
    this->player.setFillColor(sf::Color::Green);
    this->player.setSize(sf::Vector2f(PLAYER_SIZE, PLAYER_SIZE));
    this->player.setPosition(this->data->getSize().x / 2,
                             this->data->getSize().y / 2);
    std::cout << "shared ptr count: " << data.use_count() << std::endl;
}

void Player::drawPlayer(sf::RenderTarget &target) { target.draw(this->player); }

void Player::update(sf::Keyboard::Key key) {
    switch (key) {
        case sf::Keyboard::W:
            this->player.move(0.f, -MOVE_SPEED_ALL);
            break;
        case sf::Keyboard::A:
            this->player.move(-MOVE_SPEED_ALL, 0.f);
            break;
        case sf::Keyboard::S:
            this->player.move(0.f, MOVE_SPEED_ALL);
            break;
        case sf::Keyboard::D:
            this->player.move(MOVE_SPEED_ALL, 0.f);
            break;
        case sf::Keyboard::Space:
            this->player.move(2.f, 0.f);
            break;
    }
}
void Player::gravity() { this->player.move(0.f, GRAVITY); }

sf::RectangleShape Player::getPlayer() { return this->player; }

void Player::collided() {
    this->player.setPosition(
        this->player.getPosition().x,
        this->data->getSize().y - 10 - this->player.getSize().x);
    this->player.setFillColor(sf::Color::White);
}