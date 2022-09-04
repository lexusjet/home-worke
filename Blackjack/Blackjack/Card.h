#pragma once
#include "Enums.h"
#include <iostream>
#include <string>



class Card
{

private:
	int card_value;
	std::string card_suit;
	
	bool card_pos; 

public:
	Card(int a, int b, bool c);
	Card(Suit a, Value b, open_closed c);
	Card(std::string, int b, bool c);
	void Flip();
	int GetValue();
	friend std::ostream& operator<<(std::ostream &a, Card b);


};

