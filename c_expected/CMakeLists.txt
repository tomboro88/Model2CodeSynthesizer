cmake_minimum_required(VERSION 3.23)

project(c_expected)

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

add_subdirectory(src)
