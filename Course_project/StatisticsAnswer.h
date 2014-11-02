typedef unsigned uint;

#include <fstream>
#include "vector.cpp"

class StatisticsAnswer
{
    uint id;
    uint timesOfGivingAnswer; 
public:
	StatisticsAnswer();
	StatisticsAnswer(uint id, uint timesOfGivingAnswer);
	uint getAnswerID();
	uint getTimesOfGivingAnswer();
	friend std::fstream& operator>>(std::fstream& file, StatisticsAnswer& statisticsAnswer);
	friend std::fstream& operator<<(std::fstream& file, StatisticsAnswer& statisticsAnswer);
};