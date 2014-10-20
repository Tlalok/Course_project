#include "StatisticsAnswer.h"

StatisticsAnswer :: StatisticsAnswer(int id, int timeOfGivingAnswer)
{
	this->id = id;
	this->timesOfGivingAnswer = timeOfGivingAnswer;

}

StatisticsAnswer :: StatisticsAnswer()
{
	this->id = 0;
	this->timesOfGivingAnswer = 0;
}

int StatisticsAnswer :: getAnswerID()
{
	return this->id;
}

int StatisticsAnswer :: gettimesOfGivingAnswer()
{
	return this->timesOfGivingAnswer;
}