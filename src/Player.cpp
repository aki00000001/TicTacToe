#include "Display.h"
#include "Player.h"
#include <string>
#include <vector>

using std::vector;
using std::string;

Player::Player(char* playerName, bool autoModeEn)
{
	strcpy_s(name, playerName);
	autoModeEnable = autoModeEn;
	symbol = _;
}

void Player::SetSymbol(XO sym)
{
	symbol = sym;
}

XO Player::GetSymbol()
{
	return symbol;
}

Move Player::GetNextMove(Board* ticTacBoard)
{
	Move move = PromptPlayerForMove(name);
	return move;
}

void Player::DeclareWinner()
{
	PrompWinner(name);
}

Player::~Player()
{}
