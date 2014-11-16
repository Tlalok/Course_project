#include "Game.h"


class incorrectID{};

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

    for (uint i = 0; i < statisticsGames.getNumberOfCharacters(); i++)
    {
        uint idCharacter = statisticsGames.getCharacter(i).getId();
        currentProbability[idCharacter] = statisticsGames.getPAi(idCharacter);
        //std:: cout << "current probability[" << idCharacter << "] = " << currentProbability[idCharacter] << std::endl;
    }
    
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
	//for(uint i = 1; i <= statisticsGames.getNumberOfCharacters(); i++)
    for(uint i = 0; i < statisticsGames.getNumberOfCharacters(); i++)  // по идее должно быть так
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
        //result += statisticsGames.getPBjAi(i, idQuestion, idAnswer) * currentProbability[idCharacter];
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
        double CP = currentProbability[idCharacter];
        double PBjAi = statisticsGames.getPBjAi(idCharacter, idQuestion, idAnswer);
        //double PBjAi = statisticsGames.getPBjAi(i, idQuestion, idAnswer);
        double PBi = statisticsGames.getPBi(idQuestion, idAnswer);
        double probability = CP * PBjAi / PBi;
        /*
        double probability = currentProbability[idCharacter] * 
                             statisticsGames.getPBjAi(idCharacter, idQuestion, idAnswer) / 
                             statisticsGames.getPBi(idQuestion, idAnswer);
        */
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

uint Game::getIdNextQuestion()
{
    Vector<std::pair<uint, double>> H;
    uint i = 0;
    for (uint i = 0; i < questions.size(); i++)
    {
        uint idQuestion = questions[i].getId();
        if (questionWasAsked(idQuestion))
            continue;
        double currnetH = 0;
        for (uint j = 0; j < answers.size(); j++)
        {
            uint idAnswer = answers[j].getId();
            currnetH += getHPAiBQjAns(idQuestion, idAnswer) * getPQjAns(idQuestion, idAnswer);
        }
        std::pair<uint, double> HQuestion(idQuestion, currnetH);
        H.push_back(HQuestion);
    }
    if (H.size() == 0)
        return 0;    // заменить на исключение или иземнить тип возвращаемого значения
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

double Game::getPAiB(Character& character)
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
	//Character toAdd(statisticsGames.getNumberOfCharacters() + 1, name, 1);
    //Character toAdd(statisticsGames.getNumberOfCharacters() + 1, name, questions.size() * answers.size());
    Character toAdd(statisticsGames.getNumberOfCharacters() + 1, name, answers.size()); // вроде так
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
        for (uint j = 0; j < questions.size(); j++)
        {
            StatisticsQuestion statisticsQuestion = character.getStatisticsQuestion(questions[j].getId());
            std::cout << "   id:          " << questions[j].getId() << std::endl
                      << "   name:        " << questions[j].getText() << std::endl
                      << "   TimesAsking: " << statisticsQuestion.getTimesOfAskingQuestion() << std::endl
                      << "\n      StatisticsAnswer:\n";
            for (uint k = 0; k < answers.size(); k++)
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

void Game::giveAnswer(uint idQuestion, uint idAnswer)
{
	if((idQuestion <= questions.size()) && (idAnswer <= answers.size()))
	{
		std::pair<uint, uint> toAdd(idQuestion, idAnswer);
		currentAnswers.push_back(toAdd);
        for (uint i = 0; i < statisticsGames.getNumberOfCharacters(); i++)
        {
            uint idCharacter = statisticsGames.getCharacter(i).getId();
            double PBjAi = statisticsGames.getPBjAi(idCharacter, idQuestion, idAnswer);
            double PBi = statisticsGames.getPBi(idQuestion, idAnswer);
            currentProbability[idCharacter] *= PBjAi / PBi;
            std:: cout << "current probability[" << idCharacter << "] = " << currentProbability[idCharacter] << std::endl;
        }
        uint i = 0;
	}
	else throw incorrectID();
}

void Game::printProbability()
{
	Vector <Character>& characters = statisticsGames.getCharacters();
	for(uint i = 0; i < this->currentProbability.size(); i++)
	{
		std::cout<<characters[i]<<"->"<<this->currentProbability[characters[i].getId()]<<std::endl;
	}
}

Vector <Answer>& Game::getAnswers()
{
	return answers;
}

std::string Game::getQuestionText(uint idQuestion)
{
	for(uint i = 0; i < questions.size(); i++)
	{
		if(idQuestion == questions[i].getId())
			return questions[i].getText();
	}
	throw incorrectID();
}

uint  Game::LeadingCharacter()
{
    return 0; // заглушка
}