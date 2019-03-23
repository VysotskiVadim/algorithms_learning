#include "gtest/gtest.h"

#include "GenericComparer.hpp"
#include "BinaryHeap.hpp"
#include <cstring>
#include <stdexcept>
#include "BinaryHeapBasedPriorityQueue.hpp"

using namespace al;

TEST(Comparer, intGenericComparerTest) {
    auto comparer = std::unique_ptr< Comparer<int> >(new GenericComparer<int>());
    int result = comparer->compare(1, 2);
    ASSERT_EQ(result, -1);
}

TEST(BinaryHeap, defaultState) {
    BinaryHeap<int> heap;
    ASSERT_EQ(0, heap.getSize());
    ASSERT_EQ(10, heap.getCapacity());
}

TEST(BinaryHeap, inserting_heap_ordered_sequence) {
    BinaryHeap<int> heap;
    heap.insertItem(4);
    heap.insertItem(3);
    heap.insertItem(2);
    heap.insertItem(1);
    int expectedState[] = { 4, 3, 2, 1 };
    ASSERT_EQ(0, std::memcmp(heap.getInnerHeap(), &expectedState, sizeof(int) * 4));
    ASSERT_EQ(10, heap.getCapacity());
    ASSERT_EQ(4, heap.getSize());
}

TEST(BinaryHeap, swim_from_bottom) {
    int* initialState = new int[4] { 4, 3, 2, 0 };
    BinaryHeap<int> heap(initialState, 3, 4);
    heap.insertItem(5);
    int expectedState[] = { 5, 4, 2, 3 };
    ASSERT_EQ(0, std::memcmp(heap.getInnerHeap(), &expectedState, sizeof(int) * 4));
}

TEST(BinaryHeap, heap_owerflow) {
    int* initialState = new int[3] { 4, 3, 2 };
    BinaryHeap<int> heap(initialState, 3, 3);
    heap.insertItem(5);
    int expectedState[] = { 5, 4, 2, 3 };
    ASSERT_EQ(0, std::memcmp(heap.getInnerHeap(), &expectedState, sizeof(int) * 4));
    ASSERT_EQ(4, heap.getSize());
    ASSERT_EQ(6, heap.getCapacity());
}

TEST(BinaryHeap, get_item_by_index) {
    int* initialState = new int[4] { 10, 9, 8, 7 };
    BinaryHeap<int> heap(initialState, 4, 4);
    ASSERT_EQ(10, heap.getItem(1));
    ASSERT_EQ(7, heap.getItem(4));
}

TEST(BinaryHeap, get_item_by_index_out_of_range) {
    int* initialState = new int[5] { 10, 9, 8, 7, 0 };
    BinaryHeap<int> heap(initialState, 4, 5);
    ASSERT_THROW({
        heap.getItem(0);
    }, std::out_of_range);
    ASSERT_THROW({
        heap.getItem(5);
    }, std::out_of_range);
}

TEST(BinaryHeap, set_item_by_index) {
    int* initialState = new int[5] { 10, 9, 8, 7, 6 };
    BinaryHeap<int> heap(initialState, 4, 5);
    heap.setItem(1, -4);
    heap.setItem(4, 99);
    heap.setItem(5, 100);
    ASSERT_EQ(-4, heap.getItem(1));
    ASSERT_EQ(99, heap.getItem(4));
}

TEST(BinaryHeap, set_item_by_index_out_of_range) {
    int* initialState = new int[5] { 10, 9, 8, 7, 0 };
    BinaryHeap<int> heap(initialState, 4, 5);
    ASSERT_THROW({
        heap.setItem(0, 0);
    }, std::out_of_range);
    ASSERT_THROW({
        heap.setItem(6, 0);
    }, std::out_of_range);
}

TEST(BinaryHeap, heap_remove_from_top) {
    int* initialState = new int[7] { 10, 8, 9, 7, 6, 5, 4 };
    BinaryHeap<int> heap(initialState, 7, 7);

    int removedItem = -1;
    bool result = heap.removeItemFromTop(removedItem);

    ASSERT_TRUE(result);
    ASSERT_EQ(10, removedItem);
    int expectedState[] = { 9, 8, 5, 7, 6, 4 };
    ASSERT_EQ(0, std::memcmp(heap.getInnerHeap(), &expectedState, sizeof(int) * 4));
    ASSERT_EQ(6, heap.getSize());
    ASSERT_EQ(7, heap.getCapacity());
}

TEST(BinaryHeap, heap_remove_five_items) {
    int* initialState = new int[5] { 6, 5, 4, 3, 2 };
    BinaryHeap<int> heap(initialState, 5, 5);

    int nextElement = -1;
    bool result = false;

    result = heap.removeItemFromTop(nextElement);
    ASSERT_EQ(6, nextElement);
    ASSERT_EQ(true, result);
    ASSERT_EQ(4, heap.getSize());

    result = heap.removeItemFromTop(nextElement);
    ASSERT_EQ(5, nextElement);
    ASSERT_EQ(true, result);
    ASSERT_EQ(3, heap.getSize());

    result = heap.removeItemFromTop(nextElement);
    ASSERT_EQ(4, nextElement);
    ASSERT_EQ(true, result);
    ASSERT_EQ(2, heap.getSize());

    result = heap.removeItemFromTop(nextElement);
    ASSERT_EQ(3, nextElement);
    ASSERT_EQ(true, result);
    ASSERT_EQ(1, heap.getSize());

    result = heap.removeItemFromTop(nextElement);
    ASSERT_EQ(2, nextElement);
    ASSERT_EQ(true, result);
    ASSERT_EQ(0, heap.getSize());

    nextElement = -555;
    result = heap.removeItemFromTop(nextElement);
    ASSERT_EQ(-555, nextElement);
    ASSERT_EQ(false, result);
    ASSERT_EQ(0, heap.getSize());
}

TEST(PriorityQueue, queue) {
    const int sequenceSize = 10;
    int sequence[] = { 234, 58, 394, 5630, 37, 44, 36, 30, 27, 39 };
    BinaryHeapBasedPriorityQueue<int> queue;

    for (int i = 0; i < sequenceSize; i++) {
        queue.addItem(sequence[i]);
    }

    int previousIteam = -1;
    int removedItem = -2;
    queue.removeNext(previousIteam);
    for (int i = 1; i < sequenceSize; i++) {
        bool removedSuccessfully = queue.removeNext(removedItem);
        ASSERT_TRUE(removedSuccessfully);
        ASSERT_LE(removedItem, previousIteam);
        previousIteam = removedItem;
    }
    ASSERT_FALSE(queue.removeNext(removedItem));
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}