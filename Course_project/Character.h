#include <vector>
#include <map>
#include "StatisticsQuestion.h"

class Character
{
    // ��� ���������
    std::string name;
    // ������� ��� ��� �������
    // �� ���� ��� ������� �� ����������)   //amountOfPicking  , ��������,������ ����� ���� ����������
    unsigned int amountOfPicking;
    // ���������� �� �������� � ������� 
    // ��� ������� ���������
    std::vector<StatisticsQuestion> statisticsQuestions;
    //std::map<unsigned int, StatisticsQuestion> statisticsQuestions;
};