#include "Character.h"

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

uint Character::getTimesOfGivingAnswer(uint idQuestion, uint idAnswer)
{
    // переписать т.к. index != id
    return statisticsQuestions[idQuestion].getTimesOfGivingAnswer(idAnswer);
}

uint Character::getTimesOfAskingQuestion(uint idQuestion)
{
    // переписать т.к. index != id
    return statisticsQuestions[idQuestion].getTimesOfAskingQuestion();
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