#include "gtest/gtest.h"

#include <cstring>
#include <stdexcept>
#include "BinaryHeapBasedPriorityQueue.hpp"

using namespace al;

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