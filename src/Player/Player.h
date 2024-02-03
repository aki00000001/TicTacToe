#pragma once

#include "CommonDatatypes.h"
#include "Display.h"
#include "Move.h"

class Player : public  Display
{
protected:
	char name[10];

	XO symbol;

public:
	Player(char* playerName, XO sym);

	void SetSymbol(XO symbol);

	XO GetSymbol() const;

	virtual void GetNextMove(Move& outMove);

	void DeclareWinner();

	virtual ~Player();

	bool operator == (const XO symbol) const;
};

