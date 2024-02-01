#pragma once

enum XO
{
	O = -1,	_ = 0,	X = 1
};

enum TerminalState
{
	InProgress= -4,
	O_Won = -3,
	Draw = 0,
	X_Won = 3
};