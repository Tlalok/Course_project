#include <map>
#include "StatisticsAnswer.h"
#include "Question.h"
#include "Answer.h"

class StatisticsQuestion
{
    uint id;
    uint timesOfAskingQuestion;
    vector<StatisticsAnswer> statisticsAnswers;
    //std::map<uint, uint> statisticsAnswers;
public:
	StatisticsQuestion();
	StatisticsQuestion(vector<Answer>& answers);
	StatisticsQuestion(uint, uint, vector<StatisticsAnswer>);
    StatisticsQuestion(const StatisticsQuestion& toCopy);
    //StatisticsQuestion(StatisticsQuestion & statisticsQuestion);
    StatisticsQuestion& operator++();
	StatisticsAnswer& operator[](uint answerId);
	StatisticsQuestion& operator=(StatisticsQuestion& toCopy);
	void setId(uint id);
	uint getQuestionID();
	uint getTimesOfAskingQuestion();
	StatisticsAnswer getAnswerStatistic(uint);
    uint getTimesOfGivingAnswer(uint idAnswer);
	void addAnswer(StatisticsAnswer toAdd);
	friend std::ifstream& operator>>(std::ifstream& file, StatisticsQuestion& statisticsquestion);
	friend std::ofstream& operator<<(std::ofstream& file, StatisticsQuestion& statisticsquestion);
	
};