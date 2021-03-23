#include "adt/List.h"
#include <catch2/catch.hpp>

TEST_CASE("ListTest", "[List]") {
    const size_t SIZE = 10;
    auto l = List<int>(SIZE);
    int data = 0;

    // empty list edge cases
    REQUIRE(l.isEmpty());
    REQUIRE(l.getCount() == 0);
    REQUIRE_FALSE(l.insert(3, 3));
    REQUIRE_FALSE(l.insert(1, 3));
    REQUIRE_FALSE(l.getItem(1, data));

    // copy constructor, and assignment operator
    auto l2 = List<int>(l);
    auto l3 = List<int>();
    l2 = l;
    l3 = l;

    // add data
    size_t count = static_cast<size_t>(l.getSize()) / 2;
    UNSCOPED_INFO("Adding data until list half is full.");
    for (size_t i = 0; i < count; i++)
        REQUIRE(l.insert(0, i));
    REQUIRE_FALSE(l.isEmpty());
    REQUIRE(static_cast<size_t>(l.getCount()) == count);
    REQUIRE_FALSE(l.getItem(count, data));

    // copy constructor, and assignment operator
    auto l4 = List<int>(l);
    auto l5 = List<int>();
    l4 = l;
    l5 = l;

    // resizing shouldn't leak memory
    count = static_cast<size_t>(l.getCount());
    REQUIRE_FALSE(l.resize(count - 1));
    REQUIRE(l.resize(count));
    REQUIRE_FALSE(l.insert(0, 1));
    REQUIRE(l.resize(SIZE));

    // fill rest of the list
    size_t remaining = SIZE - static_cast<size_t>(l.getCount());
    for (size_t i = 0; i < remaining; i++)
        REQUIRE(l.insert(0, i));
    REQUIRE(l.getCount() == l.getSize());
    REQUIRE_FALSE(l.insert(1, 2));

    // copy constructor, and assignment operator
    auto l6 = List<int>(l);
    auto l7 = List<int>();
    l6 = l;
    l7 = l;

    // Remove all items from the list
    count = static_cast<size_t>(l.getSize());
    for (size_t i = 0; i < count; i++)
        REQUIRE(l.remove(0));
    REQUIRE_FALSE(l.remove(1));
    REQUIRE(l.isEmpty());

    // Test newly added members
    const int new_data = 10;
    REQUIRE(l.insert(0, new_data));
    REQUIRE(l.getItem(0, data));
    REQUIRE(data == new_data);
    REQUIRE(l.remove(0));
}
