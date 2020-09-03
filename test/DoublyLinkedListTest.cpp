// #include "DoublyLinkedList.h"
// #include "Test.h"

// const int SIZE = 40;

// void test()
// {
//     auto l = DoublyLinkedList<int>();
//     int item;

//     // Empty list edge cases
//     assertTrue(l.isEmpty(), "List should be empty.");
//     assertEquals(l.getLength(), 0, "Empty list's item count should be 0.");
//     assertFalse(l.insert(3, 3), "Empty list's items' index start at 1.");
//     assertFalse(l.insert(0, 3), "Empty list's items' index start at 1.");
//     assertFalse(l.getItem(1, item), "Empty list should not have vaild items.");

//     // Fill the list
//     for (int i = 0; i < SIZE / 2; i++)
//         assertTrue(l.insert(1, i), "List should have space for new items.");
//     for (int i = 1; i <= SIZE / 2; i++)
//         assertTrue(l.insert(i, i), "List should have space for new items.");
//     assertFalse(l.isEmpty(), "List should not be empty");
//     assertEquals(l.getLength(), SIZE, "List's size should be half of max size.");

//     // Insertion edge case
//     assertFalse(l.insert(SIZE + 2, 2), "List's items should have consequtive indexes.");

//     // Removal quarter of items
//     auto current = l.getLength();
//     for (int i = 1; i <= current / 4; i++)
//         assertTrue(l.remove(i), "List should contain items.");

//     auto l2 = l;
//     auto l3 = DoublyLinkedList<int>();
//     l3 = l;

//     // Remove all items from the list
//     current = l.getLength();
//     for (int i = 0; i < current; i++)
//         assertTrue(l.remove(1), "The list should not be empty.");
//     assertFalse(l.remove(1), "The list should be empty");
//     assertTrue(l.isEmpty(), "List should be empty.");

//     // Test newly added members
//     assertTrue(l.insert(1, 5), "List should have space for the items.");
//     assertTrue(l.getItem(1, item), "List should have the first item.");
//     assertEquals(item, 5, "List have retruned wrong item.");

//     // Re-fill the list
//     for (int i = 0; i < SIZE / 2; i++)
//         assertTrue(l.insert(1, i), "List should have space for new items.");
//     for (int i = 1; i <= SIZE / 2; i++)
//         assertTrue(l.insert(i, i), "List should have space for new items.");
// }
// RUN_TEST(test)
