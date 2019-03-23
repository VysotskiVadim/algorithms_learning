project('binary_heap_src')

add_library(binary_heap_lib
    Comparer.hpp
    PriorityQueue.hpp
    BinaryHeapBasedPriorityQueue.hpp
    GenericComparer.hpp
)

set_target_properties(binary_heap_lib PROPERTIES LINKER_LANGUAGE CXX)

target_include_directories(binary_heap_lib
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
)