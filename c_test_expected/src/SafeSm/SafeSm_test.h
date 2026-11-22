/*
 * @file SafeSm_test.h
 *
 * @brief Declarations common to all SafeSm package test cases.
 * @author tomboro88
 * @date   22 november 2026
 * @copyright (c) 2026 tomboro88.
 * @license SPDX-License-Identifier: EPL-2.0
 * @project github.com/tomboro88/Model2CodeSynthesizer
 */

#ifndef SAFESM_TEST_H
#define SAFESM_TEST_H

#include <unity_fixture.h>
#include <SafeSm.h>
#include "../plogger/plogger_test.h"

/**
 * @brief The default u16_param argument of the a events used in the tests.
 * @note Its value is also written in the safesm_sm1_logger_expect_transition_a
 * expected log.
 */
#define SAFESM_TEST_U16 1234u

/**
 * @brief Another u16_param argument, different from SAFESM_TEST_U16.
 */
#define SAFESM_TEST_U16_OTHER 4321u

/* Common data declarations (extern) */
extern safesm_sm1_t safesm_sm1_obj;

/* Helper functions. */
void safesm_sm1_logger_expect_initial(void);
void safesm_sm1_logger_expect_transition_a(void);
void safesm_sm1_logger_expect_safe_state(void);
void safesm_sm1_logger_dispatch_given(bool const b_is_result_ok);
void safesm_test_enter_state3(void);
void safesm_test_enter_safe_state(void);

#endif // SAFESM_TEST_H

/*** end of file ***/
