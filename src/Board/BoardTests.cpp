#include "gtest/gtest.h"
#include "Board.h"
#include "Move.h"
#include <iostream>

namespace
{
	TEST(BoardTests, ConstructorTest)
	{
		std::string expectedOutput =                  "\f          Col 1 | Col 2 | Col 3 \n\n";
		expectedOutput             = expectedOutput + "                |       |       \n";
		expectedOutput             = expectedOutput + "  Row 1:        |       |       \n";
		expectedOutput             = expectedOutput + "         _______|_______|_______\n";
		expectedOutput             = expectedOutput + "                |       |       \n";
		expectedOutput             = expectedOutput + "  Row 2:        |       |       \n";
		expectedOutput             = expectedOutput + "         _______|_______|_______\n";
		expectedOutput             = expectedOutput + "                |       |       \n";
		expectedOutput             = expectedOutput + "  Row 3:        |       |       \n";
		expectedOutput             = expectedOutput + "                |       |       \n";

		Board b;
		testing::internal::CaptureStdout();
		b.DisplayBoard();
		std::string actualOutput = testing::internal::GetCapturedStdout();
		
		EXPECT_EQ(expectedOutput, actualOutput);
	}

	TEST(BoardTests, SetMoveTest)
	{
		Board b;

		std::string expectedError1 =                  "Error: Row and column should be between 1 and 3.\n";
		expectedError1             = expectedError1 + "Entered move is (row, col):(0, 0)\nEnter new move.\n";

		Move m1(0, 0);
		testing::internal::CaptureStdout();
		EXPECT_FALSE(b.SetMove(m1, X));
		std::string actualError1 = testing::internal::GetCapturedStdout();
		EXPECT_EQ(expectedError1, actualError1);

		std::string expectedError2 =                  "Error: Row and column should be between 1 and 3.\n";
		expectedError2             = expectedError2 + "Entered move is (row, col):(4, 4)\nEnter new move.\n";
		Move m2(4, 4);
		testing::internal::CaptureStdout();
		EXPECT_FALSE(b.SetMove(m2, X));
		std::string actualError2 = testing::internal::GetCapturedStdout();
		EXPECT_EQ(expectedError2, actualError2);

		Move m3(2, 2);
		EXPECT_TRUE(b.SetMove(m3, X));

		std::string expectedError3 =                  "Error: Enter Rows and columns is occupied.\n";
		expectedError3             = expectedError3 + "Entered move is (row, col):(2, 2)\nEnter new move.\n";
		Move m4(2, 2);
		testing::internal::CaptureStdout();
		EXPECT_FALSE(b.SetMove(m4, O));
		std::string actualError3 = testing::internal::GetCapturedStdout();
		EXPECT_EQ(expectedError3, actualError3);
	}

	TEST(MoveTests, DetermineStateTest)
	{
		{
			Board b1;
			Move m1(1, 1);
			b1.SetMove(m1, X);

			Move m2(2, 2);
			b1.SetMove(m2, X);

			Move m3(3, 3);
			b1.SetMove(m3, X);

			TerminalState actualTerminalState = b1.DetermineGameState();
			EXPECT_EQ(X_Won, actualTerminalState);
		}
		{
			Board b2;
			Move m1(1, 1);
			b2.SetMove(m1, O);

			Move m2(2, 2);
			b2.SetMove(m2, O);

			Move m3(3, 3);
			b2.SetMove(m3, O);

			TerminalState actualTerminalState = b2.DetermineGameState();
			EXPECT_EQ(O_Won, actualTerminalState);
		}
		{
			Board b3;
			Move m1(1, 1);
			b3.SetMove(m1, X);

			Move m2(1, 2);
			b3.SetMove(m2, O);

			Move m3(1, 3);
			b3.SetMove(m3, X);

			Move m4(2, 1);
			b3.SetMove(m4, O);

			Move m5(2, 2);
			b3.SetMove(m5, O);

			Move m6(2, 3);
			b3.SetMove(m6, X);

			Move m7(3, 1);
			b3.SetMove(m7, X);

			Move m8(3, 2);
			b3.SetMove(m8, X);

			TerminalState actualTerminalState = b3.DetermineGameState();
			EXPECT_EQ(InProgress, actualTerminalState);

			Move m9(3, 3);
			b3.SetMove(m9, O);
			TerminalState actualTerminalState1 = b3.DetermineGameState();
			EXPECT_EQ(Draw, actualTerminalState1);
		}
	}

}