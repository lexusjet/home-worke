#include "Hand.h"
#include <numeric>

void Hand::Add(Card* crd)
{
	hand.push_back(crd);
}
void Hand::Clear()
{
	hand.clear();
}
int Hand::GetValue()
{
	auto lambda = [](int x, Card *y)  {return ( x + y->GetValue()); };
	return  std::accumulate(hand.begin(), hand.end(), static_cast <int>(0), lambda);
}

