#include "HighlightMenu.h"

HighlightMenu::HighlightMenu(int menuSize, int topMargin)
{
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursor = {1, false};  // убираем
    SetConsoleCursorInfo(hConsole, &cursor);  // курсор
    mainColor = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE;
    highlightColor = FOREGROUND_RED | FOREGROUND_BLUE;
    newMenu(menuSize, topMargin);
}

int HighlightMenu::getSelectedMenuItem()
{
    return selectedMenuItem;
}

void HighlightMenu::resetPosition()
{
    selectedMenuItem = 1;
    coordUp.X = 0;
    coordUp.Y = topMargin;
    coordDown.X = 0;
    coordDown.Y = menuSize - 1 + topMargin; 
    coord = coordUp;       
    FillConsoleOutputAttribute(hConsole, highlightColor, 50*1, coord, &cWritten);
}

void HighlightMenu::newMenu(int menuSize, int topMargin)
{
    this->menuSize = menuSize;
    this->topMargin = topMargin;
    resetPosition();
}

void HighlightMenu::KeyUp()
{
    FillConsoleOutputAttribute(hConsole, mainColor, 50*1, coord, &cWritten);
    if(selectedMenuItem == 1)
    {
        coord = coordDown;
        selectedMenuItem = menuSize;
    }
    else 
    {
        coord.Y--;
        selectedMenuItem--;
    }
    FillConsoleOutputAttribute(hConsole, highlightColor, 50*1, coord, &cWritten);
}

void HighlightMenu::KeyDown()
{
    FillConsoleOutputAttribute(hConsole, mainColor, 50*1, coord, &cWritten);
    if(selectedMenuItem == menuSize)
    {
        coord = coordUp;
        selectedMenuItem = 1;
    }
    else
    {
        coord.Y++;
        selectedMenuItem++;
    }
    FillConsoleOutputAttribute(hConsole, highlightColor, 50*1, coord, &cWritten);
}

HighlightMenu::~HighlightMenu()
{
    CONSOLE_CURSOR_INFO cursor = {25, true}; //восстанавливаем курсор
    SetConsoleCursorInfo(hConsole, &cursor);
}