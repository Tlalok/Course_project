typedef unsigned uint;

class StatisticsAnswer
{
    uint id;
    uint timesOfGivingAnswer; 
public:
	StatisticsAnswer();
	StatisticsAnswer(uint, uint);
	uint getAnswerID();
	uint getTimesOfGivingAnswer();
};