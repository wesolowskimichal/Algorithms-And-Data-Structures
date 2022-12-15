#include "Stack.h"
#include <iostream>

template<typename T>
Stack<T>::Stack() {}
template<typename T>
Stack<T>::~Stack(){
	arr.clear();
}

template<typename T>
unsigned int Stack<T>::size() const {
	return arr.size();
}

template<typename T>
void Stack<T>::push(T value) {
	arr.push_back(value);
}

template<typename T>
T Stack<T>::pop() {
	try {
		if (empty())
			throw std::exception("EMPTY Stack");
	}
	catch (std::exception& e) {
		std::cerr << e.what();
	}
	T res = top();
	arr.pop_back();
	return res;
}

template<typename T>
T Stack<T>::top() const {
	try {
		if (empty())
			throw std::exception("EMPTY Stack");
	}
	catch (std::exception& e) {
		std::cerr << e.what();
	}
	return *arr.rbegin();
}

template<typename T>
bool Stack<T>::empty() const {
	return arr.empty();
}