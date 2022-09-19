#include <iostream>
#include <random>
#include <chrono>
#include "Glue.h"

// Game Difficulty
namespace GameDifficulty {

	// Easy Game (1-100 5 Lives)  - [1] 
	// Medium Game (1-100 3 Lives or 1-1000 5 Lives)  - [4] and [5] 
	// Hard Game (1-1000 3 Lives) - [3]

	int ReturningLives(int DifficultyLevel) {
		switch (DifficultyLevel) {
		case 1: case 5:
			std::cout << "5 Lives\n";
			return 5;
			break;
		case 3: case 4:
			std::cout << "3 Lives\n";
			return 3;
			break;
		default:
			return 0;
			break;
		}
	}

	int ReturningNumberLimit(int DifficultyLevel) {
		switch (DifficultyLevel) {
		case 1: case 4:
			std::cout << "\n\n100 Limit\n";
			return 100;
			break;
		case 3: case 5:
			std::cout << "1000 Limit\n";
			return 1000;
			break;
		default:
			return 0;
			break;
		}

		// Last Life Game Question

	}
}

namespace ComputerActions {
	// Generate a random number
	int RandomNumberGenerator(int GeneratedNumberLimit) {
		// Chooses a random number using chrono as the seed
		std::mt19937 mt{ static_cast<unsigned int>(
		std::chrono::steady_clock::now().time_since_epoch().count()
		) };

		// Allows for a good random number choice selection
		std::uniform_int_distribution GeneratedNumber{ 1, GeneratedNumberLimit };

		return GeneratedNumber(mt);
	}

	// Print record

	int g_Games[20];
	int GAMEAMOUNTLIMIT{ sizeof(g_Games) / sizeof(g_Games[0])};

	void AddScoreToRecord(int Result) {
		if (g_GamesPlayed == 0) {
			g_Games[0] = Result;
		}
		else {
			g_Games[g_GamesPlayed] = Result;
		}
	}

	void CountScore() {
		int gamesWon{ 0 };

		// Loop through the games array
		for (int i = 0; i < GAMEAMOUNTLIMIT; i++) {
			// Find how many games have been won
			if (g_Games[i] == 1) {
				++gamesWon;
			}
		}

		std::cout << "You have won " << gamesWon << " / " << g_GamesPlayed << std::endl;
	}
	

	// Exit
}

namespace ComputerValidationProcess {
	// Higher or Lower 
	std::string HigherOrLower(int UserGuess, int GeneratedNumber) {
		if (UserGuess == GeneratedNumber) {
			std::cout << "The Random Number Was: " << GeneratedNumber << "\n";
			return "\nYou guessed it right";
		}
		else {
			return (UserGuess > GeneratedNumber) ? "- - - > Lower < - - -\n\n" : "- - - > Higher < - - -\n\n";
		}
	}

}

