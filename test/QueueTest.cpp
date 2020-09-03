// #include "Queue.h"
// #include "Test.h"

// void test()
// {
//     const int SIZE = 10;
//     auto s = Queue<int>();
//     int data;

//     // Empty queue cases
//     assertTrue(s.isEmpty(), "Queue should be empty.");
//     assertFalse(s.getFront(data), "Queue should be empty.");
//     assertFalse(s.dequeue(data), "Queue should be empty.");
//     assertFalse(s.dequeue(), "Queue should be empty.");

//     // Empty Queue's constructors, and assignment operators
//     auto s2 = Queue<int>(s);
//     auto s3 = Queue<int>();
//     s2 = s;
//     s3 = s;

//     // Queuing data onto the queue
//     for (int i = 0; i < SIZE; i++)
//         assertTrue(s.enqueue(i), "New item should be inserted");
//     assertFalse(s.isEmpty(), "Queue should not be empty.");

//     auto s4 = Queue<int>(s);
//     auto s5 = Queue<int>();
//     s4 = s;
//     s5 = s;

//     // Dequeueing values from the queue
//     for (int i = 0; i < SIZE; i++)
//     {
//         assertTrue(s.dequeue(data), "Queue should not be empty.");
//         assertEquals(data, i, "Dequeued value and loop index should match.");
//     }
//     auto s6 = Queue<int>(s);
//     auto s7 = Queue<int>();
//     s6 = s;
//     s7 = s;

//     // Empty queue cases
//     assertTrue(s.isEmpty(), "Queue should be empty.");
//     assertFalse(s.getFront(data), "Queue should be empty.");
//     assertFalse(s.dequeue(data), "Queue should be empty.");
//     assertFalse(s.dequeue(), "Queue should be empty.");

//     // Mixed dequeue and queue
//     for (int i = 1; i <= SIZE; i++)
//         assertTrue(s.enqueue(i), "New item should be inserted");
//     for (int i = SIZE; i > SIZE / 2; i--)
//         assertTrue(s.dequeue(), "Queue should not be empty.");
//     for (int i = 1; i <= SIZE; i++)
//         assertTrue(s.enqueue(i), "New item should be inserted");
// }
// RUN_TEST(test);
