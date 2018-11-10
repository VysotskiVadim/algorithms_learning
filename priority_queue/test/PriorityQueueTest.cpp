#include "gtest/gtest.h"

#include "GenericComparer.hpp"
#include "BinaryHeap.hpp"
#include <cstring>
#include <stdexcept>

using namespace al;

TEST(Comparer, intGenericComparerTest) {
    auto comparer = std::unique_ptr< Comparer<int> >(new GenericComparer<int>());
    int result = comparer->compare(1, 2);
    ASSERT_EQ(result, -1);
}

TEST(BinaryHeap, defaultState) {
    auto heap = BinaryHeap<int>();
    ASSERT_EQ(0, heap.getSize());
    ASSERT_EQ(10, heap.getCapacity());
}

TEST(BinaryHeap, inserting_heap_ordered_sequence) {
    auto heap = BinaryHeap<int>();
    heap.insertItem(4);
    heap.insertItem(3);
    heap.insertItem(2);
    heap.insertItem(1);
    int array[] = { 4, 3, 2, 1 };
    int *expectedState = array;
    ASSERT_EQ(0, std::memcmp(heap.getInnerHeap(), expectedState, sizeof(int) * 4));
    ASSERT_EQ(10, heap.getCapacity());
    ASSERT_EQ(4, heap.getSize());
}

TEST(BinaryHeap, swim_from_bottom) {
    int* initialState = new int[4] { 4, 3, 2, 0 };
    auto heap = BinaryHeap<int>(initialState, 3, 4);
    heap.insertItem(5);
    int array[] = { 5, 4, 2, 3 };
    int *expectedState = array;
    ASSERT_EQ(0, std::memcmp(heap.getInnerHeap(), expectedState, sizeof(int) * 4));
}

TEST(BinaryHeap, heap_owerflow) {
    int* initialState = new int[3] { 4, 3, 2 };
    auto heap = BinaryHeap<int>(initialState, 3, 3);
    heap.insertItem(5);
    int array[] = { 5, 4, 2, 3 };
    int *expectedState = array;
    ASSERT_EQ(0, std::memcmp(heap.getInnerHeap(), expectedState, sizeof(int) * 4));
    ASSERT_EQ(4, heap.getSize());
    ASSERT_EQ(6, heap.getCapacity());
}

TEST(BinaryHeap, get_item_by_index) {
    int* initialState = new int[4] { 10, 9, 8, 7 };
    auto heap = BinaryHeap<int>(initialState, 4, 4);
    ASSERT_EQ(10, heap.getItem(1));
    ASSERT_EQ(7, heap.getItem(4));
}

TEST(BinaryHeap, get_item_by_index_out_of_range) {
    int* initialState = new int[5] { 10, 9, 8, 7, 0 };
    auto heap = BinaryHeap<int>(initialState, 4, 5);
    ASSERT_THROW({
        heap.getItem(0);
    }, std::out_of_range);
    ASSERT_THROW({
        heap.getItem(5);
    }, std::out_of_range);
}

TEST(BinaryHeap, set_item_by_index) {
    int* initialState = new int[5] { 10, 9, 8, 7, 6 };
    auto heap = BinaryHeap<int>(initialState, 4, 5);
    heap.setItem(1, -4);
    heap.setItem(4, 99);
    heap.setItem(5, 100);
    ASSERT_EQ(-4, heap.getItem(1));
    ASSERT_EQ(99, heap.getItem(4));
}

TEST(BinaryHeap, set_item_by_index_out_of_range) {
    int* initialState = new int[5] { 10, 9, 8, 7, 0 };
    auto heap = BinaryHeap<int>(initialState, 4, 5);
    ASSERT_THROW({
        heap.setItem(0, 0);
    }, std::out_of_range);
    ASSERT_THROW({
        heap.setItem(6, 0);
    }, std::out_of_range);
}

TEST(BinaryHeap, heap_remove_from_top) {
    int* initialState = new int[7] { 10, 8, 9, 7, 6, 5, 4 };
    auto heap = BinaryHeap<int>(initialState, 7, 7);

    int removedItem = heap.removeItemFromTop();

    ASSERT_EQ(10, removedItem);
    int* expectedState = new int[7] { 9, 8, 5, 7, 6, 4 };
    ASSERT_EQ(0, std::memcmp(heap.getInnerHeap(), expectedState, sizeof(int) * 4));
    delete [] expectedState;
    ASSERT_EQ(6, heap.getSize());
    ASSERT_EQ(7, heap.getCapacity());
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}