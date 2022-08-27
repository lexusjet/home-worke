#pragma once
#include <string>

//	Trump(Козырь)
//	Diamonds(Бубы / Алмазы)
//	Hearts(Черви / Сердца)
//	Clubs(Трефы / Клубы)
//	Spades(Пики / Лопаты)

class Card
{

private:
	enum Suit
	{
		Trump,
		Diamonds,
		Hearts,
		Clubs,
		Spades
	};

	enum Value
	{
		two = 2,
		three = 3,
		four = 4,
		five = 5,
		six = 6,
		seven = 7,
		eight = 8,
		nine = 9,
		ten = 10,
		jack = 10,
		queen = 10,
		king = 10,
		joker = 10,
		ace = 1
	};

	enum Shirt
	{
		up = true,
		down = false
	};

	Value card_value;
	Suit card_suit;
	bool card_pos;

public:
	Card(Suit a, Value b, Shirt c);
	void Flip();
	int GetValue();

};

