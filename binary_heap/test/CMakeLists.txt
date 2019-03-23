include(GoogleTest)
project(binary_heap_test)

add_executable (binary_heap_test BinaryHeapTest.cpp)
target_link_libraries (binary_heap_test
    gtest_main
    binary_heap_lib
)

gtest_add_tests(binary_heap_test "" AUTO)