#pragma once
#include "CommonDatatypes.h"
#include "Board.h"
#include <vector>

class MinMaxController
{
public:
	Move SelectBestMove(Board* ticTacBoard, XO symbol);

private:
	int MinMax(Board* ticTacBoard, std::vector<Move>& availalbleMoves, XO symbol);
};
