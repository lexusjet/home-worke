#pragma once
#include "Hand.h"
#include <string>

class GenericPlayer : public Hand
{
protected:
	// player name
	std::string name;

public:	

	GenericPlayer(std::string name);

	virtual bool IsHitting() = 0;

	// возвращает bool значение, есть ли у игрока перебор
	bool IsBoosted();
	// выводит на экран им€ игрока и объ€вл€ет, что у него перебор.
	void Bust();
};

