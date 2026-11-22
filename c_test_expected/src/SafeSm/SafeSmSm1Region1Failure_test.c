/*
 * @file SafeSmSm1Region1Failure_test.c
 *
 * @brief Source code of the SafeSmSm1Region1Failure group test cases.
 * @details sm1 with an invalid Region1 state.
 * @author tomboro88
 * @date   22 november 2026
 * @copyright (c) 2026 tomboro88.
 * @license SPDX-License-Identifier: EPL-2.0
 * @project github.com/tomboro88/Model2CodeSynthesizer
 */
#include "SafeSm_test.h"

/*******************************************************************************
 *
 * Test group SafeSmSm1Region1Failure.
 *
 ******************************************************************************/
TEST_GROUP(SafeSmSm1Region1Failure);

TEST_SETUP(SafeSmSm1Region1Failure)
{
    plogger_test_init_buffer();
    safesm_sm1_init(&safesm_sm1_obj, &plogger_test_logger);
    safesm_sm1_obj.region1 = SAFESM_SM1_REGION1_SIZE;
    plogger_test_init_buffer();
}

TEST_TEAR_DOWN(SafeSmSm1Region1Failure)
{

}

/*================================TEST_CASES==================================*/
TEST(SafeSmSm1Region1Failure, InitResultsInInitialTransition)
{
    safesm_sm1_logger_expect_initial();
    plogger_test_given(safesm_sm1_init(&safesm_sm1_obj, &plogger_test_logger));
}

/* --------------------------------- Events -------------------------------- */

TEST(SafeSmSm1Region1Failure, DispatchA)
{
    safesm_sm1_logger_expect_safe_state();
    safesm_sm1_logger_dispatch_given(safesm_sm1_a(&safesm_sm1_obj,
                                                  SAFESM_TEST_U16));
}

/* ------------------------------ Queue errors ------------------------------ */
TEST(SafeSmSm1Region1Failure, FetchReturnsFalse)
{
    plogger_test_expect(false, NULL);
    plogger_test_given(safesm_sm1_fetch_event(&safesm_sm1_obj));
}

TEST(SafeSmSm1Region1Failure, DispatchReturnsFalse)
{
    plogger_test_expect(false, NULL);
    plogger_test_given(safesm_sm1_dispatch_event(&safesm_sm1_obj));
}

TEST(SafeSmSm1Region1Failure, ReleaseReturnsFalse)
{
    plogger_test_expect(false, NULL);
    plogger_test_given(safesm_sm1_release_event(&safesm_sm1_obj));
}

/*==============================TEST_GROUP_RUNNER=============================*/

TEST_GROUP_RUNNER(SafeSmSm1Region1Failure)
{
    RUN_TEST_CASE(SafeSmSm1Region1Failure, InitResultsInInitialTransition);

    RUN_TEST_CASE(SafeSmSm1Region1Failure, DispatchA);

    RUN_TEST_CASE(SafeSmSm1Region1Failure, FetchReturnsFalse);
    RUN_TEST_CASE(SafeSmSm1Region1Failure, DispatchReturnsFalse);
    RUN_TEST_CASE(SafeSmSm1Region1Failure, ReleaseReturnsFalse);
}

/*** end of file ***/
