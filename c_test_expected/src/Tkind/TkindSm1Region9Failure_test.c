/*
 * @file TkindSm1Region9Failure_test.c
 *
 * @brief Source code of the TkindSm1Region9Failure group test cases.
 * @author tomboro88
 * @date   21 november 2026
 * @copyright (c) 2026 tomboro88.
 * @license SPDX-License-Identifier: EPL-2.0
 * @project github.com/tomboro88/Model2CodeSynthesizer
 */
#include "Tkind_test.h"

/*******************************************************************************
 *
 * Test group TkindSm1Region9Failure.
 *
 ******************************************************************************/
TEST_GROUP(TkindSm1Region9Failure);

void tkind_test_enter_region9_failure(void)
{
    tkind_test_enter_state12();
    tkind_ctest_obj.sm1.region9 = TKIND_SM1_REGION9_SIZE;
}

TEST_SETUP(TkindSm1Region9Failure)
{
    plogger_test_init_buffer();
    tkind_test_enter_region9_failure();
    plogger_test_init_buffer();
}

TEST_TEAR_DOWN(TkindSm1Region9Failure)
{

}

/*================================TEST_CASES==================================*/
TEST(TkindSm1Region9Failure, InitResultsInInitialTransition)
{
    tkind_ctest_logger_expect_initial();
    plogger_test_given(tkind_ctest_init(&tkind_ctest_obj,
                                        &plogger_test_logger));
}

/* --------------------------------- Events -------------------------------- */

TEST(TkindSm1Region9Failure, DispatchA)
{
    plogger_test_expect(true, "Exit State2\n"
                              "State2 to State3\n"
                              "Enter State3\n"
                              "Internal transition in State10"
                              " on all events\n");
    tkind_ctest_logger_dispatch_given(tkind_ctest_a(&tkind_ctest_obj));
}

TEST(TkindSm1Region9Failure, DispatchBGuardFalse)
{
    plogger_test_expect(true, "Exit State2\n"
                              "State2 to State4\n"
                              "Enter State4\n"
                              "Internal transition in State10"
                              " on all events\n");
    tkind_ctest_obj.sm1.b_test_condition = false;
    tkind_ctest_logger_dispatch_given(tkind_ctest_b(&tkind_ctest_obj));
}

TEST(TkindSm1Region9Failure, DispatchBGuardTrue)
{
    plogger_test_expect(true, "Exit State2\n"
                              "State2 to State4\n"
                              "Enter State4\n"
                              "Internal transition in State10"
                              " on all events\n");
    tkind_ctest_obj.sm1.b_test_condition = true;
    tkind_ctest_logger_dispatch_given(tkind_ctest_b(&tkind_ctest_obj));
}

TEST(TkindSm1Region9Failure, DispatchC)
{
    plogger_test_expect(true, "Internal transition in State10"
                              " on c event\n");
    tkind_ctest_logger_dispatch_given(tkind_ctest_c(&tkind_ctest_obj));
}

TEST(TkindSm1Region9Failure, DispatchDGuardFalse)
{
    tkind_ctest_logger_expect_failure_all();
    tkind_ctest_obj.sm1.b_test_condition = false;
    tkind_ctest_logger_dispatch_given(tkind_ctest_d(&tkind_ctest_obj));
}

TEST(TkindSm1Region9Failure, DispatchDGuardTrue)
{
    plogger_test_expect(true, "Internal transition in State10"
                              " on d event\n");
    tkind_ctest_obj.sm1.b_test_condition = true;
    tkind_ctest_logger_dispatch_given(tkind_ctest_d(&tkind_ctest_obj));
}

TEST(TkindSm1Region9Failure, DispatchE)
{
    plogger_test_expect(true, "Internal transition in State10"
                              " on all events\n");
    tkind_ctest_logger_dispatch_given(tkind_ctest_e(&tkind_ctest_obj));
}

TEST(TkindSm1Region9Failure, DispatchF)
{
    plogger_test_expect(true, "Internal transition in State10"
                              " on all events\n");
    tkind_ctest_logger_dispatch_given(tkind_ctest_f(&tkind_ctest_obj));
}

TEST(TkindSm1Region9Failure, DispatchG)
{
    plogger_test_expect(true, "Internal transition in State10"
                              " on all events\n");
    tkind_ctest_logger_dispatch_given(tkind_ctest_g(&tkind_ctest_obj, 25, 'a'));
}

TEST(TkindSm1Region9Failure, DispatchH)
{
    plogger_test_expect(true, "Internal transition in State10"
                              " on all events\n");
    tkind_ctest_logger_dispatch_given(tkind_ctest_h(&tkind_ctest_obj, 16));
}

TEST(TkindSm1Region9Failure, DispatchI)
{
    plogger_test_expect(true, "Internal transition in State10"
                              " on all events\n");
    tkind_ctest_logger_dispatch_given(tkind_ctest_i(&tkind_ctest_obj));
}

TEST(TkindSm1Region9Failure, DispatchJ)
{
    plogger_test_expect(true, "Internal transition in State10"
                              " on all events\n");
    tkind_ctest_logger_dispatch_given(tkind_ctest_j(&tkind_ctest_obj));
}

TEST(TkindSm1Region9Failure, DispatchK)
{
    plogger_test_expect(true, "Internal transition in State10"
                              " on all events\n");
    tkind_ctest_logger_dispatch_given(tkind_ctest_k(&tkind_ctest_obj));
}

TEST(TkindSm1Region9Failure, DispatchL)
{
    plogger_test_expect(true, "Internal transition in State10"
                              " on all events\n");
    tkind_ctest_logger_dispatch_given(tkind_ctest_l(&tkind_ctest_obj));
}

TEST(TkindSm1Region9Failure, DispatchM)
{
    plogger_test_expect(true, "Internal transition in State10"
                              " on all events\n");
    tkind_ctest_logger_dispatch_given(tkind_ctest_m(&tkind_ctest_obj));
}

TEST(TkindSm1Region9Failure, DispatchN)
{
    plogger_test_expect(true, "Internal transition in State10"
                              " on all events\n");
    tkind_ctest_logger_dispatch_given(tkind_ctest_n(&tkind_ctest_obj));
}

TEST(TkindSm1Region9Failure, DispatchOWithFalseChoice1)
{
    plogger_test_expect(true, "Internal transition in State10"
                              " on all events\n");
    tkind_ctest_obj.sm1.b_test_condition = false;
    tkind_ctest_logger_dispatch_given(tkind_ctest_o(&tkind_ctest_obj));
}

TEST(TkindSm1Region9Failure, DispatchOWithTrueChoice1)
{
    plogger_test_expect(true, "Internal transition in State10"
                              " on all events\n");
    tkind_ctest_obj.sm1.b_test_condition = true;
    tkind_ctest_logger_dispatch_given(tkind_ctest_o(&tkind_ctest_obj));
}

/* ------------------------------ Queue errors ------------------------------ */
TEST(TkindSm1Region9Failure, FetchReturnsFalse)
{
    plogger_test_expect(false, NULL);
    plogger_test_given(tkind_ctest_fetch_event(&tkind_ctest_obj));
}

TEST(TkindSm1Region9Failure, DispatchReturnsFalse)
{
    plogger_test_expect(false, NULL);
    plogger_test_given(tkind_ctest_dispatch_event(&tkind_ctest_obj));
}

TEST(TkindSm1Region9Failure, ReleaseReturnsFalse)
{
    plogger_test_expect(false, NULL);
    plogger_test_given(tkind_ctest_release_event(&tkind_ctest_obj));
}

/*==============================TEST_GROUP_RUNNER=============================*/

TEST_GROUP_RUNNER(TkindSm1Region9Failure)
{
    RUN_TEST_CASE(TkindSm1Region9Failure, InitResultsInInitialTransition);

    RUN_TEST_CASE(TkindSm1Region9Failure, DispatchA);
    RUN_TEST_CASE(TkindSm1Region9Failure, DispatchBGuardFalse);
    RUN_TEST_CASE(TkindSm1Region9Failure, DispatchBGuardTrue);
    RUN_TEST_CASE(TkindSm1Region9Failure, DispatchC);
    RUN_TEST_CASE(TkindSm1Region9Failure, DispatchDGuardFalse);
    RUN_TEST_CASE(TkindSm1Region9Failure, DispatchDGuardTrue);
    RUN_TEST_CASE(TkindSm1Region9Failure, DispatchE);
    RUN_TEST_CASE(TkindSm1Region9Failure, DispatchF);
    RUN_TEST_CASE(TkindSm1Region9Failure, DispatchG);
    RUN_TEST_CASE(TkindSm1Region9Failure, DispatchH);
    RUN_TEST_CASE(TkindSm1Region9Failure, DispatchI);
    RUN_TEST_CASE(TkindSm1Region9Failure, DispatchJ);
    RUN_TEST_CASE(TkindSm1Region9Failure, DispatchK);
    RUN_TEST_CASE(TkindSm1Region9Failure, DispatchL);
    RUN_TEST_CASE(TkindSm1Region9Failure, DispatchM);
    RUN_TEST_CASE(TkindSm1Region9Failure, DispatchN);
    RUN_TEST_CASE(TkindSm1Region9Failure, DispatchOWithFalseChoice1);
    RUN_TEST_CASE(TkindSm1Region9Failure, DispatchOWithTrueChoice1);

    RUN_TEST_CASE(TkindSm1Region9Failure, FetchReturnsFalse);
    RUN_TEST_CASE(TkindSm1Region9Failure, DispatchReturnsFalse);
    RUN_TEST_CASE(TkindSm1Region9Failure, ReleaseReturnsFalse);
}
