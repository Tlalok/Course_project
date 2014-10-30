#include "StatisticsGames.h"
#include "Question.h"
#include "Answer.h"
#include <map>
#include <math.h>
#include <iostream>
#include <fstream>


//SetConsoleCP(1251);
//SetConsoleCP(866);
//��������� ��� ����� �������� ������ � �������

class Game
{
    StatisticsGames statisticsGames;
    // ������ ���� ��������
    _vector<Question> questions;
    // ������ ���� �������
	_vector<Answer> answers;
    // ������� ������������������ �������� � ������� ������� ��� ������������
    _vector<std::pair<uint, uint>> currentAnswers;
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