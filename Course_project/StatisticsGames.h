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
	uint getTimesCharacterPicked(uint);
	std::string getNameOfCharacter(uint);
	uint getNumberGames();
	Character getCharacter(uint);

    //���������� ����������� ���� ��� ����� ��� ��������� �����
    double getPBi(uint idQuestion, uint idAnswer);

    // P(Bj|Ai)
    double getPBjAi(uint idCharater, uint idQuestion, uint idAnswer);

	//P(Ai)
	double getPAi(uint n);

	friend std::ifstream& operator>>(std::ifstream& file, StatisticsGames& question);
	friend std::ofstream& operator<<(std::ofstream& file, StatisticsGames& question);

    StatisticsGames& operator=(StatisticsGames toCopy);
};