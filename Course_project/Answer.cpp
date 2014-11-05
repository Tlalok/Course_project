#include "Answer.h"

uint Answer::getId()
{
    return id;
}

std::string Answer::getText()
{
	return text;
}

void Answer::setId(uint id)
{
	this->id = id;
}

void Answer::setText(std::string text)
{
	this->text = text;
}

std::ifstream& operator>>(std::ifstream& file, Answer& answer)
{
	if(!file.read((char *) &answer.id, sizeof(uint)))
        return file;
    uint textLength;
    file.read((char *) &textLength, sizeof(uint));
    char *buf = new char[textLength];
    file.read(buf, textLength);
	answer.text = buf;
    delete[] buf;
    return file;
}

std::ofstream& operator<<(std::ofstream& file, Answer& answer)
{
	file.write((char *) &answer.id, sizeof(uint));
    uint textLength = answer.text.size() + 1;
    file.write((char *) &textLength, sizeof(uint));
    file.write(answer.text.c_str(), textLength);
    return file;
}