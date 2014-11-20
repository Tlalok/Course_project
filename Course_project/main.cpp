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
	//writeTestData();
	Game game;
	game.read();
	game.printStatistics();
	system("pause");
    
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
	for(uint i = 0; i < 15; i++)
		game->incNumberGames();
    game->addAnswer("��");
    game->addAnswer("���");
    game->addAnswer("� �� ���� :c");
        
    game->addQuestion("��� �������� ������7");
    game->addQuestion("��� �������� �������� ����7");
    game->addQuestion("��� �������� - ����7");
    game->addQuestion("��� �������� - ����� �������7");
	game->addQuestion("��� �������� ���������7");
    
    game->addCharacter("����(Star Trek)");
    game->addCharacter("����� �����");
    game->addCharacter("��������� �����");
    game->addCharacter("Character 4");
    game->addCharacter("Character 5");
    
	system("pause");

    game->write();
 
    delete game;
}