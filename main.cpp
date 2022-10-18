#include "Game.hpp"

/*
    Game constructor -> Initialize functions : window, enemies, etc.
    while loop -> game.runnin() : check if game is still running 
        -> game.update() : check for window closed
        -> game.render() : clear window then display new one 
*/

int main(){

    //initialize random seed
    std::srand(static_cast<unsigned>(time(0)));


    //initialize game object through constructor 
    Game game;

    //game loop

    while(game.running()){//if window not close and not game over with endGame

        game.update();//update all variables, including renderWindow
        game.render();//render all variables
    }

}