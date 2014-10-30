typedef unsigned uint;

#include <fstream>

class StatisticsAnswer
{
    uint id;
    uint timesOfGivingAnswer; 
public:
	StatisticsAnswer();
	StatisticsAnswer(uint, uint);
	uint getAnswerID();
	uint getTimesOfGivingAnswer();
	friend std::fstream& operator>>(std::fstream& file, StatisticsAnswer& statisticsAnswer);
	friend std::fstream& operator<<(std::fstream& file, StatisticsAnswer& statisticsAnswer);
};