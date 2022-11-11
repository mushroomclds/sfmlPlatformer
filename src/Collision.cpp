#include "../include/Collision.hpp"

Collision::Collision() = default;

bool Collision::CheckPlayerPlatformCollison(const sf::RectangleShape& player,
                                            const sf::RectangleShape& platform) {
  sf::Rect<float> rect1 = player.getGlobalBounds();
  sf::Rect<float> rect2 = platform.getGlobalBounds();

  return rect1.intersects(rect2);
}