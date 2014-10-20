#include "StatisticsAnswer.h"

StatisticsAnswer :: StatisticsAnswer(int id, int amountOfGivingAnswer)
{
	this->id = id;
	this->timesOfGivingAnswer = amountOfGivingAnswer;

}

StatisticsAnswer :: StatisticsAnswer()
{
	this->id = 0;
	this->timesOfGivingAnswer = 0;