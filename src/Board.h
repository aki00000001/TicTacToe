#pragma once
#include "CommonDatatypes.h"
#include <vector>
#include "Display.h"

class Board : public Display
{
private:
	XO brd[3 * 3];
	int nAvailableMoves;

public:
	Board();

	bool SetMove(Move& move, XO symbol);

	void DisplayBoard();

	TerminalState DetermineGameState();

private:
	bool CheckIfMoveValid(Move& move);

	bool CheckMoveAvailability(Move& move);

	std::vector<Move> GetAvailableMoves();

	void RevertMove(Move& move);

	friend class MinMaxController;
};