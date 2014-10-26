#include <string>

typedef unsigned uint;

class Answer
{
    uint id;
    // текст ответа
    std::string text;    //answerText не катит? чтобы путаницы не было мб, или я придираюсь?
                         // когда будем обращаться получится answers[i].text вроде норм
public:
    uint getId();

};