#include "Card.h"


void Card::Flip()
{
    this->card_pos = !(this->card_pos);
}


int Card::GetValue()
{
    return this->card_value;
}

Card::Card(Suit a, Value b, Shirt c)
{
	this->card_suit = a;
	this->card_value = b;
	this->card_pos = c;
}