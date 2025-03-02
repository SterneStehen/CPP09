/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoreron <smoreron@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 23:49:51 by smoreron          #+#    #+#             */
/*   Updated: 2025/03/02 22:54:54 by smoreron         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
}

PmergeMe::~PmergeMe()
{
}

void PmergeMe::joinVector(std::vector<int> &vect, int left, int  mid, int  right){
	int n1 = mid - left + 1;
	int n2 = right - mid;
	std::vector<int> L(n1), R(n2);

	for (int i = 0; i < n1; i++)
		L[i] = vect[left + i];
	for (int j = 0; j < n2; j++)
		R[j] = vect[mid + 1 + j];

	int i = 0, j = 0;
	int k = left;
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j]){
			vect[k] = L[i];
			i++;
		}
		
		else{
			vect[k] = R[j];
			j++;
		}
		k++;
	}
	while (i < n1)
	{
		vect[k] = L[i];
		i++;
		k++;
	}
	while (j < n2)
	{
		vect[k] = R[j];
		j++;
		k++;
	}
}

void PmergeMe::splitVector(std::vector<int> &vect, int left, int right){
	if(left >= right)
		return;
	int mid = (left+right)/2;
	splitVector(vect, left, mid);
	splitVector(vect, mid+1, right);
	joinVector(vect, left, mid, right);
}

void PmergeMe::megreSortVector(std::vector<int> &vect){
	if(vect.empty())
		return;
	splitVector(vect, 0, vect.size()-1);
}