#include <iostream>
#include <map>

int main(){
	std::map <int, std::string> m1;
	m1.insert(std::make_pair	(1, "serg"));
	m1.insert(std::pair<int, std::string> (2, "alon"));
	m1.emplace(3, "daryn");

}