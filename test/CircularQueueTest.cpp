#include "adt/CircularQueue.h"
#include <catch2/catch.hpp>

TEST_CASE("CircularQueue", "[CircularQueue]") {
    const int SIZE = 10;
    auto cq = CircularQueue<int>(SIZE);
    int data;

    // empty queue cases
    REQUIRE(cq.isEmpty());
    REQUIRE_FALSE(cq.getFront(data));
    REQUIRE_FALSE(cq.dequeue(data));
    REQUIRE_FALSE(cq.dequeue());

    // copy constructor, and assignment operator
    auto cq2 = CircularQueue<int>(cq);
    auto cq3 = CircularQueue<int>();
    cq2 = cq;
    cq3 = cq;

    // queue data
    for (int i = 0; i < SIZE; i++)
        REQUIRE(cq.enqueue(i));
    REQUIRE_FALSE(cq.isEmpty());
    REQUIRE(cq.isFull());

    // copy constructor, and assignment operator
    auto cq4 = CircularQueue<int>(cq);
    auto cq5 = CircularQueue<int>();
    cq4 = cq;
    cq5 = cq;

    // dequeue values
    for (int i = 0; i < SIZE; i++) {
        CAPTURE(i);
        REQUIRE(cq.dequeue(data));
        REQUIRE(data == i);
    }
    REQUIRE(cq.isEmpty());
    REQUIRE_FALSE(cq.getFront(data));
    REQUIRE_FALSE(cq.dequeue(data));
    REQUIRE_FALSE(cq.dequeue());
    UNSCOPED_INFO("Queue is empty.");

    // copy constructor, and assignment operator
    auto cq6 = CircularQueue<int>(cq);
    auto cq7 = CircularQueue<int>();
    cq6 = cq;
    cq7 = cq;

    // mixed dequeue and queue
    for (int i = 0; i < SIZE; i++)
        REQUIRE(cq.enqueue(i));
    REQUIRE(cq.isFull());
    for (int i = 0; i < SIZE; i++)
        REQUIRE(cq.dequeue());
    for (int i = 0; i < SIZE; i++)
        REQUIRE(cq.enqueue(i));
}
