#include <vector>
#include <map>
#include "StatisticsAnswer.h"
#include <fstream>


class StatisticsQuestion
{
    uint id;
    uint timesOfAskingQuestion;
    std::vector<StatisticsAnswer> statisticsAnswers;
    //std::map<uint, uint> statisticsAnswers;
public:
	StatisticsQuestion();
	StatisticsQuestion(uint, uint, std::vector<StatisticsAnswer>);
	uint getQuestionID();
	uint getTimesOfAskingQuestion();
	StatisticsAnswer getAnswerStatistic(uint);
    uint getTimesOfGivingAnswer(uint idAnswer);
	friend std::fstream& operator>>(std::fstream& file, StatisticsQuestion& statisticsquestion);
	friend std::fstream& operator<<(std::fstream& file, StatisticsQuestion& statisticsquestion);
	
};