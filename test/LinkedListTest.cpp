#include "adt/LinkedList.h"
#include <catch2/catch.hpp>

TEST_CASE("LinkedListTest", "[LinkedList]") {
    auto l = LinkedList<int>();
    int item = 0;
    const size_t SIZE = 40;

    REQUIRE(l.isEmpty());
    REQUIRE(l.getLength() == 0);
    REQUIRE_FALSE(l.insert(3, 3));
    REQUIRE_FALSE(l.insert(1, 3));
    REQUIRE_FALSE(l.getItem(0, item));

    // single insertion, and retrival
    REQUIRE(l.insert(0, 5));
    REQUIRE(l.getItem(0, item));
    REQUIRE(item == 5);
    REQUIRE(l.remove(0));

    // inserting items to the list
    for (size_t i = 0; i < SIZE / 2; i++)
        REQUIRE(l.insert(0, static_cast<int>(i)));
    for (size_t i = 0; i < SIZE / 2; i++)
        REQUIRE(l.insert(0, static_cast<int>(i)));
    REQUIRE_FALSE(l.isEmpty());
    REQUIRE(l.getLength() == SIZE);
    REQUIRE_FALSE(l.insert(SIZE + 2, 2));

    // remove quarter of items
    size_t current = static_cast<size_t>(l.getLength());
    for (size_t i = 0; i <= current / 4; i++)
        REQUIRE(l.remove(0));

    // assignment operator, and copy constructor
    auto l2 = l;
    auto l3 = LinkedList<int>();
    l3 = l;

    // remove all items from the list
    current = static_cast<size_t>(l.getLength());
    for (size_t i = 0; i < current; i++)
        REQUIRE(l.remove(0));
    REQUIRE_FALSE(l.remove(0));

    // re-fill the list
    for (size_t i = 0; i < SIZE / 2; i++)
        REQUIRE(l.insert(0, i));
    for (size_t i = 0; i <= SIZE / 2; i++)
        REQUIRE(l.insert(i, i));
}
