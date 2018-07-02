project(ring_buffer_test)

include_directories (
    ${CMAKE_CURRENT_SOURCE_DIR}/../src
)

add_executable (ring_buffer_test Main.cpp)
target_link_libraries (ring_buffer_test
                       ring_buffer_lib
)
add_test(ring_buffer_test ring_buffer_test)