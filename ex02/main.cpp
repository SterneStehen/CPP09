/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoreron <smoreron@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 20:25:22 by smoreron          #+#    #+#             */
/*   Updated: 2025/03/02 20:56:59 by smoreron         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include <iostream>
#include <vector>
#include <list>


int  ft_atoi(char *str){
	int res;
	long long tmp;
	tmp = std::stol(str);
	if(tmp > 2147483647)
		return -1;
	res = static_cast<int>(tmp);
	return res;
}

bool isPositiv(char *str){
	if(!str || !*str)
		return 0;
	int i = 0;
	while (str[i] != '\0')
	{
		if(str[i] < '0' || str[i] > '9')
			return 0;
		i++;
	}
	return 1;
}

int main(int ac, char *av[]){
	std::vector<int> vec;
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
			std::cout << "Not positiv number" << std::endl;
			return 0;
		}
		tmp = ft_atoi(av[i]);
		if(tmp == -1){
			std::cout << "digit more then MAX_INT" << std::endl;
			return 0;
		}
		std::cout << "tmp = " << tmp << std::endl;
	}
	
}