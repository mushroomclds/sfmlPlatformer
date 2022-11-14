#include "../include/Game.hpp"
#include "../include/DEFINITIONS.hpp"
#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/sinks/text_file_backend.hpp>
#include <boost/log/utility/setup/file.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>
#include <boost/log/sources/severity_logger.hpp>
#include <boost/log/sources/record_ostream.hpp>

namespace logging  = boost::log;
namespace keywords = boost::log::keywords;
#define LFC1_LOG_TRACE(logger)
/*      
    Game constructor -> Initialize functions : windo w, enemies, etc.
    while loop -> game.runnin() : check if game is still running
        -> game.update() : check for window closed
        -> game.render() : clear window then display new one 
*/

void Init() {
  keywords::auto_flush = true;
  boost::log::add_common_attributes();
  logging::add_file_log(keywords::file_name = "../default_%N.log",
                        keywords::format    = "[%TimeStamp%]: %Message%");
  logging::core::get()->set_filter(logging::trivial::severity >= logging::trivial::info);
}

int main() {
  // initialize random seed
  Init();
  BOOST_LOG_TRIVIAL(trace) << "A trace severity message" << LOG_LINE_FILE;
  BOOST_LOG_TRIVIAL(debug) << "A debug severity message" << LOG_LINE_FILE;
  BOOST_LOG_TRIVIAL(info) << "An informational severity message" << LOG_LINE_FILE;
  BOOST_LOG_TRIVIAL(warning) << "A warning severity message" << LOG_LINE_FILE;
  BOOST_LOG_TRIVIAL(error) << "An error severity message" << LOG_LINE_FILE;
  BOOST_LOG_TRIVIAL(fatal) << "A fatal severity message" << LOG_LINE_FILE;
  return 0;
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
    game.Render();  // render all varia bles
  }
  return 0;
}
