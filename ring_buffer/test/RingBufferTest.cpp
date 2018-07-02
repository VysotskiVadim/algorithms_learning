#include "gtest/gtest.h"
#include <string.h>

#include "RingBuffer.hpp"
using namespace al;


TEST(RingBuffer, createThenDestruct) {
    RingBuffer *rb = new RingBuffer(40);
    delete rb;
}

TEST(RingBuffer, writeAndReadInEmptyBuffer) {
    char *data = "the data";
    int length = strlen(data);
    RingBuffer rb(length);

    int written = rb.write(data, length);
    EXPECT_EQ(length, written);
    char *readedData = new char[length];
    int readed = rb.read(readedData, length);
    EXPECT_EQ(length, readed);
    ASSERT_STREQ(data, readedData);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}