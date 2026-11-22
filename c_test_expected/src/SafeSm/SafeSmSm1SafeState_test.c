/*
 * @file SafeSmSm1SafeState_test.c
 *
 * @brief Source code of the SafeSmSm1SafeState group test cases.
 * @details sm1 in the SafeState entered after an unexpected Region1 state.
 * @author tomboro88
 * @date   22 november 2026
 * @copyright (c) 2026 tomboro88.
 * @license SPDX-License-Identifier: EPL-2.0
 * @project github.com/tomboro88/Model2CodeSynthesizer
 */
#include "SafeSm_test.h"

/*******************************************************************************
 *
 * Test group SafeSmSm1SafeState.
 *
 ******************************************************************************/
TEST_GROUP(SafeSmSm1SafeState);

TEST_SETUP(SafeSmSm1SafeState)
{
    plogger_test_init_buffer();
    safesm_test_enter_safe_state();
    plogger_test_init_buffer();
}

TEST_TEAR_DOWN(SafeSmSm1SafeState)
{

}

/*================================TEST_CASES==================================*/
TEST(SafeSmSm1SafeState, InitResultsInInitialTransition)
{
    safesm_sm1_logger_expect_initial();
    plogger_test_given(safesm_sm1_init(&safesm_sm1_obj, &plogger_test_logger));
}

/* --------------------------------- Events -------------------------------- */

TEST(SafeSmSm1SafeState, DispatchA)
{
    plogger_test_expect(true, NULL);
    safesm_sm1_logger_dispatch_given(safesm_sm1_a(&safesm_sm1_obj,
                                                  SAFESM_TEST_U16));
}

/* ------------------------------ Queue errors ------------------------------ */
TEST(SafeSmSm1SafeState, FetchReturnsFalse)
{
    plogger_test_expect(false, NULL);
    plogger_test_given(safesm_sm1_fetch_event(&safesm_sm1_obj));
}

TEST(SafeSmSm1SafeState, DispatchReturnsFalse)
{
    plogger_test_expect(false, NULL);
    plogger_test_given(safesm_sm1_dispatch_event(&safesm_sm1_obj));
}

TEST(SafeSmSm1SafeState, ReleaseReturnsFalse)
{
    plogger_test_expect(false, NULL);
    plogger_test_given(safesm_sm1_release_event(&safesm_sm1_obj));
}

/*==============================TEST_GROUP_RUNNER=============================*/

TEST_GROUP_RUNNER(SafeSmSm1SafeState)
{
    RUN_TEST_CASE(SafeSmSm1SafeState, InitResultsInInitialTransition);

    RUN_TEST_CASE(SafeSmSm1SafeState, DispatchA);

    RUN_TEST_CASE(SafeSmSm1SafeState, FetchReturnsFalse);
    RUN_TEST_CASE(SafeSmSm1SafeState, DispatchReturnsFalse);
    RUN_TEST_CASE(SafeSmSm1SafeState, ReleaseReturnsFalse);
}

/*** end of file ***/
