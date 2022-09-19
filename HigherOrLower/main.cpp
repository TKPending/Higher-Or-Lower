#include <iostream>
#include "Glue.h"

int g_GamesPlayed{ 0 };

int main() {

	
	bool GameActive{ true };

	while (GameActive) {
		// User Chooses Difficulty
		int difficultyLevel{ GameDifficultyLevel() };
		// Difficuly Game Loads
		ActiveGame(GameDifficulty::ReturningLives(difficultyLevel), GameDifficulty::ReturningNumberLimit(difficultyLevel));
		++g_GamesPlayed;

		int afterGameDecision{ AfterGameUserDecision() };


		switch (afterGameDecision) {
		case 1:
			break;
		case 2:
			std::cout << "- - - - RECORD SECTION IS LOADING - - - - \n\n\n";
			ComputerActions::CountScore();
			break;
		default:
			std::exit(0);
			break;
		}
	} 

	

	return 0;
}