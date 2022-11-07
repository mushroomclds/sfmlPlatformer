#include <utility>

#include "../lib/Platform.hpp"

Platform::Platform(std::shared_ptr<sf::RenderWindow> data) : data_(std::move(data)) {
  const int width = 10;
  rectPlat_.setSize(sf::Vector2f(static_cast<float>(this->data_->getSize().x), width));
  const int widthOffset = 10;
  rectPlat_.setPosition(0, this->data_->getSize().y - widthOffset);
  std::cout << this->data_->getSize().x << " " << this->data_->getSize().y << std::endl;
  rectPlat_.setFillColor(sf::Color::Red);
}

void Platform::DrawPlatform(sf::RenderTarget& target) {  // render target for drawing
  target.draw(this->rectPlat_);                          // draws shapes defined in circle class
}

sf::RectangleShape Platform::GetPlatform() {
  return this->rectPlat_;
}