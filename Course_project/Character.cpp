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

uint Character::getTimesOfGivingAnswer(uint idQuestion, uint idAnswer)
{
    return statisticsQuestions[idQuestion].getTimesOfGivingAnswer(idAnswer);
}