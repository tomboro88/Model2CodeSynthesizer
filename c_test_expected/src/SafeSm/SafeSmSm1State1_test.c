/*
 * @file SafeSmSm1State1_test.c
 *
 * @brief Source code of the SafeSmSm1State1 group test cases.
 * @details sm1 in its initial configuration: State1, State2 and State5.
 * @author tomboro88
 * @date   22 november 2026
 * @copyright (c) 2026 tomboro88.
 * @license SPDX-License-Identifier: EPL-2.0
 * @project github.com/tomboro88/Model2CodeSynthesizer
 */
#include "SafeSm_test.h"

/*******************************************************************************
 *
 * Test group SafeSmSm1State1.
 *
 ******************************************************************************/
TEST_GROUP(SafeSmSm1State1);

TEST_SETUP(SafeSmSm1State1)
{
    plogger_test_init_buffer();
    safesm_sm1_init(&safesm_sm1_obj, &plogger_test_logger);
    plogger_test_init_buffer();
}

TEST_TEAR_DOWN(SafeSmSm1State1)
{

}

/*================================TEST_CASES==================================*/
TEST(SafeSmSm1State1, InitResultsInInitialTransition)
{
    safesm_sm1_logger_expect_initial();
    plogger_test_given(safesm_sm1_init(&safesm_sm1_obj, &plogger_test_logger));
}

/* --------------------------------- Events -------------------------------- */

TEST(SafeSmSm1State1, DispatchA)
{
    safesm_sm1_logger_expect_transition_a();
    safesm_sm1_logger_dispatch_given(safesm_sm1_a(&safesm_sm1_obj,
                                                  SAFESM_TEST_U16));
}

TEST(SafeSmSm1State1, EnqueueAUntilFull)
{
    for(unsigned int i = 0u; i < SAFESM_SM1_A_CNT; i++)
    {
        plogger_test_expect(true, NULL);
        plogger_test_given(safesm_sm1_a(&safesm_sm1_obj, SAFESM_TEST_U16));
    }

    plogger_test_expect(false, NULL);
    plogger_test_given(safesm_sm1_a(&safesm_sm1_obj, SAFESM_TEST_U16));
}

TEST(SafeSmSm1State1, DispatchATwoQueued)
{
    plogger_test_expect(true, NULL);
    plogger_test_given(safesm_sm1_a(&safesm_sm1_obj, SAFESM_TEST_U16));

    /* The first event is dispatched with its own argument. */
    safesm_sm1_logger_expect_transition_a();
    safesm_sm1_logger_dispatch_given(safesm_sm1_a(&safesm_sm1_obj,
                                                  SAFESM_TEST_U16_OTHER));
}

TEST(SafeSmSm1State1, DispatchAQueueFull)
{
    plogger_test_expect(true, NULL);
    plogger_test_given(safesm_sm1_a(&safesm_sm1_obj, SAFESM_TEST_U16));

    for(unsigned int i = 1u; i < SAFESM_SM1_A_CNT; i++)
    {
        plogger_test_given(safesm_sm1_a(&safesm_sm1_obj,
                                        SAFESM_TEST_U16_OTHER));
    }

    /* The rejected event must not overwrite the argument of the first one. */
    plogger_test_expect(false, NULL);
    plogger_test_given(safesm_sm1_a(&safesm_sm1_obj, SAFESM_TEST_U16_OTHER));

    safesm_sm1_logger_expect_transition_a();
    safesm_sm1_logger_dispatch_given(true);
}

/* ------------------------------ Queue errors ------------------------------ */
TEST(SafeSmSm1State1, FetchReturnsFalse)
{
    plogger_test_expect(false, NULL);
    plogger_test_given(safesm_sm1_fetch_event(&safesm_sm1_obj));
}

TEST(SafeSmSm1State1, DispatchReturnsFalse)
{
    plogger_test_expect(false, NULL);
    plogger_test_given(safesm_sm1_dispatch_event(&safesm_sm1_obj));
}

TEST(SafeSmSm1State1, ReleaseReturnsFalse)
{
    plogger_test_expect(false, NULL);
    plogger_test_given(safesm_sm1_release_event(&safesm_sm1_obj));
}

/*==============================TEST_GROUP_RUNNER=============================*/

TEST_GROUP_RUNNER(SafeSmSm1State1)
{
    RUN_TEST_CASE(SafeSmSm1State1, InitResultsInInitialTransition);

    RUN_TEST_CASE(SafeSmSm1State1, DispatchA);
    RUN_TEST_CASE(SafeSmSm1State1, EnqueueAUntilFull);
    RUN_TEST_CASE(SafeSmSm1State1, DispatchATwoQueued);
    RUN_TEST_CASE(SafeSmSm1State1, DispatchAQueueFull);

    RUN_TEST_CASE(SafeSmSm1State1, FetchReturnsFalse);
    RUN_TEST_CASE(SafeSmSm1State1, DispatchReturnsFalse);
    RUN_TEST_CASE(SafeSmSm1State1, ReleaseReturnsFalse);
}

/*** end of file ***/
