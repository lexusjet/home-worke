#pragma once
#include <vector>
#include "Card.h"

class Hand
{
public:
	std::vector<Card* > hand;

	Hand();
	~Hand();

	friend std::ostream& operator<<(std::ostream& ss, Hand hand_);

	Card& operator[](size_t i);

	// add card to hande
	void Add(Card*);

	// clear hand
	void Clear();

	// return sum of all cards in hand  
	int GetValue() const;

	size_t size();
};

