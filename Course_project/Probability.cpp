#include "Probability.h"
#include "StatisticsGames.h"

Probability::Probability(Character character, uint numberGames)
{
	characterId = character.getId();
	PAi = character.getTimesPicked() / numberGames;
}

void Probability::setFullProbability(double fullPr)
{
	fullProbability = fullPr;
}
