#include <stdio.h>
#include <iostream>
#include "Game.h"

int main()
{
	Game* game;
	game = new Game;
	game->read();
    return 0;
}
