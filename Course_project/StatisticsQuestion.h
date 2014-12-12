#pragma once
#include <map>
#include "StatisticsAnswer.h"
#include "Question.h"
#include "Answer.h"
#include "include.h"

class StatisticsQuestion
{
    uint id;
    uint timesOfAskingQuestion;
    Vector<StatisticsAnswer> statisticsAnswers;
    //std::map<uint, uint> statisticsAnswers;
public:
	StatisticsQuestion();
	StatisticsQuestion(Vector<Answer>& answers);
	StatisticsQuestion(uint id, uint timesOfAskingQuestion, Vector<StatisticsAnswer>& answers);
    StatisticsQuestion(StatisticsQuestion& toCopy);
    //StatisticsQuestion(StatisticsQuestion & statisticsQuestion);
    StatisticsQuestion& operator++();
	StatisticsAnswer& operator[](uint idAnswer);
	StatisticsQuestion& operator=(StatisticsQuestion& toCopy);
	void setId(uint id);
	uint getQuestionID();
	uint getTimesOfAskingQuestion();
	StatisticsAnswer& getAnswerStatistic(uint idAnswer);
    uint getTimesOfGivingAnswer(uint idAnswer);
    uint getNumberAnswers();
	void addAnswer(StatisticsAnswer& toAdd);
	void deleteAnswer(uint id);
	bool operator==(StatisticsQuestion& toCompare);
	friend std::istream& operator>>(std::istream& file, StatisticsQuestion& statisticsquestion);
	friend std::ostream& operator<<(std::ostream& file, StatisticsQuestion& statisticsquestion);
};