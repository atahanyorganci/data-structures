#include "adt/Queue.h"

#include <catch2/catch.hpp>

TEST_CASE("QueueTest", "[Queue]") {
    const int SIZE = 10;
    auto s = Queue<int>();
    int data;

    // Empty queue cases
    REQUIRE(s.isEmpty());
    REQUIRE_FALSE(s.getFront(data));
    REQUIRE_FALSE(s.dequeue(data));
    REQUIRE_FALSE(s.dequeue());

    // Empty Queue's constructors, and assignment operators
    auto s2 = Queue<int>(s);
    auto s3 = Queue<int>();
    s2 = s;
    s3 = s;

    // Queuing data onto the queue
    for (int i = 0; i < SIZE; i++)
        REQUIRE(s.enqueue(i));
    REQUIRE_FALSE(s.isEmpty());

    auto s4 = Queue<int>(s);
    auto s5 = Queue<int>();
    s4 = s;
    s5 = s;

    // Dequeueing values from the queue
    for (int i = 0; i < SIZE; i++) {
        REQUIRE(s.dequeue(data));
        REQUIRE(data == i);
    }

    auto s6 = Queue<int>(s);
    auto s7 = Queue<int>();
    s6 = s;
    s7 = s;

    // Empty queue cases
    REQUIRE(s.isEmpty());
    REQUIRE_FALSE(s.getFront(data));
    REQUIRE_FALSE(s.dequeue(data));
    REQUIRE_FALSE(s.dequeue());

    // Mixed dequeue and queue
    for (int i = 1; i <= SIZE; i++)
        REQUIRE(s.enqueue(i));
    for (int i = SIZE; i > SIZE / 2; i--)
        REQUIRE(s.dequeue());
    for (int i = 1; i <= SIZE; i++)
        REQUIRE(s.enqueue(i));
}
