#include "GenericPlayer.h"
#include <iostream>

GenericPlayer::GenericPlayer(std::string name_)
{
	name = name_;
}

// ���������� bool ��������, ���� �� � ������ �������
bool GenericPlayer::IsBoosted() const
{
	return (GetValue() > 21)? (true):(false);
}

// ������� �� ����� ��� ������ � ���������, ��� � ���� �������.
void GenericPlayer::Bust() const
{
	std::cout << "The " << name << " has a bust \n";	
}

