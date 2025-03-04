/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoreron <smoreron@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 23:49:51 by smoreron          #+#    #+#             */
/*   Updated: 2025/03/04 01:31:34 by smoreron         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/



#include "PmergeMe.hpp"


PmergeMe::PmergeMe() {
}

PmergeMe::PmergeMe(const PmergeMe &other) {
    *this = other;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other) {
    if (this != &other) {
        this->vect = other.vect;
        this->list = other.list;
    }
    return *this;
}

PmergeMe::~PmergeMe() {
}


void PmergeMe::setList(int tmp){
	list.push_back(tmp);
};
void PmergeMe::setVect(int tmp){
	vect.push_back(tmp);
};

int PmergeMe::getSize() const{
	return list.size();
};

void PmergeMe::megreSortVector()
{
	if (vect.size() < 2)
		return; 
	insertionVector(vect);
}


void PmergeMe::insertionVector(std::vector<int> &vect)
{
	const int INSERTION_THRESHOLD = 5; 
	size_t n = vect.size();

	if (n <= INSERTION_THRESHOLD)
	{
		sortSplitVector(vect, 0, n - 1);
		return;
	}

	
	std::vector<int> leaders;
	std::vector<int> followers;
	leaders.reserve(n/2 + 1);
	followers.reserve(n/2 + 1);

	for (size_t i = 0; i < n; i += 2)
	{
		if (i + 1 < n)
		{
			
			if (vect[i] <= vect[i + 1])
			{
				leaders.push_back(vect[i]);
				followers.push_back(vect[i + 1]);
			}
			else
			{
				leaders.push_back(vect[i + 1]);
				followers.push_back(vect[i]);
			}
		}
		else
		{
			
			leaders.push_back(vect[i]);
		}
	}

	
	insertionVector(leaders);

	for (size_t i = 0; i < followers.size(); i++)
	{
		binaryInsert(leaders, followers[i]);
	}

	
	vect = leaders;
}


void PmergeMe::binaryInsert(std::vector<int> &arr, int x)
{
	
	std::vector<int>::iterator it = std::lower_bound(arr.begin(), arr.end(), x);
	arr.insert(it, x);

}
	



void PmergeMe::sortSplitVector(std::vector<int> &arr, int left, int right)
{
	for (int i = left + 1; i <= right; i++)
	{
		int key = arr[i];
		int j = i - 1;
		while (j >= left && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
	}
}


void PmergeMe::insertionSortList(std::list<int> &lst)
{
	if (lst.size() < 2) return;

		
	for (std::list<int>::iterator it = ++lst.begin(); it != lst.end(); ++it)
	{
		int key = *it;
		std::list<int>::iterator j = it;
			
		while (j != lst.begin())
		{
			std::list<int>::iterator prev = j;
			--prev;
			if (*prev <= key)
				break;
				
			*j = *prev;
			j = prev;
		}
		*j = key;
	}
}

	
	
	
void PmergeMe::insertSorted(std::list<int> &lst, int value)
{
		
	for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it)
	{
		if (*it > value)
		{
			lst.insert(it, value);
			return;
		}
	}
		
	lst.push_back(value);
}

	
	
	
	
void PmergeMe::splitIntoPairs(const std::list<int> &src, std::list<int> &leaders, std::list<int> &followers)
{
	std::list<int>::const_iterator it = src.begin();
	while (it != src.end())
	{
		int first = *it;
		++it;
		if (it != src.end())
		{
			int second = *it;
			++it;
				
			if (first <= second)
			{
				leaders.push_back(first);
				followers.push_back(second);
			}
			else
			{
				leaders.push_back(second);
				followers.push_back(first);
			}
		}
		else
		{
				
			leaders.push_back(first);
		}
	}
}

	
	
	
void PmergeMe::recursiveList(std::list<int> &list)
{
	const size_t INSERTION_THRESHOLD = 5;

		
	if (list.size() <= INSERTION_THRESHOLD)
	{
		insertionSortList(list);
		return;
	}

		
	std::list<int> leaders;
	std::list<int> followers;
	splitIntoPairs(list, leaders, followers);

		
	recursiveList(leaders);

		
	for (std::list<int>::iterator it = followers.begin(); it != followers.end(); ++it)
	{
		insertSorted(leaders, *it);
	}
	list.swap(leaders); 
		
}

	
void PmergeMe::megreSortList()
{
	if (list.size() < 2)
		return; 	
	recursiveList(list);
}

void PmergeMe::printSort()
{
    // Можно вывести вектор (после sort) для наглядности
    std::cout << "After: ";
    for (std::vector<int>::iterator it = vect.begin(); it != vect.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
}