/*
 * @file SafeSmSm1State3_test.c
 *
 * @brief Source code of the SafeSmSm1State3 group test cases.
 * @details sm1 in the State3 configuration (with State4) reached by the a event.
 * @author tomboro88
 * @date   22 november 2026
 * @copyright (c) 2026 tomboro88.
 * @license SPDX-License-Identifier: EPL-2.0
 * @project github.com/tomboro88/Model2CodeSynthesizer
 */
#include "SafeSm_test.h"

/*******************************************************************************
 *
 * Test group SafeSmSm1State3.
 *
 ******************************************************************************/
TEST_GROUP(SafeSmSm1State3);

TEST_SETUP(SafeSmSm1State3)
{
    plogger_test_init_buffer();
    safesm_test_enter_state3();
    plogger_test_init_buffer();
}

TEST_TEAR_DOWN(SafeSmSm1State3)
{

}

/*================================TEST_CASES==================================*/
TEST(SafeSmSm1State3, InitResultsInInitialTransition)
{
    safesm_sm1_logger_expect_initial();
    plogger_test_given(safesm_sm1_init(&safesm_sm1_obj, &plogger_test_logger));
}

/* --------------------------------- Events -------------------------------- */

TEST(SafeSmSm1State3, DispatchA)
{
    plogger_test_expect(true, NULL);
    safesm_sm1_logger_dispatch_given(safesm_sm1_a(&safesm_sm1_obj,
                                                  SAFESM_TEST_U16));
}

/* ------------------------------ Queue errors ------------------------------ */
TEST(SafeSmSm1State3, FetchReturnsFalse)
{
    plogger_test_expect(false, NULL);
    plogger_test_given(safesm_sm1_fetch_event(&safesm_sm1_obj));
}

TEST(SafeSmSm1State3, DispatchReturnsFalse)
{
    plogger_test_expect(false, NULL);
    plogger_test_given(safesm_sm1_dispatch_event(&safesm_sm1_obj));
}

TEST(SafeSmSm1State3, ReleaseReturnsFalse)
{
    plogger_test_expect(false, NULL);
    plogger_test_given(safesm_sm1_release_event(&safesm_sm1_obj));
}

/*==============================TEST_GROUP_RUNNER=============================*/

TEST_GROUP_RUNNER(SafeSmSm1State3)
{
    RUN_TEST_CASE(SafeSmSm1State3, InitResultsInInitialTransition);

    RUN_TEST_CASE(SafeSmSm1State3, DispatchA);

    RUN_TEST_CASE(SafeSmSm1State3, FetchReturnsFalse);
    RUN_TEST_CASE(SafeSmSm1State3, DispatchReturnsFalse);
    RUN_TEST_CASE(SafeSmSm1State3, ReleaseReturnsFalse);
}

/*** end of file ***/
