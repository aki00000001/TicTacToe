#pragma once
#include "CommonDatatypes.h"
#include "Board.h"
#include "Player.h"
#include "MinMaxController.h"

class TicTacToe
{
private:
	Board board;
	Player* players[2];
	TerminalState gameState;
	Player* currentPlayer;
	MinMaxController controller;

public:
	TicTacToe();

	void ExecuteGameEvent();

	void RunGameCycle();

	~TicTacToe();
private:
	XO GetRandomSymbol();
};
