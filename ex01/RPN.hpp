/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoreron <smoreron@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 22:35:53 by smoreron          #+#    #+#             */
/*   Updated: 2025/03/03 23:03:30 by smoreron         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef RPN_CPP
#define RPN_CPP

#include <stack>
#include <sstream>
#include <iostream>
#include <stdexcept>
#include <cctype> 
#include <string>

class RPN
{
private:
		std::stack<int>	stack;
public:
	RPN();
	RPN(const RPN &other);
	RPN &operator=(const RPN &other);
	~RPN();

	int calc(const std::string &expression);
	bool isNumber(const std::string &token) const;
	bool isOperator(const std::string &token) const;
};
#endif
