#pragma once
#include <vector>
#include "CommonDatatypes.h"
#include "Display.h"

class Board : public Display
{
private:
	XO brd[3 * 3];

	int nAvailableMoves;

public:
	Board();

	bool SetMove(const Move& move, const XO symbol);

	void DisplayBoard();

	TerminalState DetermineGameState();

private:
	bool CheckMoveValidity(const Move& move);

	bool CheckMoveAvailability(const Move& move);

	void GetAvailableMoves(std::vector<Move>& outAvailableMove);

	void RevertMove(const Move& move);

	friend class MinMaxController;

	friend class BoardPrivateMethodTest;
};