// OOP_7.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
#include <string>
#include <stdexcept> 
#include <memory>

class Date
{
public:
	Date(size_t day_, size_t month_, int year_);
	Date(Date& a);
	//Date(std::string date);
	~Date() {};
	Date(Date&& date);
	size_t get_day() const;
	size_t get_month() const;
	int get_year() const;
	void operator=(Date a);
	bool operator<(Date date) const;
	bool operator>(Date date) const;
	std::string get_date();
	friend std::ostream& operator <<(std::ostream& ss, Date date);

protected:
	size_t day;
	size_t month;
	int year;
};

Date::Date(size_t day_, size_t month_, int year_) : year(year_)
{
	if (day_ <= 31) day = day_;
	if (month_ <= 12) month = month_;
}

Date::Date(Date &a ): day(a.get_day()), month(a.get_month()), year(a.get_year()){}

void Date::operator=(Date a)
{
	this->day = a.get_day();
	this->month = a.get_month();
	this->year = a.get_year();
}

bool Date::operator<(Date date) const
{
	if (this->year < date.year) return true;
	else if (this->year == date.year)
	{
		if (this->month < date.month) return true;
		else if (this->month == date.month)
		{
			if (this->day < date.day) return true;
			else return false;
		}
		else return false;
	}
	else return false;
}
bool Date::operator>(Date date) const
{
	return !(*this < date);
}

std::ostream& operator<<(std::ostream& ss, Date date) 
{
	std::cout << date.get_date();
	return ss;
}

//Date::Date(std::string date)
//{
//	int num[3];
//	for (size_t i = 0 , j = 0; i < date.size(); i++)
//	{
//		if (date[i] == '.') 
//		{
//		try	{num[j] = (std::stoi(date.substr(0, i)), NULL, 10);}
//		catch (const std::invalid_argument& ia) { return; }
//		
//
//		}
//	}
//
//}

size_t Date::get_day() const { return day; }
size_t Date::get_month() const { return month; }
int Date::get_year() const { return year; }


std::string Date::get_date() 
{
	return std::to_string(static_cast<int>(day)) + "." + std::to_string(static_cast<int>(month)) + "." + std::to_string(year); 
}
	
 Date newest(std::unique_ptr<Date>* a, std::unique_ptr<Date>* b);
void swap_date(std::unique_ptr<Date>* a, std::unique_ptr<Date>* b);

int main()
{
	using namespace std;
	Date a(5, 9, 2022);
	unique_ptr<Date> today (new Date(a));
	cout << today.get()->get_day() <<endl ; 
	cout << today.get()->get_month() << endl;
	cout << today.get()->get_year() << endl;
	cout << today.get()->get_date() << endl;
	cout << *(today.get()) << endl;
	unique_ptr<Date> date (std::move(today));
	cout << "today pointer is " << ((today.get() == nullptr) ? ("nullptr") : ("not nullptr")) << endl;
	cout << "date pointer is " << ((date.get() == nullptr) ? ("nullptr") : ("not nullptr")) << endl;

	Date a1(5, 9, 2022);
	Date a2(4, 9, 2022);
	unique_ptr<Date> date1(new Date(a1));
	unique_ptr<Date> date2(new Date(a2));
	cout << newest(&date1, &date2) << endl;

	cout << *date1.get() << " " << *date2.get() << endl;
	swap_date(&date1, &date2);
	cout << *date1.get()<< " "<<*date2.get() << endl;

}

Date newest(std::unique_ptr<Date>* a, std::unique_ptr<Date>* b)
{
	if (*(a->get()) < *(b->get())) return *(b->get());
	else return*(a->get());
}

void swap_date(std::unique_ptr<Date>* a, std::unique_ptr<Date>* b)
{
	Date buf( *(a->get()) );
	*(a->get()) = *(b->get());
	*(b->get()) = buf;
}