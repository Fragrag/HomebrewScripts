#pragma once
#include <string>
#include <map>

#define TMap std::map

using FString = std::string;
using int32 = int;
  
enum class EBetType
{
	Invalid_Status,
	Single,
	Low,
	High,
	Red,
	Black,
	Even,
	Odd,
	FirstDozen,
	SecondDozen,
	ThirdDozen,
	FirstColumn,
	SecondColumn,
	ThirdColumn
};

enum class EBetValidity
{
	Invalid_Status,
	OK,
	Not_Integer, //Variable type already goes through a check in the function
	Out_Of_Bounds
};


enum class ESingleValidity
{
	Invalid_Status,
	OK,
	Not_Integer,
	Out_Of_Bounds
};

enum class EWager
{
	Invalid_Status,
	OK,
	Not_Integer
};

class FRouletteGame
{
public:
	FRouletteGame(); // Constructor

	void Reset(); // Set starting conditions of the game

	EBetType CheckBetType(int32) const; 
	EBetValidity CheckBetValidity(int32) const;
	ESingleValidity CheckSingleValidity(int32) const;

	EBetType CheckWagerValidity(int32) const;

private:
	int32 SpinResult;
	TMap<int32, EBetType> NumberToBetType {	};

};

struct FBetSingleNumberAndType
{
	int32 Bet = 0;
	int32 Number = NULL;
	EBetType BetType = EBetType::Invalid_Status;
};