/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoreron <smoreron@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 23:49:38 by smoreron          #+#    #+#             */
/*   Updated: 2025/03/04 01:29:44 by smoreron         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/


#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <list>

class PmergeMe {
private:
	std::vector<int> vect;
	std::list<int> list;
	
	void insertionVector(std::vector<int> &vect);
	void sortSplitVector(std::vector<int> &arr, int left, int right);
	void binaryInsert(std::vector<int> &arr, int x);

	void recursiveList(std::list<int> &list);
	void insertionSortList(std::list<int> &lst);
	void insertSorted(std::list<int> &lst, int value);
	void splitIntoPairs(const std::list<int> &src, std::list<int> &leaders, std::list<int> &followers);
	
public:
    
	PmergeMe();
	PmergeMe(const PmergeMe &other);
	 PmergeMe &operator=(const PmergeMe &other);
	~PmergeMe();
    
	void megreSortVector();
	void megreSortList();
	
	void setList(int tmp);
	void setVect(int tmp);
	
	int getSize() const;
	void printSort();

};

#endif
