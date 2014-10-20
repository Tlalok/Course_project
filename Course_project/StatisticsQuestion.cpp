#include "StatisticsQuestion.h"
#include <vector>

StatisticsQuestion :: StatisticsQuestion()
{
	this->id = 0;
	this->timesOfAskingQuestion = 0;
}

StatisticsQuestion :: StatisticsQuestion(int id, int timesOfAskingQuestion, std::vector<StatisticsAnswer> statisticsAnswers)
{
	this->id = id;
	this->timesOfAskingQuestion = timesOfAskingQuestion;
	std :: vector<StatisticsAnswer> :: iterator beginGiven = statisticsAnswers.begin();
	std :: vector<StatisticsAnswer> :: iterator begin = this->statisticsAnswers.begin();
	for(;beginGiven < statisticsAnswers.end(); beginGiven++, begin++)
		begin = beginGiven;
}

int StatisticsQuestion :: getQuestionID()
{
	return this->id;
}

int StatisticsQuestion :: gettimesOfAskingQuestion()
{
	return this->timesOfAskingQuestion;
}

StatisticsAnswer StatisticsQuestion :: getAnswerStatistic(int number)
{
	return this->statisticsAnswers[number];
}