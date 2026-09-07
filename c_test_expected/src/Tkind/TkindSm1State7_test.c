/*
 * @file TkindSm1State7_test.c
 *
 * @brief Source code of the TkindSm1State7 group test cases.
 * @author tomboro88
 * @date   1 may 2026
 * @copyright (c) 2026 tomboro88. 
 * @license SPDX-License-Identifier: EPL-2.0
 * @project github.com/tomboro88/Model2CodeSynthesizer
 */
#include "Tkind_test.h"

/*******************************************************************************
 *
 * Test group TkindSm1State7.
 *
 ******************************************************************************/
TEST_GROUP(TkindSm1State7);

void tkind_test_enter_state7(void)
{
    tkind_test_init_logger_buffer();
    tkind_ctest_init(&tkind_ctest_obj, &tkind_test_logger);

    tkind_ctest_i(&tkind_ctest_obj);
    tkind_ctest_fetch_event(&tkind_ctest_obj);
    tkind_ctest_dispatch_event(&tkind_ctest_obj);
    tkind_ctest_release_event(&tkind_ctest_obj);
}

TEST_SETUP(TkindSm1State7)
{
    tkind_test_init_logger_buffer();
    tkind_test_enter_state7();
    tkind_test_init_logger_buffer();
}

TEST_TEAR_DOWN(TkindSm1State7)
{

}

/*================================TEST_CASES==================================*/
TEST(TkindSm1State7, InitResultsInInitialTransition)
{
    tkind_ctest_logger_expect(true, "Initial1 to State1\n"
                              "Enter State1\n"
                              "Initial3 to State2\n"
                              "Enter State2\n");
    tkind_ctest_logger_given(tkind_ctest_init(&tkind_ctest_obj,
                                              &tkind_test_logger));
}

/* --------------------------------- Events -------------------------------- */

TEST(TkindSm1State7, DispatchA)
{
    tkind_ctest_logger_expect(true, "Exit State2\n"
                                    "State2 to State3\n"
                                    "Enter State3\n");
    tkind_ctest_logger_dispatch_given(tkind_ctest_a(&tkind_ctest_obj));
}

TEST(TkindSm1State7, DispatchB)
{
    tkind_ctest_logger_expect(true, "Exit State2\n"
                                    "State2 to State4\n"
                                    "Enter State4\n");
    tkind_ctest_logger_dispatch_given(tkind_ctest_b(&tkind_ctest_obj));
}

TEST(TkindSm1State7, DispatchC)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_dispatch_given(tkind_ctest_c(&tkind_ctest_obj));
}

TEST(TkindSm1State7, DispatchD)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_dispatch_given(tkind_ctest_d(&tkind_ctest_obj));
}

TEST(TkindSm1State7, DispatchE)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_dispatch_given(tkind_ctest_e(&tkind_ctest_obj));
}

TEST(TkindSm1State7, DispatchF)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_dispatch_given(tkind_ctest_f(&tkind_ctest_obj));
}

TEST(TkindSm1State7, DispatchG)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_dispatch_given(tkind_ctest_g(&tkind_ctest_obj));
}

TEST(TkindSm1State7, DispatchH)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_dispatch_given(tkind_ctest_h(&tkind_ctest_obj));
}

TEST(TkindSm1State7, DispatchI)
{
    tkind_ctest_logger_expect(true, "Exit State2\n"
                                    "Exit State7\n"
                                    "Exit State1\n"
                                    "State1 to State7\n"
                                    "Enter State1\n"
                                    "Enter State7\n"
                                    "Initial3 to State2\n"
                                    "Enter State2\n");
    tkind_ctest_logger_dispatch_given(tkind_ctest_i(&tkind_ctest_obj));
}

TEST(TkindSm1State7, DispatchJ)
{
    tkind_ctest_logger_expect(true, "Exit State7\n"
                                    "State7 to State8\n"
                                    "Enter State8\n"
                                    "Initial4 to State9\n"
                                    "Enter State9\n");
    tkind_ctest_logger_dispatch_given(tkind_ctest_j(&tkind_ctest_obj));
}

TEST(TkindSm1State7, DispatchK)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_dispatch_given(tkind_ctest_k(&tkind_ctest_obj));
}

TEST(TkindSm1State7, DispatchL)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_dispatch_given(tkind_ctest_l(&tkind_ctest_obj));
}

TEST(TkindSm1State7, DispatchM)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_dispatch_given(tkind_ctest_m(&tkind_ctest_obj));
}

TEST(TkindSm1State7, DispatchN)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_dispatch_given(tkind_ctest_n(&tkind_ctest_obj));
}

TEST(TkindSm1State7, DispatchOWithFalseChoice1)
{
    tkind_ctest_logger_expect(true, "Exit State2\n"
                                    "Exit State7\n"
                                    "Exit State1\n"
                                    "State1 to Choice1\n"
                                    "Enter State1\n"
                                    "Choice1 to State1\n"
                                    "Initial3 to State2\n"
                                    "Enter State2\n");
    tkind_ctest_obj.sm1.b_test_condition = false;
    tkind_ctest_logger_dispatch_given(tkind_ctest_o(&tkind_ctest_obj));
}

TEST(TkindSm1State7, DispatchOWithTrueChoice1)
{
    tkind_ctest_logger_expect(true, "Exit State2\n"
                                    "Exit State7\n"
                                    "Exit State1\n"
                                    "State1 to Choice1\n"
                                    "Enter State1\n"
                                    "Choice1 to State8\n"
                                    "Enter State8\n"
                                    "Initial4 to State9\n"
                                    "Enter State9\n"
                                    "Initial3 to State2\n"
                                    "Enter State2\n");
    tkind_ctest_obj.sm1.b_test_condition = true;
    tkind_ctest_logger_dispatch_given(tkind_ctest_o(&tkind_ctest_obj));
}

/* ------------------------------ Queue errors ------------------------------ */
TEST(TkindSm1State7, FetchReturnsFalse)
{
    tkind_ctest_logger_expect(false, NULL);
    tkind_ctest_logger_given(tkind_ctest_fetch_event(&tkind_ctest_obj));
}

TEST(TkindSm1State7, DispatchReturnsFalse)
{
    tkind_ctest_logger_expect(false, NULL);
    tkind_ctest_logger_given(tkind_ctest_dispatch_event(&tkind_ctest_obj));
}

TEST(TkindSm1State7, ReleaseReturnsFalse)
{
    tkind_ctest_logger_expect(false, NULL);
    tkind_ctest_logger_given(tkind_ctest_release_event(&tkind_ctest_obj));
}

/*==============================TEST_GROUP_RUNNER=============================*/

TEST_GROUP_RUNNER(TkindSm1State7)
{
    RUN_TEST_CASE(TkindSm1State7, InitResultsInInitialTransition);

    RUN_TEST_CASE(TkindSm1State7, DispatchA);
    RUN_TEST_CASE(TkindSm1State7, DispatchB);
    RUN_TEST_CASE(TkindSm1State7, DispatchC);
    RUN_TEST_CASE(TkindSm1State7, DispatchD);
    RUN_TEST_CASE(TkindSm1State7, DispatchE);
    RUN_TEST_CASE(TkindSm1State7, DispatchF);
    RUN_TEST_CASE(TkindSm1State7, DispatchG);
    RUN_TEST_CASE(TkindSm1State7, DispatchH);
    RUN_TEST_CASE(TkindSm1State7, DispatchI);
    RUN_TEST_CASE(TkindSm1State7, DispatchJ);
    RUN_TEST_CASE(TkindSm1State7, DispatchK);
    RUN_TEST_CASE(TkindSm1State7, DispatchL);
    RUN_TEST_CASE(TkindSm1State7, DispatchM);
    RUN_TEST_CASE(TkindSm1State7, DispatchN);
    RUN_TEST_CASE(TkindSm1State7, DispatchOWithFalseChoice1);
    RUN_TEST_CASE(TkindSm1State7, DispatchOWithTrueChoice1);
    
    RUN_TEST_CASE(TkindSm1State7, FetchReturnsFalse);
    RUN_TEST_CASE(TkindSm1State7, DispatchReturnsFalse);
    RUN_TEST_CASE(TkindSm1State7, ReleaseReturnsFalse);
}
