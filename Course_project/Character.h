#include <vector>
#include "StatisticsQuestion.h"
//#include <unordered_map>

class Character
{
    // имя персонажа
    std::string name;
    // сколько раз был загадан
    // не знаю как назвать на английском)
    unsigned int i;
    // информация по вопросам и ответам 
    // для данного персонажа
    std::vector<StatisticsQuestion> statisticsQuestions;
};