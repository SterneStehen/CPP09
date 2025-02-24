/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoreron <smoreron@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 22:34:01 by smoreron          #+#    #+#             */
/*   Updated: 2025/02/24 18:16:00 by smoreron         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/



#include <iostream>
#include <fstream>
#include <map>
#include "BitcoinExchange.hpp"

static void trim(std::string &s)
{
    while (!s.empty() && (s.front() == ' ' || s.front() == '\t'))
    {
        s.erase(s.begin());
    }
    while (!s.empty() && (s.back() == ' ' || s.back() == '\t'))
    {
        s.pop_back();
    }
}


int main(int argv, char *argc[]){
	if(argv != 2){
		std::cout << "Error: could not open file." << std::endl;
		return 0;
	}
	BitcoinExchange data;
	if(!data.openData("data.csv")){
		std::cout << "wrong openfile data.csv" << std::endl;
		return 0;
	}

	std::cout << "==============================" << std::endl;
	std::ifstream input(argc[1]);
	if(!input){
		std::cout << "wrong input.txt" << std::endl;
	}
	
	int pipe;
	double valueInput;
	std::string dataInput;
	std::string valueStrInput;
	std::string line;
	
	getline(input, line);
	//std::cout << line << std::endl;

	while (getline(input, line))
	{
		if(line.empty() || line[0] == ' ' || line[0] == '\n')
			continue;
		pipe = line.find('|');
		if( pipe < 1 ){
			std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}
		dataInput = line.substr(0, pipe);
		valueStrInput = line.substr(pipe + 1);
		valueInput = stod(valueStrInput);
		if(valueInput < 0){
			std::cout << "Error: not a positive number." << std::endl;
			continue;
		}
		if(valueInput > 1000){
			std::cout << "Error: too large a number." << std::endl;
			continue;
		}
		int s = 0;
		
		while (dataInput[s] == ' ')
		{
			s++;
		}
		int e = s;
		while (dataInput[e] != ' ')
		{
			e++;
		}
		trim(dataInput);
		//std::cout << "dataInput = " << dataInput << "  valueInput = " << valueInput << std::endl;
		data.checkValue(dataInput, valueInput);
	}
	

	
	
}