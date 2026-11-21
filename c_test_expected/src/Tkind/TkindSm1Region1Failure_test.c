/*
 * @file TkindSm1Region1Failure_test.c
 *
 * @brief Source code of the TkindSm1Region1Failure group test cases.
 * @author tomboro88
 * @date   17 october 2026
 * @copyright (c) 2026 tomboro88. 
 * @license SPDX-License-Identifier: EPL-2.0
 * @project github.com/tomboro88/Model2CodeSynthesizer
 */
#include "Tkind_test.h"

/*******************************************************************************
 *
 * Test group TkindSm1Region1Failure.
 *
 ******************************************************************************/
TEST_GROUP(TkindSm1Region1Failure);

void tkind_test_enter_region1_failure(void)
{
	tkind_ctest_init(&tkind_ctest_obj, &tkind_test_logger);
	tkind_ctest_obj.sm1.region1 = TKIND_SM1_REGION1_SIZE;
}

TEST_SETUP(TkindSm1Region1Failure)
{
    tkind_test_init_logger_buffer();
    tkind_test_enter_region1_failure();
    tkind_test_init_logger_buffer();
}

TEST_TEAR_DOWN(TkindSm1Region1Failure)
{

}

/*================================TEST_CASES==================================*/
TEST(TkindSm1Region1Failure, InitResultsInInitialTransition)
{
	tkind_ctest_logger_expect_initial();
    tkind_ctest_logger_given(tkind_ctest_init(&tkind_ctest_obj,
                                              &tkind_test_logger));
}

/* --------------------------------- Events -------------------------------- */

TEST(TkindSm1Region1Failure, DispatchA)
{
	tkind_ctest_logger_expect_failure_a();
    tkind_ctest_logger_dispatch_given(tkind_ctest_a(&tkind_ctest_obj));
}

TEST(TkindSm1Region1Failure, DispatchBGuardFalse)
{
	tkind_ctest_logger_expect_failure_all();
    tkind_ctest_obj.sm1.b_test_condition = false;
    tkind_ctest_logger_dispatch_given(tkind_ctest_b(&tkind_ctest_obj));
}

TEST(TkindSm1Region1Failure, DispatchBGuardTrue)
{
	tkind_ctest_logger_expect_failure_all();
    tkind_ctest_obj.sm1.b_test_condition = true;
    tkind_ctest_logger_dispatch_given(tkind_ctest_b(&tkind_ctest_obj));
}

TEST(TkindSm1Region1Failure, DispatchC)
{
	tkind_ctest_logger_expect_failure_all();
    tkind_ctest_logger_dispatch_given(tkind_ctest_c(&tkind_ctest_obj));
}

TEST(TkindSm1Region1Failure, DispatchD)
{
	tkind_ctest_logger_expect_failure_all();
    tkind_ctest_obj.sm1.b_test_condition = true;
    tkind_ctest_logger_dispatch_given(tkind_ctest_d(&tkind_ctest_obj));
}

TEST(TkindSm1Region1Failure, DispatchE)
{
	tkind_ctest_logger_expect_failure_all();
    tkind_ctest_logger_dispatch_given(tkind_ctest_e(&tkind_ctest_obj));
}

TEST(TkindSm1Region1Failure, DispatchF)
{
	tkind_ctest_logger_expect_failure_all();
    tkind_ctest_logger_dispatch_given(tkind_ctest_f(&tkind_ctest_obj));
}

TEST(TkindSm1Region1Failure, DispatchG)
{
	tkind_ctest_logger_expect_failure_all();
    tkind_ctest_logger_dispatch_given(tkind_ctest_g(&tkind_ctest_obj, 25, 'a'));
}

TEST(TkindSm1Region1Failure, DispatchH)
{
	tkind_ctest_logger_expect_failure_all();
    tkind_ctest_logger_dispatch_given(tkind_ctest_h(&tkind_ctest_obj, 16));
}

TEST(TkindSm1Region1Failure, DispatchI)
{
	tkind_ctest_logger_expect_failure_all();
    tkind_ctest_logger_dispatch_given(tkind_ctest_i(&tkind_ctest_obj));
}

TEST(TkindSm1Region1Failure, DispatchJ)
{
	tkind_ctest_logger_expect_failure_all();
    tkind_ctest_logger_dispatch_given(tkind_ctest_j(&tkind_ctest_obj));
}

TEST(TkindSm1Region1Failure, DispatchK)
{
	tkind_ctest_logger_expect_failure_all();
    tkind_ctest_logger_dispatch_given(tkind_ctest_k(&tkind_ctest_obj));
}

TEST(TkindSm1Region1Failure, DispatchL)
{
	tkind_ctest_logger_expect_failure_all();
    tkind_ctest_logger_dispatch_given(tkind_ctest_l(&tkind_ctest_obj));
}

TEST(TkindSm1Region1Failure, DispatchM)
{
	tkind_ctest_logger_expect_failure_all();
    tkind_ctest_logger_dispatch_given(tkind_ctest_m(&tkind_ctest_obj));
}

TEST(TkindSm1Region1Failure, DispatchN)
{
	tkind_ctest_logger_expect_failure_all();
    tkind_ctest_logger_dispatch_given(tkind_ctest_n(&tkind_ctest_obj));
}

TEST(TkindSm1Region1Failure, DispatchOWithFalseChoice1)
{
	tkind_ctest_logger_expect_failure_all();
    tkind_ctest_obj.sm1.b_test_condition = false;
    tkind_ctest_logger_dispatch_given(tkind_ctest_o(&tkind_ctest_obj));
}

TEST(TkindSm1Region1Failure, DispatchOWithTrueChoice1)
{
	tkind_ctest_logger_expect_failure_all();
    tkind_ctest_obj.sm1.b_test_condition = true;
    tkind_ctest_logger_dispatch_given(tkind_ctest_o(&tkind_ctest_obj));
}

/* ------------------------------ Queue errors ------------------------------ */
TEST(TkindSm1Region1Failure, FetchReturnsFalse)
{
    tkind_ctest_logger_expect(false, NULL);
    tkind_ctest_logger_given(tkind_ctest_fetch_event(&tkind_ctest_obj));
}

TEST(TkindSm1Region1Failure, DispatchReturnsFalse)
{
    tkind_ctest_logger_expect(false, NULL);
    tkind_ctest_logger_given(tkind_ctest_dispatch_event(&tkind_ctest_obj));
}

TEST(TkindSm1Region1Failure, ReleaseReturnsFalse)
{
    tkind_ctest_logger_expect(false, NULL);
    tkind_ctest_logger_given(tkind_ctest_release_event(&tkind_ctest_obj));
}

/*==============================TEST_GROUP_RUNNER=============================*/

TEST_GROUP_RUNNER(TkindSm1Region1Failure)
{
    RUN_TEST_CASE(TkindSm1Region1Failure, InitResultsInInitialTransition);

    RUN_TEST_CASE(TkindSm1Region1Failure, DispatchA);
    RUN_TEST_CASE(TkindSm1Region1Failure, DispatchBGuardFalse);
    RUN_TEST_CASE(TkindSm1Region1Failure, DispatchBGuardTrue);
    RUN_TEST_CASE(TkindSm1Region1Failure, DispatchC);
    RUN_TEST_CASE(TkindSm1Region1Failure, DispatchD)
    RUN_TEST_CASE(TkindSm1Region1Failure, DispatchE);
    RUN_TEST_CASE(TkindSm1Region1Failure, DispatchF);
    RUN_TEST_CASE(TkindSm1Region1Failure, DispatchG);
    RUN_TEST_CASE(TkindSm1Region1Failure, DispatchH);
    RUN_TEST_CASE(TkindSm1Region1Failure, DispatchI);
    RUN_TEST_CASE(TkindSm1Region1Failure, DispatchJ);
    RUN_TEST_CASE(TkindSm1Region1Failure, DispatchK);
    RUN_TEST_CASE(TkindSm1Region1Failure, DispatchL);
    RUN_TEST_CASE(TkindSm1Region1Failure, DispatchM);
    RUN_TEST_CASE(TkindSm1Region1Failure, DispatchN);
    RUN_TEST_CASE(TkindSm1Region1Failure, DispatchOWithFalseChoice1);
    RUN_TEST_CASE(TkindSm1Region1Failure, DispatchOWithTrueChoice1);
    
    RUN_TEST_CASE(TkindSm1Region1Failure, FetchReturnsFalse);
    RUN_TEST_CASE(TkindSm1Region1Failure, DispatchReturnsFalse);
    RUN_TEST_CASE(TkindSm1Region1Failure, ReleaseReturnsFalse);
}
