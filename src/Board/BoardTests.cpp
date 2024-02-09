#include "gtest/gtest.h"
#include "Board.h"
#include "Move.h"
#include <iostream>

class BoardPrivateMethodTest
{
public:
	void GetAvailableMoves(Board* board, std::vector<Move> &outAvailableMoves)
	{
		board->GetAvailableMoves(outAvailableMoves);
	}

	void RevertMove(Board* board, Move &move)
	{
		board->RevertMove(move);
	}
};

struct BoardFixture : public testing::Test
{
	Board* b = NULL;
	std::vector<Move> moves;

	void SetUp()
	{
		b = new Board();
		moves.reserve(11);
		moves.emplace_back(Move(0, 0));
		moves.emplace_back(Move(1, 1));
		moves.emplace_back(Move(1, 2));
		moves.emplace_back(Move(1, 3));
		moves.emplace_back(Move(2, 1));
		moves.emplace_back(Move(2, 2));
		moves.emplace_back(Move(2, 3));
		moves.emplace_back(Move(3, 1));
		moves.emplace_back(Move(3, 2));
		moves.emplace_back(Move(3, 3));
		moves.emplace_back(Move(4, 4));
	}

	void TearDown()
	{
		delete b;
	}
};

namespace BoardTests
{
	TEST_F(BoardFixture, ConstructorTest)
	{
		// Arrange Expected output.
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

		// Act on creating board class
		testing::internal::CaptureStdout();
		b->DisplayBoard();
		std::string actualOutput = testing::internal::GetCapturedStdout();
		
		// Assert the outcome.
		EXPECT_EQ(expectedOutput, actualOutput);
	}

	TEST_F(BoardFixture, SetLowerOutOfRangeMoveTest)
	{
		// Arrange expected value.
		std::string expectedError = "Error: Row and column should be between 1 and 3.\n";
		expectedError             = expectedError + "Entered move is (row, col):(0, 0)\nEnter new move.\n";

		// Set out of bound move and capture output.
		testing::internal::CaptureStdout();
		bool actualOutputSetMove = b->SetMove(moves[0], X);
		std::string actualError  = testing::internal::GetCapturedStdout();

		// Check if set move failed and output of failure is as expected.
		EXPECT_FALSE(actualOutputSetMove);
		EXPECT_EQ(expectedError, actualError);
	}

	TEST_F(BoardFixture, SetHigherOutOfRangeMoveTest)
	{
		// Arrange expected value.
		std::string expectedError =                 "Error: Row and column should be between 1 and 3.\n";
		expectedError             = expectedError + "Entered move is (row, col):(4, 4)\nEnter new move.\n";
		
		// Set out of bound move and capture output.
		testing::internal::CaptureStdout();
		bool actualOutputSetMove = b->SetMove(moves[10], X);
		std::string actualError  = testing::internal::GetCapturedStdout();

		// Check if set move failed and output of failure is as expected.
		EXPECT_FALSE(actualOutputSetMove);
		EXPECT_EQ(expectedError, actualError);
	}

	TEST_F(BoardFixture, SetPreOccupiedMoveTest)
	{
		// Arrange expected value.
		std::string expectedError =                 "Error: Enter Rows and columns is occupied.\n";
		expectedError             = expectedError + "Entered move is (row, col):(2, 2)\nEnter new move.\n";

		// Set pre-occupied move and capture output.
		b->SetMove(moves[5], X);
		testing::internal::CaptureStdout();
		bool actualOutputSetMove = b->SetMove(moves[5], O);
		std::string actualError  = testing::internal::GetCapturedStdout();

		// Check if set move failed and output of failure is as expected.
		EXPECT_FALSE(actualOutputSetMove);
		EXPECT_EQ(expectedError, actualError);
	}

	TEST_F(BoardFixture, SetCorrectMoveTest)
	{
		// Set valid move and capture it's status.
		bool outputSetMove = b->SetMove(moves[1], X);

		// Check provided move was set correctly.
		EXPECT_TRUE(outputSetMove);
	}

	TEST_F(BoardFixture, DetermineXwonStateTest)
	{
		b->SetMove(moves[1], X);
		b->SetMove(moves[5], X);
		b->SetMove(moves[9], X);

		TerminalState actualTerminalState = b->DetermineGameState();
		EXPECT_EQ(X_Won, actualTerminalState);
	}
	
	TEST_F(BoardFixture, DetermineOwonStateTest)
	{
		b->SetMove(moves[1], O);
		b->SetMove(moves[5], O);
		b->SetMove(moves[9], O);

		TerminalState actualTerminalState = b->DetermineGameState();
		EXPECT_EQ(O_Won, actualTerminalState);
	}
	
	TEST_F(BoardFixture, DetermineInProgressStateTest)
	{
		TerminalState actualTerminalState = b->DetermineGameState();
		EXPECT_EQ(InProgress, actualTerminalState);
	}
	
	TEST_F(BoardFixture, DetermineDrawStateTest)
	{
		b->SetMove(moves[1], X);
		b->SetMove(moves[2], O);
		b->SetMove(moves[3], X);
		b->SetMove(moves[4], O);
		b->SetMove(moves[5], O);
		b->SetMove(moves[6], X);
		b->SetMove(moves[7], X);
		b->SetMove(moves[8], X);
		b->SetMove(moves[9], O);
		TerminalState actualTerminalState1 = b->DetermineGameState();
		EXPECT_EQ(Draw, actualTerminalState1);
	}

	TEST_F(BoardFixture, GetAvailableMoveTest)
	{
		BoardPrivateMethodTest testClass;
		std::vector<Move> availableMoves;
		availableMoves.reserve(9);

		b->SetMove(moves[1], X);
		b->SetMove(moves[2], O);
		b->SetMove(moves[3], X);
		b->SetMove(moves[4], O);
		b->SetMove(moves[5], X);
		b->SetMove(moves[6], O);
		b->SetMove(moves[7], X);
		b->SetMove(moves[8], O);

		testClass.GetAvailableMoves(b, availableMoves);

		EXPECT_EQ(1, availableMoves.size());
		EXPECT_EQ(moves[9], availableMoves[0]);
	}

	TEST_F(BoardFixture, RevertMoveTest)
	{
		BoardPrivateMethodTest testClass;
		std::vector<Move> availableMoves;
		availableMoves.reserve(9);

		b->SetMove(moves[1], X);
		b->SetMove(moves[2], O);

		testClass.RevertMove(b, moves[1]);

		testClass.GetAvailableMoves(b, availableMoves);

		EXPECT_EQ(moves[1], availableMoves[0]);
	}

	TEST_F(BoardFixture, PromptDrawTest)
	{
		std::string expectedOutput = "It's a draw \n";
		// Act on creating board class
		testing::internal::CaptureStdout();
		b->PromptDraw();
		std::string actualOutput = testing::internal::GetCapturedStdout();

		// Assert the outcome.
		EXPECT_EQ(expectedOutput, actualOutput);
	}
}
