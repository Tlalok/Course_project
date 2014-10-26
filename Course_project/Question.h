#include <string>

typedef unsigned uint;

class Question
{
    uint id;
    // текст вопроса
    std::string text;  //questionText не катит? чтобы путаницы не было мб, или я придираюсь?
                       // когда будем обращаться получится questions[i].text вроде норм
public:
    uint getId();
};