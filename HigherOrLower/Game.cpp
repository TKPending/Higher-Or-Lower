#include <iostream>
#include "Glue.h"

int NumberUserChoice();
constexpr int USERWIN{ 1 };
constexpr int USERLOSE{ 0 };

bool ContinueOrBreakGame(int UserNumber, int ComputerNumber) {
	return (UserNumber == ComputerNumber) ? true : false;
}

void ActiveGame(int Lives, int NumberLimit) {
	// Random number is chosen
	int generatedRandomNumber{ ComputerActions::RandomNumberGenerator(NumberLimit) };

	while (Lives != 0) {
		std::cout << "Choose a number between 1 - " << NumberLimit << ": \n";
		// User chooses a number
		int numberChosen{ NumberUserChoice() };		

		// Check if number is higher or lower
		std::cout << ComputerValidationProcess::HigherOrLower(numberChosen, generatedRandomNumber);

		// If user guesses right then break the loop
		if (ContinueOrBreakGame(numberChosen, generatedRandomNumber) == true) {
			std::cout << "\nYou guessed it right with " << Lives << " remaining\n";

			ComputerActions::AddScoreToRecord(USERWIN);
			break;
		}
		// Else decrement a life and conntinue
		else {
			--Lives;
			std::cout << "You have " << Lives << " remaining\n";
		}

		std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - \n";
	}

	// Let user know what the generated number was
	if (Lives == 0) {
		std::cout << "The number generated was: " << generatedRandomNumber << "\n\n";
		ComputerActions::AddScoreToRecord(USERLOSE);
	}
}
