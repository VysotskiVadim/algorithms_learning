#include "gtest/gtest.h"

using namespace al;

TEST(RingBuffer, writeUntillFullThenReadAllThenWriteAgain) {
    char *data = "12345";
    RingBuffer rb(4);
    char buffer[6] = {};

    rb.write(data, 5);
    rb.read(buffer, 5);

    rb.write("6789", 4);
    rb.read(buffer, 4);
    
    ASSERT_STREQ(buffer, "6789");
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}