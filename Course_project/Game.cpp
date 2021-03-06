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
	std::ifstream file("questions.txt", std::ios::binary);
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
    
	file.open("answers.txt", std::ios::binary);
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
    
    file.open("statistic.txt", std::ios::binary);
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
    }
	initializeCharactersToIgnore();
	return 1;
}

uint Game::write()
{
	std::ofstream file("questions.txt", std::ios::binary);
	if(file.is_open())
	{
		file.clear();
		Question question;
		for(uint i = 0; i < questions.size(); i++)
		{
			file << questions[i];
		}
		file.close();
	}
	else return 0;
    
	file.open("answers.txt", std::ios::binary);
	if(file.is_open())
	{
		Answer answer;
		file.clear();
		for(uint i = 0; i < answers.size(); i++)
		{
			file << answers[i];
		}
		file.close();
	}
	else return 0;
    
	file.open("statistic.txt", std::ios::binary);
	if(file.is_open())
	{
		file.clear();
		file << statisticsGames;
		file.close();
	}
	else return 0;
    
	return 1;
}

void Game::calculate()
{
	//for(uint i = 1; i <= statisticsGames.getNumberOfCharacters(); i++)
    for(uint i = 0; i < statisticsGames.getNumberOfCharacters(); i++)  // �� ���� ������ ���� ���
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
        return 0;    // �������� �� ���������� ��� �������� ��� ������������� ��������
    uint indexMin = 0;
    for (uint i = 1; i < H.size(); i++)
        if (H[indexMin].second > H[i].second)
            indexMin = i;
    return H[indexMin].first;
}

double Game::getPBAi(Character& character)
{
	double result = 1;
	uint idCharacter = character.getId();
	for(uint i = 0; i < currentAnswers.size(); i++)
		result *= statisticsGames.getPBjAi(idCharacter, currentAnswers[i].first, currentAnswers[i].second);
	return result;
}

double Game::getPAiB(Character& character)
{
	double result = 0;
	double PB = 1;
	for(uint i = 0; i < currentAnswers.size(); i++)
		PB *= statisticsGames.getPBi(currentAnswers[i].first, currentAnswers[i].second);
	//result = getPBAi(character) * statisticsGames.getPAi(character.getId()) / PB; 
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
	return (bool)statisticsGames.isCharacterExist(name);
}

void Game::addCharacter(std::string name)
{
	//Character toAdd(statisticsGames.getNumberOfCharacters() + 1, name, 1);
    //Character toAdd(statisticsGames.getNumberOfCharacters() + 1, name, questions.size() * answers.size());
    //Character toAdd(statisticsGames.getNumberOfCharacters() + 1, name, answers.size()); // ����� ���
    // �������� �������� ���� �� ����� ��������
    if (statisticsGames.isCharacterExist(name))
    {
        uint idCharacter = statisticsGames.isCharacterExist(name);
        statisticsGames.characterGuessed(idCharacter, currentAnswers);
        return;
    }
    Character toAdd(statisticsGames.getNumberOfCharacters() + 1, name, answers.size() + 1); // ����� ���

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
	// std::cout<<toAdd.getName()<<"-"<<toAdd.getNumberOfQuestions()<<std::endl;
    // �������� ����������� �� ����
    if (currentAnswers.size() == 0)
        toAdd.decTimesPicked();
	statisticsGames.addCharacter(toAdd);
}

void Game::printStatistics()
{
	std::cout << "NumberGames: " << statisticsGames.getNumberGames() << std::endl << "===========================\n";
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
		calculate();
	}
	else throw incorrectID();
}

void Game::printProbability()
{
	Vector <Character>& characters = statisticsGames.getCharacters();
	for(uint i = 0; i < this->currentProbability.size(); i++)
	{
        std::cout << characters[i].getName() << " -> " << this->currentProbability[characters[i].getId()] << std::endl;
	}
}

void Game::printNumberQuestionsCharacters()
{
    Vector<Character> characters = statisticsGames.getCharacters();
    std::cout << "Number questions: " << std:: endl;
    for (uint i = 0; i < characters.size(); i++)
    {
        std::cout << characters[i].getId() << ". " << std::setw(15) << std::left << characters[i].getName() << " - " << characters[i].getNumberOfQuestions() << std::endl;
    }
}

Vector<Answer>& Game::getAnswers()
{
	return answers;
}

Vector<Question>& Game::getQuestions()
{
	return questions;
}

Vector<Character>& Game::getCharacters()
{
	return statisticsGames.getCharacters();
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

bool Game::canSupposeCharacter()
{
	Vector<Character> leaders = getLeadingCharacters(2);
	if(leaders.size() == 1)
		return true;
	if(!leaders.size())
		return false;
	return (currentProbability[leaders[1].getId()] / currentProbability[leaders[0].getId()]) <= 0.3;
}

void Game::incNumberGames()
{
	statisticsGames.incNumberGames();
}

void Game::characterGuessed(uint idCharacter)
{
	statisticsGames.characterGuessed(idCharacter, currentAnswers);
}

Vector<Character> Game::getLeadingCharacters(uint leadersNeeded)
{
	Vector<Character> leadingCharacters;
	Vector<uint> leadingIDs;
	uint idMax;
	bool notIgnoredCharacterExist = false;
	for(uint i = 0; i < statisticsGames.getNumberOfCharacters(); i++)
	{
		if(!charactersToIgnore[statisticsGames.getCharacter(i).getId()])
		{
			idMax = statisticsGames.getCharacter(i).getId();
			leadingIDs.push_back(idMax);
			notIgnoredCharacterExist = true;
			break;
		}
	}
	if(notIgnoredCharacterExist)
	{
		for(uint i = 1; i <= currentProbability.size(); i++)
		{
			if(currentProbability[idMax] < currentProbability[i] && idMax != i && !charactersToIgnore[i])
			{
				idMax = i;
				leadingIDs[0] = i;
			}
		}
		for(uint i = 1; i < 5; i++)
		{
			for(uint k = 1; k <= currentProbability.size(); k++)
			{
				if(!leadingIDs.inVector(k) && !charactersToIgnore[k])
				{
					idMax = k;
					leadingIDs.push_back(idMax);
					break;
				}
			}
			for(uint j = 1; j <= currentProbability.size(); j++)
			{
				if(currentProbability[j] >= currentProbability[idMax] 
					&& !leadingIDs.inVector(j) 
					&& currentProbability[j] <= currentProbability[leadingIDs[leadingIDs.size() - 2]] 
					&& !charactersToIgnore[j])
				{
					idMax = j;
					leadingIDs[leadingIDs.size() - 1] = idMax;
				}
			}
		}
		for(uint i = 0; i < min(leadingIDs.size(), leadersNeeded);)
		{
			if(!charactersToIgnore[leadingIDs[i]])
			{
				leadingCharacters.push_back(statisticsGames.getCharacterById(leadingIDs[i]));
				i++;
			}
		}
	}
	return leadingCharacters;
}


void Game::deleteLastAnswer()
{
	if(currentAnswers.size())
	{
		std::pair<uint, uint> lastAnswer = currentAnswers[currentAnswers.size() - 1];
		currentAnswers.del(lastAnswer);
	}
}

void Game::deleteCharacter(uint id)
{
	statisticsGames.deleteCharacter(id);
}

void Game::deleteQuestion(uint id)
{
	questions.del(getQuestions()[id-1]);
	for(uint i = 0; i < questions.size(); i++)
	{
		if(questions[i].getId() > id)
			questions[i].setId(questions[i].getId() - 1);
	}
	statisticsGames.deleteQuestion(id);
}

void Game::deleteAnswer(uint id)
{
	answers.del(getAnswers()[id-1]);
	for(uint i = 0; i < answers.size(); i++)
	{
		if(answers[i].getId() > id)
			answers[i].setId(answers[i].getId() - 1);
	}
	statisticsGames.deleteAnswer(id);
}

void Game::ignoreCharacter(uint id)
{
	charactersToIgnore[id] = true;
}

void Game::initializeCharactersToIgnore()
{
	for(uint i = 0; i < statisticsGames.getNumberOfCharacters(); i++)
	{
		charactersToIgnore[statisticsGames.getCharacter(i).getId()] = false;
	}
}

