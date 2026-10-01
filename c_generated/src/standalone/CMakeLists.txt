add_library(standalone)

target_sources(standalone
    PRIVATE
        standalone.c
    PUBLIC
        FILE_SET standalone_headers
    TYPE HEADERS
    FILES
        standalone.h
)

target_link_libraries(standalone
    PUBLIC
        event_pool
        sm
)

target_link_libraries(standalone
    PRIVATE
        coverage_compile
)
