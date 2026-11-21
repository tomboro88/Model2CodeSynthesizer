add_library(test_tkind)

target_sources(test_tkind
    PRIVATE
        test_tkind.c
    PUBLIC
        FILE_SET test_tkind_headers
    TYPE HEADERS
    FILES
        test_tkind.h
)

target_link_libraries(test_tkind
    PUBLIC
        event_pool
        sm
)

target_link_libraries(test_tkind
    PUBLIC
        Tkind
        plogger
)

target_link_libraries(test_tkind
    PRIVATE
        coverage_compile
)
