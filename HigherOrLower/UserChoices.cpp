#include <iostream>

// Choose Difficulty
bool DifficultyMediumCheck(int UserChoice) {
	return (UserChoice == 2) ? true : false;
}

int MediumDifficultyLevel() {
	std::cout << "\nDo you want to do:\n\n";
	std::cout << "1 - 100 with 3 Guesses [1]\n1 - 1000 with 5 Guesses [2]\n\n";
	std::cout << "Answer: ";
	int userDecision{};
	std::cin >> userDecision;

	return (userDecision == 1) ? 4 : 5;
}

int MediumDifficultyProcess(int NumberChosen) {
	bool mediumDecision{DifficultyMediumCheck(NumberChosen)};

	return (mediumDecision) ? MediumDifficultyLevel() : NumberChosen;
}

int GameDifficultyLevel() {
	std::cout << "\nWhat level do you want to play at: \n";
	std::cout << "Easy [1]\nMedium [2]\nHard [3]\n\n";
	std::cout << "Answer: ";
	int userDecision{};
	std::cin >> userDecision;

	userDecision = MediumDifficultyProcess(userDecision);

	return userDecision;
}

// Choose a number
int NumberUserChoice() {
	std::cout << "\nAnswer: ";
	int NumberChosen{};
	std::cin >> NumberChosen;

	return NumberChosen;
}

// After game decision
int AfterGameUserDecision() {
	std::cout << "\nDo you want to: \n";
	std::cout << "Play Again [1]\nCheck your record[2]\nExit[3]\n";

	std::cout << "\nAnswer: ";
	int decisionAnswer{};
	std::cin >> decisionAnswer;

	return decisionAnswer;
}

