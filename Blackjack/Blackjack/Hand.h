#pragma once
#include <vector>
#include "Card.h"

class Hand
{
protected:
	std::vector<Card* > hand;
public:
	Hand();
	~Hand();
	// add card to hande
	void Add(Card*);

	// clear hand
	void Clear();

	// return sum of all cards in hand  
	int GetValue() const;

};

