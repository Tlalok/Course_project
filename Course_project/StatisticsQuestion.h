#include <vector>
#include <map>
#include "StatisticsAnswer.h"

class StatisticsQuestion
{
    unsigned int id;
    // ������� ��� ��� ����� ���� ������
    // ����� ���������� ��������� ��������
    // ����������� ������ ����� ������ 
    // ���� �� ���� ��� �������)     //amountOfAskingQuestion  ,���� �� ������ ���������.����� ������� ���
    unsigned int amountOfAskingQuestion;
    // ���������� �������
    std::vector<StatisticsAnswer> statisticsAnswers;
    //std::map<unsigned int, unsigned int> statisticsAnswers;
};