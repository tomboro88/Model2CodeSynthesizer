add_library(event_pool)

target_sources(event_pool
    PRIVATE
        event_pool.c
    PUBLIC
        FILE_SET event_pool_headers
    TYPE HEADERS
    FILES
        event_pool.h
)

target_link_libraries(event_pool
    PUBLIC
        fifo
)

target_link_libraries(event_pool
    PRIVATE
        coverage_compile
)
