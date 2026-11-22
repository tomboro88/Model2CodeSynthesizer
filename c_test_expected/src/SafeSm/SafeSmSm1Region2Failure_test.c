/*
 * @file SafeSmSm1Region2Failure_test.c
 *
 * @brief Source code of the SafeSmSm1Region2Failure group test cases.
 * @details sm1 in State1 with an invalid Region2 state.
 * @author tomboro88
 * @date   22 november 2026
 * @copyright (c) 2026 tomboro88.
 * @license SPDX-License-Identifier: EPL-2.0
 * @project github.com/tomboro88/Model2CodeSynthesizer
 */
#include "SafeSm_test.h"

/*******************************************************************************
 *
 * Test group SafeSmSm1Region2Failure.
 *
 ******************************************************************************/
TEST_GROUP(SafeSmSm1Region2Failure);

TEST_SETUP(SafeSmSm1Region2Failure)
{
    plogger_test_init_buffer();
    safesm_sm1_init(&safesm_sm1_obj, &plogger_test_logger);
    safesm_sm1_obj.region2 = SAFESM_SM1_REGION2_SIZE;
    plogger_test_init_buffer();
}

TEST_TEAR_DOWN(SafeSmSm1Region2Failure)
{

}

/*================================TEST_CASES==================================*/
TEST(SafeSmSm1Region2Failure, InitResultsInInitialTransition)
{
    safesm_sm1_logger_expect_initial();
    plogger_test_given(safesm_sm1_init(&safesm_sm1_obj, &plogger_test_logger));
}

/* --------------------------------- Events -------------------------------- */

TEST(SafeSmSm1Region2Failure, DispatchA)
{
    safesm_sm1_logger_expect_safe_state();
    safesm_sm1_logger_dispatch_given(safesm_sm1_a(&safesm_sm1_obj,
                                                  SAFESM_TEST_U16));
}

/* ------------------------------ Queue errors ------------------------------ */
TEST(SafeSmSm1Region2Failure, FetchReturnsFalse)
{
    plogger_test_expect(false, NULL);
    plogger_test_given(safesm_sm1_fetch_event(&safesm_sm1_obj));
}

TEST(SafeSmSm1Region2Failure, DispatchReturnsFalse)
{
    plogger_test_expect(false, NULL);
    plogger_test_given(safesm_sm1_dispatch_event(&safesm_sm1_obj));
}

TEST(SafeSmSm1Region2Failure, ReleaseReturnsFalse)
{
    plogger_test_expect(false, NULL);
    plogger_test_given(safesm_sm1_release_event(&safesm_sm1_obj));
}

/*==============================TEST_GROUP_RUNNER=============================*/

TEST_GROUP_RUNNER(SafeSmSm1Region2Failure)
{
    RUN_TEST_CASE(SafeSmSm1Region2Failure, InitResultsInInitialTransition);

    RUN_TEST_CASE(SafeSmSm1Region2Failure, DispatchA);

    RUN_TEST_CASE(SafeSmSm1Region2Failure, FetchReturnsFalse);
    RUN_TEST_CASE(SafeSmSm1Region2Failure, DispatchReturnsFalse);
    RUN_TEST_CASE(SafeSmSm1Region2Failure, ReleaseReturnsFalse);
}

/*** end of file ***/
