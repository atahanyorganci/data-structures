#include "adt/Stack.h"

#include <catch2/catch.hpp>

TEST_CASE("StackTest", "[Stack]") {
    const int SIZE = 10;
    auto s = Stack<int>();
    int data;

    // Empty stack cases
    REQUIRE(s.isEmpty());
    REQUIRE_FALSE(s.getTop(data));
    REQUIRE_FALSE(s.pop(data));
    REQUIRE_FALSE(s.pop());

    // Empty Stack's constructors, and assignment operators
    auto s2 = Stack<int>(s);
    auto s3 = Stack<int>();
    s2 = s;
    s3 = s;

    // Pushing data onto the stack
    for (int i = 1; i <= SIZE; i++)
        REQUIRE(s.push(i));
    REQUIRE_FALSE(s.isEmpty());

    auto s4 = Stack<int>(s);
    auto s5 = Stack<int>();
    s4 = s;
    s5 = s;

    // Poping values from the stack
    for (int i = SIZE; i > 0; i--) {
        REQUIRE(s.pop(data));
        REQUIRE(data == i);
    }

    auto s6 = Stack<int>(s);
    auto s7 = Stack<int>();
    s6 = s;
    s7 = s;

    // Empty stack cases
    REQUIRE(s.isEmpty());
    REQUIRE_FALSE(s.getTop(data));
    REQUIRE_FALSE(s.pop(data));
    REQUIRE_FALSE(s.pop());

    // Mixed pop and push
    for (int i = 1; i <= SIZE; i++)
        REQUIRE(s.push(i));
    for (int i = SIZE; i > SIZE / 2; i--)
        REQUIRE(s.pop());
    for (int i = 1; i <= SIZE; i++)
        REQUIRE(s.push(i));
}
