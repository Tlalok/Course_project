#include <vector>
//#include <unordered_map>
#include "Character.h"
#include "Probability.h"
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
    std::vector<Character> characters;
    // ���� ����� ������� �� ������ ��������� ���������� �������� 
    // � ���� ����� ������ � ������� ���-�������
    // � ����� ��������� � ��������, �� � �� ���� ��� �����(
public:
	uint getNumberOfCharacters();
	uint getTimesCharacterPicked(uint);
	std::string getNameOfCharacter(uint);
	uint getNumberGames();
	Character getCharacter(uint);

    double getPBi(uint idQuestion, uint idAnswer);

    // ������� ����� ��� ��������� ������
    uint getTimesOfAskingQuestion(uint idQuestion);
    // ������� ��� ������� ����� �� ������
    uint getTimesOfGivingAnswer(uint idQuestion, uint idAnswer);

};