/*
 * @file Tkind_test_common.h
 *
 * @brief Declarations the Tkind package all test cases.
 * @author tomboro88
 * @date   1 may 2026
 * @copyright (c) 2026 tomboro88. 
 * @license SPDX-License-Identifier: EPL-2.0
 * @project github.com/tomboro88/Model2CodeSynthesizer
 */

#ifndef TKIND_TEST_H
#define TKIND_TEST_H

#include <unity_fixture.h>
#include <Tkind.h>
#include <string.h>
#include <stddef.h>

#define TKIND_CBASE1_TEST_PROP1_DEFAULT (101u)
#define TKIND_CBASE2_TEST_PROP1_DEFAULT (-3.14f)

/* Common data declarations (extern) */
extern plogger_logger_t tkind_test_logger;
extern tkind_ctest_t tkind_ctest_obj;

/* Helper functions. */
void tkind_test_init_logger_buffer(void);
void tkind_ctest_logger_expect(bool const b_is_result_ok,
                               const char* const p_str);
void tkind_ctest_logger_given(bool const b_is_result_ok);
void tkind_ctest_logger_dispatch_given(bool const b_is_result_ok);
void tkind_test_enter_state3(void);
void tkind_test_enter_state4(void);
void tkind_test_enter_state7(void);

#endif // TKIND_TEST_COMMON_H

/*** end of file ***/
