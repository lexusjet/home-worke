#include "Card.h"

void Card::Flip()
{
    this->card_pos = !(this->card_pos);
}


int Card::GetValue() {return (this->card_value);}

Card::Card(Suit a, Value b, bool c) : card_suit(a), card_value(b) , card_pos(c) {}

Card::Card(size_t a, size_t b, bool c)
{
    if (a < 5) card_suit = a;
    if ((b > 0) && (b < 10)) card_value = b;
    card_pos = c;

}
