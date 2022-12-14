#include <gtest/gtest.h>
#include "PriorityQueue.h"
#include "PriorityQueue.cpp"
#include <queue>

class QueueTest : public ::testing::Test {
protected:
    std::priority_queue<int>* sq;
    PriorityQueue<int>* mq;
    QueueTest() {
        sq = new std::priority_queue<int>();
        mq = new PriorityQueue<int>();
    }

    ~QueueTest() override {
        delete sq;
        delete mq;
    }
};


TEST_F(QueueTest, Comparions) {
    sq->push(1);
    sq->push(2);
    sq->push(3);
    mq->push(1);
    mq->push(2);
    mq->push(3);
    EXPECT_EQ(sq->top(), mq->front());
    sq->pop();
    mq->pop();
    EXPECT_EQ(sq->top(), mq->front());
    sq->pop();
    mq->pop();
    sq->push(2);
    mq->push(2);
    EXPECT_EQ(sq->top(), mq->front());
    sq->pop();
    mq->pop();
    EXPECT_EQ(sq->top(), mq->front());
    sq->pop();
    mq->pop();
}