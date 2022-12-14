#include "PriorityQueue.h"
#include <iostream>

template<typename T>
PriorityQueue<T>::PriorityQueue() {};

template<typename T>
unsigned int PriorityQueue<T>::size() const {
	return arr.size();
}

template<typename T>
void PriorityQueue<T>::push(T value) {
	if(empty())
		arr.push_back(value);
	else {
		if (value > *arr.begin())
			arr.insert(arr.begin(), value);
		else if (value < *arr.rbegin())
			arr.push_back(value);
		else {
			int l{}, r = size();
			while (l < r) {
				int p = l + (r - l) / 2;
				if (arr[p] == value) {
					arr.insert(arr.begin() + p, value);
					return;
				}
				if (arr[p] < value)
					l = p + 1;
				else
					r = p - 1;
			}
			arr.insert(arr.begin() + r, value);
		}
	}
}

template<typename T>
T PriorityQueue<T>::pop() {
	try {
		if (empty())
			throw std::exception("EMPTY PriorityQueue");
	}
	catch (std::exception& e) {
		std::cerr << e.what();
	}
	T res = front();
	arr.erase(arr.begin());
	return res;
}

template<typename T>
T PriorityQueue<T>::front() const {
	try {
		if (empty())
			throw std::exception("EMPTY PriorityQueue");
	}
	catch (std::exception& e) {
		std::cerr << e.what();
	}
	return *arr.begin();
}

template<typename T>
T PriorityQueue<T>::back() const {
	try {
		if (empty())
			throw std::exception("EMPTY PriorityQueue");
	}
	catch (std::exception& e) {
		std::cerr << e.what();
	}
	return *arr.rbegin();
}

template<typename T>
bool PriorityQueue<T>::empty() const {
	return arr.empty();
}