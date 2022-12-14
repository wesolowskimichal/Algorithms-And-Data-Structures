#include "Queue.h"
#include <iostream>
template<typename T>
Queue<T>::Queue() {};

template<typename T>
unsigned int Queue<T>::size() const {
	return arr.size();
}

template<typename T>
void Queue<T>::push(T value) {
	arr.push_back(value);
}

template<typename T>
T Queue<T>::pop() {
	try {
		if (empty())
			throw std::exception("EMPTY QUEUE");
	}
	catch (std::exception& e) {
		std::cerr << e.what();
	}
	T res = front();
	arr.erase(arr.begin());
	return res;
}

template<typename T>
T Queue<T>::front() const {
	try {
		if (empty())
			throw std::exception("EMPTY QUEUE");
	}
	catch (std::exception& e) {
		std::cerr << e.what();
	}
	return *arr.begin();
}

template<typename T>
T Queue<T>::back() const {
	try {
		if (empty())
			throw std::exception("EMPTY QUEUE");
	}
	catch (std::exception& e) {
		std::cerr << e.what();
	}
	return *arr.rbegin();
}

template<typename T>
bool Queue<T>::empty() {
	return arr.empty();
}