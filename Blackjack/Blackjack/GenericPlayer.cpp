#include "GenericPlayer.h"
#include <iostream>

GenericPlayer::GenericPlayer(std::string name_)
{
	name = name_;
}

// возвращает bool значение, есть ли у игрока перебор
bool GenericPlayer::IsBoosted() const
{
	return (GetValue() > 21)? (true):(false);
}

// выводит на экран им€ игрока и объ€вл€ет, что у него перебор.
void GenericPlayer::Bust() const
{

	if(IsBoosted() == true)
	{
		std::cout << "the" << name << " has a bust.";
	}
}

