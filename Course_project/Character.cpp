#include "Character.h"

class noQuestion{};
class noAnswer{};

Character::Character()
{
	id = 0;
	name = "";
	timesPicked = 0;
}

Character::Character(Character& toCopy)
{
	this->id = toCopy.id;
	this->name = toCopy.name;
	this->timesPicked = toCopy.timesPicked;
	this->statisticsQuestions = toCopy.statisticsQuestions;
}

Character::Character(uint id, std::string name, uint timesPicked)
{
	this->id = id;
	this->name = name;
	this->timesPicked = timesPicked;
}

Character& Character::operator=(Character& toCopy)
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
		if(idQuestion == statisticsQuestions[i].getQuestionID())
			return statisticsQuestions[i];
	}
	throw noQuestion();
}

uint Character::getTimesOfGivingAnswer(uint idQuestion, uint idAnswer)
{
    for(uint i = 0; i < statisticsQuestions.size(); i++)
	{
		if(idQuestion == statisticsQuestions[i].getQuestionID())
			return statisticsQuestions[i].getTimesOfGivingAnswer(idAnswer);
	}
	throw noQuestion();
}

uint Character::getTimesOfAskingQuestion(uint idQuestion)
{
    for(uint i = 0; i < statisticsQuestions.size(); i++)
	{
		if(idQuestion == statisticsQuestions[i].getQuestionID())
			return statisticsQuestions[i].getTimesOfAskingQuestion();
	}
	throw noQuestion();
}

std::istream& operator>>(std::istream& file, Character& character)
{
	uint numberOfQuestions, nameLength;
	StatisticsQuestion tempStatisticsQuestion;
	file.read((char *) &character.id, sizeof(uint));
	file.read((char *) &character.timesPicked, sizeof(uint));
	file.read((char *) &nameLength, sizeof(uint));
    char *buf = new char[nameLength];
	file.read(buf, nameLength);
	character.name = buf;
	file.read((char *) &numberOfQuestions, sizeof(uint));
	for(uint i = 0; i < numberOfQuestions; i++)
	{
		file >> tempStatisticsQuestion;
		character.statisticsQuestions.push_back(tempStatisticsQuestion);
	}
    delete[] buf;
    return file;
}


std::ostream& operator<<(std::ostream& file, Character& character)
{
	uint numberOfQuestions, nameLength;
	nameLength = character.name.length() + 1;
    char *buf = new char[nameLength];
	file.write((char *) &character.id, sizeof(uint));
	file.write((char *) &character.timesPicked, sizeof(uint));
	file.write((char *) &nameLength, sizeof(uint));
	file.write(character.name.c_str(), nameLength);
	numberOfQuestions = character.getNumberOfQuestions();
	file.write((char *) &numberOfQuestions, sizeof(uint));
	for(uint i = 0; i < numberOfQuestions; i++)
	{
        file << character.statisticsQuestions[i];
	}
    delete[] buf;
    return file;
}

void Character::addQuestion(StatisticsQuestion& toAdd)
{
	statisticsQuestions.push_back(toAdd);
}

void Character::addAnswer(StatisticsAnswer& toAdd)
{
	for(uint i = 0; i < statisticsQuestions.size(); i++)
	{
		statisticsQuestions[i].addAnswer(toAdd);
		++statisticsQuestions[i];
	}
}