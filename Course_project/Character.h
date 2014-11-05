#include "StatisticsQuestion.h"


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
    Vector<StatisticsQuestion> statisticsQuestions;
    //std::map<uint, StatisticsQuestion> statisticsQuestions;
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
	friend std::ifstream& operator>>(std::ifstream& file, Character& character);
	friend std::ofstream& operator<<(std::ofstream& file, Character& character);
	void addQuestion(StatisticsQuestion& toAdd);
};