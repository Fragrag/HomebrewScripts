/*
Pseudocode
This project's structure will be based on UnrealCourse's BullCowGame
main.cpp will form the skeleton of the roulette game while FRouletteGame.h and FRouletteGame.cpp will be the meat.
*/

#pragma once

#include <iostream>
#include <string>
#include <sstream> // Handles strings 
#include <list>
#include "FRouletteGame.h"


// Make syntax Unreal friendly
using FText = std::string;
using int32 = int;

void PrintIntro();
void PlayGame();
FBetNumberAndType ReceiveChosenBet();
int32 ReceiveValidWager();
int32 SpinTheBall();

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
	FBetNumberAndType BetType = ReceiveChosenBet();	// ReceiveValidBet()
	int32 Wager = ReceiveValidWager();
	
	// Check result to bet and wager
	return;
}

// Receives a bet, checks its validity and returns the chosen bet, single number and type
FBetNumberAndType ReceiveChosenBet()
{
	// Prompt player to put in intro
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

	// Initialise variables
	int32 ChosenBet = 0;
	EBetValidity ChosenBetValidity = EBetValidity::Invalid_Status;
	EBetType ChosenBetType = EBetType::Invalid_Status;

	int32 ChosenSingleNumber = 0;
	ESingleValidity ChosenSingleNumberValidity = ESingleValidity::Invalid_Status;

	FString InputString = "";

	// Take input for bet type
	do 
	{
		// Get input from player in a safe way

		ChosenBet = RouletteGame.ValidatedIntInput();

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

	// If the chosen bet type is Single, prompt input for the chosen single number to bet on
	if (ChosenBetType == EBetType::Single) 
	{
		do {
			std::cout << "You have chosen to bet on a single number" << std::endl;
			std::cout << "Please choose a number between 0 and 36" << std::endl;
			
			ChosenSingleNumber = RouletteGame.ValidatedIntInput();

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

// Ask the player to input his wager
int32 ReceiveValidWager()
{
	int32 ValidWager = 0;
	
	std::cout << "Now put in your wager!";
	ValidWager = RouletteGame.ValidatedIntInput();

	return ValidWager;
}

int32 SpinTheBall() 
{
	int32 SpinResult;

	SpinResult = rand() % 37;

	return SpinResult;
}

/* TODO Work out how to compare SpinResult with ChosenBet and see winnings

So we create a function that will take in the SpinResult and creates a list of appropriate EBetTypes;
Then we look at the ChosenBet and if its EBetTypes is in the list, then we can say that the player won something.

*/
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
