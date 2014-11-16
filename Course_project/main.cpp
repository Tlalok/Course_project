#include <stdio.h>
#include <iostream>
#include "Game.h"
#include "locale.h"
#include "windows.h"
#include "Menu.h"

void writeTestData();

int main()
{
	setlocale(LC_ALL, "Russian");
    
	Menu menu;
	menu.menu_main();
    /*
	Game* game;
	game = new Game();
	game->read();
    game->printStatistics();
	std::string str("exist7");
	std::cout << (int)game->isQuestionExist(str) << std::endl;
	char buf[30];
	SetConsoleCP(1251);
	std::cin >> buf;
	SetConsoleCP(866);
	std::string name(buf);
	game->addQuestion(name);
    */

    return 0;
}

void writeTestData()
{
    Game* game = new Game();
    game->addAnswer("Answer 1");
    game->addAnswer("Answer 2");
    game->addAnswer("Answer 3");
        
    game->addQuestion("Question 1");
    game->addQuestion("Question 2");
    game->addQuestion("Question 3");
    game->addQuestion("Question 4");
    
    game->addCharacter("Character 1");
    game->addCharacter("Character 2");
    game->addCharacter("Character 3");
    game->addCharacter("Character 4");
    game->addCharacter("Character 5");
    
    game->write();
 
    delete game;
}