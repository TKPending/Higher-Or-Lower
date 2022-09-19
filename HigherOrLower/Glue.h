#pragma once

extern int g_GamesPlayed;

// COMPUTER CHOICES FILES

// Game Difficulty
namespace GameDifficulty {

	int ReturningLives(int DifficultyLevel);

	int ReturningNumberLimit(int DifficultyLevel);
}

namespace ComputerActions {
	int RandomNumberGenerator(int GeneratedNumberLimit);

	void AddScoreToRecord(int Result);

	void CountScore();

}

namespace ComputerValidationProcess {
	std::string HigherOrLower(int UserGuess, int GeneratedNumber);

}

// GAME FILES

// Check if user guessed right
bool ContinueOrBreakGame(int UserNumber, int ComputerNumber);

// Game logic
void ActiveGame(int Lives, int NumberLimit);



// USER CHOICE FILES

int GameDifficultyLevel();

int NumberUserChoice();

int AfterGameUserDecision();
