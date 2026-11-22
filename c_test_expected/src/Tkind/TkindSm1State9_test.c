/*
 * @file TkindSm1State9_test.c
 *
 * @brief Source code of the TkindSm1State9 group test cases.
 * @author tomboro88
 * @date   13 may 2026
 * @copyright (c) 2026 tomboro88. 
 * @license SPDX-License-Identifier: EPL-2.0
 * @project github.com/tomboro88/Model2CodeSynthesizer
 */
#include "Tkind_test.h"

/*******************************************************************************
 *
 * Test group TkindSm1State9.
 *
 ******************************************************************************/
TEST_GROUP(TkindSm1State9);

void tkind_test_enter_state9(void)
{
    tkind_test_enter_state7();

    tkind_ctest_j(&tkind_ctest_obj);
    tkind_ctest_fetch_event(&tkind_ctest_obj);
    tkind_ctest_dispatch_event(&tkind_ctest_obj);
    tkind_ctest_release_event(&tkind_ctest_obj);
}

TEST_SETUP(TkindSm1State9)
{
    plogger_test_init_buffer();
    tkind_test_enter_state9();
    plogger_test_init_buffer();
}

TEST_TEAR_DOWN(TkindSm1State9)
{

}

/*================================TEST_CASES==================================*/
TEST(TkindSm1State9, InitResultsInInitialTransition)
{
    tkind_ctest_logger_expect_initial();
    plogger_test_given(tkind_ctest_init(&tkind_ctest_obj,
                                        &plogger_test_logger));
}

/* --------------------------------- Events -------------------------------- */

TEST(TkindSm1State9, DispatchA)
{
    plogger_test_expect(true, "Exit State2\n"
                              "State2 to State3\n"
                              "Enter State3\n");
    tkind_ctest_logger_dispatch_given(tkind_ctest_a(&tkind_ctest_obj));
}

TEST(TkindSm1State9, DispatchBGuardFalse)
{
    plogger_test_expect(true, "Exit State2\n"
                              "State2 to State4\n"
                              "Enter State4\n"
                              "Internal transition in State8."
                              " b_test_condition is false.\n");
    tkind_ctest_obj.sm1.b_test_condition = false;
    tkind_ctest_logger_dispatch_given(tkind_ctest_b(&tkind_ctest_obj));
}

TEST(TkindSm1State9, DispatchBGuardTrue)
{
    plogger_test_expect(true, "Exit State2\n"
                              "State2 to State4\n"
                              "Enter State4\n"
                              "Internal transition in State8."
                              " b_test_condition is true.\n");
    tkind_ctest_obj.sm1.b_test_condition = true;
    tkind_ctest_logger_dispatch_given(tkind_ctest_b(&tkind_ctest_obj));
}

TEST(TkindSm1State9, DispatchC)
{
    plogger_test_expect(true, NULL);
    tkind_ctest_logger_dispatch_given(tkind_ctest_c(&tkind_ctest_obj));
}

TEST(TkindSm1State9, DispatchD)
{
    plogger_test_expect(true, "Local State1 to State13.\n"
                              "Enter State13\n");
    tkind_ctest_obj.sm1.b_test_condition = true;
    tkind_ctest_logger_dispatch_given(tkind_ctest_d(&tkind_ctest_obj));
}

TEST(TkindSm1State9, DispatchE)
{
    plogger_test_expect(true, NULL);
    tkind_ctest_logger_dispatch_given(tkind_ctest_e(&tkind_ctest_obj));
}

TEST(TkindSm1State9, DispatchF)
{
    plogger_test_expect(true, NULL);
    tkind_ctest_logger_dispatch_given(tkind_ctest_f(&tkind_ctest_obj));
}

TEST(TkindSm1State9, DispatchG)
{
    plogger_test_expect(true, NULL);
    tkind_ctest_logger_dispatch_given(tkind_ctest_g(&tkind_ctest_obj, 25, 'a'));
}

TEST(TkindSm1State9, DispatchH)
{
    plogger_test_expect(true, NULL);
    tkind_ctest_logger_dispatch_given(tkind_ctest_h(&tkind_ctest_obj, 16));
}

TEST(TkindSm1State9, DispatchI)
{
    plogger_test_expect(true, "Internal transition "
                              "in State9 on event i\n");
    tkind_ctest_logger_dispatch_given(tkind_ctest_i(&tkind_ctest_obj));
}

TEST(TkindSm1State9, DispatchJ)
{
    plogger_test_expect(true, "Exit State9\n"
                              "Exit State8\n"
                              "State8 to State7\n"
                              "Enter State7\n");
    tkind_ctest_logger_dispatch_given(tkind_ctest_j(&tkind_ctest_obj));
}

TEST(TkindSm1State9, DispatchK)
{
    plogger_test_expect(true, "Exit State9\n"
                              "Exit State8\n"
                              "State9 to State8\n"
                              "Enter State8\n"
                              "Initial4 to State9\n"
                              "Enter State9\n");
    tkind_ctest_logger_dispatch_given(tkind_ctest_k(&tkind_ctest_obj));
}

TEST(TkindSm1State9, DispatchL)
{
    plogger_test_expect(true, "Exit State2\n"
                              "Exit State9\n"
                              "Exit State8\n"
                              "Exit State1\n"
                              "State9 to State1\n"
                              "Enter State1\n"
                              "Initial3 to State2\n"
                              "Enter State2\n");
    tkind_ctest_logger_dispatch_given(tkind_ctest_l(&tkind_ctest_obj));
}

TEST(TkindSm1State9, DispatchM)
{
    plogger_test_expect(true, "Exit State2\n"
                              "Exit State9\n"
                              "Exit State8\n"
                              "Exit State1\n"
                              "State8 to State1\n"
                              "Enter State1\n"
                              "Initial3 to State2\n"
                              "Enter State2\n");
    tkind_ctest_logger_dispatch_given(tkind_ctest_m(&tkind_ctest_obj));
}

TEST(TkindSm1State9, DispatchN)
{
    plogger_test_expect(true, NULL);
    tkind_ctest_logger_dispatch_given(tkind_ctest_n(&tkind_ctest_obj));
}

TEST(TkindSm1State9, DispatchOWithFalseChoice1)
{
    plogger_test_expect(true, "Exit State2\n"
                              "Exit State9\n"
                              "Exit State8\n"
                              "Exit State1\n"
                              "State1 to Choice1\n"
                              "Enter State1\n"
                              "Initial3 to State2\n"
                              "Enter State2\n"
                              "Choice1 to State1\n");
    tkind_ctest_obj.sm1.b_test_condition = false;
    tkind_ctest_logger_dispatch_given(tkind_ctest_o(&tkind_ctest_obj));
}

TEST(TkindSm1State9, DispatchOWithTrueChoice1)
{
    plogger_test_expect(true, "Exit State2\n"
                              "Exit State9\n"
                              "Exit State8\n"
                              "Exit State1\n"
                              "State1 to Choice1\n"
                              "Enter State1\n"
                              "Initial3 to State2\n"
                              "Enter State2\n"
                              "Choice1 to State8\n"
                              "Enter State8\n"
                              "Initial4 to State9\n"
                              "Enter State9\n");
    tkind_ctest_obj.sm1.b_test_condition = true;
    tkind_ctest_logger_dispatch_given(tkind_ctest_o(&tkind_ctest_obj));
}

/* ------------------------------ Queue errors ------------------------------ */
TEST(TkindSm1State9, FetchReturnsFalse)
{
    plogger_test_expect(false, NULL);
    plogger_test_given(tkind_ctest_fetch_event(&tkind_ctest_obj));
}

TEST(TkindSm1State9, DispatchReturnsFalse)
{
    plogger_test_expect(false, NULL);
    plogger_test_given(tkind_ctest_dispatch_event(&tkind_ctest_obj));
}

TEST(TkindSm1State9, ReleaseReturnsFalse)
{
    plogger_test_expect(false, NULL);
    plogger_test_given(tkind_ctest_release_event(&tkind_ctest_obj));
}

/*==============================TEST_GROUP_RUNNER=============================*/

TEST_GROUP_RUNNER(TkindSm1State9)
{
    RUN_TEST_CASE(TkindSm1State9, InitResultsInInitialTransition);

    RUN_TEST_CASE(TkindSm1State9, DispatchA);
    RUN_TEST_CASE(TkindSm1State9, DispatchBGuardFalse);
    RUN_TEST_CASE(TkindSm1State9, DispatchBGuardTrue);
    RUN_TEST_CASE(TkindSm1State9, DispatchC);
    RUN_TEST_CASE(TkindSm1State9, DispatchD);
    RUN_TEST_CASE(TkindSm1State9, DispatchE);
    RUN_TEST_CASE(TkindSm1State9, DispatchF);
    RUN_TEST_CASE(TkindSm1State9, DispatchG);
    RUN_TEST_CASE(TkindSm1State9, DispatchH);
    RUN_TEST_CASE(TkindSm1State9, DispatchI);
    RUN_TEST_CASE(TkindSm1State9, DispatchJ);
    RUN_TEST_CASE(TkindSm1State9, DispatchK);
    RUN_TEST_CASE(TkindSm1State9, DispatchL);
    RUN_TEST_CASE(TkindSm1State9, DispatchM);
    RUN_TEST_CASE(TkindSm1State9, DispatchN);
    RUN_TEST_CASE(TkindSm1State9, DispatchOWithFalseChoice1);
    RUN_TEST_CASE(TkindSm1State9, DispatchOWithTrueChoice1);
    
    RUN_TEST_CASE(TkindSm1State9, FetchReturnsFalse);
    RUN_TEST_CASE(TkindSm1State9, DispatchReturnsFalse);
    RUN_TEST_CASE(TkindSm1State9, ReleaseReturnsFalse);
}
