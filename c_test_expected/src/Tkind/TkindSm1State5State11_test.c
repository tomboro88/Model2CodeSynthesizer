/*
 * @file TkindSm1State5State11_test.c
 *
 * @brief Source code of the TkindSm1State5State11 group test cases.
 * @author tomboro88
 * @date   21 november 2026
 * @copyright (c) 2026 tomboro88.
 * @license SPDX-License-Identifier: EPL-2.0
 * @project github.com/tomboro88/Model2CodeSynthesizer
 */
#include "Tkind_test.h"

/*******************************************************************************
 *
 * Test group TkindSm1State5State11.
 *
 ******************************************************************************/
TEST_GROUP(TkindSm1State5State11);

void tkind_test_enter_state5_state11(void)
{
    tkind_test_enter_state3();

    tkind_ctest_c(&tkind_ctest_obj);
    tkind_ctest_fetch_event(&tkind_ctest_obj);
    tkind_ctest_dispatch_event(&tkind_ctest_obj);
    tkind_ctest_release_event(&tkind_ctest_obj);

    tkind_ctest_k(&tkind_ctest_obj);
    tkind_ctest_fetch_event(&tkind_ctest_obj);
    tkind_ctest_dispatch_event(&tkind_ctest_obj);
    tkind_ctest_release_event(&tkind_ctest_obj);
}

TEST_SETUP(TkindSm1State5State11)
{
    tkind_test_init_logger_buffer();
    tkind_test_enter_state5_state11();
    tkind_test_init_logger_buffer();
}

TEST_TEAR_DOWN(TkindSm1State5State11)
{

}

/*================================TEST_CASES==================================*/
TEST(TkindSm1State5State11, InitResultsInInitialTransition)
{
    tkind_ctest_logger_expect_initial();
    tkind_ctest_logger_given(tkind_ctest_init(&tkind_ctest_obj,
                                              &tkind_test_logger));
}

/* --------------------------------- Events -------------------------------- */

TEST(TkindSm1State5State11, DispatchA)
{
    tkind_ctest_logger_expect(true, "Internal transition in State11"
                                    " on all events\n");
    tkind_ctest_logger_dispatch_given(tkind_ctest_a(&tkind_ctest_obj));
}

TEST(TkindSm1State5State11, DispatchBGuardFalse)
{
    tkind_ctest_logger_expect(true, "Internal transition in State11"
                                    " on all events\n");
    tkind_ctest_obj.sm1.b_test_condition = false;
    tkind_ctest_logger_dispatch_given(tkind_ctest_b(&tkind_ctest_obj));
}

TEST(TkindSm1State5State11, DispatchBGuardTrue)
{
    tkind_ctest_logger_expect(true, "Internal transition in State11"
                                    " on all events\n");
    tkind_ctest_obj.sm1.b_test_condition = true;
    tkind_ctest_logger_dispatch_given(tkind_ctest_b(&tkind_ctest_obj));
}

TEST(TkindSm1State5State11, DispatchC)
{
    tkind_ctest_logger_expect(true, "Exit State5\n"
                                    "State3 to State5\n"
                                    "Enter State5\n"
                                    "State11 to State12\n");
    tkind_ctest_logger_dispatch_given(tkind_ctest_c(&tkind_ctest_obj));
}

TEST(TkindSm1State5State11, DispatchDGuardFalse)
{
    tkind_ctest_logger_expect(true, "Exit State5\n"
                                    "State5 to State3\n"
                                    "Internal transition in State11"
                                    " on all events\n");
    tkind_ctest_obj.sm1.b_test_condition = false;
    tkind_ctest_logger_dispatch_given(tkind_ctest_d(&tkind_ctest_obj));
}

TEST(TkindSm1State5State11, DispatchDGuardTrue)
{
    tkind_ctest_logger_expect(true, "Exit State5\n"
                                    "State5 to State3\n"
                                    "Internal transition in State11"
                                    " on all events\n");
    tkind_ctest_obj.sm1.b_test_condition = true;
    tkind_ctest_logger_dispatch_given(tkind_ctest_d(&tkind_ctest_obj));
}

TEST(TkindSm1State5State11, DispatchE)
{
    tkind_ctest_logger_expect(true, "Exit State5\n"
                                    "Exit State3\n"
                                    "State5 to State1\n"
                                    "Initial3 to State2\n"
                                    "Enter State2\n"
                                    "Internal transition in State11"
                                    " on all events\n");
    tkind_ctest_logger_dispatch_given(tkind_ctest_e(&tkind_ctest_obj));
}

TEST(TkindSm1State5State11, DispatchF)
{
    tkind_ctest_logger_expect(true, "Internal transition in State11"
                                    " on all events\n");
    tkind_ctest_logger_dispatch_given(tkind_ctest_f(&tkind_ctest_obj));
}

TEST(TkindSm1State5State11, DispatchG)
{
    tkind_ctest_logger_expect(true, "Internal transition in State11"
                                    " on all events\n");
    tkind_ctest_logger_dispatch_given(tkind_ctest_g(&tkind_ctest_obj, 25, 'a'));
}

TEST(TkindSm1State5State11, DispatchH)
{
    tkind_ctest_logger_expect(true, "Internal transition in State11"
                                    " on all events\n");
    tkind_ctest_logger_dispatch_given(tkind_ctest_h(&tkind_ctest_obj, 16));
}

TEST(TkindSm1State5State11, DispatchI)
{
    tkind_ctest_logger_expect(true, "Internal transition in State11"
                                    " on all events\n");
    tkind_ctest_logger_dispatch_given(tkind_ctest_i(&tkind_ctest_obj));
}

TEST(TkindSm1State5State11, DispatchJ)
{
    tkind_ctest_logger_expect(true, "Internal transition in State11"
                                    " on all events\n");
    tkind_ctest_logger_dispatch_given(tkind_ctest_j(&tkind_ctest_obj));
}

TEST(TkindSm1State5State11, DispatchK)
{
    tkind_ctest_logger_expect(true, "Internal transition in State11"
                                    " on all events\n");
    tkind_ctest_logger_dispatch_given(tkind_ctest_k(&tkind_ctest_obj));
}

TEST(TkindSm1State5State11, DispatchL)
{
    tkind_ctest_logger_expect(true, "Internal transition in State11"
                                    " on all events\n");
    tkind_ctest_logger_dispatch_given(tkind_ctest_l(&tkind_ctest_obj));
}

TEST(TkindSm1State5State11, DispatchM)
{
    tkind_ctest_logger_expect(true, "Internal transition in State11"
                                    " on all events\n");
    tkind_ctest_logger_dispatch_given(tkind_ctest_m(&tkind_ctest_obj));
}

TEST(TkindSm1State5State11, DispatchN)
{
    tkind_ctest_logger_expect(true, "Exit State5\n"
                                    "Exit State3\n"
                                    "State5 to State6\n"
                                    "Enter State4\n"
                                    "Enter State6\n"
                                    "Internal transition in State11"
                                    " on all events\n");
    tkind_ctest_logger_dispatch_given(tkind_ctest_n(&tkind_ctest_obj));
}

TEST(TkindSm1State5State11, DispatchOWithFalseChoice1)
{
    tkind_ctest_logger_expect(true, "Internal transition in State11"
                                    " on all events\n");
    tkind_ctest_obj.sm1.b_test_condition = false;
    tkind_ctest_logger_dispatch_given(tkind_ctest_o(&tkind_ctest_obj));
}

TEST(TkindSm1State5State11, DispatchOWithTrueChoice1)
{
    tkind_ctest_logger_expect(true, "Internal transition in State11"
                                    " on all events\n");
    tkind_ctest_obj.sm1.b_test_condition = true;
    tkind_ctest_logger_dispatch_given(tkind_ctest_o(&tkind_ctest_obj));
}

/* ------------------------------ Queue errors ------------------------------ */
TEST(TkindSm1State5State11, FetchReturnsFalse)
{
    tkind_ctest_logger_expect(false, NULL);
    tkind_ctest_logger_given(tkind_ctest_fetch_event(&tkind_ctest_obj));
}

TEST(TkindSm1State5State11, DispatchReturnsFalse)
{
    tkind_ctest_logger_expect(false, NULL);
    tkind_ctest_logger_given(tkind_ctest_dispatch_event(&tkind_ctest_obj));
}

TEST(TkindSm1State5State11, ReleaseReturnsFalse)
{
    tkind_ctest_logger_expect(false, NULL);
    tkind_ctest_logger_given(tkind_ctest_release_event(&tkind_ctest_obj));
}

/*==============================TEST_GROUP_RUNNER=============================*/

TEST_GROUP_RUNNER(TkindSm1State5State11)
{
    RUN_TEST_CASE(TkindSm1State5State11, InitResultsInInitialTransition);

    RUN_TEST_CASE(TkindSm1State5State11, DispatchA);
    RUN_TEST_CASE(TkindSm1State5State11, DispatchBGuardFalse);
    RUN_TEST_CASE(TkindSm1State5State11, DispatchBGuardTrue);
    RUN_TEST_CASE(TkindSm1State5State11, DispatchC);
    RUN_TEST_CASE(TkindSm1State5State11, DispatchDGuardFalse);
    RUN_TEST_CASE(TkindSm1State5State11, DispatchDGuardTrue);
    RUN_TEST_CASE(TkindSm1State5State11, DispatchE);
    RUN_TEST_CASE(TkindSm1State5State11, DispatchF);
    RUN_TEST_CASE(TkindSm1State5State11, DispatchG);
    RUN_TEST_CASE(TkindSm1State5State11, DispatchH);
    RUN_TEST_CASE(TkindSm1State5State11, DispatchI);
    RUN_TEST_CASE(TkindSm1State5State11, DispatchJ);
    RUN_TEST_CASE(TkindSm1State5State11, DispatchK);
    RUN_TEST_CASE(TkindSm1State5State11, DispatchL);
    RUN_TEST_CASE(TkindSm1State5State11, DispatchM);
    RUN_TEST_CASE(TkindSm1State5State11, DispatchN);
    RUN_TEST_CASE(TkindSm1State5State11, DispatchOWithFalseChoice1);
    RUN_TEST_CASE(TkindSm1State5State11, DispatchOWithTrueChoice1);

    RUN_TEST_CASE(TkindSm1State5State11, FetchReturnsFalse);
    RUN_TEST_CASE(TkindSm1State5State11, DispatchReturnsFalse);
    RUN_TEST_CASE(TkindSm1State5State11, ReleaseReturnsFalse);
}
