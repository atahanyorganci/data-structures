// #include "List.h"
// #include "Test.h"

// const int SIZE = 30;

// void test()
// {
//     auto l = List<int>();
//     int item;

//     // Empty list edge cases
//     assertTrue(l.isEmpty(), "List should be empty.");
//     assertEquals(l.getCount(), 0, "Empty list's item count should be 0.");
//     assertFalse(l.insert(3, 3), "Empty list's items' index start at 1.");
//     assertFalse(l.insert(0, 3), "Empty list's items' index start at 1.");
//     assertFalse(l.getItem(1, item), "Empty list should not have vaild items.");

//     // Fill the half of the list
//     int count = l.getSize() / 2;
//     for (int i = 0; i < count; i++)
//         assertTrue(l.insert(1, i), "List should have space for new items.");
//     assertFalse(l.isEmpty(), "List should not be empty");
//     assertEquals(l.getCount(), count, "List's size should be half of max size.");
//     assertFalse(l.insert(count + 2, 2), "List's items' should have consequtive indexes.");

//     // Test for Memory leaks
//     assertFalse(l.resize(-1), "List's size should be positive");
//     assertFalse(l.resize(count - 1), "List cannot shrink below the item count.");
//     assertTrue(l.resize(count), "List's should be able shrink to item count.");
//     assertFalse(l.insert(1, 1), "List should be full.");
//     assertTrue(l.resize(SIZE), "List should be able to grow");

//     // Fill the rest of the list
//     auto remaining = SIZE - l.getCount();
//     for (int i = 0; i < remaining; i++)
//         assertTrue(l.insert(1, i), "List should have space for new items.");
//     assertEquals(l.getCount(), l.getSize(), "List should be full.");
//     assertFalse(l.insert(1, 2), "List should be full.");

//     auto l2 = l;
//     auto l3 = List<int>();
//     l3 = l;

//     // Remove all items from the list
//     for (int i = 0; i < l.getSize(); i++)
//         assertTrue(l.remove(1), "The list should not be empty.");
//     assertFalse(l.remove(1), "The list should be empty");
//     assertTrue(l.isEmpty(), "The list should be empty");

//     // Test newly added members
//     assertTrue(l.insert(1, 5), "List should have space for the items.");
//     assertTrue(l.getItem(1, item), "List should have the first item.");
//     assertEquals(item, 5, "List have retruned wrong item.");
//     assertTrue(l.remove(1), "The list should contain at least one item.");

//     // Refill the list
//     remaining = SIZE - l.getCount();
//     for (int i = 0; i < remaining; i++)
//         assertTrue(l.insert(1, i), "List should have space for new items.");
// }
// RUN_TEST(test)
