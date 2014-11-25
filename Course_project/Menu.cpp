#pragma once
#include <iostream>
#include <Windows.h>
#include <wincon.h>
#include "conio.h"
#include "Menu.h"
#include "HighlightMenu.h"
#include "include.h"

class BACKSPACE{};

const int KEY_UP      =  72;
const int KEY_DOWN    =  80;
const int KEY_ENTER   =  13;
const int KEY_ESCAPE  =  27;
const int KEY_SPECIAL =  224;
const int KEY_BACKSPACE = 8;

void Menu :: menu_main()
{
    instructions();
    #pragma region
    #pragma region
    int menuSize = 4;
    HighlightMenu highlightMenu(menuSize);
    int choice;
    #pragma endregion init menu
    do
    {
        #pragma region
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
        #pragma endregion Menu navigation
        case KEY_ENTER:
            if(highlightMenu.getSelectedMenuItem() == 1)
			{
                gameMenu();
				return;
			}
            else if(highlightMenu.getSelectedMenuItem() == 2)
                cout<<"You've chosen Two"<<endl;
            else if(highlightMenu.getSelectedMenuItem() == 3)
                cout<<"You've chosen Three"<<endl;
            else if(highlightMenu.getSelectedMenuItem() == 4)
                return;
            else
                cout<<"Invalid choice"<<endl;
            break;
        case KEY_ESCAPE:
            break;
        default:
            ;
        }
    }while(choice != KEY_ESCAPE);
    #pragma endregion Menu
}

void Menu :: instructions()
{
	system("cls");
    cout << "\t\t\tНачать игру" << endl;
    cout << "\t\t\tУправление базой" << endl;
    cout << "\t\t\tНастройки" << endl;
    cout << "\t\t\tВыход" << endl;
}

// подумать насчет вывода id ответа
uint Menu::GiveAnswer(string QuestionText, Vector<Answer>& answers)
{
	system("cls");
    cout<<QuestionText<<std::endl;
    for(uint i = 0; i < answers.size(); i++)
    {
        //std::cout << i + 1 << "." << answers[i].getText() << std::endl;
        std::cout << answers[i].getId() << "." << answers[i].getText() << std::endl;
    }
    #pragma region
    #pragma region
    int menuSize = answers.size();
    int topMargin = 1;
    HighlightMenu highlightMenu(menuSize, topMargin);
	highlightMenu.setCursor(0, 24);
	printTips();
	highlightMenu.setCursor(0, 6);
    int choice;
    #pragma endregion init menu
    do
    {
        #pragma region
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
        #pragma endregion Menu navigation
        case KEY_ENTER:
            return highlightMenu.getSelectedMenuItem();
            break;
		case KEY_BACKSPACE:
			throw BACKSPACE();
        default:
            ;
        }
    }while(1);   
    #pragma endregion Menu
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
            break;
        cout << idQuestionToAsk;
        std::string questionText = game.getQuestionText(idQuestionToAsk);
		uint answer;
        try
		{
			answer = GiveAnswer(questionText, answers);
		}
		catch(BACKSPACE)
		{
			game.deleteLastAnswer();
			counterOfAnswers--;
			continue;
		}
		game.calculate();
        game.printProbability();
        //game.printNumberQuestionsCharacters();
		system("pause");
        counterOfAnswers++;
		game.giveAnswer(idQuestionToAsk, answer);
        // counterOfAnswers == game.stackOfQuestions  -  число заданных вопросов равно ограничению
        // !game.getIdNextQuestion()                  -  не найден следующий впрос, т.е. вопросов больше нет
        if(counterOfAnswers == game.stackOfQuestions || !game.getIdNextQuestion())
        {
			Character characterToSuppose = game.getLeadingCharacter();
            //попытка угадать
           if(!game.getIdNextQuestion())
		   {
			   guessMenu(game, 1);
			   game.incNumberGames();
			   game.write();
			   return;
		   }
		   else
			   guessMenu(game);
        }
        else if(counterOfAnswers > game.minQuestions)
        {
            //uint idCharacterToSuppose = game.LeadingCharacter();
            if(game.canSupposeCharacter())
            {
                Character characterToSuppose = game.getLeadingCharacter();
                //есть лидер, угадываем
				guessMenu(game);
            }
        }
    }
}

void Menu::guessMenu(Game &game, uint End_Of_Game)
{
	system("cls");
	Character characterToSuppose = game.getLeadingCharacter();
	cout << "Name: " << characterToSuppose.getName() << endl;
	instructionsGuessMenu();
    #pragma region
    #pragma region
    int menuSize = 2;
    int topMargin = 1;
    HighlightMenu highlightMenu(menuSize, topMargin);
    int choice;
    #pragma endregion init menu
	do
    {
        #pragma region
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
        #pragma endregion menu navigation
		case KEY_ENTER:
            if(highlightMenu.getSelectedMenuItem() == 1)
		    {
			    game.characterGuessed(characterToSuppose.getId());
			    return;
		    }
            else if(highlightMenu.getSelectedMenuItem() == 2)
				if(End_Of_Game == 1)
				{
					if(uint guessedCharacter = guessMenu5LeadingCharacters(game))
					{
						game.characterGuessed(guessedCharacter);
						return;
					}
					addingNewCharacter(game);
					return;
				}
				else
				{
					return;
				}
            else
                cout<<"Неверный выбор."<<endl;
            break;
            break;
        default:
            ;
        }
    }while(1);
    #pragma endregion Menu

}

void Menu::instructionsGuessMenu()
{
	cout<<"1.Да, это мой персонаж!"<<endl;
	cout<<"2.Нет, это не тот персонаж, которого я загадал :с"<<endl;
}

void Menu::addingNewCharacter(Game &game)
{
	std::string name;
    system("cls");
	cout<<"Введите имя загаданного вами персонажа: "<<endl;
	cin>>name;
	game.addCharacter(name);
	instructionsAddingNewCharater();
    #pragma region
    #pragma region
    int menuSize = 2;
    //int topMargin = 18;
    int topMargin = 4;
    HighlightMenu highlightMenu(menuSize, topMargin);
    int choice;
    #pragma endregion init menu
	do
	{
        #pragma region
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
        #pragma endregion menu navigation
		case KEY_ENTER:
            if(highlightMenu.getSelectedMenuItem() == 1)
		    {
				std::string question;
                cin >> question;
			    game.addQuestion(question);
			    return;
		    }
            else if(highlightMenu.getSelectedMenuItem() == 2)
			{
				cout<<"Очень жаль :с"<<endl;
				return;
			}
            break;
        default:
            ;
        }
    }while(1);
    #pragma endregion Menu
}

uint Menu::guessMenu5LeadingCharacters(Game &game)
{
	system("cls");
    Vector<Character> leadingCharacters;
	leadingCharacters = game.get5LeadingCharacters();
	std::cout<<"Может быть один из этих персонажей - тот, кого ты загадал7"<<std::endl;
	uint i;
	for(i = 0; i < leadingCharacters.size(); i++)
    {
		std::cout << i + 1  << "." << leadingCharacters[i].getName()<< std::endl;
    }
	std::cout << i + 1  << "." << "Нет, ни один из этих персонажей не тот, кого я загадал." << std::endl;
    #pragma region
    #pragma region
    int menuSize = leadingCharacters.size() + 1;
    int topMargin = 1;
    HighlightMenu highlightMenu(menuSize, topMargin);
    int choice;
    #pragma endregion init menu
    do
    {
        #pragma region
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
        #pragma endregion menu navigation
        case KEY_ENTER:
            if(highlightMenu.getSelectedMenuItem() == leadingCharacters.size() + 1)
				return 0;
			return leadingCharacters[highlightMenu.getSelectedMenuItem() - 1].getId();
            break;
        default:
            ;
        }
    }while(1);
    #pragma endregion Menu
}

void Menu::instructionsAddingNewCharater()
{
	//system("pause");
	cout<<"Можете предложить вопрос, который поможет нам отличить вашего персонажа от предложенных ранее7"<<endl;
	cout<<"Да."<<endl;
	cout<<"Нет."<<endl;
}

void Menu::printTips()
{
	cout<<"Стрелки - перемещение, Enter - выбор, Backspace - отмена последнего ответа";
}