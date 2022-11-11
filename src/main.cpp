#include "../include/Game.hpp"
#include "../include/DEFINITIONS.hpp"
/*
    Game constructor -> Initialize functions : window, enemies, etc.
    while loop -> game.runnin() : check if game is still running
        -> game.update() : check for window closed
        -> game.render() : clear window then display new one
*/

int main() {
  // initialize random seed
  std::srand(static_cast<unsigned>(time(nullptr)));  // nullptr is 0 here (?)

  std::shared_ptr<sf::RenderWindow> data = std::make_shared<sf::RenderWindow>();

  data->create(sf::VideoMode(VIDEOMODE_WIDTH, VIDEOMODE_HEIGHT),
               "title",
               sf::Style::Close | sf::Style::Titlebar);
  std::cout << "Original data ptr win size: " << data->getSize().x << " x "
            << data->getSize().y << std::endl;

  // initialize game object through constructor
  Game game(data);

  // game loop

  while (game.Running()) {  // if window not close and not game over with
                            // endGame

    game.Update();  // update all variables, including renderWind ow
    game.Render();  // render all variables
  }
  return 0;
}