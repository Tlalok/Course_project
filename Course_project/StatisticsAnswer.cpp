#include "StatisticsAnswer.h"

StatisticsAnswer :: StatisticsAnswer(uint id, uint timesOfGivingAnswer)
{
	this->id = id;
	this->timesOfGivingAnswer = timesOfGivingAnswer;

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

std::fstream& operator>>(std::fstream& file, StatisticsAnswer& statisticsAnswer)
{
	file.read((char*)&statisticsAnswer.id, sizeof(uint));
	file.read((char*)&statisticsAnswer.timesOfGivingAnswer, sizeof(uint));
    return file;
}

std::fstream& operator<<(std::fstream& file, StatisticsAnswer& statisticsAnswer)
{
	file.write((char*)&statisticsAnswer.id, sizeof(uint));
	file.write((char*)&statisticsAnswer.timesOfGivingAnswer, sizeof(uint));
    return file;
}