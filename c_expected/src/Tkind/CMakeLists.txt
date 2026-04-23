add_library(Tkind)

target_sources(Tkind
    PRIVATE
        Tkind.c
    PUBLIC
        FILE_SET tkind_headers
    TYPE HEADERS
    FILES
        Tkind.h
)

target_link_libraries(Tkind
    PUBLIC
        event_pool
        sm
)

target_link_libraries(Tkind
    PRIVATE
        coverage_compile
)
