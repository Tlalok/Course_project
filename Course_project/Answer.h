#include <string>
#include <fstream>

typedef unsigned uint;

class Answer
{
	static const uint TEXT_SIZE = 20;
    uint id;
    // текст ответа
    std::string text;    //answerText не катит? чтобы путаницы не было мб, или я придираюсь?
                         // когда будем обращаться получится answers[i].text вроде норм
public:
    uint getId();
	std::string getText();
	void setId(uint id);
	void setText(std::string text);
	friend std::ifstream& operator>>(std::ifstream& file, Answer& question);
	friend std::ofstream& operator<<(std::ofstream& file, Answer& question);
};