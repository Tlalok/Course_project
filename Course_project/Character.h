#include <vector>
#include <map>
#include "StatisticsQuestion.h"

class Character
{
	//��� ������� ��� �����, �� � ���� ������� ������� �������� �����, �� ��� � ��������� � ����������� �������, ��
	int id;
    // ��� ���������
    std::string name;
    // ������� ��� ��� �������
    unsigned int timesPicked;
    // ���������� �� �������� � ������� 
    // ��� ������� ���������
    std::vector<StatisticsQuestion> statisticsQuestions;
    //std::map<unsigned int, StatisticsQuestion> statisticsQuestions;
public:
	int getTimesPicked();
	int getId();
	std::string getName();
    //unsigned int getCountQuestions();
    unsigned int getTimesOfAskingQuestion(unsigned int idQuestion);
    unsigned int getTimesOfGivingAnswer(unsigned int idQuestion, unsigned int idAnswer);
};