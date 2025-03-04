#include <iostream>
#include <sstream>


int main(){
	std::string input = "48 19 33";

	int a;
	int b;
	std::istringstream iss(input);
	iss >> a >> b;

	std::cout << "a = " << a << " b = " << b << std::endl;
}