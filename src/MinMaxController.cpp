#include <vector>
#include "MinMaxController.h"
#include <time.h>

using std::vector;

typedef void (*SelectMinMaxScore)(int&, int&);
typedef void (*SelectMinMaxMove)(int&, int&, Move&, Move&);

// In future move this functions to private section of class MinMaxController.
void SelectMaxScore(int& currentScore, int& bestScore);
void SelectMinScore(int& currentScore, int& bestScore);
void SelectMaxMove(int& currentScore, int& bestScore, Move& currentMove, Move& bestMove);
void SelectMinMove(int& currentScore, int& bestScore, Move& currentMove, Move& bestMove);

Move MinMaxController::SelectBestMove(Board* ticTacBoard, XO symbol)
{
	vector<int>idx;
	idx.reserve(ticTacBoard->nAvailableMoves);
	srand(time(0));
	while ((int)idx.size() < ticTacBoard->nAvailableMoves)
	{
		bool contains = false;
		int num = rand() % ticTacBoard->nAvailableMoves;
		for (int i = 0; i < (int)idx.size() && !contains; i++)
		{
			if (idx[i] == num)
				contains = true;
		}
		if (!contains)
			idx.emplace_back(num);
	}

	vector<Move> availableMoves;
	availableMoves.reserve(9);
	ticTacBoard->GetAvailableMoves(availableMoves);
	Move bestMove{ *(availableMoves.begin()) };
	int bestScore = symbol == X ? -100 : 100;
	SelectMinMaxMove SelectMove = symbol == X ? SelectMaxMove : SelectMinMove;

	for (int i = 0; i < ticTacBoard->nAvailableMoves; i++)
	{
		int currentScore;
		Move currentMove = *(availableMoves.begin() + idx[i]);
		availableMoves.erase(availableMoves.begin() + idx[i]);
		ticTacBoard->SetMove(currentMove, symbol);

		TerminalState score = ticTacBoard->DetermineGameState();

		if (score == InProgress)
		{
			XO nextSymbol = symbol == X ? O : X;
			currentScore = MinMax(ticTacBoard, availableMoves, nextSymbol);
		}
		else
		{
			currentScore = (int)score;
		}
		SelectMove(currentScore, bestScore, currentMove, bestMove);
		ticTacBoard->RevertMove(currentMove);
		availableMoves.insert(availableMoves.begin() + idx[i], currentMove);
	}
	return bestMove;
}

int MinMaxController::MinMax(Board* ticTacBoard, vector<Move>& availableMoves, XO symbol)
{
	int bestScore = symbol == X ? -100 : 100;
	SelectMinMaxScore selectScore = symbol == X ? SelectMaxScore : SelectMinScore;

	for (int iMove = 0; iMove < ticTacBoard->nAvailableMoves; iMove++)
	{
		int currentScore;
		Move move = *(availableMoves.begin() + iMove);
		availableMoves.erase(availableMoves.begin() + iMove);

		ticTacBoard->SetMove(move, symbol);

		TerminalState score = ticTacBoard->DetermineGameState();

		if (score == InProgress)
		{
			XO nextSymbol = symbol == X ? O : X;
			currentScore = MinMax(ticTacBoard, availableMoves, nextSymbol);
			selectScore(currentScore, bestScore);
		}
		else
		{
			bestScore = (int)score;
		}

		ticTacBoard->RevertMove(move);
		availableMoves.insert(availableMoves.begin() + iMove, move);
	}
	return bestScore;
}

void SelectMaxScore(int& currentScore, int& bestScore)
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

void SelectMinScore(int& currentScore, int& bestScore)
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

void SelectMaxMove(int& currentScore, int& bestScore, Move& currentMove, Move& bestMove)
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

void SelectMinMove(int& currentScore, int& bestScore, Move& currentMove, Move& bestMove)
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
