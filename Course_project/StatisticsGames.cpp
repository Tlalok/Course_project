#include "StatisticsGames.h"

Character StatisticsGames::getCharacter(uint n)
{
	return characters[n];
}

std::string StatisticsGames::getNameOfCharacter(uint id)
{
	for (uint i = 0; i < characters.size(); i++)
	{
		if(id == characters[i].getId())
			return characters[i].getName();
	}
	return 0;
}

uint StatisticsGames::getNumberGames()
{
	return numberGames;
}

uint StatisticsGames::getNumberOfCharacters()
{
	return characters.size();
}

uint StatisticsGames::getTimesCharacterPicked(uint id)
{
	for (uint i = 0; i < characters.size(); i++)
	{
		if(id == characters[i].getId())
			return characters[i].getTimesPicked();
	}
	return 0;
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

double StatisticsGames::getPAi(uint idCharacter)
{
	return this->getTimesCharacterPicked(idCharacter) / this->getNumberGames();
}

bool StatisticsGames::charactersIsEmpty()
{
	return characters.isEmpty();
}

void StatisticsGames::checkCharactersStatistics(Vector<Question>& questions, Vector<Answer>& answers)
{
	for(uint i = 0; i < characters.size(); i++)
	{
		if(characters[i].getNumberOfQuestions() < questions.size())
		{
			characters[i].checkCharacterStatistics(questions, answers);
		}
	}
}

std::fstream& operator>>(std::fstream& file, StatisticsGames& statisticsGames)
{
	uint numberOfCharacters;
	Character tempCharacter;
	file.read((char *) &numberOfCharacters, sizeof(uint));
	for(uint i = 0; i < numberOfCharacters; i++)
	{
		file >> tempCharacter;
		statisticsGames.characters.push_back(tempCharacter);
	}
    return file;
}

std::fstream& operator<<(std::fstream& file, StatisticsGames& statisticsGames)
{
	uint numberOfCharacters;
	Character tempCharacter;
	numberOfCharacters = statisticsGames.getNumberOfCharacters();
	file.write((char *) &numberOfCharacters, sizeof(uint));
	for(uint i = 0; i < numberOfCharacters; i++)
	{
		tempCharacter = statisticsGames.characters[i];
		file << tempCharacter;
        // file << statisticsGames.characters[i]
	}
    return file;
}

void StatisticsGames::addQuestion(StatisticsQuestion& toAdd)
{
	for(uint i = 0; i < characters.size(); i++)
	{
		characters[i].addQuestion(toAdd);
	}
}

bool StatisticsGames::isCharacterExist(std::string name)
{
	for(uint i = 0; i < characters.size(); i++)
	{
		if(name == characters[i].getName())
		{
			return true;
		}
	}
	return false;
}

void StatisticsGames::addAnswer(StatisticsAnswer& toAdd)
{
	for(uint i = 0; i < characters.size(); i++)
	{
		characters[i].addAnswer(toAdd);
	}
}

void StatisticsGames::addCharacter(Character& toAdd)
{
	characters.push_back(toAdd);
}