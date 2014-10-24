#include "StatisticsAnswer.h"

StatisticsAnswer :: StatisticsAnswer(unsigned int id, unsigned int timeOfGivingAnswer)
{
	this->id = id;
	this->timesOfGivingAnswer = timeOfGivingAnswer;

}

StatisticsAnswer :: StatisticsAnswer()
{
	this->id = 0;
	this->timesOfGivingAnswer = 0;
}

unsigned int StatisticsAnswer :: getAnswerID()
{
	return this->id;
}

unsigned int StatisticsAnswer :: getTimesOfGivingAnswer()
{
	return this->timesOfGivingAnswer;
}