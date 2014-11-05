#include "StatisticsGames.h"
#include <math.h>


//SetConsoleCP(1251);
//SetConsoleCP(866);
//шаманство для ввода русского текста в консоли

class Game
{
    StatisticsGames statisticsGames;
    // список всех вопросов
    vector<Question> questions;
    // список всех ответов
	vector<Answer> answers;
    // текущая последовательность вопросов и ответов которые дал пользователь
    vector<std::pair<uint, uint>> currentAnswers;
	// здесь должен быть какой-то массив вероятностей текущих для всех персонажей, насколько я понимаю
	// думаю да, тогда их проще будет вычислять
    // как вариант ассоциативный массив в котором вероятности хранятся по id персонажа
	std::map<uint, double> currentProbability;
    // возвращает верятность что на указанный вопрос будет дан указанный ответ
    // с учетом уже полученных ответов (нужна для расчета энтропии)
    double getPQjAns(uint idQuestion, uint idAnswer);
    // возвращает энтопию для состояния, если мы зададим указанный вопрос
    // и получим указанный ответ
    double getHPAiBQjAns(uint idQuestion, uint idAnswer);
    // возвращает индек следующего вопроса, который нужно задать
    uint gedIdNextQuestion();
    // проверяет был ли задан указанный вопрос
    bool questionWasAsked(uint idQuestion);
	//возвращает вероятность того,что будет такой набор вопросов-ответов при загаданном персонаже
	double getPBAi(Character&);
	//возвращает вероятность того,что загадан этот персонаж при данном наборе вопросов-ответов
	double getPAiB(Character);

public:
	bool isQuestionExist(std::string);
	bool isAnswerExist(std::string);
	bool isCharacterExist(std::string);
	void addQuestion(std::string);
	void addAnswer(std::string);
	void addCharacter(std::string);
	void checkCharactersStatistics();
	void calculate();
	uint read();
	uint write();

    void printStatistics();
};