typedef unsigned uint;

#include <fstream>
#include "Vector.cpp"
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
	friend std::ifstream& operator>>(std::ifstream& file, StatisticsAnswer& statisticsAnswer);
	friend std::ofstream& operator<<(std::ofstream& file, StatisticsAnswer& statisticsAnswer);
    StatisticsAnswer& operator=(StatisticsAnswer &toCopy);
};