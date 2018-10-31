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

TEST(PriorityQueue, createQueue) {
    //auto queue = std::unique_ptr< PriorityQueue<int> >(new BinaryHeapBasedPriorityQueue<int>());
    PriorityQueue<int> *queue = new BinaryHeapBasedPriorityQueue<int>();
    ASSERT_EQ(queue->getCount(), 0);
    delete queue;
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}