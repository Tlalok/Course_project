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
    // ������� ������������������ �������� � ������� ������� ��� ������������
    std::vector<std::pair<unsigned int, unsigned int>> currentAnswers;
	// ����� ������ ���� �����-�� ������ ������������ ������� ��� ���� ����������, ��������� � �������
	// ����� ��, ����� �� ����� ����� ���������
    // ��� ������� ������������� ������ � ������� ����������� �������� �� ����� ���������
	std::map<std::string, Probability> currentProbability;
public:
	Game();
	void calculate();
};