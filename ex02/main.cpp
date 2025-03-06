/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoreron <smoreron@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 20:25:22 by smoreron          #+#    #+#             */
/*   Updated: 2025/03/06 03:06:34 by smoreron         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include <iostream>
#include <vector>
#include <list>
#include <ctime> 
#include <cstdlib>
#include <climits>
#include <iomanip>
#include "PmergeMe.hpp"


int main(int ac, char *av[]){
	PmergeMe PM;
	std::string before;
	int tmp;

	if(ac < 2){
		std::cout << "add couple number" << std::endl;
		return 0;
	}
	
	for (int i = 1; i < ac; ++i)
	{
		if(!PM.isPositiv(av[i])){
			std::cout << "Error: Not positiv number" << std::endl;
			return 0;
		}
		tmp = PM.ft_atoi(av[i]);
		if(tmp == -1){
			std::cout << "digit more then MAX_INT" << std::endl;
			return 0;
		}
		PM.setList(tmp);
		PM.setVect(tmp);
		before += av[i];
		before += " ";
	}
	std::cout << "before: " << before << std::endl;
	
	try {
		clock_t startVect = clock();
		PM.FordSortVector();
		clock_t endVect = clock();
		double timeVect = static_cast<double>(endVect - startVect) / CLOCKS_PER_SEC * 1000000.0;

		clock_t startList = clock();
		PM.FordSortList();
		clock_t endList = clock();
		double timeList = static_cast<double>(endList - startList) / CLOCKS_PER_SEC * 1000000.0;

		PM.printSort();

		std::cout << std::fixed << std::setprecision(2) << "Time to process a range of " << PM.getSize() << " elements with std::vector : " << timeVect << " us" << std::endl;
		std::cout << "Time to process a range of " << PM.getSize() << " elements with std::list  : " << timeList << " us" << std::endl;
	}
	catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	return 1;
	}
}