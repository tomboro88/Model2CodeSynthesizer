add_subdirectory(Tkind)
add_subdirectory(TJunction)

add_subdirectory(fifo)
add_subdirectory(event_pool)
add_subdirectory(sm)

add_executable(umltest)

target_sources(umltest
    PRIVATE
        umltest.c
    PRIVATE
        FILE_SET umltest_headers
    TYPE HEADERS
    FILES
        umltest.h
)

target_link_libraries(umltest
    PRIVATE
        Tkind
        TJunction
)

target_link_libraries(umltest
    PRIVATE
        coverage_compile
)
