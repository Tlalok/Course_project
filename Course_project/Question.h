#include <string>
#include <iostream>
#include <fstream>

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
	void setText(std::string text);
	void setId(uint id);
	friend std::ifstream& operator>>(std::ifstream& file, Question& question);
	friend std::ofstream& operator<<(std::ofstream& file, Question& question);
	std::string getText();
};