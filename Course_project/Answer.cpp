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

std::fstream& operator>>(std::fstream& file, Answer& answer)
{
	if(!file.read((char *) &answer.id, sizeof(uint)))
        return file;
    uint length;
    file.read((char *) &length, sizeof(uint));
    char *buf = new char[length];
    file.read(buf, length);
	answer.text = buf;
    delete[] buf;
    return file;
}

std::fstream& operator<<(std::fstream& file, Answer& answer)
{
	file.write((char *) &answer.id, sizeof(uint));
    uint length = answer.text.size() + 1;
    file.write((char *) &length, sizeof(uint));
    file.write(answer.text.c_str(), length);
    return file;
}