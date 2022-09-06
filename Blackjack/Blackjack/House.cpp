#include "House.h"
const size_t MAX_VALUE = 16;

//���������� � ������������, ����� �� ��� ��� ���� ����� � ���������� ����� ������������ � ���� true ��� false.
bool House::IsHitting() const 
{
	return (GetValue() < MAX_VALUE) ? (true) : (false);
}

void House::FlipFirstCard()
{
	hand[0]->Flip();
}