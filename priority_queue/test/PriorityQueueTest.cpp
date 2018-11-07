#include "gtest/gtest.h"

#include "GenericComparer.hpp"
#include "BinaryHeap.hpp"
#include <cstring>

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

TEST(BinaryHeap, inserting_in_right_order) {
    auto heap = BinaryHeap<int>();
    heap.insertItem(4);
    heap.insertItem(3);
    heap.insertItem(2);
    heap.insertItem(1);
    int array[] = { 4, 3, 2, 1 };
    int *expectedState = array;
    ASSERT_EQ(0, std::memcmp(heap.getInnerHeap(), expectedState, sizeof(int) * 4));
}

TEST(BinaryHeap, swim_from_bottom) {
    int* initialState = new int[4] { 4, 3, 2, 0 };
    auto heap = BinaryHeap<int>(initialState, 3, 4);
    heap.insertItem(5);
    int array[] = { 5, 4, 2, 3 };
    int *expectedState = array;
    ASSERT_EQ(0, std::memcmp(heap.getInnerHeap(), expectedState, sizeof(int) * 4));
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}