#include "Question.h"

uint Question::getId()
{
    return id;
}

std::fstream& operator>>(std::fstream& file, Question& question)
{
	if (!file.read((char *) &question.id, sizeof(uint)))
        return file;
    uint length;
    file.read((char *) &length, sizeof(uint));
    char *buf = new char[length];
    file.read(buf, length);
	question.text = buf;
    delete[] buf;
    return file;
}

std::fstream& operator<<(std::fstream& file, Question& question)
{
	file.write((char *) &question.id, sizeof(uint));
    uint length = question.text.size() + 1;
    file.write((char *) &length, sizeof(uint));
    file.write(question.text.c_str(), length);
    return file;
}

std::string Question::getText()
{
	return text;
}

void Question::setText(std::string text)
{
	this->text = text;
}

void Question::setId(uint id)
{
	this->id = id;
}