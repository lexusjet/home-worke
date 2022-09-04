// Blackjack.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "Hand.h"


int main()
{
	SetConsoleOutputCP(CP_UTF8);
	setvbuf(stdout, nullptr, _IOFBF, 1000);

	Hand a;
	Card b(diamonds, two, open);
	Card c(spades, king, open );

	a.Add(&b);

	std::cout << b  <<" " << c << std::endl;



}


