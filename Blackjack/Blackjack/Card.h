#pragma once
#include "Enums.h"

class Card
{

private:
	int card_value;
	int card_suit;
	bool card_pos;

public:
	Card(size_t a, size_t b, bool c);
	Card(Suit a, Value b, bool c);
	void Flip();
	int GetValue();

};

