//#include <unordered_map>
#include "Character.h"
#include <string>
#include <fstream>


class StatisticsGames
{
    // ����� ����� ��������� ���
    // �� ���� ����� �� ��� ������� ���
    // ������ ������� ����� ����������� ��� ���    //���� �������?����?
    // ����� ���� ������� ��� ��� ������� ������   // ��, ����, ��� �� ������ ������� ��� ����
    // ��������
    uint numberGames;
    // ������ ����������
    _vector<Character> characters;
    // ���� ����� ������� �� ������ ��������� ���������� �������� 
    // � ���� ����� ������ � ������� ���-�������
    // � ����� ��������� � ��������, �� � �� ���� ��� �����(
    // ������� ����� ��� ��������� ������
    uint getTimesOfAskingQuestion(uint idQuestion);
    // ������� ��� ������� ����� �� ������
    uint getTimesOfGivingAnswer(uint idQuestion, uint idAnswer);

public:
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

	friend std::fstream& operator>>(std::fstream& file, StatisticsGames& question);
	friend std::fstream& operator<<(std::fstream& file, StatisticsGames& question);
};