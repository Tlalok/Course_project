#include "StatisticsQuestion.h"

class noAnswer{};

StatisticsQuestion :: StatisticsQuestion()
{
	this->id = 0;
	this->timesOfAskingQuestion = 0;
}

StatisticsQuestion :: StatisticsQuestion(uint id, uint timesOfAskingQuestion, Vector<StatisticsAnswer> statisticsAnswers)
{
/*	this->id = id;
	this->timesOfAskingQuestion = timesOfAskingQuestion;
	std :: vector<StatisticsAnswer> :: iterator beginGiven = statisticsAnswers.begin();
	std :: vector<StatisticsAnswer> :: iterator begin = this->statisticsAnswers.begin();
	for(;beginGiven < statisticsAnswers.end(); beginGiven++, begin++)
		*begin = *beginGiven;
		*/
}

uint StatisticsQuestion :: getQuestionID()
{
	return this->id;
}

uint StatisticsQuestion :: getTimesOfAskingQuestion()
{
	return this->timesOfAskingQuestion;
}

StatisticsAnswer StatisticsQuestion :: getAnswerStatistic(uint idAnswer)
{
	for(uint i = 0; i < statisticsAnswers.size(); i++)
	{
		if(id == statisticsAnswers[i].getAnswerID())
			return statisticsAnswers[i];
	}
	throw noAnswer();
}

uint StatisticsQuestion::getTimesOfGivingAnswer(uint idAnswer)
{
    for(uint i = 0; i < statisticsAnswers.size(); i++)
	{
		if(id == statisticsAnswers[i].getAnswerID())
			return statisticsAnswers[i].getTimesOfGivingAnswer();
	}
	throw noAnswer();
}

std::fstream& operator>>(std::fstream& file, StatisticsQuestion& statisticsquestion)
{
	uint numberOfAnswers;
	StatisticsAnswer tempStatisticsAnswers;
	file.read((char*)&statisticsquestion.id, sizeof(uint));
	file.read((char*)&statisticsquestion.timesOfAskingQuestion, sizeof(uint));
	file.read((char*)&numberOfAnswers, sizeof(uint));
	for(uint i = 0; i < numberOfAnswers; i++)
	{
		file>>tempStatisticsAnswers;
		statisticsquestion.statisticsAnswers.push_back(tempStatisticsAnswers);
	}
    return file;
}

std::fstream& operator<<(std::fstream& file, StatisticsQuestion& statisticsquestion)
{
	uint numberOfAnswers;
	StatisticsAnswer tempStatisticsAnswers;
	file.write((char*)&statisticsquestion.id, sizeof(uint));
	file.write((char*)&statisticsquestion.timesOfAskingQuestion, sizeof(uint));
	numberOfAnswers = statisticsquestion.statisticsAnswers.size();
	file.write((char*)&numberOfAnswers, sizeof(uint));
	for(uint i = 0; i < numberOfAnswers; i++)
	{
		tempStatisticsAnswers = statisticsquestion.statisticsAnswers[i];
		file<<tempStatisticsAnswers;
	}
    return file;
}

void StatisticsQuestion::addAnswer(StatisticsAnswer toAdd)
{
	statisticsAnswers.push_back(toAdd);
}

void StatisticsQuestion::setId(uint id)
{
	this->id = id;
}

