/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoreron <smoreron@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 23:49:51 by smoreron          #+#    #+#             */
/*   Updated: 2025/03/03 21:22:00 by smoreron         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/



#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
}

PmergeMe::~PmergeMe()
{
}

void PmergeMe::megreSortVector(std::vector<int> &vect)
{
	if (vect.size() < 2)
		return; 
	joinVector(vect);
}


void PmergeMe::joinVector(std::vector<int> &vect)
{
	const int INSERTION_THRESHOLD = 5; 
	size_t n = vect.size();

	if (n <= INSERTION_THRESHOLD)
	{
		splitVector(vect, 0, n - 1);
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

	
	joinVector(leaders);

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
	

void PmergeMe::splitVector(std::vector<int> &arr, int left, int right)
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


	

//sort list
	
	
	
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

	
void PmergeMe::megreSortList(std::list<int> &lst)
{
	if (lst.size() < 2)
		return; 	
	recursiveList(lst);
}
	