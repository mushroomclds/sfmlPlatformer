#include "Player.hpp"


Player::Player(std::shared_ptr<sf::RenderWindow> data) : data(data){

    this->player.setFillColor(sf::Color::Green);
    this->player.setSize(sf::Vector2f(10.f, 10.f));
    this->player.setPosition(this->data->getSize().x / 2, this->data->getSize().y / 2);


}

void Player::drawPlayer(sf::RenderTarget& target){
    target.draw(this->player);
}
