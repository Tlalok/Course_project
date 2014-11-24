#include <Windows.h>

class HighlightMenu
{
    static const int widthConsole = 80;
    HANDLE hConsole;
    DWORD cWritten;
    COORD coord, coordUp, coordDown;
    WORD  mainColor, highlightColor;
    int menuSize;
    int selectedMenuItem;
    int topMargin;
public:
    HighlightMenu(int menuSize, int topMargin = 0);
    int getSelectedMenuItem();
    void resetPosition();
    void newMenu(int menuSize, int topMargin = 0);
    void KeyUp();
    void KeyDown();
    void hideCursor();
    void showCursor();
    ~HighlightMenu();
};