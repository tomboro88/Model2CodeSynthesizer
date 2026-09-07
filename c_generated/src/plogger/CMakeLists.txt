add_library(plogger)

target_sources(plogger
    PRIVATE
        plogger.c
    PUBLIC
        FILE_SET plogger_headers
    TYPE HEADERS
    FILES
        plogger.h
)

target_link_libraries(plogger
    PRIVATE
        coverage_compile
)
