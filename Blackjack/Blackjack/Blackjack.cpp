// Blackjack.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "Hand.h"
#include "Card.h"
#include "Enums.h"


int main()
{
	Hand a;
	Card b(0, 6, true);
	a.Add(&b);
	std::cout << a.GetValue() <<std::endl; 
}


