/*
 * @file TkindSm1State6_test.c
 *
 * @brief Source code of the TkindSm1State6 group test cases.
 * @author tomboro88
 * @date   7 may 2026
 * @copyright (c) 2026 tomboro88. 
 * @license SPDX-License-Identifier: EPL-2.0
 * @project github.com/tomboro88/Model2CodeSynthesizer
 */
#include "Tkind_test.h"

/*******************************************************************************
 *
 * Test group TkindSm1State6.
 *
 ******************************************************************************/
TEST_GROUP(TkindSm1State6);

static void tkind_test_enter_state6(void)
{
    tkind_test_enter_state4();

    tkind_ctest_f(&tkind_ctest_obj);
    tkind_ctest_fetch_event(&tkind_ctest_obj);
    tkind_ctest_dispatch_event(&tkind_ctest_obj);
    tkind_ctest_release_event(&tkind_ctest_obj);
}

TEST_SETUP(TkindSm1State6)
{
    tkind_test_init_logger_buffer();
    tkind_test_enter_state6();
    tkind_test_init_logger_buffer();
}

TEST_TEAR_DOWN(TkindSm1State6)
{

}

/*================================TEST_CASES==================================*/
TEST(TkindSm1State6, InitResultsInInitialTransition)
{
    tkind_ctest_logger_expect(true, "Initial1 to State1\n"
                              "Enter State1\n"
                              "Initial3 to State2\n"
                              "Enter State2\n");
    tkind_ctest_logger_given(tkind_ctest_init(&tkind_ctest_obj,
                                              &tkind_test_logger));
}

/* --------------------------------- Events -------------------------------- */

TEST(TkindSm1State6, DispatchA)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_dispatch_given(tkind_ctest_a(&tkind_ctest_obj));
}

TEST(TkindSm1State6, DispatchB)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_dispatch_given(tkind_ctest_b(&tkind_ctest_obj));
}

TEST(TkindSm1State6, DispatchC)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_dispatch_given(tkind_ctest_c(&tkind_ctest_obj));
}

TEST(TkindSm1State6, DispatchD)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_dispatch_given(tkind_ctest_d(&tkind_ctest_obj));
}

TEST(TkindSm1State6, DispatchE)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_dispatch_given(tkind_ctest_e(&tkind_ctest_obj));
}

TEST(TkindSm1State6, DispatchF)
{
    tkind_ctest_logger_expect(true, "Exit State6\n"
                                    "Exit State4\n"
                                    "State4 to State6\n"
                                    "Enter State4\n"
                                    "Enter State6\n");
    tkind_ctest_logger_dispatch_given(tkind_ctest_f(&tkind_ctest_obj));
}

TEST(TkindSm1State6, DispatchG)
{
    tkind_ctest_logger_expect(true, "Exit State6\n"
                                    "Exit State4\n"
                                    "State6 to State4\n"
                                    "Enter State4\n");
    tkind_ctest_logger_dispatch_given(tkind_ctest_g(&tkind_ctest_obj));
}

TEST(TkindSm1State6, DispatchH)
{
    tkind_ctest_logger_expect(true, "Exit State6\n"
                                    "Exit State4\n"
                                    "Exit State1\n"
                                    "State6 to State1\n"
                                    "Enter State1\n"
                                    "Initial3 to State2\n"
                                    "Enter State2\n");
    tkind_ctest_logger_dispatch_given(tkind_ctest_h(&tkind_ctest_obj));
}

TEST(TkindSm1State6, DispatchI)
{
    tkind_ctest_logger_expect(true, "Exit State6\n"
                                    "Exit State4\n"
                                    "Exit State1\n"
                                    "State1 to State7\n"
                                    "Enter State1\n"
                                    "Enter State7\n"
                                    "Initial3 to State2\n"
                                    "Enter State2\n");
    tkind_ctest_logger_dispatch_given(tkind_ctest_i(&tkind_ctest_obj));
}

TEST(TkindSm1State6, DispatchJ)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_dispatch_given(tkind_ctest_j(&tkind_ctest_obj));
}

TEST(TkindSm1State6, DispatchK)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_dispatch_given(tkind_ctest_k(&tkind_ctest_obj));
}

TEST(TkindSm1State6, DispatchL)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_dispatch_given(tkind_ctest_l(&tkind_ctest_obj));
}

TEST(TkindSm1State6, DispatchM)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_dispatch_given(tkind_ctest_m(&tkind_ctest_obj));
}

TEST(TkindSm1State6, DispatchN)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_dispatch_given(tkind_ctest_n(&tkind_ctest_obj));
}

TEST(TkindSm1State6, DispatchOWithFalseChoice1)
{
    tkind_ctest_logger_expect(true, "Exit State6\n"
                                    "Exit State4\n"
                                    "Exit State1\n"
                                    "State1 to Choice1\n"
                                    "Enter State1\n"
                                    "Choice1 to State1\n"
                                    "Initial3 to State2\n"
                                    "Enter State2\n");
    tkind_ctest_obj.sm1.b_test_condition = false;
    tkind_ctest_logger_dispatch_given(tkind_ctest_o(&tkind_ctest_obj));
}

TEST(TkindSm1State6, DispatchOWithTrueChoice1)
{
    tkind_ctest_logger_expect(true, "Exit State6\n"
                                    "Exit State4\n"
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
TEST(TkindSm1State6, FetchReturnsFalse)
{
    tkind_ctest_logger_expect(false, NULL);
    tkind_ctest_logger_given(tkind_ctest_fetch_event(&tkind_ctest_obj));
}

TEST(TkindSm1State6, DispatchReturnsFalse)
{
    tkind_ctest_logger_expect(false, NULL);
    tkind_ctest_logger_given(tkind_ctest_dispatch_event(&tkind_ctest_obj));
}

TEST(TkindSm1State6, ReleaseReturnsFalse)
{
    tkind_ctest_logger_expect(false, NULL);
    tkind_ctest_logger_given(tkind_ctest_release_event(&tkind_ctest_obj));
}

/*==============================TEST_GROUP_RUNNER=============================*/

TEST_GROUP_RUNNER(TkindSm1State6)
{
    RUN_TEST_CASE(TkindSm1State6, InitResultsInInitialTransition);

    RUN_TEST_CASE(TkindSm1State6, DispatchA);
    RUN_TEST_CASE(TkindSm1State6, DispatchB);
    RUN_TEST_CASE(TkindSm1State6, DispatchC);
    RUN_TEST_CASE(TkindSm1State6, DispatchD);
    RUN_TEST_CASE(TkindSm1State6, DispatchE);
    RUN_TEST_CASE(TkindSm1State6, DispatchF);
    RUN_TEST_CASE(TkindSm1State6, DispatchG);
    RUN_TEST_CASE(TkindSm1State6, DispatchH);
    RUN_TEST_CASE(TkindSm1State6, DispatchI);
    RUN_TEST_CASE(TkindSm1State6, DispatchJ);
    RUN_TEST_CASE(TkindSm1State6, DispatchK);
    RUN_TEST_CASE(TkindSm1State6, DispatchL);
    RUN_TEST_CASE(TkindSm1State6, DispatchM);
    RUN_TEST_CASE(TkindSm1State6, DispatchN);
    RUN_TEST_CASE(TkindSm1State6, DispatchOWithFalseChoice1);
    RUN_TEST_CASE(TkindSm1State6, DispatchOWithTrueChoice1);
    
    RUN_TEST_CASE(TkindSm1State6, FetchReturnsFalse);
    RUN_TEST_CASE(TkindSm1State6, DispatchReturnsFalse);
    RUN_TEST_CASE(TkindSm1State6, ReleaseReturnsFalse);
}
