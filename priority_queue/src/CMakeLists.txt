project('priority_queue_src')

add_library(priority_queue_lib
    Helper.h
    Helper.cpp
    Comparer.hpp
    PriorityQueue.hpp
    BinaryHeapBasedPriorityQueue.hpp
    GenericComparer.hpp
)

set_target_properties(priority_queue_lib PROPERTIES LINKER_LANGUAGE CXX)

target_include_directories(priority_queue_lib
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
)