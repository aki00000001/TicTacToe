#include "Display.h"
#include "Player.h"

Player::Player(char* playerName, XO sym)
{
	strcpy_s(name, playerName);
	symbol = sym;
}

void Player::SetSymbol(XO sym)
{
	symbol = sym;
}

XO Player::GetSymbol() const
{
	return symbol;
}

void Player::GetNextMove(Move& outMove)
{
	PromptPlayerForMove(name, outMove);
}

void Player::DeclareWinner()
{
	PromptWinner(name);
}

Player::~Player()
{}

bool Player::operator == (const XO symbol) const
{
	return symbol == symbol;
}