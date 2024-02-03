#include <vector>
#include <time.h>
#include "MinMaxController.h"

#define score(symbol) symbol == X ? -1000 : 1000

using std::vector;

typedef void (*SelectMinMaxScore)(int&, int&);
typedef void (*SelectMinMaxMove)(int&, int&, Move&, Move&);

MinMaxController::MinMaxController(Board* ptr)
	:boardPtr(ptr)
{}

void MinMaxController::SelectBestMove(XO symbol, Move& outMove)
{
	int depth = boardPtr->nAvailableMoves;
	
	vector<int>idx;
	idx.reserve(depth);
	GetRandomIndexSeries(idx, depth);

	vector<Move> availableMoves;
	availableMoves.reserve(9);
	boardPtr->GetAvailableMoves(availableMoves);
	
	outMove                     = *(availableMoves.begin());
	int bestScore               = score(symbol);
	SelectMinMaxMove SelectMove = symbol == X ? SelectMaxMove : SelectMinMove;
	for (int i = 0; i < depth; i++)
	{
		int currentScore;
		Move currentMove;
		int score = DetermineScoreForMove(availableMoves, currentMove, symbol, idx[i]);

		if (score == (int)InProgress)
		{
			XO nextSymbol = symbol == X ? O : X;
			currentScore  = MinMax(availableMoves, nextSymbol);
		}
		else
		{
			currentScore  = score * depth;
		}
		SelectMove(currentScore, bestScore, currentMove, outMove);
		boardPtr->RevertMove(currentMove);
		availableMoves.insert(availableMoves.begin() + idx[i], currentMove);
	}
}

int MinMaxController::MinMax(vector<Move>& availableMoves, XO symbol)
{
	int depth                     = boardPtr->nAvailableMoves;
	int bestScore                 = score(symbol);
	SelectMinMaxScore selectScore = symbol == X ? SelectMaxScore : SelectMinScore;

	for (int iMove = 0; iMove < depth; iMove++)	
	{
		Move move;
		int score = DetermineScoreForMove(availableMoves, move, symbol, iMove);

		if (score == (int)InProgress)
		{
			int currentScore;
			XO nextSymbol = symbol == X ? O : X;
			currentScore  = MinMax(availableMoves, nextSymbol);

			selectScore(currentScore, bestScore);
			boardPtr->RevertMove(move);
			availableMoves.insert(availableMoves.begin() + iMove, move);
		}
		else
		{
			bestScore = score * depth;

			boardPtr->RevertMove(move);
			availableMoves.insert(availableMoves.begin() + iMove, move);
			break;
		}
	}
	return bestScore;
}

int MinMaxController::DetermineScoreForMove(vector<Move>& availableMoves, Move& currentMove, const XO& symbol, const int& iMove)
{
	currentMove = (*(availableMoves.begin() + iMove));
	availableMoves.erase(availableMoves.begin() + iMove);
	boardPtr->SetMove(currentMove, symbol);
	int score = (int)boardPtr->DetermineGameState();
	return score;
}

void MinMaxController::GetRandomIndexSeries(vector<int>& idx, const int& nAvailableMoves)
{
	srand((unsigned int)time(0));
	while ((int)idx.size() < nAvailableMoves)
	{
		bool contains = false;
		int num       = rand() % nAvailableMoves;
		for (int i = 0; i < (int)idx.size() && !contains; i++)
		{
			if (idx[i] == num)
				contains = true;
		}
		if (!contains)
			idx.emplace_back(num);
	}
}

void MinMaxController::SelectMaxScore(int& currentScore, int& bestScore)
{
	if (currentScore > bestScore)
	{
		bestScore = currentScore;
	}
	else
	{
		// Do nothing.
	}
}

void MinMaxController::SelectMinScore(int& currentScore, int& bestScore)
{
	if (currentScore < bestScore)
	{
		bestScore = currentScore;
	}
	else
	{
		// Do nothing.
	}
}

void MinMaxController::SelectMaxMove(int& currentScore, int& bestScore, Move& currentMove, Move& bestMove)
{
	if (currentScore > bestScore)
	{
		bestScore = currentScore;
		bestMove = currentMove;
	}
	else
	{
		// Do nothing.
	}
}

void MinMaxController::SelectMinMove(int& currentScore, int& bestScore, Move& currentMove, Move& bestMove)
{
	if (currentScore < bestScore)
	{
		bestScore = currentScore;
		bestMove = currentMove;
	}
	else
	{
		// Do nothing.
	}
}
