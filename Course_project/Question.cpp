#include "Question.h"

uint Question::getId()
{
    return id;
}

std::ifstream& operator>>(std::ifstream& file, Question& question)
{
	if (!file.read((char *) &question.id, sizeof(uint)))
        return file;
    uint textLength;
    file.read((char *) &textLength, sizeof(uint));
    char *buf = new char[textLength];
    file.read(buf, textLength);
	question.text = buf;
    delete[] buf;
    return file;
}

std::ofstream& operator<<(std::ofstream& file, Question& question)
{
	file.write((char *) &question.id, sizeof(uint));
    uint textLength = question.text.size() + 1;
    file.write((char *) &textLength, sizeof(uint));
    file.write(question.text.c_str(), textLength);
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

bool Question::operator==(Question& toCompare)
{
	if(this->getId() == toCompare.getId())
		return true;
	return false;
}