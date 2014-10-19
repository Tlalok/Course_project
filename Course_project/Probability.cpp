#include "Probability.h"
#include "StatisticsGames.h"

Probability::Probability(Character character, int numberGames)
{
	characterId = character.getId();
	PAi = character.getTimesPicked / numberGames;
}

void Probability::setFullProbability(double fullPr)
{
	fullProbability = fullPr;
}
