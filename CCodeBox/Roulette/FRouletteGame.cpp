#pragma once

#include "FRouletteGame.h"
#include <map>
#include <iostream>
#include <sstream> // Handles strings 

#define TMap std::map

FRouletteGame::FRouletteGame() { Reset(); } // Default constructor

void FRouletteGame::Reset() //TODO Check if this is at all necessary
{
	SpinResult = rand() % 37; // Spins the wheel and chooses and random number in between 0 and 36
}

int32 FRouletteGame::ValidatedIntInput()
{
	FString InputString;
	int32 ValidatedInt;

	while (true) {
		std::getline(std::cin, InputString);

		// The following lines will convert from string to number safely
		std::stringstream myStream(InputString);
		if (myStream >> ValidatedInt)
			break;
		std::cout << "Invalid input, please put in a number" << std::endl;
	}

	return ValidatedInt;
}

int32 FRouletteGame::CalculateWinnings(FBetNumberAndType ValidatedBet, int32 Wager)
{
	int32 Winnings;

	ValidatedBet.Bet;
	ValidatedBet.BetType;
	ValidatedBet.Number;
	Wager;

	if (ValidatedBet.BetType == EBetType::Single)
	{
		Winnings = Wager * 36;
	}
	else if (ValidatedBet.BetType == EBetType::Low || ValidatedBet.BetType == EBetType::High)
	{
		Winnings = Wager * 2;
	}
	else if (ValidatedBet.BetType == EBetType::FirstDozen || ValidatedBet.BetType == EBetType::SecondDozen || ValidatedBet.BetType == EBetType::ThirdDozen)
	{
		Winnings = Wager * 3;
	}
	else if (ValidatedBet.BetType == EBetType::FirstColumn || ValidatedBet.BetType == EBetType::SecondColumn || ValidatedBet.BetType == EBetType::ThirdColumn)
	{
		Winnings = Wager * 3;
	}
	else 
	{
		Winnings = 0;
	}
	return Winnings;
}

// Take in a bet and return it's Validity
EBetValidity FRouletteGame::CheckBetValidity(int32 Bet) const
{
	if (!(Bet >= 1 && Bet <= 13)) // If bet is not in between 1 and 13
	{
		return EBetValidity::Out_Of_Bounds;
	}
	else
	{
		return EBetValidity::OK;
	}
}

ESingleValidity FRouletteGame::CheckSingleValidity(int32 Bet) const
{
	if (!(Bet >= 0 && Bet <= 36)) // If bet is not in between 1 and 13
	{
		return ESingleValidity::Out_Of_Bounds;
	}
	else
	{
		return ESingleValidity::OK;
	}
}

// Take in a validated bet and return its type
EBetType FRouletteGame::CheckBetType(int32 ValidatedBet) const
{
	// Define TMap of BetTypes
	TMap<int32, EBetType> NumberToBetType
	{
	{ 0, EBetType::Invalid_Status },
	{ 1, EBetType::Single },
	{ 2, EBetType::Low },
	{ 3, EBetType::High },
	{ 4, EBetType::Red },
	{ 5, EBetType::Black },
	{ 6, EBetType::Even },
	{ 7, EBetType::Odd },
	{ 8, EBetType::FirstDozen },
	{ 9, EBetType::SecondDozen },
	{ 10, EBetType::ThirdDozen },
	{ 11, EBetType::FirstColumn },
	{ 12, EBetType::SecondColumn },
	{ 13, EBetType::ThirdColumn },
	};

	EBetType BetType = EBetType::Invalid_Status;
	BetType = NumberToBetType[ValidatedBet];

	return BetType;
}
