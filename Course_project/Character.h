#include "StatisticsQuestion.h"
#include "Question.h"
#include "Answer.h"

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
    Vector<StatisticsQuestion> statisticsQuestions;
    //std::map<uint, StatisticsQuestion> statisticsQuestions;
public:
	void addAnswer(StatisticsAnswer toAdd);
	operator Character();
	Character();
	Character(const Character& toCopy);
	Character& operator=(Character toCopy); 
	uint getTimesPicked();
	uint getId();
	std::string getName();
	StatisticsQuestion& getStatisticsQuestion(uint idQuestion);
    uint getNumberOfQuestions();
    uint getTimesOfAskingQuestion(uint idQuestion);
    uint getTimesOfGivingAnswer(uint idQuestion, uint idAnswer);
	void checkCharacterStatistics(Vector<Question>& questions, Vector<Answer>& answers);
	friend std::fstream& operator>>(std::fstream& file, Character& character);
	friend std::fstream& operator<<(std::fstream& file, Character& character);
	void addQuestion(StatisticsQuestion toAdd);
};