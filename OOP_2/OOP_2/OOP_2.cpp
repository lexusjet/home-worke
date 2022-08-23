#include <iostream>
#include <string>

class Person
{
public:
	Person() {};
	Person( char * f_name, char* s_name, bool gen, size_t ag, size_t weig) 
	{
		first_name = f_name;
		second_name = s_name;
		age = ag;
		weight = weig;
		if (gen) gender = "male";
		else gender = "female";
	}
	~Person(){};

	void change_weight(int w) { weight = w;}
	void change_age(int ag) { age = ag; }


protected:
	std::string first_name;
	std::string second_name;
	std::string gender;
	size_t age;
	size_t weight;

};

class Student: public Person
{
public:
	Student() 
	{
		if (amount == 0) amount = 1;
		else amount++;

	};
	
	Student (char* f_name , char* s_name, bool gen = false, size_t ag = 0, size_t weig = 0, int ed_ye = 0)
	{
		if (amount == 0) amount = 1;
		else amount++;

		first_name = f_name;
		second_name = s_name;
		age = ag;
		weight = weig;
		if (gen) gender = "male";
		else gender = "female";
		year_of_education = ed_ye;

	}
	~Student() {};
	void change_year(size_t year) 
	{
		if (year < 0) return;
		year_of_education = year;
	}
	void year_increase (size_t num) 
	{
		if (num < 0) return;		
		year_of_education += num;
	}

	void print_data() 
	{
		using namespace std; 
		cout << " name: " << first_name << endl;
		cout << "second name: "<< second_name << endl;
		cout << "gender: "<< gender << endl;
		cout << "age: "<< age << endl;
		cout << "weight: "<< weight << endl;
		cout << "year of education:"<< year_of_education << endl;
		cout << "amount of students: " << amount << endl;
		cout << endl;
	}


	int get_amount() { return amount; }
private:
	size_t year_of_education;
	static int amount;

};

class Fruit 
{
public :
	std::string getName() { return name; }
	std::string getColor() { return color; }
protected:
	std::string name;
	std::string color;
};
class Apple : public Fruit 
{
public:
	Apple() 
	{
		name = "apple";
	}
	Apple(const char * clr)
	{
		name = "apple";
		color = clr;
	}
};
class Banana : public Fruit
{

public:
	Banana()
	{ 
		name = "banan";
		color = "yellow"; 
	}


};

class GrannySmith : public Apple 
{
public:
	GrannySmith() 
	{
		name = "apple";
		color = "green";
	}
};

int Student::amount = 0;

int main()
{
	char name[] = "alex";
	char second[] = "smirnof";
	Student pop(name, second, true, 15, 42, 1);
	pop.print_data();

	Apple a("red");
	Banana b;
	GrannySmith c;

	std::cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
	std::cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
	std::cout << "My " << c.getName() << " is " << c.getColor() << ".\n";

}

