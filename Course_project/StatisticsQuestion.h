#include <vector>
#include <map>
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
    //std::map<unsigned int, unsigned int> statisticsAnswers;
};