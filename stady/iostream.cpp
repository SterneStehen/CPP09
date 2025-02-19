#include <iostream>
#include <fstream>


int main(){
	std::cout << "what did you eat today?    \n";
	std::string answer;
	std::cin >> answer;

	std::cout << "\n" << answer << std::endl;

	std::ofstream file("output.txt");
	file << answer;
	file.close();
}