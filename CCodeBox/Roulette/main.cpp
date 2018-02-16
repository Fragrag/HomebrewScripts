/*
Pseudocode
This project's structure will be based on UnrealCourse's BullCowGame
main.cpp will form the skeleton of the roulette game while FRouletteGame.h and FRouletteGame.cpp will be the meat.
*/

#pragma once

#include <iostream>
#include <string>
#include "FRouletteGame.h"
#include <sstream> // Handles strings 

// Make syntax Unreal friendly
using FText = std::string;
using int32 = int;

// Prototyping functions outside a class
void PrintIntro();
void PlayGame();
FBetSingleNumberAndType ReceiveValidBet();
int32 ReceiveValidWager();
bool AskToPlayAgain();
void PrintGameSummary();

FRouletteGame RouletteGame; // Instantiate a new game, which we will re-use

int main() 
{
	PrintIntro();
	PlayGame();
		
	return 0;
}

void PrintIntro()
{
	std::cout << "Welcome" << std::endl;
	std::cout << "Let's play roulette!" << std::endl;
	std::cout << "Put in your wager and pick a bet!" << std::endl;

	return;
}

void PlayGame() // TODO Fill PlayGame()
{
	FBetSingleNumberAndType BetType = ReceiveValidBet();	// ReceiveValidBet()	
	
	// ReceiveValidWager
	// Check result to bet and wager
	return;
}

// Receives a bet, checks its validity and returns the chosen bet, single number and type
FBetSingleNumberAndType ReceiveValidBet()
{
	// Ask the player to choose the type of bet
	// Initialise variables
	EBetValidity ChosenBetValidity = EBetValidity::Invalid_Status;
	int32 ChosenBet = 0;
	FString InputString = "";

	int32 ChosenSingleNumber;
	ESingleValidity ChosenSingleNumberValidity = ESingleValidity::Invalid_Status;
	EBetType ChosenBetType = EBetType::Invalid_Status;

	std::cout << "Choose your bet!" << std::endl;
	std::cout << "1. Single" << std::endl;
	std::cout << "2. Low" << std::endl;
	std::cout << "3. High" << std::endl;
	std::cout << "4. Red" << std::endl;
	std::cout << "5. Black" << std::endl;
	std::cout << "6. Even" << std::endl;
	std::cout << "7. Odd" << std::endl;
	std::cout << "8. First dozen" << std::endl;
	std::cout << "9. Second dozen" << std::endl;
	std::cout << "10. Third dozen" << std::endl;
	std::cout << "11. First column" << std::endl;
	std::cout << "12. Second column" << std::endl;
	std::cout << "13. Third column" << std::endl;


	// Take input for bet type
	do {
		// Get input from player in a safe way
		while (true) {
			std::getline(std::cin, InputString);

			// The following lines will convert from string to number safely
			std::stringstream myStream(InputString);
			if (myStream >> ChosenBet)
				break;
			std::cout << "Invalid input, please put in a number" << std::endl;
		}

		ChosenBetValidity = RouletteGame.CheckBetValidity(ChosenBet);

		switch (ChosenBetValidity)
		{
		case EBetValidity::Out_Of_Bounds:
			std::cout << "Please enter a number between 1 and 13" << std::endl;
			break;
		case EBetValidity::Not_Integer: // Should never pop up in this version
			std::cout << "Invalid input, please put in a number" << std::endl;
			break;
		default:
			break;
		}

	} while (ChosenBetValidity != EBetValidity::OK); // Keep looping until we get no error

	ChosenBetType = RouletteGame.CheckBetType(ChosenBet);

	// Take input for the chosen single number to bet on
	if (ChosenBetType == EBetType::Single) {

		do {
			std::cout << "You have chosen to bet on a single number" << std::endl;
			std::cout << "Please choose a number between 0 and 36" << std::endl;
			while (true) {
				std::getline(std::cin, InputString);

				// The following lines will convert from string to number safely
				std::stringstream myStream(InputString);
				if (myStream >> ChosenSingleNumber)
					break;
				std::cout << "Invalid input, please put in a number" << std::endl;
			}

			ChosenSingleNumberValidity = RouletteGame.CheckSingleValidity(ChosenSingleNumber);

			switch (ChosenSingleNumberValidity)
			{
			case ESingleValidity::Out_Of_Bounds:
				std::cout << "Please enter a number between 0 and 36" << std::endl;
				break;
			case ESingleValidity::Not_Integer: // Should never pop up in this version
				std::cout << "Invalid input, please put in a number" << std::endl;
				break;
			default:
				break;
			}
		} while (ChosenSingleNumberValidity != ESingleValidity::OK);

		return { ChosenBet, ChosenSingleNumber, ChosenBetType };
	}
}

int32 ReceiveValidWager()
{
	// Ask the player to input his wager
	return 0;
}

bool AskToPlayAgain() // TODO Fill AskToPlayAgain()
{
	return false;
}

void PrintGameSummary() // TODO Fill PrintGameSummary()
{
	// In this function we will look at the bet, the wager and where the ball landed. 
	// We compare all of these values and calculate the wins and losses 
	return;
}