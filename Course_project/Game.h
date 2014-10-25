#include "StatisticsGames.h"
#include "Question.h"
#include "Answer.h"
#include <vector>
#include <map>
#include "Probability.h"

class Game
{
    StatisticsGames statisticsGames;
    // ������ ���� ��������
    std::vector<Question> questions;
    // ������ ���� �������
    std::vector<Answer> answers;
	//������� ���-�� �������� � ���� ���� �������� // ������� ���������� ����� �������� �� �������� ������� //��� �� private, ������� �������� ����� ����� ������ � ������� ����� ���������� ����� ������ ������, ���� �����7
                                                   // �� ���� ��� ������ ���� ����� �� �����, �� ���� �� � �������� �� �� � ����� ������ ������ �� �� ����� ������� �� ����� �� ���� ���� return numberQuestions ���� return currentQustionsAnswers.size()
    // ������� ������������������ �������� � ������� ������� ��� ������������
    std::vector<std::pair<uint, uint>> currentAnswers;
	// ����� ������ ���� �����-�� ������ ������������ ������� ��� ���� ����������, ��������� � �������
	// ����� ��, ����� �� ����� ����� ���������
    // ��� ������� ������������� ������ � ������� ����������� �������� �� ����� ���������
	std::map<std::string, double> currentProbability;
public:
	Game();
	void calculate();
};