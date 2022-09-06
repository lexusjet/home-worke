#pragma once
#include "Hand.h"
#include <string>

class GenericPlayer : public Hand
{
public:	
	std::string name;

	GenericPlayer(std::string name);

	virtual bool IsHitting() const = 0;

	// ���������� bool ��������, ���� �� � ������ �������
	bool IsBoosted() const;
	// ������� �� ����� ��� ������ � ���������, ��� � ���� �������.
	void Bust() const;
};

