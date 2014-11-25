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
    SetConsoleTitle(L"��������");
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
    game->addAnswer("��");
    game->addAnswer("���");
    game->addAnswer("� �� ���� :c");
        
    game->addQuestion("��� �������� ������?");
    game->addQuestion("��� �������� �������� ����?");
    game->addQuestion("��� �������� - ����?");
    game->addQuestion("��� �������� - ����� �������?");
	game->addQuestion("��� �������� ���������?");
	game->addQuestion("� ������ ��������� ������� ������?");
	game->addQuestion("��� �������� ����������?");
    
    game->addCharacter("����(Star Trek)");
    game->addCharacter("����� �����");
    game->addCharacter("��������� �����");
    game->addCharacter("������� �����");
    game->addCharacter("������");
    
	system("pause");

    game->write();
 
    delete game;
}