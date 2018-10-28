project('priority_queue')

add_library(priority_queue_lib
    Comparer.hpp,
    PriorityQueue.hpp
)

target_include_directories(priority_queue_lib
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
)