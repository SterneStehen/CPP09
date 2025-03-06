/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoreron <smoreron@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 23:49:51 by smoreron          #+#    #+#             */
/*   Updated: 2025/03/06 03:03:54 by smoreron         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/


#include "PmergeMe.hpp"
#include <climits>    
#include <cstdlib>    
#include <algorithm>  
#include <set>        
#include <iostream>   

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


 //  (0,1,1,2,5,7,12,19...) .

std::vector<size_t> PmergeMe::genJacobOrder(size_t count) {
    std::vector<size_t> jacSeq;      
    jacSeq.push_back(0);            
    jacSeq.push_back(1);      

    //    J(n)=J(n-1) + 2*J(n-2)
    while (true) {
        size_t sz = jacSeq.size();
        size_t nextVal = jacSeq[sz - 1] + 2 * jacSeq[sz - 2];
        if (nextVal >= count)
            break;
        jacSeq.push_back(nextVal);
    }

    // 2) Remove duplicates and sort.
    std::set<size_t> uniqueSet(jacSeq.begin(), jacSeq.end());
    std::vector<size_t> uniqueJacob;
    for (std::set<size_t>::iterator it = uniqueSet.begin(); it != uniqueSet.end(); ++it) {
        if (*it < count)
            uniqueJacob.push_back(*it);
    }
    // uniqueJacob now contains Jacobsthal numbers < count in ascending order

    // 3) Add any missing indices [0..count-1] that are not in uniqueSet, in ascending order
    for (size_t i = 0; i < count; i++) {
        if (uniqueSet.find(i) == uniqueSet.end()) {
            uniqueJacob.push_back(i);
        }
    }
    return uniqueJacob;
}


void PmergeMe::insertionSortVector(std::vector<int> &vec) {
    const int INSERTION_THRESHOLD = 5; 
    size_t n = vec.size();
    if (n <= static_cast<size_t>(INSERTION_THRESHOLD)) {
        insertionSortRangeVector(vec, 0, static_cast<int>(n) - 1);
        return;
    }
    // Split into (leader/follower) pairs
    std::vector<int> leaders;
    std::vector<int> followers;
    leaders.reserve(n / 2 + 1);
    followers.reserve(n / 2 + 1);

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
            // if there's an odd number of elements, the last goes to leaders
            leaders.push_back(vec[i]);
        }
    }
    // Recursively sort leaders
    insertionSortVector(leaders);

    std::vector<size_t> jacOrder = genJacobOrder(followers.size());
    for (size_t i = 0; i < jacOrder.size(); i++) {
        size_t idx = jacOrder[i];
        // idx is an index in followers
        if (idx < followers.size()) {
            binaryInsertVector(leaders, followers[idx]);
        }
    }
    // Update
    vec = leaders;
}

// Binary search insertion: find position via binary search and insert
void PmergeMe::binaryInsertVector(std::vector<int> &arr, int x) {
    if (arr.empty()) {
        arr.push_back(x);
        return;
    }
    int left = 0, right = static_cast<int>(arr.size()) - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] < x)
            left = mid + 1;
        else
            right = mid - 1;
    }
    arr.insert(arr.begin() + left, x);
}

// Standard insertion sort in the subrange [left, right]
void PmergeMe::insertionSortRangeVector(std::vector<int> &arr, int left, int right) {
    for (int i = left + 1; i <= right; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= left && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
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
    // Split into (leader, follower) pairs
    std::list<int> leaders;
    std::list<int> followers;
    splitListIntoPairs(lst, leaders, followers);

    // Recursively sort leaders
    recursiveSortList(leaders);

    // Insert followers one by one into the sorted list of leaders
    for (std::list<int>::iterator it = followers.begin(); it != followers.end(); ++it) {
        insertSortedList(leaders, *it);
    }
    // Swap back
    lst.swap(leaders);
}

void PmergeMe::insertionSortList(std::list<int> &lst) {
    if (lst.size() < 2)
        return;
    for (std::list<int>::iterator it = ++lst.begin(); it != lst.end(); ++it) {
        int key = *it;
        std::list<int>::iterator j = it;
        while (j != lst.begin()) {
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

void PmergeMe::insertSortedList(std::list<int> &lst, int value) {
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
            // if an odd count => last one alone goes to leaders
            leaders.push_back(first);
        }
    }
}
