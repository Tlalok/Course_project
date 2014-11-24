#pragma once
#include "StatisticsQuestion.h"
#include "include.h"

class Character
{
	uint id;
    // имя персонажа
    std::string name;
    // сколько раз был загадан
    uint timesPicked;
    // информация по вопросам и ответам 
    // для данного персонажа
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
    // увеличиваем на 1 количество того сколько
    // раз был загадан персонаж
    void incTimesPicked();
    // уменьшаем на 1 количество того сколько
    // раз был загадан персонаж
    void decTimesPicked();
	void characterGuessed(Vector<std::pair<uint, uint>> currentAnswers);
	friend std::istream& operator>>(std::istream& file, Character& character);
	friend std::ostream& operator<<(std::ostream& file, Character& character);
};