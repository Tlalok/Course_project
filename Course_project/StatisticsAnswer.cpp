#include "StatisticsAnswer.h"

StatisticsAnswer :: StatisticsAnswer(uint id, uint timesOfGivingAnswer)
{
	this->id = id;
	this->timesOfGivingAnswer = timesOfGivingAnswer;
}

StatisticsAnswer :: StatisticsAnswer()
{
	this->id = 0;
	this->timesOfGivingAnswer = 1;
}

StatisticsAnswer :: StatisticsAnswer(const StatisticsAnswer &statisticsAnswer)
{
    this->id = statisticsAnswer.id;
    this->timesOfGivingAnswer = statisticsAnswer.timesOfGivingAnswer;
}

uint StatisticsAnswer :: getAnswerID()
{
	return this->id;
}

uint StatisticsAnswer :: getTimesOfGivingAnswer()
{
	return this->timesOfGivingAnswer;
}

void StatisticsAnswer::setId(uint id)
{
	this->id = id;
}

std::istream& operator>>(std::istream& file, StatisticsAnswer& statisticsAnswer)
{
	file.read((char *) &statisticsAnswer.id, sizeof(uint));
	file.read((char *) &statisticsAnswer.timesOfGivingAnswer, sizeof(uint));
    return file;
}

std::ostream& operator<<(std::ostream& file, StatisticsAnswer& statisticsAnswer)
{
	file.write((char *) &statisticsAnswer.id, sizeof(uint));
	file.write((char *) &statisticsAnswer.timesOfGivingAnswer, sizeof(uint));
    return file;
}

StatisticsAnswer& StatisticsAnswer::operator++()
{
	timesOfGivingAnswer++;
	return *this;
}

StatisticsAnswer& StatisticsAnswer::operator=(StatisticsAnswer &toCopy)
{
    this->id = toCopy.id;
    this->timesOfGivingAnswer = toCopy.timesOfGivingAnswer;
    return *this;
}
