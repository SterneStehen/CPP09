/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoreron <smoreron@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 23:49:38 by smoreron          #+#    #+#             */
/*   Updated: 2025/03/02 22:53:06 by smoreron         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <list>

class PmergeMe
{
private:
	void splitVector(std::vector<int> &vect, int left, int right);
	void joinVector(std::vector<int> &vect, int left, int mid, int right);
public:
	PmergeMe();
	~PmergeMe();
	void megreSortVector(std::vector<int> &vect);
};



#endif