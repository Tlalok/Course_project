#include "include.h"

std::istream& operator>>(std::istream& in, std::string& _string)
{
	SetConsoleCP(1251);
    in.clear();
    in.ignore(in.rdbuf()->in_avail());
    char* nameCstr = new char[100];
    in.getline(nameCstr, 100, '\n');
    _string = nameCstr;
    delete [] nameCstr;
	SetConsoleCP(866);
	return in;
}

std::ostream& operator<<(std::ostream& out, std::string& _string)
{
	out<<_string.c_str();
	return out;
}

bool operator==(std::string& string1, std::string& string2)
{
	return(!strcmp(string1.c_str(), string2.c_str()));
}