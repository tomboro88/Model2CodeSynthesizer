add_executable(test_expected)

target_sources(test_expected
    PRIVATE
        all_tests.c
        fifo/fifo_test.c
        fifo/fifo_test_runner.c
        event_pool/event_pool_test.c
        event_pool/event_pool_test_runner.c
        Tkind/Tkind_test.c
        Tkind/Tkind_test_runner.c
)

target_link_libraries(test_expected
    PRIVATE
        unity
        fifo
        event_pool
        Tkind
)

target_link_libraries(test_expected
    PRIVATE
        coverage_compile
)

find_package(Perl REQUIRED)
find_program(LCOV_PATH lcov)
find_program(GENHTML_PATH genhtml)

add_custom_target(coverage
    COMMAND ${PERL_EXECUTABLE} ${LCOV_PATH} --zerocounters --directory ${CMAKE_BINARY_DIR}
    COMMAND ${CMAKE_BINARY_DIR}/src/test_expected
    COMMAND ${PERL_EXECUTABLE} ${LCOV_PATH} --capture --directory ${CMAKE_BINARY_DIR} --output-file coverage.info --rc lcov_branch_coverage=1
    COMMAND ${PERL_EXECUTABLE} ${LCOV_PATH} --remove coverage.info '*_tests.c' '*_runner.c' '*_test.c' --output-file coverage_filtered.info --rc lcov_branch_coverage=1
    COMMAND ${PERL_EXECUTABLE} ${GENHTML_PATH} coverage_filtered.info --legend --output-directory coverage_report --rc lcov_branch_coverage=1
    COMMAND ${CMAKE_COMMAND} -E echo "=== Coverage report: file://${CMAKE_BINARY_DIR}/coverage_report/index.html ==="
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    DEPENDS test_expected
    COMMENT "Generating HTML code coverage report"
)

add_custom_target(coverage-clean
    COMMAND ${CMAKE_COMMAND} -E remove_directory coverage_report
    COMMAND find ${CMAKE_BINARY_DIR} -name '*.gcda' -delete
    COMMENT "Cleaning previous coverage data"
)
