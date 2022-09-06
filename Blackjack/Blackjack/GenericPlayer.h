#pragma once
#include "Hand.h"
#include <string>

class GenericPlayer : public Hand
{
public:	
	std::string name;

	GenericPlayer(std::string name);

	virtual bool IsHitting() const = 0;

	// возвращает bool значение, есть ли у игрока перебор
	bool IsBoosted() const;
	// выводит на экран им€ игрока и объ€вл€ет, что у него перебор.
	void Bust() const;
};

