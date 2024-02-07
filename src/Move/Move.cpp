#include "Move.h"
#include <iostream>

Move::Move()
	:row(0), col(0)
{}

Move::Move(int r, int c)
	:row(r), col(c)
{}

Move::Move(const Move& move)
	:row(move.row), col(move.col)
{}

int Move::ArrayIndex() const
{
	return ArrayIdx(row, col);
}

bool Move::InRange() const
{
	return this->row < 4 && this->col < 4 && this->row > 0 && this->col > 0;
}

std::string& Move::operator+(std::string& str) const
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

bool Move::operator == (const Move& second) const
{
	if (row == second.row && col == second.col)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Move::operator != (const Move& second) const
{
	if (row == second.row && col == second.col)
	{
		return false;
	}
	else
	{
		return true;
	}
}
