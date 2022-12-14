#include <gtest/gtest.h>
#include "Queue.h"
#include "Queue.cpp"
#include <queue>

class QueueTest : public ::testing::Test {
protected:
    std::queue<int>* sq;
    Queue<int>* mq;
    QueueTest() {
        sq = new std::queue<int>();
        mq = new Queue<int>();
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
    EXPECT_EQ(sq->front(), mq->front());
    EXPECT_EQ(sq->back(), mq->back());
    sq->pop();
    mq->pop();
    EXPECT_EQ(sq->front(), mq->front());
    EXPECT_EQ(sq->back(), mq->back());
    sq->pop();
    mq->pop();
    sq->push(2);
    mq->push(2);
    EXPECT_EQ(sq->front(), mq->front());
    EXPECT_EQ(sq->back(), mq->back());
    EXPECT_EQ(sq->front(), mq->front());
    EXPECT_EQ(sq->back(), mq->back());
    sq->pop();
    mq->pop();
}