/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoreron <smoreron@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 12:22:27 by smoreron          #+#    #+#             */
/*   Updated: 2025/02/25 23:54:45 by smoreron         ###   ########.fr       */
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
	~BitcoinExchange();

	bool openData(const std::string &dataCsv);
	bool checkValue(const std::string &date, double valueInput) const;

private:
	std::map<std::string, double> dataMap;
};

#endif
