#include <vector>
#include "StatisticsQuestion.h"
//#include <unordered_map>

class Character
{
    // ��� ���������
    std::string name;
    // ������� ��� ��� �������
    // �� ���� ��� ������� �� ����������)   //amountOfPicking  , ��������,������ ����� ���� ����������
    unsigned int i;
    // ���������� �� �������� � ������� 
    // ��� ������� ���������
    std::vector<StatisticsQuestion> statisticsQuestions;
};