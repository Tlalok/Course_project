#include "StatisticsQuestion.h"

class noAnswer{};

StatisticsQuestion :: StatisticsQuestion()
{
	this->id = 0;
	this->timesOfAskingQuestion = 0;
}

StatisticsQuestion::StatisticsQuestion(Vector<Answer>& answers)
{
	id = 0;
	timesOfAskingQuestion = answers.size();
	StatisticsAnswer toAdd;
	for(uint i = 0; i < answers.size(); i++)
	{
		toAdd.setId(answers[i].getId());
		statisticsAnswers.push_back(toAdd);
	}
}

StatisticsQuestion :: StatisticsQuestion(uint id, uint timesOfAskingQuestion, Vector<StatisticsAnswer> answers)
{
	this->id = id;
	this->timesOfAskingQuestion = timesOfAskingQuestion;
    for (uint i = 0; i < answers.size(); i++)
        this->statisticsAnswers.push_back(answers[i]);
		
}

StatisticsQuestion::StatisticsQuestion(StatisticsQuestion& toCopy)
{
	id = toCopy.id;
	timesOfAskingQuestion = toCopy.timesOfAskingQuestion;
	statisticsAnswers = toCopy.statisticsAnswers;
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
		if(idAnswer == statisticsAnswers[i].getAnswerID())
			return statisticsAnswers[i];
	}
	throw noAnswer();
}

uint StatisticsQuestion::getTimesOfGivingAnswer(uint idAnswer)
{
    for(uint i = 0; i < statisticsAnswers.size(); i++)
	{
		if(idAnswer == statisticsAnswers[i].getAnswerID())
			return statisticsAnswers[i].getTimesOfGivingAnswer();
	}
	throw noAnswer();
}

std::istream& operator>>(std::istream& file, StatisticsQuestion& statisticsQuestion)
{
	uint numberOfAnswers;
	file.read((char *) &statisticsQuestion.id, sizeof(uint));
	file.read((char *) &statisticsQuestion.timesOfAskingQuestion, sizeof(uint));
	file.read((char *) &numberOfAnswers, sizeof(uint));
	for(uint i = 0; i < numberOfAnswers; i++)
	{
        StatisticsAnswer tempStatisticsAnswers;
		file >> tempStatisticsAnswers;
		statisticsQuestion.statisticsAnswers.push_back(tempStatisticsAnswers);
	}
    return file;
}

std::ostream& operator<<(std::ostream& file, StatisticsQuestion& statisticsQuestion)
{
	uint numberOfAnswers;
	file.write((char *) &statisticsQuestion.id, sizeof(uint));
	file.write((char *) &statisticsQuestion.timesOfAskingQuestion, sizeof(uint));
	numberOfAnswers = statisticsQuestion.statisticsAnswers.size();
	file.write((char *) &numberOfAnswers, sizeof(uint));
	for(uint i = 0; i < numberOfAnswers; i++)
	{
        file << statisticsQuestion.statisticsAnswers[i];
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

StatisticsQuestion& StatisticsQuestion::operator++()
{
	this->timesOfAskingQuestion++;
	return *this;
}

StatisticsAnswer& StatisticsQuestion::operator[](uint answerId)
{
	for(uint i = 0; i < statisticsAnswers.size(); i++)
	{
		if(statisticsAnswers[i].getAnswerID() == answerId)
			return statisticsAnswers[i];
	}
	throw noAnswer();
}

StatisticsQuestion& StatisticsQuestion::operator=(StatisticsQuestion& toCopy)
{
	if(this != &toCopy)
	{
		id = toCopy.id;
		timesOfAskingQuestion = toCopy.timesOfAskingQuestion;
		statisticsAnswers = toCopy.statisticsAnswers;
	}
	return *this;
}


uint StatisticsQuestion::getNumberAnswers()
{
    return statisticsAnswers.size();
}
	