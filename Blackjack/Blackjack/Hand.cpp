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
int Hand::GetValue() const
{
	auto lambda = [](int x, Card *y)  {return ( x + y->GetValue()); };
	return  std::accumulate(hand.begin(), hand.end(), static_cast <int>(0), lambda);
}

//return size of vector hand
size_t Hand::size() { return hand.size(); }


Card& Hand::operator[](size_t i)
{
	return *hand[i];
}

std::ostream& operator<<(std::ostream& ss, Hand hand_) 
{
	for (size_t i = 0; i < hand_.hand.size(); i++)
	{
		std::cout << hand_[i] << " ";
	}
	return ss;

}