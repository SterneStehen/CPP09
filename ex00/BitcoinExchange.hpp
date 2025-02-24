/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoreron <smoreron@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 12:22:27 by smoreron          #+#    #+#             */
/*   Updated: 2025/02/24 17:53:23 by smoreron         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include <iostream>
#include <fstream>
#include <map>

class BitcoinExchange
{
private:
	std::map<std::string, int> dataMap;
public:
	BitcoinExchange();
	~BitcoinExchange();
	bool openData(const std::string &dataCsv);
	bool checkValue(const std::string &dataInput, double valueInput);
};


