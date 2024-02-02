#include "AutoPlayer.h"

AutoPlayer::AutoPlayer(char* playerName, XO sym, MinMaxController* controllerPtr) : Player(playerName, sym)
{
	controller = controllerPtr;
}

void AutoPlayer::GetNextMove(Move& outMove)
{
	PromptPlayersTurn(name);
	controller->SelectBestMove(symbol, outMove);
}

AutoPlayer::~AutoPlayer()
{}