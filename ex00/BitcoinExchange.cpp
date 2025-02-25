/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoreron <smoreron@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 22:40:03 by smoreron          #+#    #+#             */
/*   Updated: 2025/02/25 23:58:14 by smoreron         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/


#include "BitcoinExchange.hpp"
#include <iomanip> 
#include "BitcoinExchange.hpp"
#include <fstream>
#include <sstream>

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::~BitcoinExchange()
{
}

bool BitcoinExchange::openData(const std::string &dataCsv)
{
	std::ifstream file(dataCsv);
	if (!file.is_open())
	{
		std::cerr << "Error: Could not open data file: " << dataCsv << std::endl;
		return false;
	}

	std::string line;
	while (std::getline(file, line))
	{
		if (line.empty())
			continue;
	
		std::size_t commaPos = line.find(',');
		if (commaPos == std::string::npos)
			continue; 	

		std::string date = line.substr(0, commaPos);
		std::string rateStr = line.substr(commaPos + 1);

			
		while (!date.empty() && (date.front() == ' ' || date.front() == '\t'))
			date.erase(date.begin());
		while (!date.empty() && (date.back() == ' ' || date.back() == '\t'))
			date.pop_back();
		while (!rateStr.empty() && (rateStr.front() == ' ' || rateStr.front() == '\t'))
			rateStr.erase(rateStr.begin());
		while (!rateStr.empty() && (rateStr.back() == ' ' || rateStr.back() == '\t'))
			rateStr.pop_back();

		double rate;
		try
		{
			rate = std::stod(rateStr);
		}
		catch (const std::exception &e)
		{		
			continue;
		}
		dataMap[date] = rate;
	}
	file.close();
	return true;
}

bool BitcoinExchange::checkValue(const std::string &date, double valueInput) const
{
		
		
	std::map<std::string, double>::const_iterator it = dataMap.lower_bound(date);

	if (it == dataMap.end())
	{
		if (dataMap.empty())
		{
				
			std::cout << "Error: database is empty" << std::endl;
			return false;
		}
			
		it = --dataMap.end();
	}
	else if (it->first != date)
	{		
		if (it == dataMap.begin())
		{	
			std::cout << "Error: no earlier date found for " << date << std::endl;
			return false;
		}
		else
		{	
			--it;
		}
	}
	double rate = it->second;
	double result = rate * valueInput;
	std::cout << date << " => " << valueInput << " = " << result << std::endl;
	return true;
}

	