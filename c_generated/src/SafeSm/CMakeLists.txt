add_library(SafeSm)

target_sources(SafeSm
    PRIVATE
        SafeSm.c
    PUBLIC
        FILE_SET safesm_headers
    TYPE HEADERS
    FILES
        SafeSm.h
)

target_link_libraries(SafeSm
    PUBLIC
        event_pool
        sm
)

target_link_libraries(SafeSm
    PRIVATE
        coverage_compile
)
