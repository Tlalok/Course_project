#include <map>
#include "StatisticsQuestion.h"
#include <fstream>

class Character
{
	//��� ������� ��� �����, �� � ���� ������� ������� �������� �����, �� ��� � ��������� � ����������� �������, ��
	uint id;
    // ��� ���������
    std::string name;
    // ������� ��� ��� �������
    uint timesPicked;
    // ���������� �� �������� � ������� 
    // ��� ������� ���������
    _vector<StatisticsQuestion> statisticsQuestions;
    //std::map<uint, StatisticsQuestion> statisticsQuestions;
public:
	operator Character();
	Character();
	Character(const Character& toCopy);
	Character& operator=(Character toCopy); 
	uint getTimesPicked();
	uint getId();
	std::string getName();
    uint getNumberOfQuestions();
    uint getTimesOfAskingQuestion(uint idQuestion);
    uint getTimesOfGivingAnswer(uint idQuestion, uint idAnswer);
	friend std::fstream& operator>>(std::fstream& file, Character& character);
	friend std::fstream& operator<<(std::fstream& file, Character& character);
};