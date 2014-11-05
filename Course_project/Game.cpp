#include "Game.h"

double log(double a, double b)
{
    return log(b) / log(a);
}

void Game::checkCharactersStatistics()
{
	if(!statisticsGames.charactersIsEmpty())
	{
        if(!questions.empty())
			statisticsGames.checkCharactersStatistics(questions, answers);
	}
}

uint Game::read()
{
    
	std::ifstream file("questions.txt");
	if(file.is_open())
	{
		Question question;
        while(file >> question)
		{
			questions.push_back(question);
		}
		file.close();
	}
	else return 0;
    
	file.open("answers.txt");
	if(file.is_open())
	{
		Answer answer;
        while(file >> answer)
		{
			answers.push_back(answer);
		}
		file.close();
	}
	else return 0;
    
    file.open("statistic.txt");
    if(file.is_open())
	{
        file >> statisticsGames;
		file.close();
	}
	else return 0;
	return 1;
}

uint Game::write()
{
	std::ofstream file("questions.txt");
	if(file.is_open())
	{
		Question question;
		for(uint i = 0; i < questions.size(); i++)
		{
			file << questions[i];
		}
		file.close();
	}
	else return 0;
    
	file.open("answers.txt");
	if(file.is_open())
	{
		Answer answer;
		for(uint i = 0; i < answers.size(); i++)
		{
			file << answers[i];
		}
		file.close();
	}
	else return 0;
    
	file.open("statistic.txt");
	if(file.is_open())
	{
		file << statisticsGames;
		file.close();
	}
	else return 0;
    
	return 1;
}

void Game::calculate()
{
	for(uint i = 0; i < statisticsGames.getNumberOfCharacters(); i++)
	{
		currentProbability[statisticsGames.getCharacter(i).getId()] = getPAiB(statisticsGames.getCharacter(i));
	}
}

double Game::getPQjAns(uint idQuestion, uint idAnswer)
{
    double result = 0;
    for (uint i = 0; i < statisticsGames.getNumberOfCharacters(); i++)
    {
        uint idCharacter = statisticsGames.getCharacter(i).getId();
        result += statisticsGames.getPBjAi(idCharacter, idQuestion, idAnswer) * currentProbability[idCharacter];
    }
    return result;
}

double Game::getHPAiBQjAns(uint idQuestion, uint idAnswer)
{
    double result =  0;
    for (uint i = 0; i < statisticsGames.getNumberOfCharacters(); i++)
    {
        uint idCharacter = statisticsGames.getCharacter(i).getId();
        double probability = currentProbability[idCharacter] * 
                             statisticsGames.getPBjAi(idCharacter, idQuestion, idAnswer) / 
                             statisticsGames.getPBi(idQuestion, idAnswer);
        result -= probability * log(2, probability);
        //result += probability * log(2, probability);
    }
    return result;
}

bool Game::questionWasAsked(uint idQuestion)
{
    for (uint i = 0; i < currentAnswers.size(); i++)
        if (currentAnswers[i].first == idQuestion)
            return true;
    return false;
}

uint Game::gedIdNextQuestion()
{
    Vector<std::pair<uint, double>> H;
    uint i = 0;
    for (uint i = 0; i < questions.size(); i++)
    {
        uint idQuestion = questions[i].getId();
        if (questionWasAsked(idQuestion))
            continue;
        double currnetH;
        for (uint j = 0; j < answers.size(); j++)
        {
            uint idAnswer = answers[j].getId();
            currnetH += getHPAiBQjAns(idQuestion, idAnswer) * getPQjAns(idQuestion, idAnswer);
        }
        std::pair<uint, double> HQuestion(idQuestion, currnetH);
        H.push_back(HQuestion);
    }
    if (H.size() == 0)
        return -1;    // заменить на исключение или иземнить тип возвращаемого значения
    uint indexMin = 0;
    for (uint i = 1; i < H.size(); i++)
        if (H[indexMin].second > H[i].second)
            indexMin = i;
    return H[indexMin].first;
}

double Game::getPBAi(Character& character)
{
	double result = 0;
	uint idCharacter = character.getId();
	for(uint i = 0; i < currentAnswers.size(); i++)
		result *= statisticsGames.getPBjAi(idCharacter, currentAnswers[i].first, currentAnswers[i].second);
	return result;
}

double Game::getPAiB(Character character)
{
	double result = 0;
	double PB = 1;
	for(uint i = 0; i < questions.size(); i++)
		PB *= statisticsGames.getPBi(currentAnswers[i].first, currentAnswers[i].second);
	result = getPBAi(character) * statisticsGames.getPAi(character.getId()) / PB;
    return result;
}

void Game::addQuestion(std::string text)
{
	Question toAdd;
	toAdd.setId(questions.size() + 1);
	toAdd.setText(text);
	questions.push_back(toAdd);
	StatisticsQuestion statisticsQToAdd(answers);
	statisticsQToAdd.setId(toAdd.getId());
	statisticsGames.addQuestion(statisticsQToAdd);
}

void Game::addAnswer(std::string text)
{
	Answer toAdd;
	toAdd.setId(answers.size() + 1);
	toAdd.setText(text);
	answers.push_back(toAdd);
	StatisticsAnswer toAddAStatistic(toAdd.getId(), 1);
	statisticsGames.addAnswer(toAddAStatistic);
}

bool Game::isAnswerExist(std::string text)
{
	for(uint i = 0; i < answers.size(); i++)
	{
		if(text == answers[i].getText())
		{
			return true;
		}
	}
	return false;
}

bool Game::isQuestionExist(std::string text)
{
	for(uint i = 0; i < questions.size(); i++)
	{
		if(text == questions[i].getText())
		{
			return true;
		}
	}
	return false;
}

bool Game::isCharacterExist(std::string name)
{
	return statisticsGames.isCharacterExist(name);
}

void Game::addCharacter(std::string name)
{
	Character toAdd(statisticsGames.getNumberOfCharacters() + 1, name, 1);
	StatisticsQuestion toAddQStatistics(answers);
	for(uint i = 0; i < questions.size(); i++)
	{
		toAddQStatistics.setId(questions[i].getId());
		for(uint j = 0; j < currentAnswers.size(); j++)
		{
			if(currentAnswers[j].first == toAddQStatistics.getQuestionID())
			{
				++toAddQStatistics;
				++toAddQStatistics[currentAnswers[j].second];
			}
		}
		toAdd.addQuestion(toAddQStatistics);
	}
	statisticsGames.addCharacter(toAdd);
}

void Game::printStatistics()
{
    std::cout << "\nQuestions:\n" << "===========================\n";
    for (uint i = 0; i < questions.size(); i++)
        std::cout << "id:   " << questions[i].getId() << std::endl
                  << "text: " << questions[i].getText() << std::endl
                  << "--------------------------------\n";
    std::cout << "\nAnswers:\n" << "===========================\n";
    for (uint i = 0; i < answers.size(); i++)
        std::cout << "id:   " << answers[i].getId() << std::endl
                  << "text: " << answers[i].getText() << std::endl
                  << "--------------------------------\n";
    std::cout << "\nCharacters:\n" << "===========================\n";
    for (uint i = 0; i < statisticsGames.getNumberOfCharacters(); i++)
    {
        Character character = statisticsGames.getCharacter(i);
        std::cout << "name:         " << character.getName() << std::endl
                  << "times picked: " << character.getTimesPicked() << std::endl
                  << "++++++++++++++++++++++++++++\n";
    
        std::cout << "\n   StatisticsQuestions:\n";
        for (int j = 0; j < questions.size(); j++)
        {
            StatisticsQuestion statisticsQuestion = character.getStatisticsQuestion(questions[j].getId());
            std::cout << "   id:          " << questions[j].getId() << std::endl
                      << "   name:        " << questions[j].getText() << std::endl
                      << "   TimesAsking: " << statisticsQuestion.getTimesOfAskingQuestion() << std::endl
                      << "\n      StatisticsAnswer:\n";
            for (int k = 0; k < answers.size(); k++)
            {
                StatisticsAnswer statisticsAnswer = statisticsQuestion.getAnswerStatistic(answers[k].getId());
                std::cout << "      id:          " << answers[k].getId() << std::endl
                          << "      name:        " << answers[k].getText() << std::endl
                          << "      TimesGiving: " << statisticsAnswer.getTimesOfGivingAnswer() << std::endl;

            }
            std::cout << std::endl;
        }

    }   
}