cmake_minimum_required(VERSION 3.23)

project(c_test_expected)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_C_FLAGS 
"${CMAKE_C_FLAGS} -Wall -Wextra -Wpedantic -Werror -Wshadow -Wstrict-prototypes"
)

add_library(coverage_compile INTERFACE)
target_compile_options(coverage_compile INTERFACE 
    $<$<CONFIG:Coverage>:
        -O0 
        -g 
        --coverage
    >
)
target_link_options(coverage_compile INTERFACE 
    $<$<CONFIG:Coverage>:
        --coverage
    >
)

add_subdirectory(unity)
add_subdirectory(../c_expected/src/fifo fifo_src)
add_subdirectory(../c_expected/src/event_pool event_pool_src)
add_subdirectory(../c_expected/src/Tkind Tkind_src)
add_subdirectory(../c_expected/src/sm sm_src)
add_subdirectory(src)
