/*
 * @file TkindSm1Region3Failure_test.c
 *
 * @brief Source code of the TkindSm1Region3Failure group test cases.
 * @author tomboro88
 * @date   18 november 2026
 * @copyright (c) 2026 tomboro88.
 * @license SPDX-License-Identifier: EPL-2.0
 * @project github.com/tomboro88/Model2CodeSynthesizer
 */
#include "Tkind_test.h"

/*******************************************************************************
 *
 * Test group TkindSm1Region3Failure.
 *
 ******************************************************************************/
TEST_GROUP(TkindSm1Region3Failure);

void tkind_test_enter_region3_failure(void)
{
    tkind_test_enter_state3();
    tkind_ctest_obj.sm1.region3 = TKIND_SM1_REGION3_SIZE;
}

TEST_SETUP(TkindSm1Region3Failure)
{
    tkind_test_init_logger_buffer();
    tkind_test_enter_region3_failure();
    tkind_test_init_logger_buffer();
}

TEST_TEAR_DOWN(TkindSm1Region3Failure)
{

}

/*================================TEST_CASES==================================*/
TEST(TkindSm1Region3Failure, InitResultsInInitialTransition)
{
    tkind_ctest_logger_expect_initial();
    tkind_ctest_logger_given(tkind_ctest_init(&tkind_ctest_obj,
                                              &tkind_test_logger));
}

/* --------------------------------- Events -------------------------------- */

TEST(TkindSm1Region3Failure, DispatchA)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_dispatch_given(tkind_ctest_a(&tkind_ctest_obj));
}

TEST(TkindSm1Region3Failure, DispatchBGuardFalse)
{
    tkind_ctest_logger_expect(true, "Internal transition in State1"
                                    " on event b\n");
    tkind_ctest_obj.sm1.b_test_condition = false;
    tkind_ctest_logger_dispatch_given(tkind_ctest_b(&tkind_ctest_obj));
}

TEST(TkindSm1Region3Failure, DispatchBGuardTrue)
{
    tkind_ctest_logger_expect(true, "Internal transition in State1"
                                    " on event b\n");
    tkind_ctest_obj.sm1.b_test_condition = true;
    tkind_ctest_logger_dispatch_given(tkind_ctest_b(&tkind_ctest_obj));
}

TEST(TkindSm1Region3Failure, DispatchC)
{
    tkind_ctest_logger_expect_failure_all();
    tkind_ctest_logger_dispatch_given(tkind_ctest_c(&tkind_ctest_obj));
}

TEST(TkindSm1Region3Failure, DispatchD)
{
    tkind_ctest_logger_expect_failure_all();
    tkind_ctest_obj.sm1.b_test_condition = true;
    tkind_ctest_logger_dispatch_given(tkind_ctest_d(&tkind_ctest_obj));
}

TEST(TkindSm1Region3Failure, DispatchE)
{
    tkind_ctest_logger_expect_failure_all();
    tkind_ctest_logger_dispatch_given(tkind_ctest_e(&tkind_ctest_obj));
}

TEST(TkindSm1Region3Failure, DispatchF)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_dispatch_given(tkind_ctest_f(&tkind_ctest_obj));
}

TEST(TkindSm1Region3Failure, DispatchG)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_dispatch_given(tkind_ctest_g(&tkind_ctest_obj, 25, 'a'));
}

TEST(TkindSm1Region3Failure, DispatchH)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_dispatch_given(tkind_ctest_h(&tkind_ctest_obj, 16));
}

TEST(TkindSm1Region3Failure, DispatchI)
{
    tkind_ctest_logger_expect_failure_all();
    tkind_ctest_logger_dispatch_given(tkind_ctest_i(&tkind_ctest_obj));
}

TEST(TkindSm1Region3Failure, DispatchJ)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_dispatch_given(tkind_ctest_j(&tkind_ctest_obj));
}

TEST(TkindSm1Region3Failure, DispatchK)
{
    tkind_ctest_logger_expect(true, "Local State1 to State10.\n");
    tkind_ctest_logger_dispatch_given(tkind_ctest_k(&tkind_ctest_obj));
}

TEST(TkindSm1Region3Failure, DispatchL)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_dispatch_given(tkind_ctest_l(&tkind_ctest_obj));
}

TEST(TkindSm1Region3Failure, DispatchM)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_dispatch_given(tkind_ctest_m(&tkind_ctest_obj));
}

TEST(TkindSm1Region3Failure, DispatchN)
{
    tkind_ctest_logger_expect_failure_all();
    tkind_ctest_logger_dispatch_given(tkind_ctest_n(&tkind_ctest_obj));
}

TEST(TkindSm1Region3Failure, DispatchOWithFalseChoice1)
{
    tkind_ctest_logger_expect_failure_all();
    tkind_ctest_obj.sm1.b_test_condition = false;
    tkind_ctest_logger_dispatch_given(tkind_ctest_o(&tkind_ctest_obj));
}

TEST(TkindSm1Region3Failure, DispatchOWithTrueChoice1)
{
    tkind_ctest_logger_expect_failure_all();
    tkind_ctest_obj.sm1.b_test_condition = true;
    tkind_ctest_logger_dispatch_given(tkind_ctest_o(&tkind_ctest_obj));
}

/* ------------------------------ Queue errors ------------------------------ */
TEST(TkindSm1Region3Failure, FetchReturnsFalse)
{
    tkind_ctest_logger_expect(false, NULL);
    tkind_ctest_logger_given(tkind_ctest_fetch_event(&tkind_ctest_obj));
}

TEST(TkindSm1Region3Failure, DispatchReturnsFalse)
{
    tkind_ctest_logger_expect(false, NULL);
    tkind_ctest_logger_given(tkind_ctest_dispatch_event(&tkind_ctest_obj));
}

TEST(TkindSm1Region3Failure, ReleaseReturnsFalse)
{
    tkind_ctest_logger_expect(false, NULL);
    tkind_ctest_logger_given(tkind_ctest_release_event(&tkind_ctest_obj));
}

/*==============================TEST_GROUP_RUNNER=============================*/

TEST_GROUP_RUNNER(TkindSm1Region3Failure)
{
    RUN_TEST_CASE(TkindSm1Region3Failure, InitResultsInInitialTransition);

    RUN_TEST_CASE(TkindSm1Region3Failure, DispatchA);
    RUN_TEST_CASE(TkindSm1Region3Failure, DispatchBGuardFalse);
    RUN_TEST_CASE(TkindSm1Region3Failure, DispatchBGuardTrue);
    RUN_TEST_CASE(TkindSm1Region3Failure, DispatchC);
    RUN_TEST_CASE(TkindSm1Region3Failure, DispatchD);
    RUN_TEST_CASE(TkindSm1Region3Failure, DispatchE);
    RUN_TEST_CASE(TkindSm1Region3Failure, DispatchF);
    RUN_TEST_CASE(TkindSm1Region3Failure, DispatchG);
    RUN_TEST_CASE(TkindSm1Region3Failure, DispatchH);
    RUN_TEST_CASE(TkindSm1Region3Failure, DispatchI);
    RUN_TEST_CASE(TkindSm1Region3Failure, DispatchJ);
    RUN_TEST_CASE(TkindSm1Region3Failure, DispatchK);
    RUN_TEST_CASE(TkindSm1Region3Failure, DispatchL);
    RUN_TEST_CASE(TkindSm1Region3Failure, DispatchM);
    RUN_TEST_CASE(TkindSm1Region3Failure, DispatchN);
    RUN_TEST_CASE(TkindSm1Region3Failure, DispatchOWithFalseChoice1);
    RUN_TEST_CASE(TkindSm1Region3Failure, DispatchOWithTrueChoice1);

    RUN_TEST_CASE(TkindSm1Region3Failure, FetchReturnsFalse);
    RUN_TEST_CASE(TkindSm1Region3Failure, DispatchReturnsFalse);
    RUN_TEST_CASE(TkindSm1Region3Failure, ReleaseReturnsFalse);
}
