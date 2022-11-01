#include "../lib/Platform.hpp"

Platform::Platform(std::shared_ptr<sf::RenderWindow> data) : data(data) {
    rectPlat.setSize(
        sf::Vector2f(static_cast<float>(this->data->getSize().x), 10.f));
    rectPlat.setPosition(0, this->data->getSize().y - 10);
    std::cout << this->data->getSize().x << " " << this->data->getSize().y
              << std::endl;
    rectPlat.setFillColor(sf::Color::Red);
}

void Platform::drawPlatform(
    sf::RenderTarget &target) {    // render target for drawing
    target.draw(this->rectPlat);   // draws shapes defined in circle class
}

sf::RectangleShape Platform::getPlatform() { return this->rectPlat; }