#pragma once
#include <vector>
#include "Card.h"

class Hand
{
	std::vector<Card* > hand;
public:
	void Add(Card*);
	void Clear();
	int GetValue();

};

