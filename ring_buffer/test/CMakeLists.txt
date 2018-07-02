project(ring_buffer_test)

add_executable (ring_buffer_test RingBufferTest.cpp)
target_link_libraries (ring_buffer_test
    gtest_main
    ring_buffer_lib
)
add_test(ring_buffer_test ring_buffer_test)