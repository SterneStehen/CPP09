#include <iostream>
#include <map>

int main(){
	std::map <int, std::string> m1;
	m1.emplace(4, "nik");
	m1.insert(std::make_pair	(1, "serg"));
	m1.insert(std::pair<int, std::string> (2, "alon"));
	m1.emplace(3, "daryn");
	

	for (size_t i = 1; i < 4; i++)
	{
		auto it = m1.find(i);
		std::cout << it->first << "  " << it->second << std::endl;
	}
	for (auto it = m1.begin(); it != m1.end(); it++)
	{
		std::cout << it->first << "  " << it->second << std::endl;
	}

	std::map <int, std::string>::iterator it = m1.find(3);
	if(it != m1.end())
		std::cout << it->first << "  " << it->second << std::endl;
	else
	std::cout << "element not found" << std::endl;

	it = m1.find(5);
	if(it != m1.end())
		std::cout << it->first << "  " << it->second << std::endl;
	else
	std::cout << "element not found" << std::endl;

	std::cout << "======================================"  << std::endl;

	std::cout << m1[2] << std::endl;

	std::cout << "======================================"  << std::endl;


	std::map<std::string, std::string> map_name;

	map_name.emplace("sergii", "moroz");
	map_name.emplace("alex", "anohin");
	map_name.emplace("nik", "morar");

	std::cout << map_name["nik"] << std::endl;
 
	map_name["alex"] = "newname";

	std::cout << map_name["alex"] << std::endl;

	map_name["darin"] = "mor";
	map_name["darin"] = "mor2";

	std::cout << "======================================"  << std::endl;

	for (auto i = map_name.begin(); i != map_name.end(); i++)
	{
		std::cout << i->second << std::endl;
	}

	map_name.at("darin") = "sivak";
	std::cout << "======================================"  << std::endl;

	for (auto i = map_name.begin(); i != map_name.end(); i++)
	{
		std::cout << i->second << std::endl;
	}
	
	map_name.erase("darin");

	std::cout << "======================================"  << std::endl;

	for (auto i = map_name.begin(); i != map_name.end(); i++)
	{
		std::cout << i->second << std::endl;
	}
}