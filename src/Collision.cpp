#include "../include/Collision.hpp"

#include "../include/DEFINITIONS.hpp"

Collision::Collision() = default;

bool Collision::CheckPlayerPlatformCollison(const sf::RectangleShape& player,
                                            const sf::RectangleShape& platform) {
  sf::Rect<float> rect1 = player.getGlobalBounds();
  sf::Rect<float> rect2 = platform.getGlobalBounds();

  LOG << "getpos " << player.getPosition().x << " getsize " << player.getSize().x;
  LOG << "platgetPOs " << platform.getPosition().x << " platgetsize" << platform.getSize().x;

  return rect1.intersects(rect2);
}

bool Collision::CheckPlayerPlatformCollison2(const sf::RectangleShape& player,
                                             const sf::RectangleShape& platform) {

  LOG << "getpos " << player.getPosition().x << " getsize" << player.getSize().x;
  LOG << "platgetPOs " << platform.getPosition().x << " platgetsize" << platform.getSize().x;
  bool cond1 =
      (player.getPosition().x >= platform.getPosition().x  //falls within platform left range
       && player.getPosition().x <= (platform.getPosition().x + platform.getSize().x))
      || ((player.getPosition().x + player.getSize().x)  //falls within platform right range
              <= (platform.getPosition().x + platform.getSize().x)
          && ((player.getPosition().x + player.getSize().x) >= platform.getPosition().x));
  bool cond2 = platform.getPosition().y - (player.getPosition().y + player.getSize().y)
            == 0;  //if player on top of plat
  LOG << cond1 << " " << cond2;
  return cond1 && cond2;
}
