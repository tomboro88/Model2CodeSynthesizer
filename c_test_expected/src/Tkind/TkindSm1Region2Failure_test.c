/*
 * @file TkindSm1Region2Failure_test.c
 *
 * @brief Source code of the TkindSm1Region2Failure group test cases.
 * @author tomboro88
 * @date   17 october 2026
 * @copyright (c) 2026 tomboro88. 
 * @license SPDX-License-Identifier: EPL-2.0
 * @project github.com/tomboro88/Model2CodeSynthesizer
 */
#include "Tkind_test.h"

/*******************************************************************************
 *
 * Test group TkindSm1Region2Failure.
 *
 ******************************************************************************/
TEST_GROUP(TkindSm1Region2Failure);

void tkind_test_enter_region2_failure(void)
{
    tkind_ctest_init(&tkind_ctest_obj, &plogger_test_logger);
    tkind_ctest_obj.sm1.region2 = TKIND_SM1_REGION2_SIZE;
}

TEST_SETUP(TkindSm1Region2Failure)
{
    plogger_test_init_buffer();
    tkind_test_enter_region2_failure();
    plogger_test_init_buffer();
}

TEST_TEAR_DOWN(TkindSm1Region2Failure)
{

}

/*================================TEST_CASES==================================*/
TEST(TkindSm1Region2Failure, InitResultsInInitialTransition)
{
    tkind_ctest_logger_expect_initial();
    plogger_test_given(tkind_ctest_init(&tkind_ctest_obj,
                                        &plogger_test_logger));
}

/* --------------------------------- Events -------------------------------- */

TEST(TkindSm1Region2Failure, DispatchA)
{
    tkind_ctest_logger_expect_failure_a();
    tkind_ctest_logger_dispatch_given(tkind_ctest_a(&tkind_ctest_obj));
}

TEST(TkindSm1Region2Failure, DispatchBGuardFalse)
{
    tkind_ctest_logger_expect_failure_all();
    tkind_ctest_obj.sm1.b_test_condition = false;
    tkind_ctest_logger_dispatch_given(tkind_ctest_b(&tkind_ctest_obj));
}

TEST(TkindSm1Region2Failure, DispatchBGuardTrue)
{
    tkind_ctest_logger_expect_failure_all();
    tkind_ctest_obj.sm1.b_test_condition = true;
    tkind_ctest_logger_dispatch_given(tkind_ctest_b(&tkind_ctest_obj));
}

TEST(TkindSm1Region2Failure, DispatchC)
{
    tkind_ctest_logger_expect_failure_all();
    tkind_ctest_logger_dispatch_given(tkind_ctest_c(&tkind_ctest_obj));
}

TEST(TkindSm1Region2Failure, DispatchD)
{
    tkind_ctest_logger_expect_failure_all();
    tkind_ctest_obj.sm1.b_test_condition = true;
    tkind_ctest_logger_dispatch_given(tkind_ctest_d(&tkind_ctest_obj));
}

TEST(TkindSm1Region2Failure, DispatchE)
{
    tkind_ctest_logger_expect_failure_all();
    tkind_ctest_logger_dispatch_given(tkind_ctest_e(&tkind_ctest_obj));
}

TEST(TkindSm1Region2Failure, DispatchF)
{
    tkind_ctest_logger_expect_failure_all();
    tkind_ctest_logger_dispatch_given(tkind_ctest_f(&tkind_ctest_obj));
}

TEST(TkindSm1Region2Failure, DispatchG)
{
    tkind_ctest_logger_expect_failure_all();
    tkind_ctest_logger_dispatch_given(tkind_ctest_g(&tkind_ctest_obj, 25, 'a'));
}

TEST(TkindSm1Region2Failure, DispatchH)
{
    tkind_ctest_logger_expect_failure_all();
    tkind_ctest_logger_dispatch_given(tkind_ctest_h(&tkind_ctest_obj, 16));
}

TEST(TkindSm1Region2Failure, DispatchI)
{
    tkind_ctest_logger_expect_failure_all();
    tkind_ctest_logger_dispatch_given(tkind_ctest_i(&tkind_ctest_obj));
}

TEST(TkindSm1Region2Failure, DispatchJ)
{
    plogger_test_expect(true, NULL);
    tkind_ctest_logger_dispatch_given(tkind_ctest_j(&tkind_ctest_obj));
}

TEST(TkindSm1Region2Failure, DispatchK)
{
    plogger_test_expect(true, "Local State1 to State10.\n");
    tkind_ctest_logger_dispatch_given(tkind_ctest_k(&tkind_ctest_obj));
}

TEST(TkindSm1Region2Failure, DispatchL)
{
    plogger_test_expect(true, NULL);
    tkind_ctest_logger_dispatch_given(tkind_ctest_l(&tkind_ctest_obj));
}

TEST(TkindSm1Region2Failure, DispatchM)
{
    plogger_test_expect(true, NULL);
    tkind_ctest_logger_dispatch_given(tkind_ctest_m(&tkind_ctest_obj));
}

TEST(TkindSm1Region2Failure, DispatchN)
{
    tkind_ctest_logger_expect_failure_all();
    tkind_ctest_logger_dispatch_given(tkind_ctest_n(&tkind_ctest_obj));
}

TEST(TkindSm1Region2Failure, DispatchOWithFalseChoice1)
{
    tkind_ctest_logger_expect_failure_all();
    tkind_ctest_obj.sm1.b_test_condition = false;
    tkind_ctest_logger_dispatch_given(tkind_ctest_o(&tkind_ctest_obj));
}

TEST(TkindSm1Region2Failure, DispatchOWithTrueChoice1)
{
    tkind_ctest_logger_expect_failure_all();
    tkind_ctest_obj.sm1.b_test_condition = true;
    tkind_ctest_logger_dispatch_given(tkind_ctest_o(&tkind_ctest_obj));
}

/* ------------------------------ Queue errors ------------------------------ */
TEST(TkindSm1Region2Failure, FetchReturnsFalse)
{
    plogger_test_expect(false, NULL);
    plogger_test_given(tkind_ctest_fetch_event(&tkind_ctest_obj));
}

TEST(TkindSm1Region2Failure, DispatchReturnsFalse)
{
    plogger_test_expect(false, NULL);
    plogger_test_given(tkind_ctest_dispatch_event(&tkind_ctest_obj));
}

TEST(TkindSm1Region2Failure, ReleaseReturnsFalse)
{
    plogger_test_expect(false, NULL);
    plogger_test_given(tkind_ctest_release_event(&tkind_ctest_obj));
}

/*==============================TEST_GROUP_RUNNER=============================*/

TEST_GROUP_RUNNER(TkindSm1Region2Failure)
{
    RUN_TEST_CASE(TkindSm1Region2Failure, InitResultsInInitialTransition);

    RUN_TEST_CASE(TkindSm1Region2Failure, DispatchA);
    RUN_TEST_CASE(TkindSm1Region2Failure, DispatchBGuardFalse);
    RUN_TEST_CASE(TkindSm1Region2Failure, DispatchBGuardTrue);
    RUN_TEST_CASE(TkindSm1Region2Failure, DispatchC);
    RUN_TEST_CASE(TkindSm1Region2Failure, DispatchD)
    RUN_TEST_CASE(TkindSm1Region2Failure, DispatchE);
    RUN_TEST_CASE(TkindSm1Region2Failure, DispatchF);
    RUN_TEST_CASE(TkindSm1Region2Failure, DispatchG);
    RUN_TEST_CASE(TkindSm1Region2Failure, DispatchH);
    RUN_TEST_CASE(TkindSm1Region2Failure, DispatchI);
    RUN_TEST_CASE(TkindSm1Region2Failure, DispatchJ);
    RUN_TEST_CASE(TkindSm1Region2Failure, DispatchK);
    RUN_TEST_CASE(TkindSm1Region2Failure, DispatchL);
    RUN_TEST_CASE(TkindSm1Region2Failure, DispatchM);
    RUN_TEST_CASE(TkindSm1Region2Failure, DispatchN);
    RUN_TEST_CASE(TkindSm1Region2Failure, DispatchOWithFalseChoice1);
    RUN_TEST_CASE(TkindSm1Region2Failure, DispatchOWithTrueChoice1);
    
    RUN_TEST_CASE(TkindSm1Region2Failure, FetchReturnsFalse);
    RUN_TEST_CASE(TkindSm1Region2Failure, DispatchReturnsFalse);
    RUN_TEST_CASE(TkindSm1Region2Failure, ReleaseReturnsFalse);
}
