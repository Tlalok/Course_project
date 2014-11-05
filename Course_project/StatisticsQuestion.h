#include <map>
#include "StatisticsAnswer.h"
#include "Question.h"
#include "Answer.h"

class StatisticsQuestion
{
    uint id;
    uint timesOfAskingQuestion;
    Vector<StatisticsAnswer> statisticsAnswers;
    //std::map<uint, uint> statisticsAnswers;
public:
	StatisticsQuestion();
	StatisticsQuestion(Vector<Answer>& answers);
	StatisticsQuestion(uint, uint, Vector<StatisticsAnswer>);
    StatisticsQuestion(StatisticsQuestion& toCopy);
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
	friend std::istream& operator>>(std::istream& file, StatisticsQuestion& statisticsquestion);
	friend std::ostream& operator<<(std::ostream& file, StatisticsQuestion& statisticsquestion);
	
};