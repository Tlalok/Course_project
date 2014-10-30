#include <string>
#include <iostream>
#include <fstream>

using namespace std;
typedef unsigned uint;

class Question
{
	static const uint TEXT_SIZE = 100;
    uint id;
    // текст вопроса
    std::string text;  //questionText не катит? чтобы путаницы не было мб, или я придираюсь?
                       // когда будем обращаться получится questions[i].text вроде норм
public:
    uint getId();
	friend fstream& operator>>(fstream& file, Question& question);
	friend fstream& operator<<(fstream& file, Question& question);
};