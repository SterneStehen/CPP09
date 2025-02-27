/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoreron <smoreron@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 15:23:37 by smoreron          #+#    #+#             */
/*   Updated: 2025/02/27 23:37:17 by smoreron         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/



#include "RPN.hpp"
#include <iostream>

int main(int ac, char **av)
{
	if (argc != 2)
	{
		std::cerr << "Error. Try ./RPN ..." << std::endl;
		return 1;
	}
	try
	{
		int result = rpn.calc(argv[1]);
		std::cout << result << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		return 1;
	}
	return 0;
}
	
