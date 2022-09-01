#include "GenericPlayer.h"
#include <iostream>

GenericPlayer::GenericPlayer(std::string name_)
{
	name = name_;
}

// ���������� bool ��������, ���� �� � ������ �������
bool GenericPlayer::IsBoosted()
{
	return (GetValue() > 21)? (true):(false);
}

// ������� �� ����� ��� ������ � ���������, ��� � ���� �������.
void GenericPlayer::Bust()
{

	if(IsBoosted() == true)
	{
		std::cout << "the" << name << " has a bust.";
	}
}
