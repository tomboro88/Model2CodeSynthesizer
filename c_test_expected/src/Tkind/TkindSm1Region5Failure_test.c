/*
 * @file TkindSm1Region5Failure_test.c
 *
 * @brief Source code of the TkindSm1Region5Failure group test cases.
 * @author tomboro88
 * @date   18 november 2026
 * @copyright (c) 2026 tomboro88.
 * @license SPDX-License-Identifier: EPL-2.0
 * @project github.com/tomboro88/Model2CodeSynthesizer
 */
#include "Tkind_test.h"

/*******************************************************************************
 *
 * Test group TkindSm1Region5Failure.
 *
 ******************************************************************************/
TEST_GROUP(TkindSm1Region5Failure);

void tkind_test_enter_region5_failure(void)
{
    tkind_ctest_init(&tkind_ctest_obj, &tkind_test_logger);
    tkind_ctest_obj.sm1.region5 = TKIND_SM1_REGION5_SIZE;
}

TEST_SETUP(TkindSm1Region5Failure)
{
    tkind_test_init_logger_buffer();
    tkind_test_enter_region5_failure();
    tkind_test_init_logger_buffer();
}

TEST_TEAR_DOWN(TkindSm1Region5Failure)
{

}

/*================================TEST_CASES==================================*/
TEST(TkindSm1Region5Failure, InitResultsInInitialTransition)
{
    tkind_ctest_logger_expect_initial();
    tkind_ctest_logger_given(tkind_ctest_init(&tkind_ctest_obj,
                                              &tkind_test_logger));
}

/* --------------------------------- Events -------------------------------- */

TEST(TkindSm1Region5Failure, DispatchA)
{
    tkind_ctest_logger_expect(true, "Exit State2\n"
                                    "State2 to State3\n"
                                    "Enter State3\n");
    tkind_ctest_logger_dispatch_given(tkind_ctest_a(&tkind_ctest_obj));
}

TEST(TkindSm1Region5Failure, DispatchBGuardFalse)
{
    tkind_ctest_logger_expect(true, "Exit State2\n"
                                    "State2 to State4\n"
                                    "Enter State4\n"
                                    "Enter Failure\n");
    tkind_ctest_obj.sm1.b_test_condition = false;
    tkind_ctest_logger_dispatch_given(tkind_ctest_b(&tkind_ctest_obj));
}

TEST(TkindSm1Region5Failure, DispatchBGuardTrue)
{
    tkind_ctest_logger_expect(true, "Exit State2\n"
                                    "State2 to State4\n"
                                    "Enter State4\n"
                                    "Enter Failure\n");
    tkind_ctest_obj.sm1.b_test_condition = true;
    tkind_ctest_logger_dispatch_given(tkind_ctest_b(&tkind_ctest_obj));
}

TEST(TkindSm1Region5Failure, DispatchC)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_dispatch_given(tkind_ctest_c(&tkind_ctest_obj));
}

TEST(TkindSm1Region5Failure, DispatchD)
{
    tkind_ctest_logger_expect(true, "Local State1 to State13.\n"
                                    "Enter State13\n");
    tkind_ctest_obj.sm1.b_test_condition = true;
    tkind_ctest_logger_dispatch_given(tkind_ctest_d(&tkind_ctest_obj));
}

TEST(TkindSm1Region5Failure, DispatchE)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_dispatch_given(tkind_ctest_e(&tkind_ctest_obj));
}

TEST(TkindSm1Region5Failure, DispatchF)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_dispatch_given(tkind_ctest_f(&tkind_ctest_obj));
}

TEST(TkindSm1Region5Failure, DispatchG)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_dispatch_given(tkind_ctest_g(&tkind_ctest_obj, 25, 'a'));
}

TEST(TkindSm1Region5Failure, DispatchH)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_dispatch_given(tkind_ctest_h(&tkind_ctest_obj, 16));
}

TEST(TkindSm1Region5Failure, DispatchI)
{
    tkind_ctest_logger_expect_failure_all();
    tkind_ctest_logger_dispatch_given(tkind_ctest_i(&tkind_ctest_obj));
}

TEST(TkindSm1Region5Failure, DispatchJ)
{
    tkind_ctest_logger_expect_failure_all();
    tkind_ctest_logger_dispatch_given(tkind_ctest_j(&tkind_ctest_obj));
}

TEST(TkindSm1Region5Failure, DispatchK)
{
    tkind_ctest_logger_expect_failure_all();
    tkind_ctest_logger_dispatch_given(tkind_ctest_k(&tkind_ctest_obj));
}

TEST(TkindSm1Region5Failure, DispatchL)
{
    tkind_ctest_logger_expect_failure_all();
    tkind_ctest_logger_dispatch_given(tkind_ctest_l(&tkind_ctest_obj));
}

TEST(TkindSm1Region5Failure, DispatchM)
{
    tkind_ctest_logger_expect_failure_all();
    tkind_ctest_logger_dispatch_given(tkind_ctest_m(&tkind_ctest_obj));
}

TEST(TkindSm1Region5Failure, DispatchN)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_dispatch_given(tkind_ctest_n(&tkind_ctest_obj));
}

TEST(TkindSm1Region5Failure, DispatchOWithFalseChoice1)
{
    tkind_ctest_logger_expect(true, "Exit State2\n"
                                    "Enter Failure\n");
    tkind_ctest_obj.sm1.b_test_condition = false;
    tkind_ctest_logger_dispatch_given(tkind_ctest_o(&tkind_ctest_obj));
}

TEST(TkindSm1Region5Failure, DispatchOWithTrueChoice1)
{
    tkind_ctest_logger_expect(true, "Exit State2\n"
                                    "Enter Failure\n");
    tkind_ctest_obj.sm1.b_test_condition = true;
    tkind_ctest_logger_dispatch_given(tkind_ctest_o(&tkind_ctest_obj));
}

/* ------------------------------ Queue errors ------------------------------ */
TEST(TkindSm1Region5Failure, FetchReturnsFalse)
{
    tkind_ctest_logger_expect(false, NULL);
    tkind_ctest_logger_given(tkind_ctest_fetch_event(&tkind_ctest_obj));
}

TEST(TkindSm1Region5Failure, DispatchReturnsFalse)
{
    tkind_ctest_logger_expect(false, NULL);
    tkind_ctest_logger_given(tkind_ctest_dispatch_event(&tkind_ctest_obj));
}

TEST(TkindSm1Region5Failure, ReleaseReturnsFalse)
{
    tkind_ctest_logger_expect(false, NULL);
    tkind_ctest_logger_given(tkind_ctest_release_event(&tkind_ctest_obj));
}

/*==============================TEST_GROUP_RUNNER=============================*/

TEST_GROUP_RUNNER(TkindSm1Region5Failure)
{
    RUN_TEST_CASE(TkindSm1Region5Failure, InitResultsInInitialTransition);

    RUN_TEST_CASE(TkindSm1Region5Failure, DispatchA);
    RUN_TEST_CASE(TkindSm1Region5Failure, DispatchBGuardFalse);
    RUN_TEST_CASE(TkindSm1Region5Failure, DispatchBGuardTrue);
    RUN_TEST_CASE(TkindSm1Region5Failure, DispatchC);
    RUN_TEST_CASE(TkindSm1Region5Failure, DispatchD);
    RUN_TEST_CASE(TkindSm1Region5Failure, DispatchE);
    RUN_TEST_CASE(TkindSm1Region5Failure, DispatchF);
    RUN_TEST_CASE(TkindSm1Region5Failure, DispatchG);
    RUN_TEST_CASE(TkindSm1Region5Failure, DispatchH);
    RUN_TEST_CASE(TkindSm1Region5Failure, DispatchI);
    RUN_TEST_CASE(TkindSm1Region5Failure, DispatchJ);
    RUN_TEST_CASE(TkindSm1Region5Failure, DispatchK);
    RUN_TEST_CASE(TkindSm1Region5Failure, DispatchL);
    RUN_TEST_CASE(TkindSm1Region5Failure, DispatchM);
    RUN_TEST_CASE(TkindSm1Region5Failure, DispatchN);
    RUN_TEST_CASE(TkindSm1Region5Failure, DispatchOWithFalseChoice1);
    RUN_TEST_CASE(TkindSm1Region5Failure, DispatchOWithTrueChoice1);

    RUN_TEST_CASE(TkindSm1Region5Failure, FetchReturnsFalse);
    RUN_TEST_CASE(TkindSm1Region5Failure, DispatchReturnsFalse);
    RUN_TEST_CASE(TkindSm1Region5Failure, ReleaseReturnsFalse);
}
