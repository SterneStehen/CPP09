/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoreron <smoreron@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 22:34:01 by smoreron          #+#    #+#             */
/*   Updated: 2025/02/25 23:55:15 by smoreron         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/



#include <iostream>
#include <fstream>
#include <map>
#include "BitcoinExchange.hpp"

static void trim(std::string &s)
{
	while (!s.empty() && (s.front() == ' ' || s.front() == '\t' || s.front() == '\n'))
	{
		s.erase(s.begin());
	}
	while (!s.empty() && (s.back() == ' ' || s.back() == '\t' || s.back() == '\n'))
	{
		s.pop_back();
	}
}

	
	
static bool isDateValid(const std::string &date)
{
	if (date.size() != 10)
		return false;
		
	if (date[4] != '-' || date[7] != '-')
		return false;
		
	for (std::size_t i = 0; i < date.size(); i++)
	{
		if (i == 4 || i == 7)
			continue;
		if (!std::isdigit(static_cast<unsigned char>(date[i])))
			return false;
	}
		
	return true;
}

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cout << "Error: could not open file." << std::endl;
		return 1;
	}

		
	BitcoinExchange btc;
		
	if (!btc.openData("data.csv"))
	{
		std::cout << "Error: wrong open data.csv" << std::endl;
		return 1;
	}

		
	std::ifstream input(argv[1]);
	if (!input.is_open())
	{
		std::cout << "Error: could not open " << argv[1] << std::endl;
		return 1;
	}

		
	std::string line;
	if (!std::getline(input, line))
	{
			
		std::cout << "Error: empty input file" << std::endl;
		return 1;
	}

		
	while (std::getline(input, line))
	{
		trim(line);
		if (line.empty())
			continue;
	

		std::size_t pipePos = line.find('|');
		if (pipePos == std::string::npos )
		{
			std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}
	
		std::string date = line.substr(0, pipePos);
		std::string valueStr = line.substr(pipePos + 1);
	
			
		trim(date);
		trim(valueStr);
	
			
		if (!isDateValid(date))
		{
			std::cout << "Error: bad date => " << date << std::endl;
			continue;
		}

			
		double value;
		try
		{
			value = std::stod(valueStr);
		}
		catch (...)
		{
			std::cout << "Error: bad value => " << valueStr << std::endl;
			continue;
		}

			
		if (value < 0.0)
		{
			std::cout << "Error: not a positive number." << std::endl;
			continue;
		}
		if (value > 1000.0)
		{
			std::cout << "Error: too large a number." << std::endl;
			continue;
		}

			
		btc.checkValue(date, value);
	}

	input.close();
	return 0;
}
