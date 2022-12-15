#include <gtest/gtest.h>
#include "Stack.h"
#include "Stack.cpp"
#include <stack>

class StackTest : public ::testing::Test {
protected:
    std::stack<int>* ss;
    Stack<int>* ms;
    StackTest() {
        ss = new std::stack<int>();
        ms = new Stack<int>();
    }

    ~StackTest() override {
        delete ss;
        delete ms;
    }
};


TEST_F(StackTest, Comparions) {
    ms->push(1);
    ss->push(1);
    EXPECT_EQ(ms->top(), ss->top());
    ms->push(2);
    ss->push(2);
    EXPECT_EQ(ms->top(), ss->top());
    ms->pop();
    ss->pop();
    EXPECT_EQ(ms->top(), ss->top());
    ms->push(2);
    ss->push(2);
    ms->push(3);
    ss->push(3);
    EXPECT_EQ(ms->top(), ss->top());
    ms->pop();
    ss->pop();
    ms->pop();
    ss->pop();
    EXPECT_EQ(ms->top(), ss->top());
}