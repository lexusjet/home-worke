#include "Hand.h"
#include <numeric>

Hand::Hand() {}

Hand::~Hand(){}

// add card to hande
void Hand::Add(Card* crd)
{
	hand.push_back(crd);
}

// clear hand
void Hand::Clear()
{
	hand.clear();
}

// return sum of all cards in hand  
int Hand::GetValue()
{
	auto lambda = [](int x, Card *y)  {return ( x + y->GetValue()); };
	return  std::accumulate(hand.begin(), hand.end(), static_cast <int>(0), lambda);
}

