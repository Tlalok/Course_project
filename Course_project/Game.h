#pragma once
#include "StatisticsGames.h"
#include <iomanip>
#include <math.h>
#include "include.h"

//SetConsoleCP(1251);
//SetConsoleCP(866);
//шаманство для ввода русского текста в консоли

class Game
{
    StatisticsGames statisticsGames;
    // список всех вопросов
    Vector<Question> questions;
    // список всех ответов
	Vector<Answer> answers;
    // текущая последовательность вопросов и ответов которые дал пользователь
    Vector<std::pair<uint, uint>> currentAnswers;
	// здесь должен быть какой-то массив вероятностей текущих для всех персонажей, насколько я понимаю
	// думаю да, тогда их проще будет вычислять
    // как вариант ассоциативный массив в котором вероятности хранятся по id персонажа
	std::map<uint, double> currentProbability;
    // возвращает верятность что на указанный вопрос будет дан указанный ответ
    // с учетом уже полученных ответов (нужна для расчета энтропии)
	std::map<uint, bool> charactersToIgnore;
    double getPQjAns(uint idQuestion, uint idAnswer);
    // возвращает энтопию для состояния, если мы зададим указанный вопрос
    // и получим указанный ответ
    double getHPAiBQjAns(uint idQuestion, uint idAnswer);
    // проверяет был ли задан указанный вопрос
    bool questionWasAsked(uint idQuestion);
	//возвращает вероятность того,что будет такой набор вопросов-ответов при загаданном персонаже
	double getPBAi(Character&);
	//возвращает вероятность того,что загадан этот персонаж при данном наборе вопросов-ответов
	double getPAiB(Character&);
	void initializeCharactersToIgnore();
public: 
	const static uint stackOfQuestions = 20;
	const static uint minQuestions = 10;
	// возвращает индекс следующего вопроса, который нужно задать
    uint getIdNextQuestion();
	bool isQuestionExist(std::string text);
	bool isAnswerExist(std::string text);
	bool isCharacterExist(std::string name);
	void addQuestion(std::string text);
	void addAnswer(std::string text);
	void addCharacter(std::string name);
	void checkCharactersStatistics();
	void calculate();
	uint read();
	uint write();
    void printStatistics();
	void giveAnswer(uint idQuestion, uint idAnswer);
	void printProbability();
    void printNumberQuestionsCharacters();
	//Vector<Answer>& getAnswers();
    Vector<Answer> getAnswers();
	Vector<Question> getQuestions();
	Vector<Character> getCharacters();
	std::string getQuestionText(uint idQuestion);
    bool canSupposeCharacter();
	Vector<Character> getLeadingCharacters(uint leadersNeeded = 5);
	void incNumberGames();
	void characterGuessed(uint idCharacter);
	void deleteLastAnswer();
	void deleteQuestion(uint id);
	void deleteCharacter(uint id);
	void deleteAnswer(uint id);
	void ignoreCharacter(uint id);
};