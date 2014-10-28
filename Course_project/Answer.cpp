#include "Answer.h"

uint Answer::getId()
{
    return id;
}

fstream& operator>>(fstream& file, Answer& answer)
{
	file.read((char*)&answer.id, sizeof(uint));
	char buf[100];
	file.read(buf, answer.TEXT_SIZE);
	answer.text = buf;
}

fstream& operator<<(fstream& file, Answer& answer)
{
	file.write((char*)&answer.id, sizeof(uint));
	file.write(answer.text.data, answer.TEXT_SIZE);
}