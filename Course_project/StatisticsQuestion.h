#include <vector>
#include "StatisticsAnswer.h"

class StatisticsQuestion
{
    unsigned int id;
    // ������� ��� ��� ����� ���� ������
    // ����� ���������� ��������� ��������
    // ����������� ������ ����� ������ 
    // ���� �� ���� ��� �������)
    unsigned int i;
    // ���������� �������
    std::vector<StatisticsAnswer> statisticsAnswers;
};