#pragma once
#include "Hand.h"
#include <string>

class GenericPlayer : public Hand
{
protected:
	// player name
	std::string name;

public:	

	GenericPlayer(std::string name);

	virtual bool IsHitting() = 0;

	// ���������� bool ��������, ���� �� � ������ �������
	bool IsBoosted();
	// ������� �� ����� ��� ������ � ���������, ��� � ���� �������.
	void Bust();
};

