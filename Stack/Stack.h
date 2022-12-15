#pragma once
#include <vector>

template<typename T>
class Stack
{
private:
	std::vector<T> arr;
public:
	Stack();
	~Stack();
	unsigned int size() const;
	void push(T value);
	bool empty() const;
	T top() const;
	T pop();
};

