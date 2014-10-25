#include "StatisticsQuestion.h"
#include <vector>

StatisticsQuestion :: StatisticsQuestion()
{
	this->id = 0;
	this->timesOfAskingQuestion = 0;
}

StatisticsQuestion :: StatisticsQuestion(uint id, uint timesOfAskingQuestion, std::vector<StatisticsAnswer> statisticsAnswers)
{
	this->id = id;
	this->timesOfAskingQuestion = timesOfAskingQuestion;
	std :: vector<StatisticsAnswer> :: iterator beginGiven = statisticsAnswers.begin();
	std :: vector<StatisticsAnswer> :: iterator begin = this->statisticsAnswers.begin();
	for(;beginGiven < statisticsAnswers.end(); beginGiven++, begin++)
		*begin = *beginGiven;
}

uint StatisticsQuestion :: getQuestionID()
{
	return this->id;
}

uint StatisticsQuestion :: getTimesOfAskingQuestion()
{
	return this->timesOfAskingQuestion;
}

StatisticsAnswer StatisticsQuestion :: getAnswerStatistic(uint number)
{
	return this->statisticsAnswers[number];
}

uint StatisticsQuestion::getTimesOfGivingAnswer(uint idAnswer)
{
    return statisticsAnswers[idAnswer].getTimesOfGivingAnswer();
}