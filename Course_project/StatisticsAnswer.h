typedef unsigned uint;

#include <fstream>
#include "vector.cpp"

class StatisticsAnswer
{
    uint id;
    uint timesOfGivingAnswer; 
public:
	StatisticsAnswer();
	StatisticsAnswer& operator++();
	StatisticsAnswer(uint id, uint timesOfGivingAnswer);
	uint getAnswerID();
	uint getTimesOfGivingAnswer();
	void setId(uint id);
	friend std::fstream& operator>>(std::fstream& file, StatisticsAnswer& statisticsAnswer);
	friend std::fstream& operator<<(std::fstream& file, StatisticsAnswer& statisticsAnswer);
};