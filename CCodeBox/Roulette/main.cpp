#pragma once

#include <iostream>
#include <string>
#include <sstream> // Handles strings 
#include <list>
#include <time.h>
#include "FRouletteGame.h"

/*
First working version of roulette

TODO Make game out of this

Do this by adding a budget, persistantly keeping winnings and losses through each session.

TODO Make a chance simulator out of this

Do this by have it loop automatically, keep wins, losses, bet types... And calculate statistics
*/

// Make syntax Unreal friendly
using FText = std::string;
using int32 = int;

void PrintIntro();
void PlayGame();
FBetNumberAndType ReceiveChosenBet();
int32 ReceiveValidWager();
int32 SpinTheWheel();

bool AskToPlayAgain();

int32 CheckVictory(FBetNumberAndType ChosenBet, int32 Wager, int32 SpinResult, std::vector<EBetType> SpinResultBytes);

FRouletteGame RouletteGame; // Instantiate a new game, which we will re-use

int main() 
{
	bool bPlayAgain = false;
	do 
	{
	PrintIntro();
	PlayGame();
	bPlayAgain = AskToPlayAgain();
	} while (bPlayAgain);
		
	return 0;
}

void PrintIntro()
{
	std::cout << "" << std::endl;
	std::cout << "Welcome" << std::endl;
	std::cout << "Let's play roulette!" << std::endl;
	std::cout << "Put in your wager and pick a bet!" << std::endl;
	std::cout << "" << std::endl;

	return;
}

void PlayGame()
{
	int32 Winnings = 0;
	RouletteGame.Reset();
	FBetNumberAndType ChosenBet = ReceiveChosenBet();	// ReceiveValidBet()
	int32 Wager = ReceiveValidWager();
	int32 SpinResult = SpinTheWheel();
	
	RouletteGame.SetSpinResultBetTypes(SpinResult);
	std::cout << "" << std::endl;
	std::cout << "The spin result is " << SpinResult << std::endl;
	std::vector<EBetType> SpinResultBetTypes = RouletteGame.SpinResultBetTypes;

	Winnings = CheckVictory(ChosenBet, Wager, SpinResult, SpinResultBetTypes);

	std::cout << "" << std::endl;
		
	return;
}

// Receives a bet, checks its validity and returns the chosen bet, single number and type
FBetNumberAndType ReceiveChosenBet()
{
	// Prompt player to put in intro
	std::cout << "" << std::endl;
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
	std::cout << "" << std::endl;

	// Initialise variables
	int32 ChosenBet = 0;
	EBetValidity ChosenBetValidity = EBetValidity::Invalid_Status;
	EBetType ChosenBetType = EBetType::Invalid_Status;

	int32 ChosenNumber = 0;
	ESingleValidity ChosenNumberValidity = ESingleValidity::Invalid_Status;

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
			
			ChosenNumber = RouletteGame.ValidatedIntInput();

			ChosenNumberValidity = RouletteGame.CheckSingleValidity(ChosenNumber);

			switch (ChosenNumberValidity)
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
		} while (ChosenNumberValidity != ESingleValidity::OK);

		return { ChosenBet, ChosenNumber, ChosenBetType };
	}
	else 
	{
		return { ChosenBet, NULL, ChosenBetType };
	}
}

// Ask the player to input his wager
int32 ReceiveValidWager()
{
	int32 ValidWager = 0;
	
	std::cout << "Now put in your wager!: ";
	ValidWager = RouletteGame.ValidatedIntInput();

	return ValidWager;
}

int32 SpinTheWheel() 
{
	int32 SpinResult;

	srand(time(NULL)); // Set random seed as based on time
	SpinResult = rand() % 37;

	return SpinResult;
}

bool AskToPlayAgain() 
{
	std::cout << "Do you want to play again? (y/n)";
	FText Response = "";
	std::getline(std::cin, Response);
	return (Response[0] == 'y') || (Response[0] == 'Y');
}

int32 CheckVictory(FBetNumberAndType ChosenBet, int32 Wager, int32 SpinResult, std::vector<EBetType> SpinResultBetTypes)
{
	int32 Winnings = 0;

	if (ChosenBet.BetType == EBetType::Single)	// If the ChosenBetType is Single,
	{
		if (ChosenBet.Number == SpinResult)		// then we compare the ChosenNumber with the SpinResult
		{
			Winnings = RouletteGame.CalculateWinnings(ChosenBet, Wager);	// If it's the same, jackpot!
			std::cout << "You win!" << std::endl;
			std::cout << "You wagered " << Wager << std::endl;
			std::cout << "And you won " << Winnings << std::endl;
		}
		else
		{
			Winnings = 0;	// If it's not, loss
			std::cout << "You lost!" << std::endl;
			std::cout << "You wagered " << Wager << std::endl;
			std::cout << "And you won " << Winnings << std::endl;
		}
	}
	else // Else we have to compare the ChosenBetType to SpinResultBetTypes
	{
		if (std::find(std::begin(SpinResultBetTypes), std::end(SpinResultBetTypes), ChosenBet.BetType) != std::end(SpinResultBetTypes)) // if the former is in the latter, it is a win
		{
			Winnings = RouletteGame.CalculateWinnings(ChosenBet, Wager); // We calculate the winnings then
			std::cout << "You win!" << std::endl;
			std::cout << "You wagered " << Wager << std::endl;
			std::cout << "And you won " << Winnings << std::endl;
		}
		else
		{
			Winnings = 0;	// Else, it's a loss
			std::cout << "You lost!" << std::endl;
			std::cout << "You wagered " << Wager << std::endl;
			std::cout << "And you won " << Winnings << std::endl;
		}
	}
	return Winnings;
}
