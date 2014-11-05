#include "StatisticsGames.h"
#include <math.h>


//SetConsoleCP(1251);
//SetConsoleCP(866);
//��������� ��� ����� �������� ������ � �������

class Game
{
    StatisticsGames statisticsGames;
    // ������ ���� ��������
    vector<Question> questions;
    // ������ ���� �������
	vector<Answer> answers;
    // ������� ������������������ �������� � ������� ������� ��� ������������
    vector<std::pair<uint, uint>> currentAnswers;
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
	bool isQuestionExist(std::string);
	bool isAnswerExist(std::string);
	bool isCharacterExist(std::string);
	void addQuestion(std::string);
	void addAnswer(std::string);
	void addCharacter(std::string);
	void checkCharactersStatistics();
	void calculate();
	uint read();
	uint write();

    void printStatistics();
};