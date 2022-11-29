#include <iostream>
#include <cstdint>

class Power
{
public:
	Power() {};
	~Power(){};
	double calculate()
	{		
		return(pow(base_, degre_));		
	}
	void set(double bas, double degr)
	{
		base_ = bas;
		degre_ = degr;
	}

private:
	double base_;
	double degre_;
};
class RGBA
{

public:
	RGBA(std::uint8_t r = 0, std::uint8_t g = 0, std::uint8_t b = 0, std::uint8_t alpha = 255) 
	: m_red{ r }, m_green{ g }, m_blue{ b }, m_alpha{alpha}	{}
	~RGBA(){};

	void print() const 
	{
		using namespace std;
		cout << "m_red = "	 << static_cast<unsigned int>(m_red)   << endl;
		cout << "m_green = " << static_cast<unsigned int>(m_green) << endl;
		cout << "m_blue = "  << static_cast<unsigned int>(m_blue)  << endl;
		cout << "m_alpha = " << static_cast<unsigned int>(m_alpha) << endl;
	}
private:
	std::uint8_t m_red;
	std::uint8_t m_green;
	std::uint8_t m_blue;
	std::uint8_t m_alpha;
};
class Stack
{
public:
	Stack()
	{
		head = 0;
	};
	~Stack() {};
	void reset() 
	{
		memset(&arr, 0, sizeof(arr));
		head = 0;
	}
	bool push(int num) 
	{
		if (head == 10) { return false; }
		arr[head] = num;
		head++;
	}
	int pop(bool eror = false)
	{
		if (head == 0) 
		{
			eror = true;
			return 0;		
		}
		head--;
		return arr[head];
	}
	void print() 
	{
		using namespace std;
		for (size_t i = 0; i < head; i++)
		{
			cout << arr[i] << "  ";
		}
		cout << endl;
	}
private:
	int arr[10];
	size_t head;
};



int main()
{
	using namespace std;

	Power a;
	a.set(static_cast<double>(5), static_cast<double>(2));
	cout << a.calculate() << endl;

	RGBA b;
	b.print();

	Stack stack;
	stack.reset();
	stack.print();

	stack.push(3);
	stack.push(7);
	stack.push(5);
	stack.print();

	stack.pop();
	stack.print();

	stack.pop();
	stack.pop();
	stack.print();
}

