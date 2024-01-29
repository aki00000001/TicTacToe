#pragma once
#include "CommonDatatypes.h"
#include "Board.h"
#include "Player.h"

class TicTacToe
{
private:
	Board board;
	Player* players[2];
	TerminalState gameState = InProgress;
	Player* currentPlayer = NULL;

public:
	TicTacToe();

	void ExecuteGameEvent();

	void RunGameCycle();

private:
	void DeterminePlayerSymbol();

	void SetCurrentPlayerForTurn();
};
