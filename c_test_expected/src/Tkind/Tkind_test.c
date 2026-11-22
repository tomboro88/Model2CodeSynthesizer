/*
 * @file Tkind_test.c
 *
 * @brief Source code of the Tkind package test cases.
 * @author tomboro88
 * @date   4 mar 2026
 * @copyright (c) 2026 tomboro88.
 * @license SPDX-License-Identifier: EPL-2.0
 * @project github.com/tomboro88/Model2CodeSynthesizer
 */

/*******************************************************************************
 *
 * Include statements.
 *
 ******************************************************************************/
#include <unity_fixture.h>
#include <Tkind.h>
#include "../plogger/plogger_test.h"
#include <string.h>
#include <stddef.h>

/*******************************************************************************
 *
 * Static data declarations.
 *
 ******************************************************************************/
/**
 * @brief The ctest object that is tested.
 */
tkind_ctest_t tkind_ctest_obj = {0};

/*******************************************************************************
 *
 * Inline functions.
 *
 ******************************************************************************/

/*******************************************************************************
 *
 * Public function bodies.
 *
 ******************************************************************************/
void
tkind_ctest_logger_expect_initial(void)
{
    plogger_test_expect(true, "Initial1 to State1\n"
                              "Enter State1\n"
                              "Initial3 to State2\n"
                              "Enter State2\n");
}

void
tkind_ctest_logger_expect_failure_a(void)
{
    plogger_test_expect(true, "Enter Failure\n");
}

void
tkind_ctest_logger_expect_failure_all(void)
{
    plogger_test_expect(true, "Enter Failure\n");
}

void
tkind_ctest_logger_expect_recovery(void)
{
    plogger_test_expect(true, "UnexpectedState to State1.\n"
                              "Enter State1\n"
                              "Initial3 to State2\n"
                              "Enter State2\n");
}

void
tkind_ctest_logger_expect_recovery_b(void)
{
    plogger_test_expect(true, "b triggered UnexpectedState to State1.\n"
                              "Enter State1\n"
                              "Initial3 to State2\n"
                              "Enter State2\n");
}

void
tkind_ctest_logger_dispatch_given(bool const b_is_result_ok)
{
    plogger_test_assert_result(b_is_result_ok);

    plogger_test_assert(NULL);
    TEST_ASSERT_TRUE(tkind_ctest_fetch_event(&tkind_ctest_obj));
    plogger_test_assert(NULL);
    TEST_ASSERT_TRUE(tkind_ctest_fetch_event(&tkind_ctest_obj));
    plogger_test_assert(NULL);
    TEST_ASSERT_TRUE(tkind_ctest_dispatch_event(&tkind_ctest_obj));
    plogger_test_assert_expected();
    TEST_ASSERT_FALSE(tkind_ctest_dispatch_event(&tkind_ctest_obj));
    plogger_test_assert_expected();
    TEST_ASSERT_TRUE(tkind_ctest_release_event(&tkind_ctest_obj));
    plogger_test_assert_expected();
    TEST_ASSERT_FALSE(tkind_ctest_release_event(&tkind_ctest_obj));
    plogger_test_assert_expected();
}

/*** end of file ***/
