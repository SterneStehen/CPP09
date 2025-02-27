/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoreron <smoreron@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 00:02:23 by smoreron          #+#    #+#             */
/*   Updated: 2025/02/27 23:42:03 by smoreron         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/


#include "RPN.hpp"


RPN::RPN() {}
RPN::RPN(const RPN &other) { (void)other; }
RPN &RPN::operator=(const RPN &other) { (void)other; return *this; }
RPN::~RPN() {}


bool RPN::isNumber(const std::string &token) const {
	return token.size() == 1 && std::isdigit(token[0]);
}

bool RPN::isOperator(const std::string &token) const {
	return token == "+" || token == "-" || token == "*" || token == "/";
}

int RPN::calculate(const std::string &expression) {
	std::istringstream iss(expression);  
	std::stack<int> stack;  
	std::string token;

	while (iss >> token) {  
		if (isNumber(token)) {
			
			stack.push(token[0] - '0');
		} 
		else if (isOperator(token)) {
			
			if (stack.size() < 2)
				throw std::runtime_error("Error: add digit");

			int right = stack.top(); stack.pop();  
			int left = stack.top(); stack.pop();   

			int result = 0;
			if (token == "+") result = left + right;
			else if (token == "-") result = left - right;
			else if (token == "*") result = left * right;
			else if (token == "/") {
				if (right == 0)
					throw std::runtime_error("Error: not pissible 0");
				result = left / right;
			}

			stack.push(result);  
		} 
		else {
			throw std::runtime_error("Error: incorrect symbol");
		}
	}

	
	if (stack.size() != 1)
		throw std::runtime_error("Error: wrong equation");

	return stack.top();
}
