#include <vector>
#include <map>
#include "StatisticsQuestion.h"

class Character
{
	//мне кажется что нужно, да и инты быстрее стринга работать будут, мб ещё и персонажи с одинаковыми именами, хз
	int id;
    // имя персонажа
    std::string name;
    // сколько раз был загадан
    unsigned int timesPicked;
    // информация по вопросам и ответам 
    // для данного персонажа
    std::vector<StatisticsQuestion> statisticsQuestions;
    //std::map<unsigned int, StatisticsQuestion> statisticsQuestions;
public:
	int getTimesPicked();
	int getId();
	std::string getName();
};