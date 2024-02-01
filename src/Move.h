#pragma once
#include <string>

class Move
{
private:
	int row;
	int col;

public:
	Move();
	Move(int r, int c);
	int ArrayIndex();
	bool InRange();
	std::string& operator +(std::string& str);
	friend std::istream& operator >>(std::istream& stream, Move& move);
};