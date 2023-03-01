#include <SFML/Graphics.hpp>
#include "Game.h"
#include <stdlib.h>
#include<time.h>
int main()
{
    //Initialise the random number generator

    srand(time(NULL));

    //Create the Game
    Game gameInstance; // calling default constructor

    gameInstance.RunGameLoop();

    //If we get here, the loop exited, so the game is over
    //end the program by returning
    return 0;
}