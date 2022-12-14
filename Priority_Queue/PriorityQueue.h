#pragma once
#include <vector>
template<typename T>
class PriorityQueue
{
private:
	std::vector<T> arr;
public:
	PriorityQueue();
	unsigned int size() const;
	void push(T value);
	T pop();
	T front() const;
	T back() const;
	bool empty() const;
};
