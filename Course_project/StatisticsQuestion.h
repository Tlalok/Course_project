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
	StatisticsQuestion& operator++();
	void setId(uint id);
	StatisticsQuestion();
	StatisticsQuestion(Vector<Answer>& answers);
	StatisticsQuestion(uint, uint, Vector<StatisticsAnswer>);
	uint getQuestionID();
	uint getTimesOfAskingQuestion();
	StatisticsAnswer getAnswerStatistic(uint);
    uint getTimesOfGivingAnswer(uint idAnswer);
	void addAnswer(StatisticsAnswer toAdd);
	friend std::fstream& operator>>(std::fstream& file, StatisticsQuestion& statisticsquestion);
	friend std::fstream& operator<<(std::fstream& file, StatisticsQuestion& statisticsquestion);
	
};