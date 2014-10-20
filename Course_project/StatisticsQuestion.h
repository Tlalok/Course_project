#include <vector>
#include <map>
#include "StatisticsAnswer.h"

class StatisticsQuestion
{
    unsigned int id;
    unsigned int timesOfAskingQuestion;
    std::vector<StatisticsAnswer> statisticsAnswers;
    //std::map<unsigned int, unsigned int> statisticsAnswers;
public:
	StatisticsQuestion();
	StatisticsQuestion(int, int, std::vector<StatisticsAnswer>);
	int getQuestionID();
	int gettimesOfAskingQuestion();
	StatisticsAnswer getAnswerStatistic(int);
	
};