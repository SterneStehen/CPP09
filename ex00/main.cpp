/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoreron <smoreron@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 22:34:01 by smoreron          #+#    #+#             */
/*   Updated: 2025/02/24 15:51:49 by smoreron         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/



#include <iostream>
#include <fstream>
#include <map>

bool openData(const std::string &dataCsv){
	std::string line;
	//std::ifstream file(dataFile);
	//file >> dataString;
	//std::cout << dataString << std::endl;
	std::map<std::string, int> dataMap;
	std::ifstream file(dataCsv);
	int comma;
	std::string dataNumber;
	std::string strValue;
	double value;
	while (std::getline(file, line))
	{
		if(line.empty())
			continue;
		comma = line.find(',');
		dataNumber = line.substr(0, comma);
		strValue = line.substr(comma+1);
		try{
			value = std::stod(strValue);
		}
		catch(...){
			continue;
		}
		std::cout << "string dataNumber = " << dataNumber << "   double Value = " << value << std::endl;
	}
	
	return 1;
}


int main(int argv, char *argc[]){
	if(argv != 2){
		std::cout << "add input.txt file" << std::endl;
		return 0;
	}
	if(!openData("data.csv")){
		std::cout << "wrong openfile" << std::endl;
		return 0;
	}
}