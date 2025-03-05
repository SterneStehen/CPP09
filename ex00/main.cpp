/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoreron <smoreron@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 22:34:01 by smoreron          #+#    #+#             */
/*   Updated: 2025/03/06 00:17:42 by smoreron         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/



#include <iostream>
#include <fstream>
#include <map>
#include "BitcoinExchange.hpp"

#include <cstdlib>

#include <iostream>
#include "BitcoinExchange.hpp"

int main(int argc, char *argv[])
{
	
	if (argc != 2) {
		std::cout << "Error: could not open file." << std::endl;
		return 1;
	}

	
	BitcoinExchange btc;

		if (!btc.openData("data.csv")) {
		std::cout << "Error: wrong open data.csv" << std::endl;
		return 1;
	}

	if (!btc.processInputFile(argv[1])) {
		return 1;
	}

	return 0;
}
