#pragma once
#include "CommonDatatypes.h"
#include "Board.h"

class MinMaxController
{
public:
	Move SelectBestMove(Board* ticTacBoard, XO symbol);

private:
	int MinMax(Board* ticTacBoard, XO symbol);
};
