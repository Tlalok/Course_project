#include "StatisticsGames.h"
#include "Question.h"
#include "Answer.h"

class Game
{
    StatisticsGames statisticsGames;
    // ������ ��� ��������
    std::vector<Question> questions;
    // ������ ���� �������
    std::vector<Answer> answers;
	//������� ���-�� �������� � ���� ���� �������� // ������� ���������� ����� �������� �� �������� ������� //��� �� private, ������� �������� ����� ����� ������ � ������� ����� ���������� ����� ������ ������, ���� �����7
                                                   // �� ���� ��� ������ ���� ����� �� �����, �� ���� �� � �������� �� �� � ����� ������ ������ �� �� ����� ������� �� ����� �� ���� ���� return numberQuestions ���� return currentQustionsAnswers.size()
    // ������� ������������������ �������� � ������� ������� ��� ������������
    std::vector<std::pair<unsigned int, unsigned int>> currentQustionsAnswers;
	// ����� ������ ���� �����-�� ������ ������������ ������� ��� ���� ����������, ��������� � �������
	// ����� ��, ����� �� ����� ����� ���������
    // ��� ������� ������������� ������ � ������� ����������� �������� �� ����� ���������
    // std::map<std::string, double> currentProbability;

    const double normalizingCoefficient = 0.95;
};