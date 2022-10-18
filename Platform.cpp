#include "Platform.hpp"


Platform::Platform(std::shared_ptr<sf::RenderWindow> data) : data(data){
    circleObj.setRadius(500.f);
    circleObj.setFillColor(sf::Color::Red);

}
Platform::~Platform() = default;

void Platform::drawPlatform(sf::RenderTarget& target){ //render target for drawing 
    target.draw(circleObj);  //draws shapes defined in circle class 

}