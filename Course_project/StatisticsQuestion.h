#include <vector>
#include "StatisticsAnswer.h"

class StatisticsQuestion
{
    unsigned int id;
    // ������� ��� ��� ����� ���� ������
    // ����� ���������� ��������� ��������
    // ����������� ������ ����� ������ 
    // ���� �� ���� ��� �������)     //amountOfAskingQuestion  ,���� �� ������ ���������.����� ������� ���
    unsigned int i;
    // ���������� �������
    std::vector<StatisticsAnswer> statisticsAnswers;
};