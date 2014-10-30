#include "Question.h"

uint Question::getId()
{
    return id;
}

std::fstream& operator>>(std::fstream& file, Question& question)
{
	file.read((char*)&question.id, sizeof(uint));
	char buf[100];
	file.read(buf, question.TEXT_SIZE);
	question.text = buf;
    return file;
}

std::fstream& operator<<(std::fstream& file, Question& question)
{
	file.write((char*)&question.id, sizeof(uint));
	file.write(question.text.c_str(), question.TEXT_SIZE);
    return file;
}
