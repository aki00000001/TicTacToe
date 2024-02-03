#pragma once
#include "CommonDatatypes.h"
#include "Board.h"
#include <vector>

class MinMaxController
{
private:
	Board* boardPtr;

public:
	MinMaxController(Board* ptr);

	void SelectBestMove(XO symbol, Move& outMove);

private:
	int MinMax(std::vector<Move>& availalbleMoves, XO symbol);

	int DetermineScoreForMove(std::vector<Move>& availableMoves, Move& currentMove, const XO& symbol, const int& iMove);

	void GetRandomIndexSeries(std::vector<int>& idx, const int& nAvailableMoves);

	static void SelectMaxScore(int& currentScore, int& bestScore);

	static void SelectMinScore(int& currentScore, int& bestScore);
	
	static void SelectMaxMove(int& currentScore, int& bestScore, Move& currentMove, Move& bestMove);
	
	static void SelectMinMove(int& currentScore, int& bestScore, Move& currentMove, Move& bestMove);
};
