#pragma once
#include "vector.cpp"
#include "Game.h"

using namespace std;

class Menu
{
public:
	void menu_main();
	void instructions();
	uint GiveAnswer(string QuestionText, Vector<Answer>& answers);
	void gameMenu();
};