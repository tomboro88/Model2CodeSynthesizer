/*
 * @file plogger_test.h
 *
 * @brief Declarations of the test logger shared by all package test cases.
 * @details The plogger_test_logger object implements the plogger logger
 * interface. It is passed to the tested object (e.g. its init function) and
 * captures all strings recorded through the logger interface in a guarded
 * buffer, which contents are then verified with plogger_test_assert().
 * @author tomboro88
 * @date   22 november 2026
 * @copyright (c) 2026 tomboro88.
 * @license SPDX-License-Identifier: EPL-2.0
 * @project github.com/tomboro88/Model2CodeSynthesizer
 */

#ifndef PLOGGER_TEST_H
#define PLOGGER_TEST_H

#include <unity_fixture.h>
#include <plogger.h>
#include <stdbool.h>

/* Common data declarations (extern) */
extern plogger_logger_t plogger_test_logger;

/* Helper functions. */
void plogger_test_init_buffer(void);
void plogger_test_assert(const char* const p_str);
void plogger_test_expect(bool const b_is_result_ok, const char* const p_str);
void plogger_test_assert_result(bool const b_is_result_ok);
void plogger_test_assert_expected(void);
void plogger_test_given(bool const b_is_result_ok);

#endif // PLOGGER_TEST_H

/*** end of file ***/
