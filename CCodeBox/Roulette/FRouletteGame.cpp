#pragma once

#include "FRouletteGame.h"
#include <map>
#include <iostream>
#include <sstream> // Handles strings 
#include <list>

#define TMap std::map
#define TList std::list

FRouletteGame::FRouletteGame() { Reset(); } // Default constructor

void FRouletteGame::Reset()
{
	std::vector<EBetType> SpinResultBetTypes = { };
}

int32 FRouletteGame::ValidatedIntInput()
{
	FString InputString;
	int32 ValidatedInt;

	while (true) {
		//std::cout << " " << std::endl;
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

// Takes in SpinResult and goes through multiple conditions. If true add EBetType to it.
void FRouletteGame::SetSpinResultBetTypes(int32 SpinResult)
{
	// Explanation following syntax:
	// (std::find(std::begin(Red), std::end(Red), SpinResult) != std::end(Red))
	// std::find goes through the array and if it does not reach the end, then it will return true

	int Red[] = { 1, 3, 5, 7, 9, 12, 14, 16, 18, 19, 21, 23, 25, 27, 30, 32, 34, 36 };
	int Black[] = { 2, 4, 6, 8, 10, 11, 13, 15, 17, 20, 22, 24, 26, 28, 29, 31, 33, 35 };

	int Even[] = { 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32, 34, 36 };
	int Odd[] = { 1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23, 25, 27, 29, 31, 33, 35 };

	int FirstColumn[] = { 1, 4, 7, 10, 13, 16, 19, 22, 25, 28, 31, 34 };
	int SecondColumn[] = { 2, 5, 8, 11, 14, 17, 20, 23, 26, 29, 32, 35 };
	int ThirdColumn[] = { 3, 6, 9, 12, 15, 18, 21, 24, 27, 30, 33, 36 };

	// Low and high
	if (SpinResult >= 1 && SpinResult <= 18)
	{
		SpinResultBetTypes.push_back(EBetType::Low);
	}
	else {}

	if (SpinResult >= 19 && SpinResult <= 36)
	{
		SpinResultBetTypes.push_back(EBetType::High);
	}
	else {}

	// Red and black
	if (std::find(std::begin(Red), std::end(Red), SpinResult) != std::end(Red))
	{
		SpinResultBetTypes.push_back(EBetType::Red);
	}
	else {}

	if (std::find(std::begin(Black), std::end(Black), SpinResult) != std::end(Black))
	{
		SpinResultBetTypes.push_back(EBetType::Black);
	}
	else {}

	// Even and odd
	if (std::find(std::begin(Even), std::end(Even), SpinResult) != std::end(Even))
	{
		SpinResultBetTypes.push_back(EBetType::Even);
	}
	else {}

	if (std::find(std::begin(Odd), std::end(Odd), SpinResult) != std::end(Odd))
	{
		SpinResultBetTypes.push_back(EBetType::Odd);
	}
	else {}

	// Dozens
	if (SpinResult >= 1 && SpinResult <= 12)
	{
		SpinResultBetTypes.push_back(EBetType::FirstDozen);
	}
	else {}

	if (SpinResult >= 13 && SpinResult <= 24)
	{
		SpinResultBetTypes.push_back(EBetType::SecondDozen);
	}
	else {}

	if (SpinResult >= 25 && SpinResult <= 36)
	{
		SpinResultBetTypes.push_back(EBetType::ThirdDozen);
	}
	else {}

	// Columns
	if (std::find(std::begin(FirstColumn), std::end(FirstColumn), SpinResult) != std::end(FirstColumn))
	{
		SpinResultBetTypes.push_back(EBetType::FirstColumn);
	}
	else {}

	if (std::find(std::begin(SecondColumn), std::end(SecondColumn), SpinResult) != std::end(SecondColumn))
	{
		SpinResultBetTypes.push_back(EBetType::SecondColumn);
	}
	else {}

	if (std::find(std::begin(ThirdColumn), std::end(ThirdColumn), SpinResult) != std::end(ThirdColumn))
	{
		SpinResultBetTypes.push_back(EBetType::ThirdColumn);
	}
	else {}
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
