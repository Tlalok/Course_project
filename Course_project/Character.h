#include <vector>
#include "StatisticsQuestion.h"
//#include <unordered_map>

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
};