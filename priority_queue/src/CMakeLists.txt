project('priority_queue_src')

add_library(priority_queue_lib
    PriorityQueue.hpp
    BinaryHeapBasedPriorityQueue.hpp
)

target_link_libraries(priority_queue_lib binary_heap_lib)
set_target_properties(priority_queue_lib PROPERTIES LINKER_LANGUAGE CXX)

target_include_directories(priority_queue_lib
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
)