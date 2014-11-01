#include "Character.h"

class noQuestion{};
class noAnswer{};

Character::Character()
{
	id = 0;
	name = "";
	timesPicked = 0;
}

Character::Character(const Character& toCopy)
{
	this->id = toCopy.id;
	this->name = toCopy.name;
	this->timesPicked = toCopy.timesPicked;
	this->statisticsQuestions = toCopy.statisticsQuestions;
}

Character& Character::operator=(Character toCopy)
{
	this->id = toCopy.id;
	this->name = toCopy.name;
	this->timesPicked = toCopy.timesPicked;
	this->statisticsQuestions = toCopy.statisticsQuestions;
	return *this;
}

uint Character::getId()
{
	return id;
}

std::string Character::getName()
{
	return name;
}

uint Character::getTimesPicked()
{
	return timesPicked;
}

uint Character::getNumberOfQuestions()
{
	return statisticsQuestions.size();
}

void Character::checkCharacterStatistics(Vector<Question>& questions, Vector<Answer>& answers)
{
	for(uint i = 0; i < questions.size(); i++)
	{
		uint idQuestionToCheck = questions[i].getId();
		try
		{
			getStatisticsQuestion(idQuestionToCheck);
		}
		catch(noQuestion)
		{
			StatisticsQuestion temp;
			temp.setId(questions[i].getId());
			statisticsQuestions.push_back(temp);
		}
	}
}

StatisticsQuestion& Character::getStatisticsQuestion(uint idQuestion)
{
	for(uint i = 0; i < statisticsQuestions.size(); i++)
	{
		if(id == statisticsQuestions[i].getQuestionID())
			return statisticsQuestions[i];
	}
	throw noQuestion();
}

uint Character::getTimesOfGivingAnswer(uint idQuestion, uint idAnswer)
{
    for(uint i = 0; i < statisticsQuestions.size(); i++)
	{
		if(id == statisticsQuestions[i].getQuestionID())
			return statisticsQuestions[i].getTimesOfGivingAnswer(idAnswer);
	}
	throw noQuestion();
}

uint Character::getTimesOfAskingQuestion(uint idQuestion)
{
    for(uint i = 0; i < statisticsQuestions.size(); i++)
	{
		if(id == statisticsQuestions[i].getQuestionID())
			return statisticsQuestions[i].getTimesOfAskingQuestion();
	}
	throw noQuestion();
}

std::fstream& operator>>(std::fstream& file, Character& character)
{
	char buf[100];
	uint numberOfQuestions, nameLength;
	StatisticsQuestion tempStatisticsQuestion;
	file.read((char*)&character.id, sizeof(uint));
	file.read((char*)&character.timesPicked, sizeof(uint));
	file.read((char*)&nameLength, sizeof(uint));
	file.read(buf, nameLength);
	character.name = buf;
	file.read((char*)&numberOfQuestions, sizeof(uint));
	for(uint i = 0; i < numberOfQuestions; i++)
	{
		file>>tempStatisticsQuestion;
		character.statisticsQuestions.push_back(tempStatisticsQuestion);
	}
    return file;
}


std::fstream& operator<<(std::fstream& file, Character& character)
{
	char buf[100];
	uint numberOfQuestions, nameLength;
	StatisticsQuestion tempStatisticsQuestion;
	nameLength = character.name.length();
	file.write((char*)&character.id, sizeof(uint));
	file.write((char*)&character.timesPicked, sizeof(uint));
	file.write((char*)&nameLength, sizeof(uint));
	file.write(buf, nameLength);
	numberOfQuestions = character.getNumberOfQuestions();
	file.write((char*)&numberOfQuestions, sizeof(uint));
	for(uint i = 0; i < numberOfQuestions; i++)
	{
		tempStatisticsQuestion = character.statisticsQuestions[i];
		file<<tempStatisticsQuestion;
	}
    return file;
}

void Character::addQuestion(StatisticsQuestion toAdd)
{
	statisticsQuestions.push_back(toAdd);
}