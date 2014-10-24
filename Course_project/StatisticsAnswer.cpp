#include "StatisticsAnswer.h"

StatisticsAnswer :: StatisticsAnswer(uint id, uint timeOfGivingAnswer)
{
	this->id = id;
	this->timesOfGivingAnswer = timeOfGivingAnswer;

}

StatisticsAnswer :: StatisticsAnswer()
{
	this->id = 0;
	this->timesOfGivingAnswer = 0;
}

uint StatisticsAnswer :: getAnswerID()
{
	return this->id;
}

uint StatisticsAnswer :: getTimesOfGivingAnswer()
{
	return this->timesOfGivingAnswer;
}