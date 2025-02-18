#include <map>
#include <string>
#include <iostream>


int main()
{
	std::pair<int, std::string> p1(1, "serg");
	std::pair<int, std::string> p2(1, "alon");

	std::cout << p1.first << "   " << p1.second << std::endl;
	std::cout << p2.first << "   " << p2.second << std::endl;

}