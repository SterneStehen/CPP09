/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoreron <smoreron@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 20:25:22 by smoreron          #+#    #+#             */
/*   Updated: 2025/03/04 00:30:05 by smoreron         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include <iostream>
#include <vector>
#include <list>
#include <ctime> 
#include <cstdlib>
#include <climits>
#include "PmergeMe.hpp"
#include <cstdlib>  
#include <climits>  

int ft_atoi(const char *str) {
	if (!str || !*str)  
		return -1;

	char *endptr;
	long tmp = std::strtol(str, &endptr, 10);  

	if (*endptr != '\0')
		return -1;

	if (tmp > INT_MAX)
		return -1;

	return static_cast<int>(tmp);
}


bool isPositiv(char *str){
	if(!str || !*str)
		return 0;
	int i = 0;
	while (str[i] != '\0')
	{
		if(str[i] < '0' || str[i] > '9')
			return -1;
		i++;
	}
	return 1;
}

int main(int ac, char *av[]){
	std::vector<int> vect;
	std::list<int> list;
	std::string before;
	int tmp;

	if(ac < 2){
		std::cout << "add couple number" << std::endl;
		return 0;
	}
	for (int i = 1; i < ac; ++i)
	{
		if(!isPositiv(av[i])){
			std::cout << "Error: Not positiv number" << std::endl;
			return 0;
		}
		tmp = ft_atoi(av[i]);
		if(tmp == -1){
			std::cout << "digit more then MAX_INT" << std::endl;
			return 0;
		}
		before += av[i];
		before += " ";
		list.push_back(tmp);
		vect.push_back(tmp);
	}
	std::cout << "before: " << before << std::endl;
	
	
	
	
	
	
	
	

	PmergeMe PM;

	try {
	clock_t startVect = clock();
	PM.megreSortVector(vect);
	clock_t endVect = clock();
	double timeVect = static_cast<double>(endVect - startVect) / CLOCKS_PER_SEC * 1000000.0;

	clock_t startList = clock();
	PM.megreSortList(list);
	clock_t endList = clock();
	double timeList = static_cast<double>(endList - startList) / CLOCKS_PER_SEC * 1000000.0;

	
	
	
	
	

	std::cout << "After: ";
	for (std::list<int>::iterator it = list.begin(); it != list.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	std::cout << "Time to process a range of " << vect.size() << " elements with std::vector : " << timeVect << " us" << std::endl;
	std::cout << "Time to process a range of " << list.size() << " elements with std::list  : " << timeList << " us" << std::endl;
	}
	catch (const std::exception &e) {
		std::cerr << e.what() << '\n';
	return 1;
	}
}