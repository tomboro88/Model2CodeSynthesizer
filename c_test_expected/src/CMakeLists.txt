add_executable(test_expected)

target_sources(test_expected
    PRIVATE
        all_tests.c
        fifo/fifo_test.c
        fifo/fifo_test_runner.c
        event_pool/event_pool_test.c
        event_pool/event_pool_test_runner.c
        event_pool/event_pool_single_test.c
        plogger/plogger_test.c
        Tkind/Tkind_test.c
        Tkind/Tkindcbase1_test.c
        Tkind/Tkindcbase2_test.c
        Tkind/Tkindctest_test.c
        Tkind/TkindSm1ZeroInit_test.c
        Tkind/TkindSm1State2_test.c
        Tkind/TkindSm1State3_test.c
        Tkind/TkindSm1State4_test.c
        Tkind/TkindSm1State5_test.c
        Tkind/TkindSm1State6_test.c
        Tkind/TkindSm1State7_test.c
        Tkind/TkindSm1State9_test.c
        Tkind/TkindSm1State11_test.c
        Tkind/TkindSm1State12_test.c
        Tkind/TkindSm1State5State11_test.c
        Tkind/TkindSm1Region1Failure_test.c
        Tkind/TkindSm1Region2Failure_test.c
        Tkind/TkindSm1Failure_test.c
        Tkind/TkindSm1Region3Failure_test.c
        Tkind/TkindSm1Region4Failure_test.c
        Tkind/TkindSm1Region5Failure_test.c
        Tkind/TkindSm1Region6Failure_test.c
        Tkind/TkindSm1Region7Failure_test.c
        Tkind/TkindSm1Region8Failure_test.c
        Tkind/TkindSm1Region9Failure_test.c
        TJunction/TJunction_test.c
        SafeSm/SafeSm_test.c
        SafeSm/SafeSmSm1State1_test.c
        SafeSm/SafeSmSm1State3_test.c
        SafeSm/SafeSmSm1SafeState_test.c
        SafeSm/SafeSmSm1Region1Failure_test.c
        SafeSm/SafeSmSm1Region2Failure_test.c
        SafeSm/SafeSmSm1Region4Failure_test.c
        SafeSm/SafeSmSm1Region3Failure_test.c
)

target_link_libraries(test_expected
    PRIVATE
        unity
        fifo
        event_pool
        Tkind
        TJunction
        SafeSm
        plogger
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
