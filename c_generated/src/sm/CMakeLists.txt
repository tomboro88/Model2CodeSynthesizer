add_library(sm)

target_sources(sm
    PRIVATE
        sm.c
    PUBLIC
        FILE_SET sm_headers
    TYPE HEADERS
    FILES
        sm.h
)

target_link_libraries(sm
    PRIVATE
        coverage_compile
)
