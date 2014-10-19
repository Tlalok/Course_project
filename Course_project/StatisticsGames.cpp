#include "StatisticsGames.h"

Character StatisticsGames::getCharacter(int n)
{
	return characters[n];
}

std::string StatisticsGames::getNameOfCharacter(int n)
{
	return characters[n].getName();
}

int StatisticsGames::getNumberGames()
{
	return numberGames;
}

int StatisticsGames::getNumberOfCharacters()
{
	return characters.size();
}

int StatisticsGames::getTimesCharacterPicked(int n)
{
	return characters[n].getTimesPicked();
}