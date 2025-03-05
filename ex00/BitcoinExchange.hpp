/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoreron <smoreron@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 12:22:27 by smoreron          #+#    #+#             */
/*   Updated: 2025/03/06 00:21:22 by smoreron         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/


#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <string>

class BitcoinExchange
{
public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange &other);
	BitcoinExchange &operator=(const BitcoinExchange &other);
	~BitcoinExchange();
	
	
	bool openData(const std::string &dataCsv);

	
	bool processInputFile(const std::string &inputFile);

private:
	
	std::map<std::string, double> dataMap;

	
	void ft_trimB(std::string &s);

	
	double ft_stodB(const std::string &str);

	
	bool checkValue(const std::string &date, double valueInput) const;

	
	double stringToDouble(const std::string &str);
	void trim(std::string &s);
	bool isDateValid(const std::string &date);
};

#endif
