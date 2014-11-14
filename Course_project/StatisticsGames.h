#pragma once
//#include <unordered_map>
#include "Character.h"
#include <string>


class StatisticsGames
{
    // ����� ����� ��������� ���
    // �� ���� ����� �� ��� ������� ���
    // ������ ������� ����� ����������� ��� ���    //���� �������?����?
    // ����� ���� ������� ��� ��� ������� ������   // ��, ����, ��� �� ������ ������� ��� ����
    // ��������
    uint numberGames;
    // ������ ����������
    Vector<Character> characters;
    // ���� ����� ������� �� ������ ��������� ���������� �������� 
    // � ���� ����� ������ � ������� ���-�������
    // � ����� ��������� � ��������, �� � �� ���� ��� �����(
    // ������� ����� ��� ��������� ������
    uint getTimesOfAskingQuestion(uint idQuestion);
    // ������� ��� ������� ����� �� ������
    uint getTimesOfGivingAnswer(uint idQuestion, uint idAnswer);
public:
    StatisticsGames();
    StatisticsGames(StatisticsGames &StatisticsGames);
	void addAnswer(StatisticsAnswer& toAdd);
	bool isCharacterExist(std::string name);
	void addQuestion(StatisticsQuestion& toAdd);
	void addCharacter(Character& toAdd);
	void checkCharactersStatistics(Vector<Question>& questions, Vector<Answer>& answers);
	bool charactersIsEmpty();
	uint getNumberOfCharacters();
	uint getTimesCharacterPicked(uint idCharacter);
	std::string getNameOfCharacter(uint idCharacter);
	uint getNumberGames();
	Character getCharacter(uint idCharacter);
	Vector <Character>& getCharacters();

    //���������� ����������� ���� ��� ����� ��� ��������� �����
    double getPBi(uint idQuestion, uint idAnswer);

    // P(Bj|Ai)
    double getPBjAi(uint idCharater, uint idQuestion, uint idAnswer);

	//P(Ai)
	double getPAi(uint idCharacter);

	friend std::istream& operator>>(std::istream& file, StatisticsGames& question);
	friend std::ostream& operator<<(std::ostream& file, StatisticsGames& question);

    StatisticsGames& operator=(StatisticsGames toCopy);
};