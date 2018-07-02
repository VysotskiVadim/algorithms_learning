#include "gtest/gtest.h"

#include "RingBuffer.hpp"
using namespace al;


TEST(RingBuffer, createThenDestruct) {
    RingBuffer *rb = new RingBuffer(40);
    delete rb;
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}