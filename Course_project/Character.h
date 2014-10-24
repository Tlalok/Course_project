#include <vector>
#include <map>
#include "StatisticsQuestion.h"

class Character
{
	//��� ������� ��� �����, �� � ���� ������� ������� �������� �����, �� ��� � ��������� � ����������� �������, ��
	uint id;
    // ��� ���������
    std::string name;
    // ������� ��� ��� �������
    uint timesPicked;
    // ���������� �� �������� � ������� 
    // ��� ������� ���������
    std::vector<StatisticsQuestion> statisticsQuestions;
    //std::map<uint, StatisticsQuestion> statisticsQuestions;
public:
	uint getTimesPicked();
	uint getId();
	std::string getName();
    //uint getCountQuestions();
    uint getTimesOfAskingQuestion(uint idQuestion);
    uint getTimesOfGivingAnswer(uint idQuestion, uint idAnswer);
};