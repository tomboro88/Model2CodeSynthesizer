/*
 * @file TkindSm1Region6Failure_test.c
 *
 * @brief Source code of the TkindSm1Region6Failure group test cases.
 * @author tomboro88
 * @date   18 november 2026
 * @copyright (c) 2026 tomboro88.
 * @license SPDX-License-Identifier: EPL-2.0
 * @project github.com/tomboro88/Model2CodeSynthesizer
 */
#include "Tkind_test.h"

/*******************************************************************************
 *
 * Test group TkindSm1Region6Failure.
 *
 ******************************************************************************/
TEST_GROUP(TkindSm1Region6Failure);

void tkind_test_enter_region6_failure(void)
{
    tkind_test_enter_state9();
    tkind_ctest_obj.sm1.region6 = TKIND_SM1_REGION6_SIZE;
}

TEST_SETUP(TkindSm1Region6Failure)
{
    plogger_test_init_buffer();
    tkind_test_enter_region6_failure();
    plogger_test_init_buffer();
}

TEST_TEAR_DOWN(TkindSm1Region6Failure)
{

}

/*================================TEST_CASES==================================*/
TEST(TkindSm1Region6Failure, InitResultsInInitialTransition)
{
    tkind_ctest_logger_expect_initial();
    plogger_test_given(tkind_ctest_init(&tkind_ctest_obj,
                                        &plogger_test_logger));
}

/* --------------------------------- Events -------------------------------- */

TEST(TkindSm1Region6Failure, DispatchA)
{
    plogger_test_expect(true, "Exit State2\n"
                              "State2 to State3\n"
                              "Enter State3\n");
    tkind_ctest_logger_dispatch_given(tkind_ctest_a(&tkind_ctest_obj));
}

TEST(TkindSm1Region6Failure, DispatchBGuardFalse)
{
    plogger_test_expect(true, "Exit State2\n"
                              "State2 to State4\n"
                              "Enter State4\n"
                              "Internal transition in State8."
                              " b_test_condition is false.\n");
    tkind_ctest_obj.sm1.b_test_condition = false;
    tkind_ctest_logger_dispatch_given(tkind_ctest_b(&tkind_ctest_obj));
}

TEST(TkindSm1Region6Failure, DispatchBGuardTrue)
{
    plogger_test_expect(true, "Exit State2\n"
                              "State2 to State4\n"
                              "Enter State4\n"
                              "Internal transition in State8."
                              " b_test_condition is true.\n");
    tkind_ctest_obj.sm1.b_test_condition = true;
    tkind_ctest_logger_dispatch_given(tkind_ctest_b(&tkind_ctest_obj));
}

TEST(TkindSm1Region6Failure, DispatchC)
{
    plogger_test_expect(true, NULL);
    tkind_ctest_logger_dispatch_given(tkind_ctest_c(&tkind_ctest_obj));
}

TEST(TkindSm1Region6Failure, DispatchD)
{
    plogger_test_expect(true, "Local State1 to State13.\n"
                              "Enter State13\n");
    tkind_ctest_obj.sm1.b_test_condition = true;
    tkind_ctest_logger_dispatch_given(tkind_ctest_d(&tkind_ctest_obj));
}

TEST(TkindSm1Region6Failure, DispatchE)
{
    plogger_test_expect(true, NULL);
    tkind_ctest_logger_dispatch_given(tkind_ctest_e(&tkind_ctest_obj));
}

TEST(TkindSm1Region6Failure, DispatchF)
{
    plogger_test_expect(true, NULL);
    tkind_ctest_logger_dispatch_given(tkind_ctest_f(&tkind_ctest_obj));
}

TEST(TkindSm1Region6Failure, DispatchG)
{
    plogger_test_expect(true, NULL);
    tkind_ctest_logger_dispatch_given(tkind_ctest_g(&tkind_ctest_obj, 25, 'a'));
}

TEST(TkindSm1Region6Failure, DispatchH)
{
    plogger_test_expect(true, NULL);
    tkind_ctest_logger_dispatch_given(tkind_ctest_h(&tkind_ctest_obj, 16));
}

TEST(TkindSm1Region6Failure, DispatchI)
{
    tkind_ctest_logger_expect_failure_all();
    tkind_ctest_logger_dispatch_given(tkind_ctest_i(&tkind_ctest_obj));
}

TEST(TkindSm1Region6Failure, DispatchJ)
{
    tkind_ctest_logger_expect_failure_all();
    tkind_ctest_logger_dispatch_given(tkind_ctest_j(&tkind_ctest_obj));
}

TEST(TkindSm1Region6Failure, DispatchK)
{
    tkind_ctest_logger_expect_failure_all();
    tkind_ctest_logger_dispatch_given(tkind_ctest_k(&tkind_ctest_obj));
}

TEST(TkindSm1Region6Failure, DispatchL)
{
    tkind_ctest_logger_expect_failure_all();
    tkind_ctest_logger_dispatch_given(tkind_ctest_l(&tkind_ctest_obj));
}

TEST(TkindSm1Region6Failure, DispatchM)
{
    plogger_test_expect(true, "Exit State2\n"
                              "Enter Failure\n");
    tkind_ctest_logger_dispatch_given(tkind_ctest_m(&tkind_ctest_obj));
}

TEST(TkindSm1Region6Failure, DispatchN)
{
    plogger_test_expect(true, NULL);
    tkind_ctest_logger_dispatch_given(tkind_ctest_n(&tkind_ctest_obj));
}

TEST(TkindSm1Region6Failure, DispatchOWithFalseChoice1)
{
    plogger_test_expect(true, "Exit State2\n"
                              "Enter Failure\n");
    tkind_ctest_obj.sm1.b_test_condition = false;
    tkind_ctest_logger_dispatch_given(tkind_ctest_o(&tkind_ctest_obj));
}

TEST(TkindSm1Region6Failure, DispatchOWithTrueChoice1)
{
    plogger_test_expect(true, "Exit State2\n"
                              "Enter Failure\n");
    tkind_ctest_obj.sm1.b_test_condition = true;
    tkind_ctest_logger_dispatch_given(tkind_ctest_o(&tkind_ctest_obj));
}

/* ------------------------------ Queue errors ------------------------------ */
TEST(TkindSm1Region6Failure, FetchReturnsFalse)
{
    plogger_test_expect(false, NULL);
    plogger_test_given(tkind_ctest_fetch_event(&tkind_ctest_obj));
}

TEST(TkindSm1Region6Failure, DispatchReturnsFalse)
{
    plogger_test_expect(false, NULL);
    plogger_test_given(tkind_ctest_dispatch_event(&tkind_ctest_obj));
}

TEST(TkindSm1Region6Failure, ReleaseReturnsFalse)
{
    plogger_test_expect(false, NULL);
    plogger_test_given(tkind_ctest_release_event(&tkind_ctest_obj));
}

/*==============================TEST_GROUP_RUNNER=============================*/

TEST_GROUP_RUNNER(TkindSm1Region6Failure)
{
    RUN_TEST_CASE(TkindSm1Region6Failure, InitResultsInInitialTransition);

    RUN_TEST_CASE(TkindSm1Region6Failure, DispatchA);
    RUN_TEST_CASE(TkindSm1Region6Failure, DispatchBGuardFalse);
    RUN_TEST_CASE(TkindSm1Region6Failure, DispatchBGuardTrue);
    RUN_TEST_CASE(TkindSm1Region6Failure, DispatchC);
    RUN_TEST_CASE(TkindSm1Region6Failure, DispatchD);
    RUN_TEST_CASE(TkindSm1Region6Failure, DispatchE);
    RUN_TEST_CASE(TkindSm1Region6Failure, DispatchF);
    RUN_TEST_CASE(TkindSm1Region6Failure, DispatchG);
    RUN_TEST_CASE(TkindSm1Region6Failure, DispatchH);
    RUN_TEST_CASE(TkindSm1Region6Failure, DispatchI);
    RUN_TEST_CASE(TkindSm1Region6Failure, DispatchJ);
    RUN_TEST_CASE(TkindSm1Region6Failure, DispatchK);
    RUN_TEST_CASE(TkindSm1Region6Failure, DispatchL);
    RUN_TEST_CASE(TkindSm1Region6Failure, DispatchM);
    RUN_TEST_CASE(TkindSm1Region6Failure, DispatchN);
    RUN_TEST_CASE(TkindSm1Region6Failure, DispatchOWithFalseChoice1);
    RUN_TEST_CASE(TkindSm1Region6Failure, DispatchOWithTrueChoice1);

    RUN_TEST_CASE(TkindSm1Region6Failure, FetchReturnsFalse);
    RUN_TEST_CASE(TkindSm1Region6Failure, DispatchReturnsFalse);
    RUN_TEST_CASE(TkindSm1Region6Failure, ReleaseReturnsFalse);
}
