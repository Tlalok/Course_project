#pragma once
typedef unsigned uint;

#include <fstream>
#include "vector.cpp"
//#include <Vector>
//using namespace std;

class StatisticsAnswer
{
    uint id;
    uint timesOfGivingAnswer; 
public:
	StatisticsAnswer();
	StatisticsAnswer(uint id, uint timesOfGivingAnswer);
    StatisticsAnswer(const StatisticsAnswer &statisticsAnswer);
    StatisticsAnswer& operator++();
	uint getAnswerID();
	uint getTimesOfGivingAnswer();
	void setId(uint id);
	friend std::istream& operator>>(std::istream& file, StatisticsAnswer& statisticsAnswer);
	friend std::ostream& operator<<(std::ostream& file, StatisticsAnswer& statisticsAnswer);
    StatisticsAnswer& operator=(StatisticsAnswer &toCopy);
};