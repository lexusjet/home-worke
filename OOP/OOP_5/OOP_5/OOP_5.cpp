// OOP_5.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>

template< typename T > class Pair1
{
public:
	Pair1(T a, T b) : first_(a) , second_(b){};
	~Pair1(){};

	T first()	const {return first_;}
	T second()  const { return second_; }
private:
	T first_;
	T second_;
};

template <typename T1, typename T2> class Pair
{
public:
	Pair(T1 a, T2 b ): first_(a), second_(b) {};
	~Pair() {};

	T1 first()	const;
	T2 second()  const;

protected:
	T1 first_;
	T2 second_;
};
template <typename T1, typename T2> T1 Pair<T1, T2>::first() const
{
	return first_;
}
template <typename T1, typename T2> T2 Pair<T1, T2>::second() const 
{
	return second_;
}


template <typename T> class Pair <std::string , T>
{
public:
	Pair(std::string a, T b) : first_(a), second_(b) {};
	~Pair() {};

	std::string first()	const { return first_; }
	T second()  const { return second_; }

protected:
	std::string first_;
	T second_;

};

template < typename T> class StringValuePair : public Pair < std::string ,T >
{
public:
	StringValuePair(std::string a, T b) : Pair <std::string , T>(a, b) {};

};


int main()
{
	using namespace std;
		
	Pair1<int> p1(6, 9);
	cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';

	const Pair1<double> p2(3.4, 7.8);
	cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';

	Pair<int, double> p3(6, 7.8);
	cout << "Pair: " << p3.first() << ' ' << p3.second() << '\n';

	const Pair<double, int> p4(3.4, 5);
	cout << "Pair: " << p4.first() << ' ' << p4.second() << '\n';

	StringValuePair< int> svp("Amazing", 7);
	std::cout << "Pair: " << svp.first() << ' ' << svp.second() << '\n';
}


