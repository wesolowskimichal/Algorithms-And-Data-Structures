#include <iostream>
#include <stack>
#include <unordered_map>

using namespace std;

string conv_to_ONP(string eq) { 
	unordered_map<char, int> prio = { {'(', 0}, {'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}, {'^', 3} };
	stack<char>ops;
	stack<int>brackets;
	string ans{};


	for (auto c : eq) {
		if (isalnum(c))
			ans += c;
		else if (c == '(')
			ops.push(c);
		else if (c == ')') {
			while (ops.top() != '(') {
				ans += ops.top();
				ops.pop();
			}
			ops.pop();
		}
		else {
			while (!ops.empty() && prio[ops.top()] >= prio[c]) {
				ans += ops.top();
				ops.pop();
			}
			ops.push(c);
		}
	}

	while (!ops.empty()) {
		ans += ops.top();
		ops.pop();
	}

	return ans;
}