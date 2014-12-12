#pragma once
#include <iostream>
#include <Windows.h>
#include <wincon.h>
#include "conio.h"
#include "Menu.h"
#include "HighlightMenu.h"
#include "include.h"

class BACKSPACE{};

const int KEY_UP         =  72;
const int KEY_DOWN       =  80;
const int KEY_ENTER      =  13;
const int KEY_ESCAPE     =  27;
const int KEY_SPECIAL    =  224;
const int KEY_BACKSPACE  =  8;

typedef uint (Menu::*eventHandler)(int, void *);
typedef void (Game::*deleteFunc)(uint);
typedef void (Game::*addFunc)(std::string);


void Menu::instructionsMainMenu()
{
	system("cls");
	cout << "\t\t\tНачать игру" << endl;
    cout << "\t\t\tУправление базой" << endl;
    cout << "\t\t\tВыход" << endl;
}

void Menu::instructionsBaseMenu()
{
	system("cls");
	cout << "\t\t\tУправление базой:" << endl;
	cout << "\t\t\tПерсонажи." << endl;
    cout << "\t\t\tВопросы." << endl;
    cout << "\t\t\tОтветы." << endl;
}

void Menu::instructionsDataActions()
{
	system("cls");
	cout << "\t\t\tВыберите действие:" << endl;
	cout << "\t\t\tДобавление." << endl;
    cout << "\t\t\tУдаление." << endl;
}

void Menu::instructionsGuessMenu()
{
	cout << "1.Да, это мой персонаж!" << endl;
	cout << "2.Нет, это не тот персонаж, которого я загадал :с" << endl;
}

void Menu::instructionsAddingNewCharater()
{
	cout << "Можете предложить вопрос, который поможет нам отличить вашего персонажа от предложенных ранее?"<<endl;
	cout << "Да." << endl;
	cout << "Нет." << endl;
}

uint Menu::RunMenu(int menuSize, int topMargin, eventHandler keyEnterPress, void *param, eventHandler keyBackspacePress)
{
    HighlightMenu highlightMenu(menuSize, topMargin);
    int choice;
    do
    {
        choice = _getch();
        switch(choice)
        {
        case KEY_SPECIAL:
            choice = _getch();
            switch(choice)
            {
            case KEY_UP: //вверх
                highlightMenu.KeyUp();
                break;
            case KEY_DOWN://вниз
                highlightMenu.KeyDown();
                break;
            }
            break;
        case KEY_ENTER:
            highlightMenu.showCursor();
            if (keyEnterPress)
                return (this->*keyEnterPress)(highlightMenu.getSelectedMenuItem(), param);
            return highlightMenu.getSelectedMenuItem();
            break;
        case KEY_BACKSPACE:
            if (keyBackspacePress)
                (this->*keyBackspacePress)(highlightMenu.getSelectedMenuItem(), param);
            break;
		case KEY_ESCAPE:
			exit(0);
			break;
        default:
			break;
        }
    } while(1);
}

uint Menu::chooseActionMainMenu(int seletedMenuItem, void *param)
{
    switch(seletedMenuItem)
    {
    case 1:
        gameMenu();
        break;
    case 2:
		baseManagementMenu();
        break;
	case 3:
		exit(0);
		break;
    default:
		break;
    }
    return seletedMenuItem;
}

void Menu::baseManagementMenu()
{
	Game statistic;
	statistic.read();
	uint selectedData;
	while(1)
	{
		instructionsBaseMenu();
		try
		{
			selectedData = RunMenu(3, 1, NULL, NULL, &Menu::throwBackspacePressException);
		}
		catch(BACKSPACE)
		{
			return;
		}
		while(1)
		{
			uint selectedAction;
			instructionsDataActions();
			try
			{
				selectedAction = RunMenu(2, 1, NULL, NULL, &Menu::throwBackspacePressException);
			}
			catch(BACKSPACE)
			{
				break;
			}
			Vector<Character> characters;
			Vector<Question> questions;
			Vector<Answer> answers;
			switch(selectedData)
			{
			case 1:
				switch(selectedAction)
				{
				case 1:
					system("cls");
					cout<<"Введите имя нового персонажа:"<<endl;
					addToBase(&statistic, &Game::addCharacter);
					break;
				case 2:
					characters = statistic.getCharacters();
					system("cls");
					for(uint i = 0; i < characters.size(); i++)
					{
						std::cout << characters[i].getId() << "." << characters[i].getName() << std::endl;
					}
					try
					{
						deleteFromBase(&statistic, &Game::deleteCharacter, characters.size());
					}
					catch(BACKSPACE)
					{
						continue;
					}
					break;
				default:
					break;
				}
				break;
			case 2:
				switch(selectedAction)
				{
				case 1:
					system("cls");
					cout<<"Введите новый вопрос:"<<endl;
					addToBase(&statistic, &Game::addQuestion);
					break;
				case 2:
					questions = statistic.getQuestions();
					system("cls");
					for(uint i = 0; i < questions.size(); i++)
					{
						std::cout << questions[i].getId() << "." << questions[i].getText() << std::endl;
					}
					try
					{
						deleteFromBase(&statistic, &Game::deleteQuestion, questions.size());
					}
					catch(BACKSPACE)
					{
						continue;
					}
					break;
				default:
					break;
				}
				break;
			case 3:
				switch(selectedAction)
				{
				case 1:
					system("cls");
					cout<<"Введите новый ответ:"<<endl;
					addToBase(&statistic, &Game::addAnswer);
					break;
				case 2:
					answers = statistic.getAnswers();
					system("cls");
					for(uint i = 0; i < answers.size(); i++)
					{
						std::cout << answers[i].getId() << "." << answers[i].getText() << std::endl;
					}
					try
					{
					deleteFromBase(&statistic, &Game::deleteAnswer, answers.size());
					}
					catch(BACKSPACE)
					{
						continue;
					}
					break;
			default:
				return;
				}
				break;
			}
			break;
		}
	}
	statistic.write();
	cout<<"Изменения успешно сохранены."<<endl;
	system("pause");
}

void Menu::addToBase(Game* game, addFunc addFuncPtr)
{
	std::string newText;
	cin>>newText;
	(game->*addFuncPtr)(newText);
}

void Menu::deleteFromBase(Game* game, deleteFunc deleteFuncPtr, uint numberOfUnits)
{
	uint selectedAction;
	try
	{
		selectedAction = RunMenu(numberOfUnits, 0, NULL, NULL, &Menu::throwBackspacePressException);
	}
	catch(BACKSPACE)
	{
		throwBackspacePressException(0, NULL);
	}
	(game->*deleteFuncPtr)(selectedAction);
}


uint Menu::chooseActionAddingQuestion(int selectedMenuItem, void *param)
{
    Game *game = (Game *)param;
    if(selectedMenuItem == 1)
    {
        cout << "Пожалуйста, введите вопрос." << endl;
        std::string question;
        cin >> question;
        game->addQuestion(question);
        return selectedMenuItem;
    }
    else if(selectedMenuItem == 2)
    {
        cout << "Очень жаль :с" << endl;
        return selectedMenuItem;
    }
    return selectedMenuItem;
}

uint Menu::chooseFrom5Characters(int selectedMenuItem, void *param)
{
    Vector<Character> *leadingCharacters = (Vector<Character> *) param;
    if(selectedMenuItem == leadingCharacters->size() + 1)
	    return 0;
	return (*leadingCharacters)[selectedMenuItem - 1].getId();
}

uint Menu::chooseCharacterMiddleGame(int selectedMenuItem, void *param)
{
    const uint constinueGame = 1;
    const uint finishGame = 0;
    Game *game = (Game *)param;
    Vector<Character> characterToSuppose = game->getLeadingCharacters(1);
	if(!characterToSuppose.size())
	{
		return constinueGame;
	}
	if(selectedMenuItem == 1)
	{
		game->characterGuessed(characterToSuppose[0].getId());
		return finishGame;
	}
	else if(selectedMenuItem == 2)
	{
		game->ignoreCharacter(characterToSuppose[0].getId());
		return constinueGame;
	}
	else
		cout << "Неверный выбор." << endl;
	return selectedMenuItem;
}

uint Menu::throwBackspacePressException(int selectedMenuItem, void *param)
{
    throw BACKSPACE();
    return selectedMenuItem;
}

void Menu :: menu_main()
{
	while(1)
	{
		instructionsMainMenu();
		int menuSize = 3;
		int topMargin = 0;
		RunMenu(menuSize, topMargin , &Menu::chooseActionMainMenu);
	}
}

uint Menu::GiveAnswer(string QuestionText, Vector<Answer>& answers)
{
	system("cls");
    cout << QuestionText << std::endl;
    for(uint i = 0; i < answers.size(); i++)
    {
        std::cout << answers[i].getId() << "." << answers[i].getText() << std::endl;
    }
    printTips();
    int menuSize = answers.size();
    int topMargin = 1;
    return RunMenu(menuSize, topMargin, NULL, NULL, &Menu::throwBackspacePressException);
}

void Menu::gameMenu()
{
    Game game;
    game.read();
    Vector<Answer> answers = game.getAnswers();
    uint counterOfAnswers = 0;
    
    while(1)
    {
        uint idQuestionToAsk = game.getIdNextQuestion();
        if (idQuestionToAsk == 0)
        {
            uint continueGame = guessMenuMiddleGame(game);
            if (continueGame)
            {
                if(uint guessedCharacter = guessMenuLeadingCharacters(game))
                    game.characterGuessed(guessedCharacter);
                else
                    addingNewCharacter(game);
            }
			game.incNumberGames();
			game.write();
            break;
        }
        std::string questionText = game.getQuestionText(idQuestionToAsk);
		uint answer;
        try
		{
			answer = GiveAnswer(questionText, answers);
		}
		catch(BACKSPACE)
		{
            if (counterOfAnswers > 0)
            {
                game.deleteLastAnswer();
			    counterOfAnswers--;
                game.calculate();
            }
			else
			{
				return;
			}
			continue;
		}
        counterOfAnswers++;
		game.giveAnswer(idQuestionToAsk, answer);
        game.calculate();
        //game.printProbability();
		//system("pause");
        bool askedMinNumberQuestions = counterOfAnswers >= game.minQuestions;
        bool mustTryGuess = (counterOfAnswers % game.stackOfQuestions) == 0;
        if(mustTryGuess || askedMinNumberQuestions && game.canSupposeCharacter())
        {
            //попытка угадать
			//uint continueGame = guessMenu(game);
            uint continueGame = guessMenuMiddleGame(game);
            if (!continueGame)
            {
                game.incNumberGames();
			    game.write();
			    return;
            }
        }
    }
}

uint Menu::guessMenuMiddleGame(Game &game)
{
	system("cls");
	Vector<Character> characterToSuppose = game.getLeadingCharacters(1);
	cout << "Name: " << characterToSuppose[0].getName() << endl;
	instructionsGuessMenu();
    int menuSize = 2;
    int topMargin = 1;
    return RunMenu(menuSize, topMargin, &Menu::chooseCharacterMiddleGame, &game);
}

uint Menu::guessMenuLeadingCharacters(Game &game)
{
	system("cls");
    Vector<Character> leadingCharacters;
	//leadingCharacters = game.getLeadingCharacters(1);
    leadingCharacters = game.getLeadingCharacters(5);
    if (leadingCharacters.size() == 0)
        return 0;
	std::cout << "Может быть один из этих персонажей - тот, кого ты загадал?" << std::endl;
	uint i;
	for(i = 0; i < leadingCharacters.size(); i++)
    {
		std::cout << i + 1  << "." << leadingCharacters[i].getName() << std::endl;
    }
	std::cout << i + 1  << "." << "Нет, ни один из этих персонажей не тот, кого я загадал." << std::endl;

    int menuSize = leadingCharacters.size() + 1;
    int topMargin = 1;
    return RunMenu(menuSize, topMargin, &Menu::chooseFrom5Characters, &leadingCharacters);
}

void Menu::addingNewCharacter(Game &game)
{
	std::string name;
    system("cls");
	cout << "Введите имя загаданного вами персонажа: " << endl;
	cin>>name;
	game.addCharacter(name);
	instructionsAddingNewCharater();

    int menuSize = 2;
    int topMargin = 4;
    RunMenu(menuSize, topMargin, &Menu::chooseActionAddingQuestion, &game);
}

void Menu::setCursor(int X, int Y)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD position = {X, Y};
	SetConsoleCursorPosition(handle, position);
}

void Menu::printTips()
{
    setCursor(0, 24);
    cout << "Стрелки - перемещение, Enter - выбор, Backspace - назад/отмена ответа";
	setCursor(0, 6);
}