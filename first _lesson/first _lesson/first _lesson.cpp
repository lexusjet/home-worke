// first _lesson.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>


// 4-е здание
struct croses_zeros
{
	enum figure {cros = 'x' , zero = 'o', vd =' ', line_horis ='_', line_vrt = '|'};
	char feeld[3][3];

};


// 5-е здание
struct flags
{

	unsigned int is_int : 1;
	unsigned int is_flout : 1;
	unsigned int is_rex : 1; 

	flags()
	{
		is_int = 0;
		is_flout = 0;
		is_rex = 0;
	}
	
};

struct MyVariant
{
public:
	MyVariant()
	{
		num.first = 0;
		characteristic.is_int = 1;
	}


	union MyData {int first; float second; char rex;};
	flags characteristic;
	MyData num;



public:
	void operator= (int term)
	{
		num.first = term;
		characteristic.is_int = 1;
		characteristic.is_flout = 0;
		characteristic.is_rex = 0;
	}
	void operator=(float term)
	{
		num.second = term;
		characteristic.is_int = 0;
		characteristic.is_flout = 1;
		characteristic.is_rex = 0;
	}
	void operator=(char term)
	{
		num.rex = term;
		characteristic.is_int = 0;
		characteristic.is_flout = 0;
		characteristic.is_rex = 1;
	}

	void show_status()
	{
		if(characteristic.is_int == 1){
			std::cout << "int " << num.first << std::endl;
		}
		else{
			if(characteristic.is_flout == 1){
				std::cout << "float " << num.second << std::endl;
			}
			else{
				if(characteristic.is_rex == 1){
					std::cout << "char " << num.rex << std::endl;
				}
			}
		}
	}
};



int _tmain(int argc, _TCHAR* argv[])
{
	// 1-ое задание 
	int a = 36;
	short int b = 1 ;
	long long c = 1;
	char d = 'x';
	bool e = true;
	float j = 1.01;
	double z = 4.33;

	// 2-ое задание 
	enum figure {cros = 'x' , zero = 'o', vd =' ', line_horis ='_', line_vrt = '|'};
	
	//3-е задание
	char feeld[3] = {cros};

	//5-е задание
	
	MyVariant Lord;

	Lord.num.first= a;
	Lord.characteristic.is_flout = 0;
	Lord.characteristic.is_int = 1;
	Lord.characteristic.is_rex = 0;

	Lord.num.second = d;
	Lord.characteristic.is_flout = 1;
	Lord.characteristic.is_int = 0;
	Lord.characteristic.is_rex = 0;


	int r;
	std::cin >> r;
	return 0;
}
