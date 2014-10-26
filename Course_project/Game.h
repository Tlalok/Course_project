#include "StatisticsGames.h"
#include "Question.h"
#include "Answer.h"
#include <vector>
#include <map>
#include <math.h>
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
    // ��� ������� ������������� ������ � ������� ����������� �������� �� id ���������
	std::map<uint, double> currentProbability;

    // ���������� ���������� ��� �� ��������� ������ ����� ��� ��������� �����
    // � ������ ��� ���������� ������� (����� ��� ������� ��������)
    double getPQjAns(uint idQuestion, uint idAnswer);
    // ���������� ������� ��� ���������, ���� �� ������� ��������� ������
    // � ������� ��������� �����
    double getHPAiBQjAns(uint idQuestion, uint idAnswer);
    // ���������� ����� ���������� �������, ������� ����� ������
    uint gedIdNextQuestion();
    // ��������� ��� �� ����� ��������� ������
    bool questionWasAsked(uint idQuestion);

public:
	Game();
	void calculate();
};