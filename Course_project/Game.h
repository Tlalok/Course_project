#include "StatisticsGames.h"
#include "Question.h"
#include "Answer.h"
#include "Character.h"
#include <vector>
#include <map>
#include <math.h>
#include "Probability.h"
#include <iostream>
#include <fstream>

using namespace std;

//SetConsoleCP(1251);
//SetConsoleCP(866);
//��������� ��� ����� �������� ������ � �������

class Game
{
    StatisticsGames statisticsGames;
    // ������ ���� ��������
    std::vector<Question> questions;
    // ������ ���� �������
    std::vector<Answer> answers;
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
	//���������� ����������� ����,��� ����� ����� ����� ��������-������� ��� ���������� ���������
	double getPBAi(Character&);
	//���������� ����������� ����,��� ������� ���� �������� ��� ������ ������ ��������-�������
	double getPAiB(Character);

public:
	Game();
	void calculate();
	uint read();
	uint write();
};