#include "../include/Collision.hpp"

#include "../include/DEFINITIONS.hpp"

Collision::Collision() = default;

bool Collision::CheckPlayerPlatformCollison(const sf::RectangleShape& player,
                                            const sf::RectangleShape& platform) {
  sf::Rect<float> rect1 = player.getGlobalBounds();
  sf::Rect<float> rect2 = platform.getGlobalBounds();

  LOG << "getpos " << player.getPosition().x << " getsize" << player.getSize().x;
  LOG << "platgetPOs " << platform.getPosition().x << " platgetsize" << platform.getSize().x;

  return rect1.intersects(rect2);
}

bool Collision::CheckPlayerPlatformCollison2(const sf::RectangleShape& player,
                                             const sf::RectangleShape& platform) {
  sf::Rect<float> rect1 = player.getGlobalBounds();
  sf::Rect<float> rect2 = platform.getGlobalBounds();

  LOG << "getpos " << player.getPosition().x << " getsize" << player.getSize().x;
  LOG << "platgetPOs " << platform.getPosition().x << " platgetsize" << platform.getSize().x;
  bool cond1 = (player.getPosition().x >= platform.getPosition().x
                && player.getPosition().x <= platform.getSize().x)
            || ((player.getPosition().x + player.getSize().x) <= platform.getSize().x
                && ((player.getPosition().x + player.getSize().x)
                    >= platform.getPosition().x));  //if player in range of platform
  bool cond2 = platform.getPosition().y - (player.getPosition().y + player.getSize().y)
            == 0;  //if player on top of plat
  return cond1 && cond2;
}