#include "Game.h"

Game::Game()
{
	for(uint i = 0; i < statisticsGames.getNumberOfCharacters(); i++)
	{
		Probability temp(statisticsGames.getCharacter(i), statisticsGames.getNumberGames);
		currentProbability[statisticsGames.getNameOfCharacter(i)] = temp;
	}
}

void Game::calculate()
{
	for(uint i = 0; i < statisticsGames.getNumberOfCharacters(); i++)
	{

	}
}