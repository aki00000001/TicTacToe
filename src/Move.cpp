#include "Move.h"
#include <iostream>

int Move::ArrayIndex()
{
	return (3 * this->row) + this->col - 4;
}

bool Move::InRange()
{
	return this->row < 4 && this->col < 4 && this->row > 0 && this->col > 0;
}

std::string& Move::operator+(std::string& str)
{
	str = str + "(" + std::to_string(row) + ", " + std::to_string(col) + ")";
	return str;
}

std::istream& operator >>(std::istream& stream, Move& move)
{
	std::cout << "Enter row no. (between 1 and 3): ";
	stream >> move.row;
	std::cout << "Enter column no. (between 1 and 3): ";
	stream >> move.col;
	return stream;
}
