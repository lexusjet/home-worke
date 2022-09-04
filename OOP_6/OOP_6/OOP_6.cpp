#include <iostream>
#include <sstream>
#include <string>
#include <climits>



int get_int()
{
	using namespace std;

	string line;
	int anser;
	do
	{
		cout << "Please enter an integer: ";

		getline(cin, line);
		if (line.size() < to_string(INT_MAX).size()) 
		{
			stringstream ss(line);
			if ((ss >> anser) && ss.eof()) return anser;
			cout << "Incorect input, please try again.\n";			
		}
		else
		{
			cout << "Too big number , the number should not be larger then " << INT_MAX << endl;	
		}
	} while (true);
}
namespace my {  
	std::ostream& endl(std::ostream& stream) 
	{ 
		stream << '\n';
		stream << '\n';
		stream.flush();
		 return stream;
	}
} 



int main()
{
	get_int();
	std::cout << "Too big number , the number should not be larger then " << my::endl << INT_MAX;
}

