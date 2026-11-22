/*
 * @file SafeSm_test.c
 *
 * @brief Common helpers of the SafeSm package test cases.
 * @author tomboro88
 * @date   22 november 2026
 * @copyright (c) 2026 tomboro88.
 * @license SPDX-License-Identifier: EPL-2.0
 * @project github.com/tomboro88/Model2CodeSynthesizer
 */

/*******************************************************************************
 *
 * Include statements.
 *
 ******************************************************************************/
#include "SafeSm_test.h"

/*******************************************************************************
 *
 * Private function prototypes.
 *
 ******************************************************************************/
static void safesm_test_process_a(void);

/*******************************************************************************
 *
 * Static data declarations.
 *
 ******************************************************************************/
/**
 * @brief The sm1 object that is tested.
 */
safesm_sm1_t safesm_sm1_obj = {0};

/*******************************************************************************
 *
 * Public function bodies.
 *
 ******************************************************************************/
void
safesm_sm1_logger_expect_initial(void)
{
    plogger_test_expect(true, "Initial1 to State1\n"
                              "Initial2 to State2\n"
                              "Initial3 to State5\n");
}

/**
 * @brief Expects the transition triggered by the a event with the
 * SAFESM_TEST_U16 argument from the initial configuration.
 */
void
safesm_sm1_logger_expect_transition_a(void)
{
    plogger_test_expect(true, "Exit State5\n"
                              "State5 to Junction5\n"
                              "Exit State2\n"
                              "Junction5 to Junction3\n"
                              "Exit State1\n"
                              "Junction3 to Junction4, u16=1234, char=a\n"
                              "Junction4 to Junction2\n"
                              "Enter State3\n"
                              "Junction2 to State4\n");
}

void
safesm_sm1_logger_expect_safe_state(void)
{
    plogger_test_expect(true, "Enter SafeState\n");
}

void
safesm_sm1_logger_dispatch_given(bool const b_is_result_ok)
{
    plogger_test_assert_result(b_is_result_ok);

    plogger_test_assert(NULL);
    TEST_ASSERT_TRUE(safesm_sm1_fetch_event(&safesm_sm1_obj));
    plogger_test_assert(NULL);
    TEST_ASSERT_TRUE(safesm_sm1_fetch_event(&safesm_sm1_obj));
    plogger_test_assert(NULL);
    TEST_ASSERT_TRUE(safesm_sm1_dispatch_event(&safesm_sm1_obj));
    plogger_test_assert_expected();
    TEST_ASSERT_FALSE(safesm_sm1_dispatch_event(&safesm_sm1_obj));
    plogger_test_assert_expected();
    TEST_ASSERT_TRUE(safesm_sm1_release_event(&safesm_sm1_obj));
    plogger_test_assert_expected();
    TEST_ASSERT_FALSE(safesm_sm1_release_event(&safesm_sm1_obj));
    plogger_test_assert_expected();
}

/**
 * @brief Brings sm1 into the State3 (with State4) configuration with the
 * regular transition triggered by the a event.
 */
void
safesm_test_enter_state3(void)
{
    safesm_sm1_init(&safesm_sm1_obj, &plogger_test_logger);
    safesm_test_process_a();
}

/**
 * @brief Brings sm1 into the SafeState by corrupting the Region1 state and
 * dispatching the a event.
 */
void
safesm_test_enter_safe_state(void)
{
    safesm_sm1_init(&safesm_sm1_obj, &plogger_test_logger);
    safesm_sm1_obj.region1 = SAFESM_SM1_REGION1_SIZE;
    safesm_test_process_a();
}

/*******************************************************************************
 *
 * Private function bodies.
 *
 ******************************************************************************/
/**
 * @brief Processes a single a event without any verification.
 */
static void
safesm_test_process_a(void)
{
    safesm_sm1_a(&safesm_sm1_obj, SAFESM_TEST_U16);
    safesm_sm1_fetch_event(&safesm_sm1_obj);
    safesm_sm1_dispatch_event(&safesm_sm1_obj);
    safesm_sm1_release_event(&safesm_sm1_obj);
}

/*** end of file ***/
