#pragma once
#include <iostream>
#include <Windows.h>
#include <wincon.h>
#include "conio.h"
#include "Menu.h"

const int KEY_UP      =  72;
const int KEY_DOWN    =  80;
const int KEY_ENTER   =  13;
const int KEY_ESCAPE  =  27;
const int KEY_SPECIAL =  224;

void Menu :: menu_main()
{
    instructions();
    #pragma region
    #pragma region
    HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursor = {1, false};  // �������
    SetConsoleCursorInfo(hOutput, &cursor);   // ������
    DWORD cWritten;
    COORD coord, coordUp, coordDown;
    WORD  wColor1, wColor2;
    int choice;
    int count = 1;
    int menuSize = 4;
    coordUp.X = coordUp.Y = 0;
    coordDown.X = 0;
    coordDown.Y = menuSize - 1; 
    coord.X = 0;      
    coord.Y = 0;  
    wColor1 = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE;
    wColor2 = FOREGROUND_RED | FOREGROUND_BLUE;
    FillConsoleOutputAttribute(hOutput, wColor2, 70*1, coord, &cWritten);
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
            case KEY_UP: //�����
                FillConsoleOutputAttribute(hOutput, wColor1, 70*1, coord, &cWritten);
                if(count == 1)
                {
                    coord = coordDown;
                    count = menuSize;
                }
                else 
                {
                    coord.Y--;
                    count--;
                }
                FillConsoleOutputAttribute(hOutput, wColor2, 70*1, coord, &cWritten);
                break;
            case KEY_DOWN://����
                FillConsoleOutputAttribute(hOutput, wColor1, 70*1, coord, &cWritten);
                if(count == menuSize)
                {
                    coord = coordUp;
                    count = 1;
                }
                else
                {
                    coord.Y++;
                    count++;
                }
                FillConsoleOutputAttribute(hOutput, wColor2, 70*1, coord, &cWritten);
                break;
            }
            break;
        #pragma endregion Menu navigation
        case KEY_ENTER:
            if(count == 1)
			{
                gameMenu();
				return;
			}
            else if(count == 2)
                cout<<"You've chosen Two"<<endl;
            else if(count == 3)
                cout<<"You've chosen Three"<<endl;
            else if(count == 4)
                cout<<"You've chosen Four"<<endl;
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
    cout << "\t\t\t������ ����" << endl;
    cout << "\t\t\tTwo" << endl;
    cout << "\t\t\tThree" << endl;
    cout << "\t\t\tFour" << endl;
}

// �������� ������ ������ id ������
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
    HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD cWritten;
    COORD coord, coordUp, coordDown;
    WORD  wColor1, wColor2;
    int choice;
    int count = 1;
    int menuSize = answers.size();
    coordUp.X = 0;
    coordUp.Y = 1;
    coordDown.X = 0;
    coordDown.Y = coordUp.Y + menuSize - 1; 
    coord = coordUp;
    wColor1 = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE;
    wColor2 = FOREGROUND_RED | FOREGROUND_BLUE;
    FillConsoleOutputAttribute(hOutput, wColor2, 70*1, coord, &cWritten);
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
            case KEY_UP: //�����
                FillConsoleOutputAttribute(hOutput, wColor1, 70*1, coord, &cWritten);
                if(count == 1)
                {
                    coord = coordDown;
                    count = menuSize;
                }
                else 
                {
                    coord.Y--;
                    count--;
                }
                FillConsoleOutputAttribute(hOutput, wColor2, 70*1, coord, &cWritten);
                break;
            case KEY_DOWN://����
                FillConsoleOutputAttribute(hOutput, wColor1, 70*1, coord, &cWritten);
                if(count == menuSize)
                {
                    coord = coordUp;
                    count = 1;
                }
                else
                {
                    coord.Y++;
                    count++;
                }
                FillConsoleOutputAttribute(hOutput, wColor2, 70*1, coord, &cWritten);
                break;
            }
            break;
        #pragma endregion Menu navigation
        case KEY_ENTER:
            return count;
            break;
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
        uint Answer = GiveAnswer(questionText, answers);
		game.calculate();
        game.printProbability();
        //game.printNumberQuestionsCharacters();
		system("pause");
        counterOfAnswers++;
		game.giveAnswer(idQuestionToAsk, Answer);
        // counterOfAnswers == game.stackOfQuestions  -  ����� �������� �������� ����� �����������
        // !game.getIdNextQuestion()                  -  �� ������ ��������� �����, �.�. �������� ������ ���
        if(counterOfAnswers == game.stackOfQuestions || !game.getIdNextQuestion())
        {
			Character characterToSuppose = game.getLeadingCharacter();
            //������� �������
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
                //���� �����, ���������
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
	HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD cWritten;
    COORD coord, coordUp, coordDown;
    WORD  wColor1, wColor2;
    int choice;
    int count = 1;
    int menuSize = 2;
    coordUp.X = 0;
    coordUp.Y = 1;
    coordDown.X = 0;
    coordDown.Y = coordUp.Y + menuSize - 1; 
    coord = coordUp;
    wColor1 = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE;
    wColor2 = FOREGROUND_RED | FOREGROUND_BLUE;
    FillConsoleOutputAttribute(hOutput, wColor2, 70*1, coord, &cWritten);
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
            case KEY_UP: //�����
                FillConsoleOutputAttribute(hOutput, wColor1, 70*1, coord, &cWritten);
                if(count == 1)
                {
                    coord = coordDown;
                    count = menuSize;
                }
                else 
                {
                    coord.Y--;
                    count--;
                }
                FillConsoleOutputAttribute(hOutput, wColor2, 70*1, coord, &cWritten);
                break;
            case KEY_DOWN://����
                FillConsoleOutputAttribute(hOutput, wColor1, 70*1, coord, &cWritten);
                if(count == menuSize)
                {
                    coord = coordUp;
                    count = 1;
                }
                else
                {
                    coord.Y++;
                    count++;
                }
                FillConsoleOutputAttribute(hOutput, wColor2, 70*1, coord, &cWritten);
                break;
            }
            break;
        #pragma endregion menu navigation
		case KEY_ENTER:
            if(count == 1)
		    {
			    game.characterGuessed(characterToSuppose.getId());
			    return;
		    }
            else if(count == 2)
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
                cout<<"�������� �����."<<endl;
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
	cout<<"1.��, ��� ��� ��������!"<<endl;
	cout<<"2.���, ��� �� ��� ��������, �������� � ������� :�"<<endl;
}

void Menu::addingNewCharacter(Game &game)
{
	std::string name;
	cout<<"������� ��� ���������: "<<endl;
	SetConsoleCP(1251);
	cin>>name;
	SetConsoleCP(866);
	game.addCharacter(name);
	instructionsAddingNewCharater();
    #pragma region
    #pragma region
	HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD cWritten;
    COORD coord, coordUp, coordDown;
    WORD  wColor1, wColor2;
    int choice;
    int count = 1;
    int menuSize = 2;
    coordUp.X = 0;
    coordUp.Y = 18;
    coordDown.X = 0;
    coordDown.Y = coordUp.Y + menuSize - 1; 
    coord = coordUp;
    wColor1 = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE;
    wColor2 = FOREGROUND_RED | FOREGROUND_BLUE;
    FillConsoleOutputAttribute(hOutput, wColor2, 70*1, coord, &cWritten);
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
            case KEY_UP: //�����
                FillConsoleOutputAttribute(hOutput, wColor1, 70*1, coord, &cWritten);
                if(count == 1)
                {
                    coord = coordDown;
                    count = menuSize;
                }
                else 
                {
                    coord.Y--;
                    count--;
                }
                FillConsoleOutputAttribute(hOutput, wColor2, 70*1, coord, &cWritten);
                break;
            case KEY_DOWN://����
                FillConsoleOutputAttribute(hOutput, wColor1, 70*1, coord, &cWritten);
                if(count == menuSize)
                {
                    coord = coordUp;
                    count = 1;
                }
                else
                {
                    coord.Y++;
                    count++;
                }
                FillConsoleOutputAttribute(hOutput, wColor2, 70*1, coord, &cWritten);
                break;
            }
            break;
        #pragma endregion menu navigation
		case KEY_ENTER:
            if(count == 1)
		    {
			    cout<<"����������, ������� ������."<<endl;
			    std::string question;
				SetConsoleCP(1251);
				cin>>question;
				SetConsoleCP(866);
			    game.addQuestion(question);
			    return;
		    }
            else if(count == 2)
			{
				cout<<"����� ���� :�"<<endl;
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
	std::cout<<"����� ���� ���� �� ���� ���������� - ���, ���� �� �������7"<<std::endl;
	uint i;
	for(i = 0; i < leadingCharacters.size(); i++)
    {
		std::cout << i + 1  << "." << leadingCharacters[i].getName()<< std::endl;
    }
	std::cout << i + 1  << "." << "���, �� ���� �� ���� ���������� �� ���, ���� � �������." << std::endl;
    #pragma region
    #pragma region
    HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD cWritten;
    COORD coord, coordUp, coordDown;
    WORD  wColor1, wColor2;
    int choice;
    uint count = 1;
	int menuSize = leadingCharacters.size() + 1;
    coordUp.X = 0;
    coordUp.Y = 1;
    coordDown.X = 0;
    coordDown.Y = coordUp.Y + menuSize; 
    coord = coordUp;
    wColor1 = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE;
    wColor2 = FOREGROUND_RED | FOREGROUND_BLUE;
    FillConsoleOutputAttribute(hOutput, wColor2, 70*1, coord, &cWritten);
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
            case KEY_UP: //�����
                FillConsoleOutputAttribute(hOutput, wColor1, 70*1, coord, &cWritten);
                if(count == 1)
                {
                    coord = coordDown;
                    count = menuSize;
                }
                else 
                {
                    coord.Y--;
                    count--;
                }
                FillConsoleOutputAttribute(hOutput, wColor2, 70*1, coord, &cWritten);
                break;
            case KEY_DOWN://����
                FillConsoleOutputAttribute(hOutput, wColor1, 70*1, coord, &cWritten);
                if(count == menuSize)
                {
                    coord = coordUp;
                    count = 1;
                }
                else
                {
                    coord.Y++;
                    count++;
                }
                FillConsoleOutputAttribute(hOutput, wColor2, 70*1, coord, &cWritten);
                break;
            }
            break;
        #pragma endregion menu navigation
        case KEY_ENTER:
			if(count == leadingCharacters.size() + 1)
				return 0;
			return leadingCharacters[count - 1].getId();
            break;
        default:
            ;
        }
    }while(1);
    #pragma endregion Menu
}

void Menu::instructionsAddingNewCharater()
{
	system("pause");
	cout<<"������ ���������� ������, ������� ������� ��� �������� ������ ��������� �� ������������ �����7"<<endl;
	cout<<"��."<<endl;
	cout<<"���."<<endl;
}