#include "StatisticsQuestion.h"


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
    vector<StatisticsQuestion> statisticsQuestions;
    //std::map<uint, StatisticsQuestion> statisticsQuestions;
public:
    Character();
	Character(const Character& toCopy);
	Character(uint id, std::string name, uint timesPicked);
	void addAnswer(StatisticsAnswer& toAdd);
	Character& operator=(Character& toCopy); 
	uint getTimesPicked();
	uint getId();
	std::string getName();
	StatisticsQuestion& getStatisticsQuestion(uint idQuestion);
    uint getNumberOfQuestions();
    uint getTimesOfAskingQuestion(uint idQuestion);
    uint getTimesOfGivingAnswer(uint idQuestion, uint idAnswer);
	void checkCharacterStatistics(vector<Question>& questions, vector<Answer>& answers);
	friend std::ifstream& operator>>(std::ifstream& file, Character& character);
	friend std::ofstream& operator<<(std::ofstream& file, Character& character);
	void addQuestion(StatisticsQuestion& toAdd);
};