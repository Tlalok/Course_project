#include "Character.h"

int Character::getId()
{
	return id;
}

std::string Character::getName()
{
	return name;
}

int Character::getTimesPicked()
{
	return timesPicked;
}

unsigned int Character::getTimesOfGivingAnswer(unsigned int idQuestion, unsigned int idAnswer)
{
    return getTimesOfGivingAnswer(idQuestion, idAnswer);
}