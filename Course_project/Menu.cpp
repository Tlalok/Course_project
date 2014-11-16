#pragma once
#include <iostream>
#include <Windows.h>
#include <wincon.h>
#include "conio.h"
#include "menu.h"

const int KEY_UP     = 72;
const int KEY_DOWN   = 80;
const int KEY_ENTER  = 13;
const int KEY_ESCAPE = 27;

void Menu :: menu_main()
{
    instructions();
    HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursor = {1, false};  // убираем
    SetConsoleCursorInfo(hOutput, &cursor);   // курсор
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
    FillConsoleOutputAttribute(hOutput, wColor2, 50*1, coord, &cWritten);
    do
    {
        choice = _getch();
        switch(choice)
        {
        case 224:
            choice = _getch();
            switch(choice)
            {
            case KEY_UP: //вверх
                FillConsoleOutputAttribute(hOutput, wColor1, 50*1, coord, &cWritten);
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
                FillConsoleOutputAttribute(hOutput, wColor2, 50*1, coord, &cWritten);
                break;
            case KEY_DOWN://вниз
                FillConsoleOutputAttribute(hOutput, wColor1, 50*1, coord, &cWritten);
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
                FillConsoleOutputAttribute(hOutput, wColor2, 50*1, coord, &cWritten);
                break;
            }
            break;
        case KEY_ENTER:
            if(count == 1)
                gameMenu();
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
}

void Menu :: instructions()
{
    cout << "\t\t\tgameMenu()" << endl;
    cout << "\t\t\tTwo" << endl;
    cout << "\t\t\tThree" << endl;
    cout << "\t\t\tFour" << endl;
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
    FillConsoleOutputAttribute(hOutput, wColor2, 50*1, coord, &cWritten);
    do
    {
        choice = _getch();
        switch(choice)
        {
        case 224:
            choice = _getch();
            switch(choice)
            {
            case KEY_UP: //вверх
                FillConsoleOutputAttribute(hOutput, wColor1, 50*1, coord, &cWritten);
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
                FillConsoleOutputAttribute(hOutput, wColor2, 50*1, coord, &cWritten);
                break;
            case KEY_DOWN://вниз
                FillConsoleOutputAttribute(hOutput, wColor1, 50*1, coord, &cWritten);
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
                FillConsoleOutputAttribute(hOutput, wColor2, 50*1, coord, &cWritten);
                break;
            }
            break;
        case KEY_ENTER:
            return count;
            break;
        default:
            ;
        }
    }while(1);
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
        //game.printProbability();
        //_getch();
        counterOfAnswers++;
		game.giveAnswer(idQuestionToAsk, Answer);
        // counterOfAnswers == game.stackOfQuestions  -  число заданных вопросов равно ограничению
        // !game.getIdNextQuestion()                  -  не найден следующий впрос, т.е. вопросов больше нет
        if(counterOfAnswers == game.stackOfQuestions || !game.getIdNextQuestion())
        {
            //попытка угадать
            Character characterToSuppos = game.getLeadingCharacter();
            cout << "Name: " << characterToSuppos.getName() << endl;
            _getch();
        }
        else if(counterOfAnswers > game.minQuestions)
        {
            //uint idCharacterToSuppose = game.LeadingCharacter();
            if(game.canSupposeCharacter())
            {
                Character characterToSuppos = game.getLeadingCharacter();
                //есть лидер, угадываем
            }
        }
    }
    

}