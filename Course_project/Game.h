#pragma once
#include "StatisticsGames.h"
#include <iomanip>
#include <math.h>
#include "include.h"

//SetConsoleCP(1251);
//SetConsoleCP(866);
//��������� ��� ����� �������� ������ � �������

class Game
{
    StatisticsGames statisticsGames;
    // ������ ���� ��������
    Vector<Question> questions;
    // ������ ���� �������
	Vector<Answer> answers;
    // ������� ������������������ �������� � ������� ������� ��� ������������
    Vector<std::pair<uint, uint>> currentAnswers;
	// ����� ������ ���� �����-�� ������ ������������ ������� ��� ���� ����������, ��������� � �������
	// ����� ��, ����� �� ����� ����� ���������
    // ��� ������� ������������� ������ � ������� ����������� �������� �� id ���������
	std::map<uint, double> currentProbability;
    // ���������� ���������� ��� �� ��������� ������ ����� ��� ��������� �����
    // � ������ ��� ���������� ������� (����� ��� ������� ��������)
	std::map<uint, bool> charactersToIgnore;
    double getPQjAns(uint idQuestion, uint idAnswer);
    // ���������� ������� ��� ���������, ���� �� ������� ��������� ������
    // � ������� ��������� �����
    double getHPAiBQjAns(uint idQuestion, uint idAnswer);
    // ��������� ��� �� ����� ��������� ������
    bool questionWasAsked(uint idQuestion);
	//���������� ����������� ����,��� ����� ����� ����� ��������-������� ��� ���������� ���������
	double getPBAi(Character&);
	//���������� ����������� ����,��� ������� ���� �������� ��� ������ ������ ��������-�������
	double getPAiB(Character&);
	void initializeCharactersToIgnore();
public: 
	const static uint stackOfQuestions = 20;
	const static uint minQuestions = 10;
	// ���������� ������ ���������� �������, ������� ����� ������
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