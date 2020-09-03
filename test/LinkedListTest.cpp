#include "LinkedList.h"
#include <catch2/catch.hpp>

TEST_CASE("LinkedList test", "[LinkedList]") {
    auto l = LinkedList<int>();
    int item = 0;
    const int SIZE = 40;

    REQUIRE(l.isEmpty());
    REQUIRE(l.getLength() == 0);
    REQUIRE_FALSE(l.insert(3, 3));
    REQUIRE_FALSE(l.insert(0, 3));
    REQUIRE_FALSE(l.getItem(1, item));

    SECTION("single insertion, and retrival") {
        REQUIRE(l.insert(1, 5));
        REQUIRE(l.getItem(1, item));
        REQUIRE(item == 5);
        REQUIRE(l.remove(1));
    }
    SECTION("inserting items to the list") {
        for (int i = 0; i < SIZE / 2; i++)
            REQUIRE(l.insert(1, i));
        for (int i = 1; i <= SIZE / 2; i++)
            REQUIRE(l.insert(i, i));
        REQUIRE_FALSE(l.isEmpty());
        REQUIRE(l.getLength() == SIZE);
        REQUIRE_FALSE(l.insert(SIZE + 2, 2));
    }
    SECTION("remove quarter of items") {
        auto current = l.getLength();
        for (int i = 1; i <= current / 4; i++)
            REQUIRE(l.remove(i));
    }
    SECTION("assignment operator, and copy constructor") {
        auto l2 = l;
        auto l3 = LinkedList<int>();
        l3 = l;
    }
    SECTION("remove all items from the list") {
        auto current = l.getLength();
        for (int i = 0; i < current; i++)
            REQUIRE(l.remove(1));
        REQUIRE_FALSE(l.remove(1));
    }
    SECTION("re-fill the list") {
        for (int i = 0; i < SIZE / 2; i++)
            REQUIRE(l.insert(1, i));
        for (int i = 1; i <= SIZE / 2; i++)
            REQUIRE(l.insert(i, i));
    }
}
