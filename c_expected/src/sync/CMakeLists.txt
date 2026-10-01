add_library(sync)

target_sources(sync
    PRIVATE
        sync.c
    PUBLIC
        FILE_SET sync_headers
    TYPE HEADERS
    FILES
        sync.h
)

target_link_libraries(sync
    PRIVATE
        coverage_compile
)
