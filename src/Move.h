#pragma once
#include <string>

struct Move
{
	int row;
	int col;

	int ArrayIndex();
	bool InRange();
	std::string& operator +(std::string& str);
	friend std::istream& operator >>(std::istream& stream, Move& move);
};