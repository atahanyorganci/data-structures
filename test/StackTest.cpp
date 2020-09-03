// #include "Stack.h"
// #include "Test.h"

// void test()
// {
//     const int SIZE = 10;
//     auto s = Stack<int>();
//     int data;

//     // Empty stack cases
//     assertTrue(s.isEmpty(), "Stack should be empty.");
//     assertFalse(s.getTop(data), "Stack should be empty.");
//     assertFalse(s.pop(data), "Stack should be empty.");
//     assertFalse(s.pop(), "Stack should be empty.");

//     // Empty Stack's constructors, and assignment operators
//     auto s2 = Stack<int>(s);
//     auto s3 = Stack<int>();
//     s2 = s;
//     s3 = s;

//     // Pushing data onto the stack
//     for (int i = 1; i <= SIZE; i++)
//         assertTrue(s.push(i), "New item should be inserted");
//     assertFalse(s.isEmpty(), "Stack should not be empty.");

//     auto s4 = Stack<int>(s);
//     auto s5 = Stack<int>();
//     s4 = s;
//     s5 = s;

//     // Poping values from the stack
//     for (int i = SIZE; i > 0; i--)
//     {
//         assertTrue(s.pop(data), "Stack should not be empty.");
//         assertEquals(data, i, "Poped value and loop index should match.");
//     }
//     auto s6 = Stack<int>(s);
//     auto s7 = Stack<int>();
//     s6 = s;
//     s7 = s;

//     // Empty stack cases
//     assertTrue(s.isEmpty(), "Stack should be empty.");
//     assertFalse(s.getTop(data), "Stack should be empty.");
//     assertFalse(s.pop(data), "Stack should be empty.");
//     assertFalse(s.pop(), "Stack should be empty.");

//     // Mixed pop and push
//     for (int i = 1; i <= SIZE; i++)
//         assertTrue(s.push(i), "New item should be inserted");
//     for (int i = SIZE; i > SIZE / 2; i--)
//         assertTrue(s.pop(), "Stack should not be empty.");
//     for (int i = 1; i <= SIZE; i++)
//         assertTrue(s.push(i), "New item should be inserted");
// }
// RUN_TEST(test);
