#pragma once
#include <string>

#define ArrayIdx(row, col) (3 * row) + col - 4

class Move
{
private:
	int row;
	int col;

public:
	Move();

	Move(int r, int c);
	
	explicit Move(const Move& move);
	
	int ArrayIndex() const;
	
	bool InRange() const;
	
	std::string& operator +(std::string& str) const;
	
	friend std::istream& operator >>(std::istream& stream, Move& move);
};