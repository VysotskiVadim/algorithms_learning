include(GoogleTest)
project(priority_queue_test)

add_executable (priority_queue_test PriorityQueueTest.cpp)
target_link_libraries (priority_queue_test
    gtest_main
    priority_queue_lib
)

gtest_add_tests(priority_queue_test "" AUTO)