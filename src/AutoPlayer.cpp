#include "AutoPlayer.h"

AutoPlayer::AutoPlayer(char* playerName, bool autoModeEn) : Player(playerName, autoModeEn)
{}

Move AutoPlayer::GetNextMove(Board* ticTacBoard)
{
	PromptPlayersTurn(name);

	Move bestMove = SelectBestMove(ticTacBoard, symbol);

	return bestMove;
}
