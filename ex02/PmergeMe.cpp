/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoreron <smoreron@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 23:49:51 by smoreron          #+#    #+#             */
/*   Updated: 2025/03/03 12:51:33 by smoreron         ###   ########.fr       */
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