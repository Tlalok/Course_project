#include "Game.h"

double log(double a, double b)
{
    return log(b) / log(a);
}

Game::Game()
{
	for(uint i = 0; i < statisticsGames.getNumberOfCharacters(); i++)
	{
		
	}
}

void Game::calculate()
{
	for(uint i = 0; i < statisticsGames.getNumberOfCharacters(); i++)
	{

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
        return -1;    // �������� �� ���������� ��� �������� ��� ������������� ��������
    uint indexMin = 0;
    for (uint i = 1; i < H.size(); i++)
        if (H[indexMin].second > H[i].second)
            indexMin = i;
    return H[indexMin].first;
}

double Game::getPBAi(StatisticsGames statisticGame, StatisticsQuestion statisticQuestion, Character character, Question question, Answer answer)
{
	double result = 0;
	uint idCharacter = character.getId();
	uint idQuestion = question.getId();
	uint idAnswer = answer.getId();
	for(uint i = 0; i < statisticQuestion.getAnswerStatistic.size(); i++)
		result *= statisticGame.getPBjAi(idCharacter, idQuestion, idAnswer);
	return result;
}

double Game::getPAiB(StatisticsGames statisticGame, StatisticsQuestion statisticQuestion, Character character, Question question, Answer answer, uint n)
{
	double result = 0;
	uint idQuestion = question.getId();
	uint idAnswer = answer.getId();
	result = this->getPBAi(statisticGame, statisticQuestion, character, question, answer) * statisticGame.getPAi(n) / statisticGame.getPBi(idQuestion, idAnswer);;
}