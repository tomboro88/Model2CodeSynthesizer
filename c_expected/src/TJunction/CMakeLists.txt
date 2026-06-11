add_library(TJunction)

target_sources(TJunction
    PRIVATE
        TJunction.c
    PUBLIC
        FILE_SET tjunction_headers
    TYPE HEADERS
    FILES
        TJunction.h
)

target_link_libraries(TJunction
    PUBLIC
        event_pool
        sm
)

target_link_libraries(TJunction
    PRIVATE
        coverage_compile
)
