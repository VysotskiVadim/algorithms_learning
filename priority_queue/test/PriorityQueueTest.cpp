#include "gtest/gtest.h"

#include "GenericComparer.hpp"
#include "BinaryHeap.hpp"

using namespace al;

TEST(Comparer, intGenericComparerTest) {
    auto comparer = std::unique_ptr< Comparer<int> >(new GenericComparer<int>());
    int result = comparer->compare(1, 2);
    ASSERT_EQ(result, -1);
}

TEST(BinaryHeap, defaultState) {
    auto heap = BinaryHeap<int>();
    ASSERT_EQ(10, heap.getSize());
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}