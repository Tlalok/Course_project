#include <vector>
#include <map>
#include "StatisticsQuestion.h"

class Character
{
    // ��� ���������
    std::string name;
    // ������� ��� ��� �������
    // �� ���� ��� ������� �� ����������)
    unsigned int i;
    // ���������� �� �������� � ������� 
    // ��� ������� ���������
    std::vector<StatisticsQuestion> statisticsQuestions;
    //std::map<unsigned int, StatisticsQuestion> statisticsQuestions;
};