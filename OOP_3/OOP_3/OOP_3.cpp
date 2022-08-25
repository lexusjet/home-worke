// OOP_3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include<math.h>
const double  PI = 3.1415926535;
const double rad_in_degre = 57.2958;


class Figure 
{

public:
	virtual double area() = 0;
};
class Parallelogram : public Figure 
{
protected:
	double bottom;
	double side;
	double angle_1;
	double angle_2;

public:
	Parallelogram() {};
	Parallelogram(double bot, double si,double a)
	{
		bottom = bot;
		side = si;
		angle_1 = a;
		angle_2 = 180 - a * 57.2958;
		
	}

	double area()
	{
		int area = (bottom * side) * (rad_in_degre * std::sin(angle_1));
		return area;
	}
};

class Circle : public Figure 
{
protected:
	double radius;
public:
	Circle(double rad) { radius = rad; }
	double area() 
	{
		return(PI * radius * radius);
	}

};

class Rectangle : public Parallelogram 
{
public:
	Rectangle(double bot, double si)
	{
		bottom = bot;
		side = si;
		angle_1 = 1.5708;
		angle_2 = 1.5708;
	};
	double area() 
	{
		return(bottom * side);
	}
};
class Square : public Parallelogram
{
	Square(double a) 
	{
		side = a;
		bottom = a;
		angle_1 = 1.5708;
		angle_2 = 1.5708;
	}
	double area() 
	{
		return (side * side);
	}
};
class Rhombus : public Parallelogram
{
	Rhombus(double s, double ang) 
	{
		bottom = s;
		side = s;
		angle_1 = ang;
		angle_2 = ((360 - (2 * ang * rad_in_degre)) / 2) / rad_in_degre;
	}
	double area() 
	{
		int area = (side * side) * (std::sin(angle_1) * rad_in_degre);
	}
};




class Car 
{
private:
	std::string company;
	std::string model;
public:	
	Car() 
	{
		std::cout << "Car constructor is colled " << std::endl;
	}
	Car(const char* com,const  char* mod)
	{
		company = com;
		model = mod;
	}

	Car(char* com, char* mod) 
	{
		company = com;
		model = mod;
	}
};

class PassengerCar: virtual public Car 
{
public:
	PassengerCar() 
	{	
		std::cout << "PassengerCar constructor is colled " << std::endl;	
	}

};

class Bus : virtual public Car
{
public:
	Bus()
	{
		std::cout << "Bus constructor is colled " << std::endl;
	};
};

class Minivan : public Bus, public PassengerCar
{
public:
	Minivan()  
	{
		std::cout << "Minivan constructor is colled " << std::endl;
	}

};

class Fraction
{
public:
	int numerator;
	int denominator;
	Fraction(int a, int b) 
	{
		numerator = a;
		if(b != 0) denominator = b;
	}

	Fraction operator +(Fraction a)
	{

		if (a.denominator == this->denominator)
		{
			return Fraction((this->numerator + a.numerator), this->denominator);		
		}
		else 
		{
			int new_denominator = this->denominator * a.denominator;
			int new_num = (this->numerator * (new_denominator - this->denominator)) + (a.numerator * (new_denominator - a.denominator));
			return Fraction(new_num, new_denominator);
		}
	}

	Fraction operator *(Fraction a)
	{
		return Fraction((this->numerator * a.numerator), (a.denominator * this->denominator));
	}

	Fraction operator -(Fraction a) 
	{
		if (a.denominator == this->denominator) 
		{
			return Fraction((this->numerator - a.numerator), a.denominator);
		}
		else
		{
			int new_denominator = this->denominator * a.denominator;
			int new_num = (this->numerator * (new_denominator - this->denominator)) - (a.numerator - (new_denominator - a.denominator));
			return Fraction(new_num ,new_denominator);
		}
		
	}

	Fraction operator /(Fraction a) 
	{
		 return Fraction(this->numerator * a.denominator, this->denominator * a.numerator);
	}
	
	bool operator==(Fraction a)
	{
		if (this->denominator == a.denominator) return (this->numerator == a.numerator);
		else return((this->numerator * a.denominator) == (a.numerator * this->denominator));
	}
	
	bool operator !=(Fraction a) 
	{
		return !(*this == a);
	}

	bool operator <(Fraction a) 
	{
		if (this->denominator == a.denominator) return(this->numerator < a.numerator);
		else return ((this->numerator * a.denominator ) < (a.numerator * this->denominator));
	}

	bool operator >(Fraction a) 
	{
		return !(*this < a);
	}

	bool operator <=(Fraction a) 
	{
		if (this->denominator == a.denominator) return(this->numerator <= a.numerator);
		else return ((this->numerator * a.denominator) <= (a.numerator * this->denominator));	
	}

	bool operator >=(Fraction a) 
	{		
		 return((*this < a) || (*this == a));
	}

	double print() 
	{
		return  (static_cast <double> (this->numerator) / static_cast <double>(this->denominator));
	}
};




int main()
{
	Minivan tst;
	double ss = 0.1;
	Fraction a(2, 10), b(3,10), c(4,2);

}


