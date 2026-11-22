/*
 * @file TkindSm1State2_test.c
 *
 * @brief Source code of the TkindSm1State2 group test cases.
 * @author tomboro88
 * @date   1 may 2026
 * @copyright (c) 2026 tomboro88. 
 * @license SPDX-License-Identifier: EPL-2.0
 * @project github.com/tomboro88/Model2CodeSynthesizer
 */
#include "Tkind_test.h"


/*******************************************************************************
 *
 * Test group TkindSm1State3.
 *
 ******************************************************************************/
void tkind_test_enter_state3(void)
{
    plogger_test_init_buffer();
    tkind_ctest_init(&tkind_ctest_obj, &plogger_test_logger);

    tkind_ctest_a(&tkind_ctest_obj);
    tkind_ctest_fetch_event(&tkind_ctest_obj);
    tkind_ctest_dispatch_event(&tkind_ctest_obj);
    tkind_ctest_release_event(&tkind_ctest_obj);
}

TEST_GROUP(TkindSm1State3);

TEST_SETUP(TkindSm1State3)
{
    tkind_test_enter_state3();
    plogger_test_init_buffer();
}

TEST_TEAR_DOWN(TkindSm1State3)
{

}

/*================================TEST_CASES==================================*/
TEST(TkindSm1State3, InitResultsInInitialTransition)
{
    tkind_ctest_logger_expect_initial();
    plogger_test_given(tkind_ctest_init(&tkind_ctest_obj, &plogger_test_logger));
}

TEST(TkindSm1State3, DispatchA)
{
    plogger_test_expect(true, NULL);
    tkind_ctest_logger_dispatch_given(tkind_ctest_a(&tkind_ctest_obj));
}

TEST(TkindSm1State3, DispatchB)
{
    plogger_test_expect(true, "Internal transition in State1 "
                              "on event b\n");
    tkind_ctest_logger_dispatch_given(tkind_ctest_b(&tkind_ctest_obj));
}

TEST(TkindSm1State3, DispatchC)
{
    plogger_test_expect(true, "State3 to State5\n"
                              "Enter State5\n");
    tkind_ctest_logger_dispatch_given(tkind_ctest_c(&tkind_ctest_obj));
}

TEST(TkindSm1State3, DispatchD)
{
    plogger_test_expect(true, "Local State1 to State13.\n"
                              "Enter State13\n");
    tkind_ctest_obj.sm1.b_test_condition = true;
    tkind_ctest_logger_dispatch_given(tkind_ctest_d(&tkind_ctest_obj));
}

TEST(TkindSm1State3, DispatchE)
{
    plogger_test_expect(true, NULL);
    tkind_ctest_logger_dispatch_given(tkind_ctest_e(&tkind_ctest_obj));
}

TEST(TkindSm1State3, DispatchF)
{
    plogger_test_expect(true, NULL);
    tkind_ctest_logger_dispatch_given(tkind_ctest_f(&tkind_ctest_obj));
}

TEST(TkindSm1State3, DispatchG)
{
    plogger_test_expect(true, NULL);
    tkind_ctest_logger_dispatch_given(tkind_ctest_g(&tkind_ctest_obj, 25, 'a'));
}

TEST(TkindSm1State3, DispatchH)
{
    plogger_test_expect(true, NULL);
    tkind_ctest_logger_dispatch_given(tkind_ctest_h(&tkind_ctest_obj, 16));
}

TEST(TkindSm1State3, DispatchI)
{
    plogger_test_expect(true, "Exit State3\n"
                              "Exit State1\n"
                              "State1 to State7\n"
                              "Enter State1\n"
                              "Initial3 to State2\n"
                              "Enter State2\n"
                              "Enter State7\n");
    tkind_ctest_logger_dispatch_given(tkind_ctest_i(&tkind_ctest_obj));
}

TEST(TkindSm1State3, DispatchJ)
{
    plogger_test_expect(true, NULL);
    tkind_ctest_logger_dispatch_given(tkind_ctest_j(&tkind_ctest_obj));
}

TEST(TkindSm1State3, DispatchK)
{
    plogger_test_expect(true, "Local State1 to State10.\n");
    tkind_ctest_logger_dispatch_given(tkind_ctest_k(&tkind_ctest_obj));
}

TEST(TkindSm1State3, DispatchL)
{
    plogger_test_expect(true, NULL);
    tkind_ctest_logger_dispatch_given(tkind_ctest_l(&tkind_ctest_obj));
}

TEST(TkindSm1State3, DispatchM)
{
    plogger_test_expect(true, NULL);
    tkind_ctest_logger_dispatch_given(tkind_ctest_m(&tkind_ctest_obj));
}

TEST(TkindSm1State3, DispatchN)
{
    plogger_test_expect(true, NULL);
    tkind_ctest_logger_dispatch_given(tkind_ctest_n(&tkind_ctest_obj));
}

TEST(TkindSm1State3, DispatchOWithFalseChoice1)
{
    plogger_test_expect(true, "Exit State3\n"
                              "Exit State1\n"
                              "State1 to Choice1\n"
                              "Enter State1\n"
                              "Initial3 to State2\n"
                              "Enter State2\n"
                              "Choice1 to State1\n");
    tkind_ctest_obj.sm1.b_test_condition = false;
    tkind_ctest_logger_dispatch_given(tkind_ctest_o(&tkind_ctest_obj));
}

TEST(TkindSm1State3, DispatchOWithTrueChoice1)
{
    plogger_test_expect(true, "Exit State3\n"
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

TEST(TkindSm1State3, FetchReturnsFalse)
{
    plogger_test_expect(false, NULL);
    plogger_test_given(tkind_ctest_fetch_event(&tkind_ctest_obj));
}

TEST(TkindSm1State3, DispatchReturnsFalse)
{
    plogger_test_expect(false, NULL);
    plogger_test_given(tkind_ctest_dispatch_event(&tkind_ctest_obj));
}

TEST(TkindSm1State3, ReleaseReturnsFalse)
{
    plogger_test_expect(false, NULL);
    plogger_test_given(tkind_ctest_release_event(&tkind_ctest_obj));
}


TEST_GROUP_RUNNER(TkindSm1State3)
{
    RUN_TEST_CASE(TkindSm1State3, InitResultsInInitialTransition);

    RUN_TEST_CASE(TkindSm1State3, DispatchA);
    RUN_TEST_CASE(TkindSm1State3, DispatchB);
    RUN_TEST_CASE(TkindSm1State3, DispatchC);
    RUN_TEST_CASE(TkindSm1State3, DispatchD);
    RUN_TEST_CASE(TkindSm1State3, DispatchE);
    RUN_TEST_CASE(TkindSm1State3, DispatchF);
    RUN_TEST_CASE(TkindSm1State3, DispatchG);
    RUN_TEST_CASE(TkindSm1State3, DispatchH);
    RUN_TEST_CASE(TkindSm1State3, DispatchI);
    RUN_TEST_CASE(TkindSm1State3, DispatchJ);
    RUN_TEST_CASE(TkindSm1State3, DispatchK);
    RUN_TEST_CASE(TkindSm1State3, DispatchL);
    RUN_TEST_CASE(TkindSm1State3, DispatchM);
    RUN_TEST_CASE(TkindSm1State3, DispatchN);
    RUN_TEST_CASE(TkindSm1State3, DispatchOWithFalseChoice1);
    RUN_TEST_CASE(TkindSm1State3, DispatchOWithTrueChoice1);

    RUN_TEST_CASE(TkindSm1State3, FetchReturnsFalse);
    RUN_TEST_CASE(TkindSm1State3, DispatchReturnsFalse);
    RUN_TEST_CASE(TkindSm1State3, ReleaseReturnsFalse);
}

/*** end of file ***/
