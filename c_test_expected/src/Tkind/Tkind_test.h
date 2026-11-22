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
#include "../plogger/plogger_test.h"
#include <string.h>
#include <stddef.h>

#define TKIND_CBASE1_TEST_PROP1_DEFAULT (101u)
#define TKIND_CBASE2_TEST_PROP1_DEFAULT (-3.14f)

/* Common data declarations (extern) */
extern tkind_ctest_t tkind_ctest_obj;

/* Helper functions. */
void tkind_ctest_logger_expect_initial(void);
void tkind_ctest_logger_expect_failure_a(void);
void tkind_ctest_logger_expect_failure_all(void);
void tkind_ctest_logger_expect_recovery(void);
void tkind_ctest_logger_expect_recovery_b(void);
void tkind_ctest_logger_dispatch_given(bool const b_is_result_ok);
void tkind_test_enter_state3(void);
void tkind_test_enter_state4(void);
void tkind_test_enter_state7(void);
void tkind_test_enter_state9(void);
void tkind_test_enter_state11(void);
void tkind_test_enter_state12(void);
void tkind_test_enter_region1_failure(void);

#endif // TKIND_TEST_COMMON_H

/*** end of file ***/
