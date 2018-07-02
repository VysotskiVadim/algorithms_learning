project('ring_buffer_scr')

add_library(ring_buffer_lib
    RingBuffer.cpp
    RingBuffer.hpp
    RingBufferHelper.hpp
    RingBufferHelper.cpp
)

target_include_directories(ring_buffer_lib
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
)