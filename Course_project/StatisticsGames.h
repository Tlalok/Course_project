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
    unsigned int numberGames;
    // ������ ����������
    std::vector<Character> characters;
    // ���� ����� ������� �� ������ ��������� ���������� �������� 
    // � ���� ����� ������ � ������� ���-�������
    // � ����� ��������� � ��������, �� � �� ���� ��� �����(
public:
	int getNumberOfCharacters();
	int getTimesCharacterPicked(int);
	std::string getNameOfCharacter(int);
	int getNumberGames();
	Character getCharacter(int)
};