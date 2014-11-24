#pragma once
#include <iostream>
#include "windows.h"

std::istream& operator>>(std::istream& file, std::string& string);
std::ostream& operator<<(std::ostream& file, std::string& string);

bool operator==(std::string& string1, std::string& string2);