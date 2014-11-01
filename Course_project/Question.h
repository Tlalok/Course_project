#include <string>
#include <iostream>
#include <fstream>

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
	void setText(std::string text);
	void setId(uint id);
	friend std::fstream& operator>>(std::fstream& file, Question& question);
	friend std::fstream& operator<<(std::fstream& file, Question& question);
	std::string getText();
};