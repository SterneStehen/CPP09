/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoreron <smoreron@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 23:49:51 by smoreron          #+#    #+#             */
/*   Updated: 2025/03/06 02:12:25 by smoreron         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "PmergeMe.hpp"
#include <climits>	
#include <cstdlib>
#include <algorithm>

PmergeMe::PmergeMe() {
}

PmergeMe::PmergeMe(const PmergeMe &other) {
	*this = other;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other) {
	if (this != &other) {
		this->m_vector = other.m_vector;
		this->m_list   = other.m_list;
	}
	return *this;
}

PmergeMe::~PmergeMe() {

}

// util
int PmergeMe::ft_atoi(const char *str) {
	if (!str || !*str)  
		return -1;
	char *endptr;
	long tmp = std::strtol(str, &endptr, 10);
	if (*endptr != '\0')
		return -1;
	if (tmp > INT_MAX)
		return -1;
	return static_cast<int>(tmp);
}

bool PmergeMe::isPositiv(char *str) {
	if (!str || !*str)
		return false;
	int i = 0;
	while (str[i] != '\0') {
		if (str[i] < '0' || str[i] > '9')
			return false;
		i++;
	}
	return true;
}

void PmergeMe::setList(int value) {
	m_list.push_back(value);
}

void PmergeMe::setVect(int value) {
	m_vector.push_back(value);
}

int PmergeMe::getSize() const {
	return static_cast<int>(m_list.size());
}

void PmergeMe::FordSortVector() { 
	if (m_vector.size() < 2)
		return;
	insertionSortVector(m_vector);
}

void PmergeMe::FordSortList() {
	if (m_list.size() < 2)
		return;
	recursiveSortList(m_list);
}

void PmergeMe::printSort() {
	std::cout << "After: ";
	for (std::vector<int>::iterator it = m_vector.begin(); it != m_vector.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

// vector
void PmergeMe::insertionSortVector(std::vector<int> &vec) {
	const int INSERTION_THRESHOLD = 5; // threshold below which we do a direct insertion sort
	size_t n = vec.size();
	if (n <= INSERTION_THRESHOLD) {
		insertionSortRangeVector(vec, 0, static_cast<int>(n) - 1);
		return;
	}
	// Split elements into leader/follower pairs
	std::vector<int> leaders;
	std::vector<int> followers;
	leaders.reserve(n/2 + 1);
	followers.reserve(n/2 + 1);

	for (size_t i = 0; i < n; i += 2) {
		if (i + 1 < n) {
			if (vec[i] <= vec[i + 1]) {
				leaders.push_back(vec[i]);
				followers.push_back(vec[i + 1]);
			} else {
				leaders.push_back(vec[i + 1]);
				followers.push_back(vec[i]);
			}
		} else {
			leaders.push_back(vec[i]);
		}
	}
	// Recursively sort the leaders
	insertionSortVector(leaders);
	// Insert each follower into sorted leaders
	for (size_t i = 0; i < followers.size(); i++) {
		binaryInsertVector(leaders, followers[i]);
	}
	vec = leaders;
}

void PmergeMe::binaryInsertVector(std::vector<int> &arr, int x) {
    if (arr.empty()) {
        arr.push_back(x);
        return;
    }

    int left = 0, right = arr.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] < x)
            left = mid + 1;
        else
            right = mid - 1;
    }

    arr.insert(arr.begin() + left, x);
}


void PmergeMe::insertionSortRangeVector(std::vector<int> &arr, int left, int right) {
    for (int i = left + 1; i <= right; i++) {
        int key = arr[i]; // Store the current element
        int j = i - 1;

        // Shift elements to the right until the correct position for key is found
        while (j >= left && arr[j] > key) {
            arr[j + 1] = arr[j]; // Move element to the right
            j--;
        }
        // Insert key
        arr[j + 1] = key;
    }
}




//List
void PmergeMe::recursiveSortList(std::list<int> &lst) {
	const size_t INSERTION_THRESHOLD = 5;
	if (lst.size() <= INSERTION_THRESHOLD) {
		insertionSortList(lst);
		return;
	}
	// Split into leader/follower pairs
	std::list<int> leaders;
	std::list<int> followers;
	splitListIntoPairs(lst, leaders, followers);
	recursiveSortList(leaders);
	// Insert followers
	for (std::list<int>::iterator it = followers.begin(); it != followers.end(); ++it) {
		insertSortedList(leaders, *it);
	}
	// Move sorted data back into original list
	lst.swap(leaders);
}

void PmergeMe::insertionSortList(std::list<int> &lst) {
    if (lst.size() < 2)
        return;
    
    for (std::list<int>::iterator it = ++lst.begin(); it != lst.end(); ++it) {
        int key = *it; // Store the current element
        std::list<int>::iterator j = it;
        
        // Shift elements to the right until the correct position for key is found
        while (j != lst.begin()) {
            std::list<int>::iterator prev = j;
            --prev;
            if (*prev <= key) // Stop shifting if the correct position is found
                break;
            *j = *prev; // Move element one position forward
            j = prev;
        }
        
        // Insert key in the correct position
        *j = key;
    }
}


void PmergeMe::insertSortedList(std::list<int> &lst, int value) {
	//Insert into the correct position in a sorted list
	for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it) {
		if (*it > value) {
			lst.insert(it, value);
			return;
		}
	}
	lst.push_back(value);
}

void PmergeMe::splitListIntoPairs(const std::list<int> &src, std::list<int> &leaders,  std::list<int> &followers) 
{
	// Splits elements of 'src' into (leader, follower) pairs
	std::list<int>::const_iterator it = src.begin();
	while (it != src.end()) {
		int first = *it;
		++it;
		if (it != src.end()) {
			int second = *it;
			++it;
			if (first <= second) {
				leaders.push_back(first);
				followers.push_back(second);
			} else {
				leaders.push_back(second);
				followers.push_back(first);
			}
		} else {
			// odd count => last item alone goes to leaders
			leaders.push_back(first);
		}
	}
}
