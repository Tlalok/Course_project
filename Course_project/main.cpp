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
    SetConsoleTitle(L"Акинатор");
	//writeTestData();
	Menu menu;
	menu.menu_main();
    return 0;
}

void writeTestData()
{
    Game* game = new Game();
	for(uint i = 0; i < 15; i++)
		game->incNumberGames();
    game->addAnswer("да");
    game->addAnswer("нет");
    game->addAnswer("я не знаю :c");
        
    game->addQuestion("Ваш персонаж реален?");
    game->addQuestion("Ваш персонаж мужского пола?");
    game->addQuestion("Ваш персонаж - актёр?");
    game->addQuestion("Ваш персонаж - герой сериала?");
	game->addQuestion("Ваш персонаж президент?");
	game->addQuestion("У вашего персонажа светлые волосы?");
	game->addQuestion("Ваш персонаж супергерой?");
    
    game->addCharacter("Спок(Star Trek)");
    game->addCharacter("Барак Обама");
    game->addCharacter("Анджелина Джоли");
    game->addCharacter("Мерилин Монро");
    game->addCharacter("Бэтмен");
    
	system("pause");

    game->write();
 
    delete game;
}