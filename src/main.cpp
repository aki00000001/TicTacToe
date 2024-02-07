#include <iostream>
#include <gtest/gtest.h>
#include "TicTacToe.h"

#define RUN_TESTS true

int main(int argc, char** argv)
{
#if RUN_TESTS

	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();

#else

	{
		TicTacToe ticTacToe;

		ticTacToe.ExecuteGameEvent();
	}

	std::cin.get();

#endif
}