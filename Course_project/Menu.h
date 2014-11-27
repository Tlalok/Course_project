#pragma once
#include "vector.cpp"
#include "Game.h"
#include "include.h"

using namespace std;

class Menu
{
    typedef uint (Menu::*eventHandler)(int seletedMenuItem, void *param);

    uint RunMenu(int menuSize, int topMargin, eventHandler keyEnterPress = NULL, void *param = NULL, eventHandler keyBackspacePress = NULL);
    uint chooseActionMainMenu(int seletedMenuItem, void *param);
    uint chooseActionAddingQuestion(int selectedMenuItem, void *param);
    uint chooseFrom5Characters(int selectedMenuItem, void *param);
    uint chooseCharacterMiddleGame(int selectedMenuItem, void *param);
    uint throwBackspacePressException(int selectedMenuItem, void *param);
    void setCursor(int X, int Y);
public:
	void menu_main();
	void instructionsMainMenu();
	uint GiveAnswer(string QuestionText, Vector<Answer>& answers);
	void gameMenu();
	//void guessMenu(Game &game, uint End_Of_Game = 0);
    uint guessMenuMiddleGame(Game &game);
	uint guessMenu5LeadingCharacters(Game &game);
	void instructionsGuessMenu();
	void addingNewCharacter(Game &game);
	void instructionsAddingNewCharater();
	void printTips();
};