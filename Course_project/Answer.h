#pragma once
#include <fstream>
#include "include.h"

typedef unsigned uint;

class Answer
{
	static const uint TEXT_SIZE = 20;
    uint id;
    // ����� ������
    std::string text;
public:
	//���������� ID ������
    uint getId();
	//���������� ����� ������
	std::string getText();
	//������������� ID
	void setId(uint id);
	//������������� �����
	void setText(std::string text);
	bool operator==(Answer& toCompare);
	friend std::ifstream& operator>>(std::ifstream& file, Answer& question);
	friend std::ofstream& operator<<(std::ofstream& file, Answer& question);
};