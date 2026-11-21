add_subdirectory(test_tkind)

add_library(tests)

target_sources(tests
    PRIVATE
        tests.c
    PUBLIC
        FILE_SET tests_headers
    TYPE HEADERS
    FILES
        tests.h
)

target_link_libraries(tests
    PUBLIC
        test_tkind
)

target_link_libraries(tests
    PRIVATE
        coverage_compile
)
