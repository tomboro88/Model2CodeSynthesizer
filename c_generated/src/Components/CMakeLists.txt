add_library(Components)

target_sources(Components
    PRIVATE
        Components.c
    PUBLIC
        FILE_SET components_headers
    TYPE HEADERS
    FILES
        Components.h
)

target_link_libraries(Components
    PRIVATE
        coverage_compile
)
