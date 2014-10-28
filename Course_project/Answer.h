#include <string>
#include <fstream>

using namespace std;

typedef unsigned uint;

class Answer
{
	const uint TEXT_SIZE = 20;
    uint id;
    // текст ответа
    std::string text;    //answerText не катит? чтобы путаницы не было мб, или я придираюсь?
                         // когда будем обращаться получится answers[i].text вроде норм
public:
    uint getId();
	friend fstream& operator>>(fstream& file, Answer& question);
	friend fstream& operator<<(fstream& file, Answer& question);
};