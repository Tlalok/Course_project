#include <map>
#include "StatisticsQuestion.h"
#include <fstream>

class Character
{
	//мне кажется что нужно, да и инты быстрее стринга работать будут, мб ещё и персонажи с одинаковыми именами, хз
	uint id;
    // имя персонажа
    std::string name;
    // сколько раз был загадан
    uint timesPicked;
    // информация по вопросам и ответам 
    // для данного персонажа
    _vector<StatisticsQuestion> statisticsQuestions;
    //std::map<uint, StatisticsQuestion> statisticsQuestions;
public:
	operator Character();
	Character();
	Character(const Character& toCopy);
	Character& operator=(Character toCopy); 
	uint getTimesPicked();
	uint getId();
	std::string getName();
    uint getNumberOfQuestions();
    uint getTimesOfAskingQuestion(uint idQuestion);
    uint getTimesOfGivingAnswer(uint idQuestion, uint idAnswer);
	friend std::fstream& operator>>(std::fstream& file, Character& character);
	friend std::fstream& operator<<(std::fstream& file, Character& character);
};