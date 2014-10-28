#include "Character.h"

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
    return statisticsQuestions[idQuestion].getTimesOfGivingAnswer(idAnswer);
}

std::fstream& operator>>(std::fstream& file, Character& character)
{
	char buf[100];
	uint numberOfQuestions;
	StatisticsQuestion tempStatisticsQuestion;
	file.read(buf, character.NAME_SIZE);
	character.name = buf;
	file.read((char*)&numberOfQuestions, sizeof(uint));
	for(uint i = 0; i < numberOfQuestions; i++)
	{
		file>>tempStatisticsQuestion;
	}
}


std::fstream& operator<<(std::fstream& file, Character& character)
{

}