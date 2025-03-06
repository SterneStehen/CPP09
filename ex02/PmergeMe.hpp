/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoreron <smoreron@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 23:49:38 by smoreron          #+#    #+#             */
/*   Updated: 2025/03/06 01:51:13 by smoreron         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>   
#include <vector>	 
#include <list>	   

class PmergeMe {
private:
	std::vector<int> m_vector;  
	std::list<int>   m_list;	
	
	void insertionSortVector(std::vector<int> &vec);
	void insertionSortRangeVector(std::vector<int> &arr, int left, int right);
	void binaryInsertVector(std::vector<int> &arr, int x);
	
	void recursiveSortList(std::list<int> &lst);
	void insertionSortList(std::list<int> &lst);
	void insertSortedList(std::list<int> &lst, int value);	
	void splitListIntoPairs(const std::list<int> &src, std::list<int> &leaders,	std::list<int> &followers);

public:
	PmergeMe();						  
	PmergeMe(const PmergeMe &other);	 
	PmergeMe &operator=(const PmergeMe &other);  
	~PmergeMe();						 

	int ft_atoi(const char *str);
	bool isPositiv(char *str);
	void setList(int value);
	void setVect(int value);
	int getSize() const;
	
	void FordSortVector();
	void FordSortList();
	void printSort();
};

#endif
