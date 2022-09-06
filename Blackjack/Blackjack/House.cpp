#include "House.h"
const size_t MAX_VALUE = 16;

//спрашивает у пользователя, нужна ли ему еще одна карта и возвращает ответ пользователя в виде true или false.
bool House::IsHitting() const 
{
	return (GetValue() < MAX_VALUE) ? (true) : (false);
}

void House::FlipFirstCard()
{
	hand[0]->Flip();
}