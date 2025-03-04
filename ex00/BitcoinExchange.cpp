/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoreron <smoreron@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 22:40:03 by smoreron          #+#    #+#             */
/*   Updated: 2025/03/03 22:44:12 by smoreron         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/


#include "BitcoinExchange.hpp"
#include <iomanip> 
#include "BitcoinExchange.hpp"
#include <fstream>
#include <sstream>

BitcoinExchange::BitcoinExchange(){}
BitcoinExchange::~BitcoinExchange(){}
BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) {
    this->dataMap = other.dataMap;
}
BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other) {
    if (this != &other) {
        this->dataMap = other.dataMap;
    }
    return *this;
}

void BitcoinExchange::ft_trimB(std::string &s)
{
	while (!s.empty() && (s[0] == ' ' || s[0] == '\t' || s[0] == '\n')){
		s.erase(s.begin());
	}
	while (!s.empty())
	{
		char lastChar = s[s.size() - 1];
		if (lastChar == ' ' || lastChar == '\t' || lastChar == '\n')
			s.erase(s.end() - 1);
		else
			break;
    }
}

double BitcoinExchange::ft_stodB(const std::string &str)
{
	if (str.empty())
		throw std::exception();

	char *endptr;
	double val = std::strtod(str.c_str(), &endptr);

	if (*endptr != '\0')
		throw std::exception();

	return val;
}

bool BitcoinExchange::openData(const std::string &dataCsv)
{
	std::ifstream file(dataCsv.c_str());
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

		ft_trimB(date);
        ft_trimB(rateStr);

		double rate;
		try
		{
			rate = ft_stodB(rateStr);
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

	