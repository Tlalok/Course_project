#pragma once
#include "vector.cpp"
#include "Game.h"
#include "include.h"

using namespace std;

class Menu
{
public:
	void menu_main();
	void instructions();
	uint GiveAnswer(string QuestionText, Vector<Answer>& answers);
	void gameMenu();
	void guessMenu(Game &game, uint End_Of_Game = 0);
	uint guessMenu5LeadingCharacters(Game &game);
	void instructionsGuessMenu();
	void addingNewCharacter(Game &game);
	void instructionsAddingNewCharater();
	void printTips();
};