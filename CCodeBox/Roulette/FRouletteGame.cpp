#pragma once

#include "FRouletteGame.h"
#include <map>

#define TMap std::map

FRouletteGame::FRouletteGame() { Reset(); } // Default constructor

void FRouletteGame::Reset()
{
	SpinResult = rand() % 37; // Spins the wheel and chooses and random number in between 0 and 36
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
	if (!(Bet >= 1 && Bet <= 13)) // If bet is not in between 1 and 13
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


