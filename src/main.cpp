#include "../include/Game.hpp"
#include "../include/DEFINITIONS.hpp"
#include "SFML/System/Clock.hpp"

/*      
    Game constructor -> Initialize functions : windo w, enemies, etc. 
    while loop -> game.runnin() : check if game is still running
        -> game.update() : check for window closed
        -> game.render() : clear window then display new one 
*/
namespace logging  = boost::log;
namespace keywords = boost::log::keywords;
void Init() {
  keywords::auto_flush = true;
  boost::log::add_common_attributes();
  logging::add_file_log(keywords::file_name = "../default_%N.log",
                        keywords::format    = "%Message% ");  //%TimeStamp%
  logging::core::get()->set_filter(logging::trivial::severity >= logging::trivial::info);
}

int main() {

  Init();  //intialize boost logging

  std::srand(static_cast<unsigned>(
      time(nullptr)));  //initialize random seed, nullptr is 0 here (?)

  std::shared_ptr<sf::RenderWindow> data = std::make_shared<sf::RenderWindow>();
  data->create(sf::VideoMode(VIDEOMODE_WIDTH, VIDEOMODE_HEIGHT),
               "title",
               sf::Style::Close | sf::Style::Titlebar);

  LOG << "Original data ptr win size: " << data->getSize().x << " x "
      << data->getSize().y;

  Game game(data);  // initialize game object through constructor

  sf::Clock clock;
  data->setFramerateLimit(FRAMERATE);
  // game loop
  while (game.Running()) {  // if window not close and not game over with

    float currentTime = clock.restart().asSeconds();
    float fps         = 1.0F / currentTime;
    std::cout << "fps: " << fps << std::endl;

    game.Update();  // update all variables, including renderWind ow
    game.Render();  // render all varia bles
  }
  return 0;
}
