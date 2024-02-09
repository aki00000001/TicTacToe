#include "gtest/gtest.h"
#include "CommonDatatypes.h"
#include "Player.h"
#include "Move.h"

struct PlayerFixture : public testing::Test
{
	Player* player = NULL;

	void SetUp()
	{
		char name[4] = "XYZ";
		player = new Player(name, _);
	}

	void TearDown()
	{
		delete player;
	}
};

namespace PlayerTests
{
	TEST_F(PlayerFixture, SetGetSymbolTest)
	{
		// Check by default fixture is set to _.
		EXPECT_EQ(_, player->GetSymbol());

		// Set Symbol to O and check if that is set correctly.
		player->SetSymbol(O);
		// Check if we can set O
		EXPECT_EQ(O, player->GetSymbol());

		// Set Symbol to X and check if that is set correctly.
		player->SetSymbol(X);
		// Check if we can set X
		EXPECT_EQ(X, player->GetSymbol());
	}

	TEST_F(PlayerFixture, PlayerHasSameSymbolTest)
	{
		// Check if player is initialized to _.
		EXPECT_EQ(*player, _);

		// Check if player is set to X.
		player->SetSymbol(X);
		EXPECT_EQ(*player, X);

		// Check if player is set to O.
		player->SetSymbol(O);
		EXPECT_EQ(*player, O);
	}

	TEST_F(PlayerFixture, DeclareWinnerTest)
	{
		// Generate expected output for generated winner.
		char expectedName[] = "The winner is XYZ\n";

		// Capture the actual output.
		testing::internal::CaptureStdout();
		player->DeclareWinner();
		std::string actualName = testing::internal::GetCapturedStdout();

		// Check if Declared winner is same as expected winner.
		EXPECT_EQ(expectedName, actualName);
	}

	TEST_F(PlayerFixture, PromptPlayerForTurnTest)
	{
		std::string expectedOutput = "It's XYZ's turn.\n";
		// Act on creating board class
		testing::internal::CaptureStdout();
		player->PromptPlayersTurn("XYZ");
		std::string actualOutput = testing::internal::GetCapturedStdout();

		// Assert the outcome.
		EXPECT_EQ(expectedOutput, actualOutput);
	}
}