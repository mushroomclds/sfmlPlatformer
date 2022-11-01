#include "../lib/Collision.hpp"

Collision::Collision() {}

bool Collision::checkPlayerPlatformCollison(sf::RectangleShape player,
                                            sf::RectangleShape platform) {
    sf::Rect<float> rect1 = player.getGlobalBounds();
    sf::Rect<float> rect2 = platform.getGlobalBounds();

    if (rect1.intersects(rect2)) {
        return true;
    } else {
        return false;
    }
}