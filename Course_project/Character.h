#pragma once
#include "StatisticsQuestion.h"
#include "include.h"

class Character
{
	uint id;
    // ��� ���������
    std::string name;
    // ������� ��� ��� �������
    uint timesPicked;
    // ���������� �� �������� � ������� 
    // ��� ������� ���������
    Vector<StatisticsQuestion> statisticsQuestions;
public:
    Character();
	Character(Character& toCopy);
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
	void checkCharacterStatistics(Vector<Question>& questions, Vector<Answer>& answers);
    void addQuestion(StatisticsQuestion& toAdd);
    // ����������� �� 1 ���������� ���� �������
    // ��� ��� ������� ��������
    void incTimesPicked();
    // ��������� �� 1 ���������� ���� �������
    // ��� ��� ������� ��������
    void decTimesPicked();
	void characterGuessed(Vector<std::pair<uint, uint>> currentAnswers);
	friend std::istream& operator>>(std::istream& file, Character& character);
	friend std::ostream& operator<<(std::ostream& file, Character& character);
};