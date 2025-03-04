/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoreron <smoreron@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 12:22:27 by smoreron          #+#    #+#             */
/*   Updated: 2025/03/03 22:36:27 by smoreron         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/



#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <string>
#include <cstdlib>



class BitcoinExchange
{
public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange &other);
	BitcoinExchange &operator=(const BitcoinExchange &other);
	~BitcoinExchange(); 

	bool openData(const std::string &dataCsv);
	bool checkValue(const std::string &date, double valueInput) const;
	void ft_trimB(std::string &s);
	double ft_stodB(const std::string &str);

private:
	std::map<std::string, double> dataMap;
};

#endif
