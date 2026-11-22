/*
 * @file TkindSm1Region7Failure_test.c
 *
 * @brief Source code of the TkindSm1Region7Failure group test cases.
 * @author tomboro88
 * @date   19 november 2026
 * @copyright (c) 2026 tomboro88.
 * @license SPDX-License-Identifier: EPL-2.0
 * @project github.com/tomboro88/Model2CodeSynthesizer
 */
#include "Tkind_test.h"

/*******************************************************************************
 *
 * Test group TkindSm1Region7Failure.
 *
 ******************************************************************************/
TEST_GROUP(TkindSm1Region7Failure);

void tkind_test_enter_region7_failure(void)
{
    tkind_ctest_init(&tkind_ctest_obj, &plogger_test_logger);
    tkind_ctest_obj.sm1.region7 = TKIND_SM1_REGION7_SIZE;
}

TEST_SETUP(TkindSm1Region7Failure)
{
    plogger_test_init_buffer();
    tkind_test_enter_region7_failure();
    plogger_test_init_buffer();
}

TEST_TEAR_DOWN(TkindSm1Region7Failure)
{

}

/*================================TEST_CASES==================================*/
TEST(TkindSm1Region7Failure, InitResultsInInitialTransition)
{
    tkind_ctest_logger_expect_initial();
    plogger_test_given(tkind_ctest_init(&tkind_ctest_obj,
                                        &plogger_test_logger));
}

/* --------------------------------- Events -------------------------------- */

TEST(TkindSm1Region7Failure, DispatchA)
{
    plogger_test_expect(true, "Exit State2\n"
                              "State2 to State3\n"
                              "Enter State3\n"
                              "Enter Failure\n");
    tkind_ctest_logger_dispatch_given(tkind_ctest_a(&tkind_ctest_obj));
}

TEST(TkindSm1Region7Failure, DispatchBGuardFalse)
{
    plogger_test_expect(true, "Exit State2\n"
                              "State2 to State4\n"
                              "Enter State4\n"
                              "Enter Failure\n");
    tkind_ctest_obj.sm1.b_test_condition = false;
    tkind_ctest_logger_dispatch_given(tkind_ctest_b(&tkind_ctest_obj));
}

TEST(TkindSm1Region7Failure, DispatchBGuardTrue)
{
    plogger_test_expect(true, "Exit State2\n"
                              "State2 to State4\n"
                              "Enter State4\n"
                              "Enter Failure\n");
    tkind_ctest_obj.sm1.b_test_condition = true;
    tkind_ctest_logger_dispatch_given(tkind_ctest_b(&tkind_ctest_obj));
}

TEST(TkindSm1Region7Failure, DispatchC)
{
    tkind_ctest_logger_expect_failure_all();
    tkind_ctest_logger_dispatch_given(tkind_ctest_c(&tkind_ctest_obj));
}

TEST(TkindSm1Region7Failure, DispatchD)
{
    tkind_ctest_logger_expect_failure_all();
    tkind_ctest_obj.sm1.b_test_condition = true;
    tkind_ctest_logger_dispatch_given(tkind_ctest_d(&tkind_ctest_obj));
}

TEST(TkindSm1Region7Failure, DispatchE)
{
    tkind_ctest_logger_expect_failure_all();
    tkind_ctest_logger_dispatch_given(tkind_ctest_e(&tkind_ctest_obj));
}

TEST(TkindSm1Region7Failure, DispatchF)
{
    tkind_ctest_logger_expect_failure_all();
    tkind_ctest_logger_dispatch_given(tkind_ctest_f(&tkind_ctest_obj));
}

TEST(TkindSm1Region7Failure, DispatchG)
{
    tkind_ctest_logger_expect_failure_all();
    tkind_ctest_logger_dispatch_given(tkind_ctest_g(&tkind_ctest_obj, 25, 'a'));
}

TEST(TkindSm1Region7Failure, DispatchH)
{
    tkind_ctest_logger_expect_failure_all();
    tkind_ctest_logger_dispatch_given(tkind_ctest_h(&tkind_ctest_obj, 16));
}

TEST(TkindSm1Region7Failure, DispatchI)
{
    tkind_ctest_logger_expect_failure_all();
    tkind_ctest_logger_dispatch_given(tkind_ctest_i(&tkind_ctest_obj));
}

TEST(TkindSm1Region7Failure, DispatchJ)
{
    tkind_ctest_logger_expect_failure_all();
    tkind_ctest_logger_dispatch_given(tkind_ctest_j(&tkind_ctest_obj));
}

TEST(TkindSm1Region7Failure, DispatchK)
{
    tkind_ctest_logger_expect_failure_all();
    tkind_ctest_logger_dispatch_given(tkind_ctest_k(&tkind_ctest_obj));
}

TEST(TkindSm1Region7Failure, DispatchL)
{
    tkind_ctest_logger_expect_failure_all();
    tkind_ctest_logger_dispatch_given(tkind_ctest_l(&tkind_ctest_obj));
}

TEST(TkindSm1Region7Failure, DispatchM)
{
    tkind_ctest_logger_expect_failure_all();
    tkind_ctest_logger_dispatch_given(tkind_ctest_m(&tkind_ctest_obj));
}

TEST(TkindSm1Region7Failure, DispatchN)
{
    tkind_ctest_logger_expect_failure_all();
    tkind_ctest_logger_dispatch_given(tkind_ctest_n(&tkind_ctest_obj));
}

TEST(TkindSm1Region7Failure, DispatchOWithFalseChoice1)
{
    tkind_ctest_logger_expect_failure_all();
    tkind_ctest_obj.sm1.b_test_condition = false;
    tkind_ctest_logger_dispatch_given(tkind_ctest_o(&tkind_ctest_obj));
}

TEST(TkindSm1Region7Failure, DispatchOWithTrueChoice1)
{
    tkind_ctest_logger_expect_failure_all();
    tkind_ctest_obj.sm1.b_test_condition = true;
    tkind_ctest_logger_dispatch_given(tkind_ctest_o(&tkind_ctest_obj));
}

/* ------------------------------ Queue errors ------------------------------ */
TEST(TkindSm1Region7Failure, FetchReturnsFalse)
{
    plogger_test_expect(false, NULL);
    plogger_test_given(tkind_ctest_fetch_event(&tkind_ctest_obj));
}

TEST(TkindSm1Region7Failure, DispatchReturnsFalse)
{
    plogger_test_expect(false, NULL);
    plogger_test_given(tkind_ctest_dispatch_event(&tkind_ctest_obj));
}

TEST(TkindSm1Region7Failure, ReleaseReturnsFalse)
{
    plogger_test_expect(false, NULL);
    plogger_test_given(tkind_ctest_release_event(&tkind_ctest_obj));
}

/*==============================TEST_GROUP_RUNNER=============================*/

TEST_GROUP_RUNNER(TkindSm1Region7Failure)
{
    RUN_TEST_CASE(TkindSm1Region7Failure, InitResultsInInitialTransition);

    RUN_TEST_CASE(TkindSm1Region7Failure, DispatchA);
    RUN_TEST_CASE(TkindSm1Region7Failure, DispatchBGuardFalse);
    RUN_TEST_CASE(TkindSm1Region7Failure, DispatchBGuardTrue);
    RUN_TEST_CASE(TkindSm1Region7Failure, DispatchC);
    RUN_TEST_CASE(TkindSm1Region7Failure, DispatchD);
    RUN_TEST_CASE(TkindSm1Region7Failure, DispatchE);
    RUN_TEST_CASE(TkindSm1Region7Failure, DispatchF);
    RUN_TEST_CASE(TkindSm1Region7Failure, DispatchG);
    RUN_TEST_CASE(TkindSm1Region7Failure, DispatchH);
    RUN_TEST_CASE(TkindSm1Region7Failure, DispatchI);
    RUN_TEST_CASE(TkindSm1Region7Failure, DispatchJ);
    RUN_TEST_CASE(TkindSm1Region7Failure, DispatchK);
    RUN_TEST_CASE(TkindSm1Region7Failure, DispatchL);
    RUN_TEST_CASE(TkindSm1Region7Failure, DispatchM);
    RUN_TEST_CASE(TkindSm1Region7Failure, DispatchN);
    RUN_TEST_CASE(TkindSm1Region7Failure, DispatchOWithFalseChoice1);
    RUN_TEST_CASE(TkindSm1Region7Failure, DispatchOWithTrueChoice1);

    RUN_TEST_CASE(TkindSm1Region7Failure, FetchReturnsFalse);
    RUN_TEST_CASE(TkindSm1Region7Failure, DispatchReturnsFalse);
    RUN_TEST_CASE(TkindSm1Region7Failure, ReleaseReturnsFalse);
}
