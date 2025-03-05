/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoreron <smoreron@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 22:40:03 by smoreron          #+#    #+#             */
/*   Updated: 2025/03/06 00:22:31 by smoreron         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/


#include <iomanip> 

#include <sstream>
#include "BitcoinExchange.hpp"
#include <fstream>

#include <cstdlib>
#include <cctype> 

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::~BitcoinExchange() {}

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
	while (!s.empty() && (s[0] == ' ' || s[0] == '\t' || s[0] == '\n')) {
		s.erase(s.begin());
	}
	while (!s.empty()) {
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

double BitcoinExchange::stringToDouble(const std::string &str)
{
	char *endptr;
	double val = std::strtod(str.c_str(), &endptr);
	if (*endptr != '\0')
		throw std::exception();
	return val;
}

void BitcoinExchange::trim(std::string &s)
{
	while (!s.empty() && (s[0] == ' ' || s[0] == '\t' ||
						  s[0] == '\n' || s[0] == '\r')) {
		s.erase(s.begin());
	}
	while (!s.empty()) {
		char lastChar = s[s.size() - 1];
		if (lastChar == ' ' || lastChar == '\t' ||
			lastChar == '\n' || lastChar == '\r') {
			s.erase(s.end() - 1);
		} else {
			break;
		}
	}
}

bool BitcoinExchange::isDateValid(const std::string &date)
{
	
	if (date.size() != 10)
		return false;
	if (date[4] != '-' || date[7] != '-')
		return false;
	for (std::size_t i = 0; i < date.size(); i++) {
		if (i == 4 || i == 7)
			continue;
		if (!std::isdigit(static_cast<unsigned char>(date[i])))
			return false;
	}
	return true;
}

bool BitcoinExchange::openData(const std::string &dataCsv)
{
	std::ifstream file(dataCsv.c_str());
	if (!file.is_open()) {
		std::cerr << "Error: Could not open data file: " << dataCsv << std::endl;
		return false;
	}

	std::string line;
	while (std::getline(file, line)) {
		if (line.empty())
			continue;

		std::size_t commaPos = line.find(',');
		if (commaPos == std::string::npos)
			continue;

		std::string date	= line.substr(0, commaPos);
		std::string rateStr = line.substr(commaPos + 1);

		ft_trimB(date);
		ft_trimB(rateStr);

		double rate;
		try {
			rate = ft_stodB(rateStr);
		} catch (const std::exception &) {
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

	if (it == dataMap.end()) {
		if (dataMap.empty()) {
			std::cout << "Error: database is empty" << std::endl;
			return false;
		}
		
		it = --dataMap.end();
	}
	else if (it->first != date) {
		if (it == dataMap.begin()) {
			std::cout << "Error: no earlier date found for " << date << std::endl;
			return false;
		}
		else {
			--it;
		}
	}

	double rate = it->second;
	double result = rate * valueInput;
	std::cout << date << " => " << valueInput << " = " << result << std::endl;
	return true;
}


bool BitcoinExchange::processInputFile(const std::string &inputFile)
{
	std::ifstream input(inputFile.c_str());
	if (!input.is_open()) {
		std::cout << "Error: could not open " << inputFile << std::endl;
		return false;
	}

	
	
	std::string line;
	if (!std::getline(input, line)) {
		std::cout << "Error: empty input file" << std::endl;
		return false;
	}

	
	while (std::getline(input, line)) {
		trim(line);
		if (line.empty())
			continue;

		std::size_t pipePos = line.find('|');
		if (pipePos == std::string::npos) {
			std::cout << "Error1: bad input => " << line << std::endl;
			continue;
		}

		std::string date	= line.substr(0, pipePos);
		std::string valueStr = line.substr(pipePos + 1);

		trim(date);
		trim(valueStr);

		if (!isDateValid(date)) {
			std::cout << "Error2: bad date => " << date << std::endl;
			continue;
		}

		double value;
		try {
			value = stringToDouble(valueStr);
		} catch (...) {
			std::cout << "Error3: bad value => " << valueStr << std::endl;
			continue;
		}

		if (value < 0.0) {
			std::cout << "Error: not a positive number." << std::endl;
			continue;
		}
		if (value > 1000.0) {
			std::cout << "Error: too large a number." << std::endl;
			continue;
		}

		
		checkValue(date, value);
	}

	input.close();
	return true;
}
