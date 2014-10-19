#include "Game.h"

Game::Game()
{
	for(int i = 0; i < statisticsGames.getNumberOfCharacters(); i++)
	{
		Probability temp(statisticsGames.getCharacter(i), statisticsGames.getNumberGames);
		currentProbability[statisticsGames.getNameOfCharacter(i)] = temp;
	}
}

void Game::calculate()
{
	for(int i = 0; i < statisticsGames.getNumberOfCharacters(); i++)
	{

	}
}