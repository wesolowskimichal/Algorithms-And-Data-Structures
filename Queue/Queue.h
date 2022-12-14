#pragma once
#include <vector>
template<typename T>
class Queue
{
private:
	std::vector<T> arr;
public:
	Queue();
	unsigned int size() const;
	void push(T value);
	T pop();
	T front() const;
	T back() const;
	bool empty();
};

