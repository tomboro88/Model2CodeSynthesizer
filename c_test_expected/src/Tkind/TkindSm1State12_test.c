/*
 * @file TkindSm1State12_test.c
 *
 * @brief Source code of the TkindSm1State12 group test cases.
 * @author tomboro88
 * @date   17 october 2026
 * @copyright (c) 2026 tomboro88. 
 * @license SPDX-License-Identifier: EPL-2.0
 * @project github.com/tomboro88/Model2CodeSynthesizer
 */
#include "Tkind_test.h"

/*******************************************************************************
 *
 * Test group TkindSm1State12.
 *
 ******************************************************************************/
TEST_GROUP(TkindSm1State12);

void tkind_test_enter_state12(void)
{
    tkind_test_enter_state11();

    tkind_ctest_c(&tkind_ctest_obj);
    tkind_ctest_fetch_event(&tkind_ctest_obj);
    tkind_ctest_dispatch_event(&tkind_ctest_obj);
    tkind_ctest_release_event(&tkind_ctest_obj);
}

TEST_SETUP(TkindSm1State12)
{
    plogger_test_init_buffer();
    tkind_test_enter_state12();
    plogger_test_init_buffer();
}

TEST_TEAR_DOWN(TkindSm1State12)
{

}

/*================================TEST_CASES==================================*/
TEST(TkindSm1State12, InitResultsInInitialTransition)
{
    tkind_ctest_logger_expect_initial();
    plogger_test_given(tkind_ctest_init(&tkind_ctest_obj,
                                        &plogger_test_logger));
}

/* --------------------------------- Events -------------------------------- */

TEST(TkindSm1State12, DispatchA)
{
    plogger_test_expect(true, "Exit State2\n"
                              "State2 to State3\n"
                              "Enter State3\n"
                              "Internal transition in State10"
                              " on all events\n");
    tkind_ctest_logger_dispatch_given(tkind_ctest_a(&tkind_ctest_obj));
}

TEST(TkindSm1State12, DispatchBGuardFalse)
{
    plogger_test_expect(true, "Exit State2\n"
                              "State2 to State4\n"
                              "Enter State4\n"
                              "Internal transition in State10"
                              " on all events\n");
    tkind_ctest_obj.sm1.b_test_condition = false;
    tkind_ctest_logger_dispatch_given(tkind_ctest_b(&tkind_ctest_obj));
}

TEST(TkindSm1State12, DispatchBGuardTrue)
{
    plogger_test_expect(true, "Exit State2\n"
                              "State2 to State4\n"
                              "Enter State4\n"
                              "Internal transition in State10"
                              " on all events\n");
    tkind_ctest_obj.sm1.b_test_condition = true;
    tkind_ctest_logger_dispatch_given(tkind_ctest_b(&tkind_ctest_obj));
}

TEST(TkindSm1State12, DispatchC)
{
    plogger_test_expect(true, "Internal transition in State10"
                              " on c event\n");
    tkind_ctest_logger_dispatch_given(tkind_ctest_c(&tkind_ctest_obj));
}

TEST(TkindSm1State12, DispatchDGuardFalse)
{
    plogger_test_expect(true, "Local State1 to State13.\n"
                              "Enter State13\n");
    tkind_ctest_obj.sm1.b_test_condition = false;
    tkind_ctest_logger_dispatch_given(tkind_ctest_d(&tkind_ctest_obj));
}

TEST(TkindSm1State12, DispatchDGuardTrue)
{
    plogger_test_expect(true, "Internal transition in State10"
                              " on d event\n");
    tkind_ctest_obj.sm1.b_test_condition = true;
    tkind_ctest_logger_dispatch_given(tkind_ctest_d(&tkind_ctest_obj));
}

TEST(TkindSm1State12, DispatchE)
{
    plogger_test_expect(true, "Internal transition in State10"
                              " on all events\n");
    tkind_ctest_logger_dispatch_given(tkind_ctest_e(&tkind_ctest_obj));
}

TEST(TkindSm1State12, DispatchF)
{
    plogger_test_expect(true, "Internal transition in State10"
                              " on all events\n");
    tkind_ctest_logger_dispatch_given(tkind_ctest_f(&tkind_ctest_obj));
}

TEST(TkindSm1State12, DispatchG)
{
    plogger_test_expect(true, "Internal transition in State10"
                              " on all events\n");
    tkind_ctest_logger_dispatch_given(tkind_ctest_g(&tkind_ctest_obj, 25, 'a'));
}

TEST(TkindSm1State12, DispatchH)
{
    plogger_test_expect(true, "Internal transition in State10"
                              " on all events\n");
    tkind_ctest_logger_dispatch_given(tkind_ctest_h(&tkind_ctest_obj, 16));
}

TEST(TkindSm1State12, DispatchI)
{
    plogger_test_expect(true, "Internal transition in State10"
                              " on all events\n");
    tkind_ctest_logger_dispatch_given(tkind_ctest_i(&tkind_ctest_obj));
}

TEST(TkindSm1State12, DispatchJ)
{
    plogger_test_expect(true, "Internal transition in State10"
                              " on all events\n");
    tkind_ctest_logger_dispatch_given(tkind_ctest_j(&tkind_ctest_obj));
}

TEST(TkindSm1State12, DispatchK)
{
    plogger_test_expect(true, "Internal transition in State10"
                              " on all events\n");
    tkind_ctest_logger_dispatch_given(tkind_ctest_k(&tkind_ctest_obj));
}

TEST(TkindSm1State12, DispatchL)
{
    plogger_test_expect(true, "Internal transition in State10"
                              " on all events\n");
    tkind_ctest_logger_dispatch_given(tkind_ctest_l(&tkind_ctest_obj));
}

TEST(TkindSm1State12, DispatchM)
{
    plogger_test_expect(true, "Internal transition in State10"
                              " on all events\n");
    tkind_ctest_logger_dispatch_given(tkind_ctest_m(&tkind_ctest_obj));
}

TEST(TkindSm1State12, DispatchN)
{
    plogger_test_expect(true, "Internal transition in State10"
                              " on all events\n");
    tkind_ctest_logger_dispatch_given(tkind_ctest_n(&tkind_ctest_obj));
}

TEST(TkindSm1State12, DispatchOWithFalseChoice1)
{
    plogger_test_expect(true, "Internal transition in State10"
                              " on all events\n");
    tkind_ctest_obj.sm1.b_test_condition = false;
    tkind_ctest_logger_dispatch_given(tkind_ctest_o(&tkind_ctest_obj));
}

TEST(TkindSm1State12, DispatchOWithTrueChoice1)
{
    plogger_test_expect(true, "Internal transition in State10"
                              " on all events\n");
    tkind_ctest_obj.sm1.b_test_condition = true;
    tkind_ctest_logger_dispatch_given(tkind_ctest_o(&tkind_ctest_obj));
}

/* ------------------------------ Queue errors ------------------------------ */
TEST(TkindSm1State12, FetchReturnsFalse)
{
    plogger_test_expect(false, NULL);
    plogger_test_given(tkind_ctest_fetch_event(&tkind_ctest_obj));
}

TEST(TkindSm1State12, DispatchReturnsFalse)
{
    plogger_test_expect(false, NULL);
    plogger_test_given(tkind_ctest_dispatch_event(&tkind_ctest_obj));
}

TEST(TkindSm1State12, ReleaseReturnsFalse)
{
    plogger_test_expect(false, NULL);
    plogger_test_given(tkind_ctest_release_event(&tkind_ctest_obj));
}

/*==============================TEST_GROUP_RUNNER=============================*/

TEST_GROUP_RUNNER(TkindSm1State12)
{
    RUN_TEST_CASE(TkindSm1State12, InitResultsInInitialTransition);

    RUN_TEST_CASE(TkindSm1State12, DispatchA);
    RUN_TEST_CASE(TkindSm1State12, DispatchBGuardFalse);
    RUN_TEST_CASE(TkindSm1State12, DispatchBGuardTrue);
    RUN_TEST_CASE(TkindSm1State12, DispatchC);
    RUN_TEST_CASE(TkindSm1State12, DispatchDGuardFalse);
    RUN_TEST_CASE(TkindSm1State12, DispatchDGuardTrue);
    RUN_TEST_CASE(TkindSm1State12, DispatchE);
    RUN_TEST_CASE(TkindSm1State12, DispatchF);
    RUN_TEST_CASE(TkindSm1State12, DispatchG);
    RUN_TEST_CASE(TkindSm1State12, DispatchH);
    RUN_TEST_CASE(TkindSm1State12, DispatchI);
    RUN_TEST_CASE(TkindSm1State12, DispatchJ);
    RUN_TEST_CASE(TkindSm1State12, DispatchK);
    RUN_TEST_CASE(TkindSm1State12, DispatchL);
    RUN_TEST_CASE(TkindSm1State12, DispatchM);
    RUN_TEST_CASE(TkindSm1State12, DispatchN);
    RUN_TEST_CASE(TkindSm1State12, DispatchOWithFalseChoice1);
    RUN_TEST_CASE(TkindSm1State12, DispatchOWithTrueChoice1);
    
    RUN_TEST_CASE(TkindSm1State12, FetchReturnsFalse);
    RUN_TEST_CASE(TkindSm1State12, DispatchReturnsFalse);
    RUN_TEST_CASE(TkindSm1State12, ReleaseReturnsFalse);
}
