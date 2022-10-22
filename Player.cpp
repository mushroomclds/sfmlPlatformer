#include "Player.hpp"


Player::Player(std::shared_ptr<sf::RenderWindow> data) : data(data){

    this->player.setFillColor(sf::Color::Green);
    this->player.setSize(sf::Vector2f(10.f, 10.f));
    this->player.setPosition(this->data->getSize().x / 2, this->data->getSize().y / 2);
    std::cout << "shared ptr count: " << data.use_count() << std::endl;

}

void Player::drawPlayer(sf::RenderTarget& target){
    target.draw(this->player);
}


void Player::update(sf::Keyboard::Key key){
    switch(key){
        case sf::Keyboard::W:
            this->player.move(0.f, -1.f);
            break;
        case sf::Keyboard::A:
            this->player.move(-1.f, 0.f);
            break;
        case sf::Keyboard::S:
            this->player.move(0.f, 1.f);
            break;
        case sf::Keyboard::D:
            this->player.move(1.f, 0.f);
            break;
    }
}