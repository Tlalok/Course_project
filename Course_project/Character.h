#include <vector>
#include <map>
#include "StatisticsQuestion.h"
#include <fstream>

class Character
{
	const uint NAME_SIZE = 100;
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
    uint getNumberOfQuestions();
    uint getTimesOfAskingQuestion(uint idQuestion);
    uint getTimesOfGivingAnswer(uint idQuestion, uint idAnswer);
	friend std::fstream& operator>>(std::fstream& file, Character& character);
	friend std::fstream& operator<<(std::fstream& file, Character& character);
};