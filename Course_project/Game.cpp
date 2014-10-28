#include "Game.h"

double log(double a, double b)
{
    return log(b) / log(a);
}

Game::Game()
{
	Question question;
	fstream file("questions.txt", std::ios::in);
	while(!file.eof())
	{
		file>>question;
		questions.push_back(question);
	}
	file.close();

	file.open("answers.txt", std::ios::in);
	Answer answer;
	fstream file("answers.txt");
	while(!file.eof())
	{
		file>>answer;
		answers.push_back(answer);
	}
	file.close();

	for(uint i = 0; i < statisticsGames.getNumberOfCharacters(); i++)
	{
		
	}
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
    std::vector<std::pair<uint, double>> H;
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

double Game::getPAiB(Character& character)
{
	double result = 0;
	double PB = 1;
	for(uint i = 0; i < questions.size(); i++)
		PB *= statisticsGames.getPBi(currentAnswers[i].first, currentAnswers[i].second);
	result = getPBAi(character) * statisticsGames.getPAi(character.getId()) / PB;
}