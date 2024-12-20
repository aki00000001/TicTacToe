#include <iostream>
#include <gtest/gtest.h>

#include "TicTacToe.h"

int main(int argc, char** argv)
{
	if (argc > 1 && std::string("TEST") == argv[1])
	{
		testing::InitGoogleTest(&argc, argv);

		return RUN_ALL_TESTS();
	}
	else if (argc > 1 && std::string("TEST") != argv[1])
	{
		TicTacToe ticTacToe(argv);

		ticTacToe.ExecuteGameEvent();

		return 0;
	}
	else
	{
		TicTacToe ticTacToe;

		ticTacToe.ExecuteGameEvent();

		return 0;
	}
}
