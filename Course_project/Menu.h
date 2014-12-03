#pragma once
#include "vector.cpp"
#include "Game.h"
#include "include.h"

using namespace std;

class Menu
{
    typedef uint (Menu::*eventHandler)(int seletedMenuItem, void *param);
	typedef void (Game::*deleteFunc)(uint);
	typedef void (Game::*addFunc)(std::string);

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
    uint guessMenuMiddleGame(Game &game);
	uint guessMenuLeadingCharacters(Game &game);
	void baseManagementMenu();
	void instructionsGuessMenu();
	void instructionsBaseMenu();
	void instructionsDataActions();
	void addingNewCharacter(Game &game);
	void instructionsAddingNewCharater();
	void printTips();
	void deleteFromBase(Game* game, deleteFunc deleteNode, uint numberOfUnits);
	void addToBase(Game* game, addFunc addNode);
};