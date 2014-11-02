#include <stdio.h>
#include <iostream>
#include "Game.h"
#include "locale.h"
#include "windows.h"

int main()
{
	setlocale(LC_ALL, "Russian");
	Game* game;
	game = new Game();
	game->read();
	std::string str("Obama");
	std::cout<<(int)game->isCharacterExist(str)<<std::endl;
	char buf[30];
	SetConsoleCP(1251);
	std::cin>>buf;
	SetConsoleCP(866);
	std::string name(buf);
	game->addCharacter(name);
	game->write();
    return 0;
}
