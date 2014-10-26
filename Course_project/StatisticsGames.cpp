#include "StatisticsGames.h"

Character StatisticsGames::getCharacter(uint n)
{
	return characters[n];
}

std::string StatisticsGames::getNameOfCharacter(uint n)
{
	return characters[n].getName();
}

uint StatisticsGames::getNumberGames()
{
	return numberGames;
}

uint StatisticsGames::getNumberOfCharacters()
{
	return characters.size();
}

uint StatisticsGames::getTimesCharacterPicked(uint n)
{
	return characters[n].getTimesPicked();
}

uint StatisticsGames::getTimesOfAskingQuestion(uint idQuestion)
{
    uint result = 0;
    for (uint i = 0; i < characters.size(); i++)
        result += characters[i].getTimesOfAskingQuestion(idQuestion);
    return result;
}

uint StatisticsGames::getTimesOfGivingAnswer(uint idQuestion, uint idAnswer)
{
    uint result = 0;
    for (uint i = 0; i < characters.size(); i++)
        result += characters[i].getTimesOfGivingAnswer(idQuestion, idAnswer);
    return result;
    
}

double StatisticsGames::getPBi(uint idQuestion, uint idAnswer)
{
    return (double)getTimesOfGivingAnswer(idQuestion, idAnswer) / (double)getTimesOfAskingQuestion(idQuestion);
}


double StatisticsGames::getPBjAi(uint idCharater, uint idQuestion, uint idAnswer)
{
    return characters[idCharater].getTimesOfGivingAnswer(idQuestion, idAnswer) / characters[idAnswer].getTimesOfAskingQuestion(idQuestion);
}