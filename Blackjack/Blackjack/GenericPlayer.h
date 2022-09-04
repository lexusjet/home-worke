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

	virtual bool IsHitting() const = 0;

	// ���������� bool ��������, ���� �� � ������ �������
	bool IsBoosted() const;
	// ������� �� ����� ��� ������ � ���������, ��� � ���� �������.
	void Bust() const;
};

