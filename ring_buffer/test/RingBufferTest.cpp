#include "gtest/gtest.h"
#include <string.h>

#include "RingBufferHelper.hpp"
#include "RingBuffer.hpp"
using namespace al;

TEST(RingBufferHelper, getFreeSpace) {
    int result = -1;
    result = getFreeSpaceOfCycleBuffer(0, 2, 4);
    EXPECT_EQ(result, 2);
    result = getFreeSpaceOfCycleBuffer(1, 2, 4);
    EXPECT_EQ(result, 3);
    result = getFreeSpaceOfCycleBuffer(4, 2, 6);
    EXPECT_EQ(result, 2);
    result = getFreeSpaceOfCycleBuffer(0, 0, 8);
    EXPECT_EQ(result, 8);
}

TEST(RingBufferHelper, getUsedSpace) {
    int result = -1;
    result = getUsedSpaceOfCycleBuffer(0, 2, 4);
    EXPECT_EQ(result, 2);
    result = getUsedSpaceOfCycleBuffer(1, 2, 4);
    EXPECT_EQ(result, 1);
    result = getUsedSpaceOfCycleBuffer(4, 2, 10);
    EXPECT_EQ(result, 8);
    result = getUsedSpaceOfCycleBuffer(0, 0, 8);
    EXPECT_EQ(result, 0);
}

TEST(RingBuffer, createThenDestruct) {
    RingBuffer *rb = new RingBuffer(40);
    delete rb;
}

TEST(RingBuffer, writeThenReadInEmptyBuffer) {
    char *data = "12345678";
    const int length = 8;
    RingBuffer rb(8);

    int written = rb.write(data, 8);
    EXPECT_EQ(8, written);
    char readedData[length + 1] = {};
    int readed = rb.read(readedData, length);
    EXPECT_EQ(length, readed);
    ASSERT_STREQ(data, readedData);
}

TEST(RingBuffer, partialRead) {
    char *data = "123456789";
    int length = strlen(data);
    RingBuffer rb(length);
    rb.write(data, length);

    char readedData[11] = {};
    int readed = rb.read(readedData, 2);
    EXPECT_EQ(2, readed);
    ASSERT_STREQ(readedData, "12");

    readed = rb.read(readedData, 3);
    EXPECT_EQ(3, readed);
    ASSERT_STREQ(readedData, "345");

    readed = rb.read(readedData, 10);
    EXPECT_EQ(4, readed);
    ASSERT_STREQ(readedData, "6789");
}

TEST(RingBuffer, overflowEmptyBuffer) {
    char *data = "the data";
    int length = strlen(data);
    int bufferSize = length - 1;
    RingBuffer rb(bufferSize);

    int written = rb.write(data, length);
    ASSERT_EQ(written, bufferSize);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}