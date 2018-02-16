#pragma once
#include <string>
#include <map>
#include <array>
#include <list>
#include <vector>
#include <sstream> // Handles strings 

#define TMap std::map
#define TArray array
#define TList std::list

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

struct FBetNumberAndType
{
	int32 Bet = 0;
	int32 Number = NULL;
	EBetType BetType = EBetType::Invalid_Status;
};

class FRouletteGame
{
public:
	FRouletteGame(); // Constructor

	void Reset(); // Set starting conditions of the game
	int32 ValidatedIntInput();
	int32 CalculateWinnings(FBetNumberAndType ValidatedBet, int32 Wager);

	EBetType CheckBetType(int32) const; 
	EBetValidity CheckBetValidity(int32) const;
	ESingleValidity CheckSingleValidity(int32) const;

	void SetWinningBetTypes(int32 SpinResult);

private:
	int32 SpinResult;
	std::vector<EBetType> WinningBetTypes;
};

