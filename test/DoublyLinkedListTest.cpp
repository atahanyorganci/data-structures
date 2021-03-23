#include "adt/DoublyLinkedList.h"

#include <catch2/catch.hpp>

const int SIZE = 40;

TEST_CASE("DoublyLinkedListTest", "[DoublyLinkedList]") {
    auto l = DoublyLinkedList<int>();
    int item;

    // Empty list edge cases
    REQUIRE(l.isEmpty());
    REQUIRE(l.getLength() == 0);
    REQUIRE_FALSE(l.insert(3, 3));
    REQUIRE_FALSE(l.insert(0, 3));
    REQUIRE_FALSE(l.getItem(1, item));

    // Fill the list
    for (int i = 0; i < SIZE / 2; i++)
        REQUIRE(l.insert(1, i));
    for (int i = 1; i <= SIZE / 2; i++)
        REQUIRE(l.insert(i, i));
    REQUIRE_FALSE(l.isEmpty());
    REQUIRE(l.getLength() == SIZE);

    // Insertion edge case
    REQUIRE_FALSE(l.insert(SIZE + 2, 2));

    // Removal quarter of items
    auto current = l.getLength();
    for (int i = 1; i <= current / 4; i++)
        REQUIRE(l.remove(i));

    auto l2 = l;
    auto l3 = DoublyLinkedList<int>();
    l3 = l;

    // Remove all items from the list
    current = l.getLength();
    for (int i = 0; i < current; i++)
        REQUIRE(l.remove(1));
    REQUIRE_FALSE(l.remove(1));
    REQUIRE(l.isEmpty());

    // Test newly added members
    REQUIRE(l.insert(1, 5));
    REQUIRE(l.getItem(1, item));
    REQUIRE(item == 5);

    // Re-fill the list
    for (int i = 0; i < SIZE / 2; i++)
        REQUIRE(l.insert(1, i));
    for (int i = 1; i <= SIZE / 2; i++)
        REQUIRE(l.insert(i, i));
}
