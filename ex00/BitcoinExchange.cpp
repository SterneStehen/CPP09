/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoreron <smoreron@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 22:40:03 by smoreron          #+#    #+#             */
/*   Updated: 2025/02/24 18:21:40 by smoreron         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/


#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(/* args */)
{
}

BitcoinExchange::~BitcoinExchange()
{
}


bool BitcoinExchange::openData(const std::string &dataCsv){
	int comma;
	double value;
	std::string dataNumber;
	std::string strValue;
	std::string line;
	//std::ifstream file(dataFile);
	//file >> dataString;
	//std::cout << dataString << std::endl;
	//std::map<std::string, int> dataMap;
	std::ifstream file(dataCsv);
	
	while (std::getline(file, line))
	{
		if(line.empty())
			continue;
		comma = line.find(',');
		dataNumber = line.substr(0, comma);
		strValue = line.substr(comma+1);
		try{
			value = std::stod(strValue);
			dataMap[dataNumber] = value;
		}
		catch(...){
			continue;
		}
		
		//std::cout << "string dataNumber = " << dataNumber << "   double Value = " << value << std::endl;
	}
	// auto it = dataMap.begin();
	// while (it != dataMap.end())
	// {
	// 	std::cout << it->second << it->first << std::endl;
	// 	it++;
	// }
	return 1;
}

bool BitcoinExchange::checkValue(const std::string &dataInput, double valueInput){
	//std::cout << dataInput << std::endl;
	
	for (auto it = dataMap.begin(); it != dataMap.end(); it++)
	{
		std::cout<<it->first << "     it = " << it->second << std::endl;
	}
	
	
	
	auto it = dataMap.find(dataInput);
	if(it != dataMap.end())
		std::cout<< "it = " << it->second << std::endl;
	// auto it = dataMap.begin();
	// while (it != dataMap.end())
	// {
	// 	if(it == dataIn)
	// }
	return 1;
}


