#include <string>
#include <iostream>
#include <fstream>

using namespace std;
typedef unsigned uint;

class Question
{
	static const uint TEXT_SIZE = 100;
    uint id;
    // ����� �������
    std::string text;  //questionText �� �����? ����� �������� �� ���� ��, ��� � ����������?
                       // ����� ����� ���������� ��������� questions[i].text ����� ����
public:
    uint getId();
	friend fstream& operator>>(fstream& file, Question& question);
	friend fstream& operator<<(fstream& file, Question& question);
};