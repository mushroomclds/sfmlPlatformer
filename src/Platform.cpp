#include <utility>

#include "../include/Platform.hpp"
#include "../include/DEFINITIONS.hpp"

Platform::Platform(std::shared_ptr<sf::RenderWindow> data,
                   unsigned int length,
                   const int width,
                   float posX,
                   float posY)
    : data_(std::move(data)) {
  LOG << "Player data win size: " << data_->getSize().x << " x " << data_->getSize().y;
  // const int width = 10;
  rectPlat_.setSize(sf::Vector2f(static_cast<float>(length), static_cast<float>(width)));
  rectPlat_.setPosition(posX, posY);
  LOG << this->data_->getSize().x << " " << this->data_->getSize().y;
  rectPlat_.setFillColor(sf::Color::Red);
}

void Platform::DrawPlatform(sf::RenderTarget& target) {  // render target for drawing
  target.draw(this->rectPlat_);                          // draws shapes defined in circle class
}

sf::RectangleShape Platform::GetPlatform() {
  return this->rectPlat_;
}