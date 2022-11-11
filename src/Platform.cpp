#include <utility>

#include "../include/Platform.hpp"
#include "../include/DEFINITIONS.hpp"

Platform::Platform(std::shared_ptr<sf::RenderWindow> data) : data_(std::move(data)) {
  std::cout << "Player data win size: " << data_->getSize().x << " x "
            << data_->getSize().y << std::endl;
  const int width = 10;
  rectPlat_.setSize(sf::Vector2f(static_cast<float>(this->data_->getSize().x), width));
  rectPlat_.setPosition(0, static_cast<float>(this->data_->getSize().y) - WIDTH_OFFSET);
  std::cout << this->data_->getSize().x << " " << this->data_->getSize().y << std::endl;
  rectPlat_.setFillColor(sf::Color::Red);
}

void Platform::DrawPlatform(sf::RenderTarget& target) {  // render target for drawing
  target.draw(this->rectPlat_);  // draws shapes defined in circle class
}

sf::RectangleShape Platform::GetPlatform() {
  return this->rectPlat_;
}