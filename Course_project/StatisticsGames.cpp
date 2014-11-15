#include "StatisticsGames.h"

class NoCharacter {};

StatisticsGames::StatisticsGames()
{
    numberGames = 0;
}
StatisticsGames::StatisticsGames(StatisticsGames &statisticsGames)
{
    this->numberGames = statisticsGames.numberGames;
    this->characters = statisticsGames.characters;
}

Character StatisticsGames::getCharacter(uint n)
{
	return characters[n];
}

Character StatisticsGames::getCharacterById(uint id)
{
    for (uint i = 0; i < characters.size(); i++)
        if (characters[i].getId() == id)
            return characters[i];
    throw new NoCharacter;
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
    uint timesOfGivingAnswer = getCharacterById(idCharater).getTimesOfGivingAnswer(idQuestion, idAnswer);
    uint timesOfAskingQuestion = getCharacterById(idCharater).getTimesOfAskingQuestion(idQuestion);
    return timesOfGivingAnswer / timesOfAskingQuestion;
    //return characters[idCharater].getTimesOfGivingAnswer(idQuestion, idAnswer) / characters[idAnswer].getTimesOfAskingQuestion(idQuestion);
}

double StatisticsGames::getPAi(uint idCharacter)
{
	return this->getTimesCharacterPicked(idCharacter) / this->getNumberGames();
}

bool StatisticsGames::charactersIsEmpty()
{
    return characters.empty();
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

std::istream& operator>>(std::istream& file, StatisticsGames& statisticsGames)
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

std::ostream& operator<<(std::ostream& file, StatisticsGames& statisticsGames)
{
	uint numberOfCharacters;
	numberOfCharacters = statisticsGames.getNumberOfCharacters();
	file.write((char *) &numberOfCharacters, sizeof(uint));
	for(uint i = 0; i < numberOfCharacters; i++)
	{
        file << statisticsGames.characters[i];
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

StatisticsGames& StatisticsGames::operator=(StatisticsGames toCopy)
{
    this->numberGames = toCopy.numberGames;
    this->characters = toCopy.characters;
    return *this;
}

Vector <Character> &StatisticsGames::getCharacters()
{
	return this->characters;
}