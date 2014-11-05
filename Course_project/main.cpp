#include <stdio.h>
#include <iostream>
#include "Game.h"
#include "locale.h"
#include "windows.h"

int main()
{
	setlocale(LC_ALL, "Russian");
    
	Game* game;
	game = new Game();
	game->read();
    game->printStatistics();
    /*
	std::string str("exist7");
	std::cout << (int)game->isQuestionExist(str) << std::endl;
	char buf[30];
	SetConsoleCP(1251);
	std::cin >> buf;
	SetConsoleCP(866);
	std::string name(buf);
    */
	//game->addQuestion(name);
    
    /*
    game->addAnswer("Answer 1");
    game->addAnswer("Answer 2");
    game->addAnswer("Answer 3");
        
    game->addQuestion("Question 1");
    game->addQuestion("Question 2");
    game->addQuestion("Question 3");
    game->addQuestion("Question 4");
    
    game->addCharacter("Character 1");
    game->addCharacter("Character 2");
    game->addCharacter("Character 3");
    game->addCharacter("Character 4");
    game->addCharacter("Character 5");
    
    game->write();
    */
    delete game;

    /*
    std::ofstream ofs("testAnswer.txt");
    StatisticsAnswer sa(1, 20);
    ofs << sa;
    ofs.close();

    StatisticsAnswer sa2(0, 0);
    std::ifstream ifs("testAnswer.txt");
    ifs >> sa2;
    ifs.close();
    */
    /*
    Answer a;
    a.setId(1);
    a.setText("ddfgs");
    Answer a2;
    a2.setId(4);
    a2.setText("nbcvbn");
    vector<Answer> v;
    v.push_back(a);
    v.push_back(a2);
    StatisticsQuestion sq(v);
    
    std::ofstream ofs("testQuestion.txt");
    ofs << sq;
    ofs.close();
    
    StatisticsQuestion sq2;
    
    std::ifstream ifs("testQuestion.txt");
    ifs >> sq2;
    ifs.close();
    
    //StatisticsAnswer sa = sq2.getAnswerStatistic(1);
    //StatisticsAnswer sa2 = sq2.getAnswerStatistic(4);
    */
    /*
    Character c(1, "char1", 5);
    c.addQuestion(sq);
    c.addQuestion(sq2);
    
    std::ofstream ofs("testCharacter.txt");
    ofs << c;
    ofs.close();

    Character c2;
    
    std::ifstream ifs("testCharacter.txt");
    ifs >> c2;
    ifs.close();
    */
    return 0;
}
