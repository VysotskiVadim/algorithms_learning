#include "gtest/gtest.h"

#include "Comparer.hpp"
#include "GenericComparer.hpp"
#include "BinaryHeapBasedPriorityQueue.hpp"

using namespace al;

TEST(Comparer, intGenericComparerTest) {
    auto comparer = std::unique_ptr< Comparer<int> >(new GenericComparer<int>());
    int result = comparer->compare(1, 2);
    ASSERT_EQ(result, -1);
}

TEST(PriorityQueue, queueInitialState) {
    auto queue = std::unique_ptr< PriorityQueue<float> >(new BinaryHeapBasedPriorityQueue<float>());
    ASSERT_EQ(queue->getCount(), 0);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}