#pragma once
#include <fstream>
#include "include.h"

typedef unsigned uint;

class Answer
{
	static const uint TEXT_SIZE = 20;
    uint id;
    // текст ответа
    std::string text;
public:
	//возвращает ID ответа
    uint getId();
	//возвращает текст ответа
	std::string getText();
	//устанавливает ID
	void setId(uint id);
	//устанавливает текст
	void setText(std::string text);
	bool operator==(Answer& toCompare);
	friend std::ifstream& operator>>(std::ifstream& file, Answer& question);
	friend std::ofstream& operator<<(std::ofstream& file, Answer& question);
};