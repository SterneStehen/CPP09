/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoreron <smoreron@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 23:49:38 by smoreron          #+#    #+#             */
/*   Updated: 2025/03/04 00:11:18 by smoreron         ###   ########.fr       */
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
//vector
	void sortSplitVector(std::vector<int> &vect, int left, int right);
	void insertionVector(std::vector<int> &vect);
	void binaryInsert(std::vector<int> &arr, int x);
//list
	void recursiveList(std::list<int> &list);
	void splitIntoPairs(const std::list<int> &src, std::list<int> &leaders, std::list<int> &followers);
	void insertSorted(std::list<int> &lst, int value);
	void insertionSortList(std::list<int> &lst);
	
public:
	PmergeMe();
	~PmergeMe();
	void megreSortVector(std::vector<int> &vect);
	void megreSortList(std::list<int> &lst);
};



#endif