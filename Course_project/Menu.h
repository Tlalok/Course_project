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
	void guessMenu(Game &game, uint idCharacter, uint End_Of_Game = 0);
	void instructionsGuessMenu();
	void addingNewCharacter(Game &game);
	void instructionsAddingNewCharater();
};