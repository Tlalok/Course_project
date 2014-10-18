#include <vector>
#include "StatisticsAnswer.h"

class StatisticsQuestion
{
    unsigned int id;
    // сколько раз был задан этот вопрос
    // когда загадывали персонажа которому
    // принадлежит объект этого класса 
    // тоже не знаю как назвать)     //amountOfAskingQuestion  ,если не сильно громоздко.можно урезать имя
    unsigned int i;
    // статистика ответов
    std::vector<StatisticsAnswer> statisticsAnswers;
};