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

unsigned int StatisticsGames::getTimesOfAskingQuestion(unsigned int idQuestion)
{
    unsigned int result = 0;
    for (int i = 0; i < characters.size(); i++)
        result += characters[i].getTimesOfAskingQuestion(idQuestion);
    return result;
}

unsigned int StatisticsGames::getTimesOfGivingAnswer(unsigned int idQuestion, unsigned int idAnswer)
{
    unsigned int result = 0;
    for (int i = 0; i < characters.size(); i++)
        result += characters[i].getTimesOfGivingAnswer(idQuestion, idAnswer);
    return result;
    
}

double StatisticsGames::getPBi(unsigned int idQuestion, unsigned int idAnswer)
{
    return (double)getTimesOfGivingAnswer(idQuestion, idAnswer) / (double)getTimesOfAskingQuestion(idQuestion);
}