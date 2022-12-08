#include "ONP_CONV.h"
#include <vector>

string conv_from_ONP(string eq)
{
    unordered_map<char, int> prio = { {'(', 0}, {'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}, {'^', 3} };
    stack<string> stos;
    stack<int> priostack;
    string temp = "";
    int nums{}, ops{};

    for (int i = 0; i < eq.length(); i++)
    {
        if (eq[i] != '(' && eq[i] != ')') {
            if (isalnum(eq[i]))
            {
                string s = "";
                s += eq[i];
                stos.push(s);
                priostack.push(prio[eq[i]]);
                nums++;
            }
            else
            {
                temp = "";
                ops++;
                if (priostack.top() <= prio[eq[i]])
                    temp = "(" + stos.top() + ")";
                else
                    temp = stos.top();
                stos.pop();
                priostack.pop();
                if (priostack.top() < prio[eq[i]]) {
                    string s = "";
                    s += eq[i];
                    temp = "(" + stos.top() + ")" + s + temp;
                }
                else {
                    temp = stos.top() + eq[i] + temp;
                }
                stos.pop();
                priostack.pop();
                stos.push(temp);
                priostack.push(prio[eq[i]]);
            }
        }
    }
    if (nums - 1 == ops) {
        return stos.top();
    }
    cerr << "WRONG DATA\n";
    return "ERROR";
}