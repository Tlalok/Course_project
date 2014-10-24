#include <vector>
#include <map>
#include "StatisticsQuestion.h"

class Character
{
	//мне кажется что нужно, да и инты быстрее стринга работать будут, мб ещё и персонажи с одинаковыми именами, хз
	uint id;
    // имя персонажа
    std::string name;
    // сколько раз был загадан
    uint timesPicked;
    // информация по вопросам и ответам 
    // для данного персонажа
    std::vector<StatisticsQuestion> statisticsQuestions;
    //std::map<uint, StatisticsQuestion> statisticsQuestions;
public:
	uint getTimesPicked();
	uint getId();
	std::string getName();
    //uint getCountQuestions();
    uint getTimesOfAskingQuestion(uint idQuestion);
    uint getTimesOfGivingAnswer(uint idQuestion, uint idAnswer);
};