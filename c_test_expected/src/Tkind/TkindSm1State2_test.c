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

#define TKIND_CTEST_EVENT_COUNT_SUM  (TKIND_CTEST_I_CNT\
                                      + TKIND_CTEST_O_CNT\
                                      + TKIND_CTEST_A_CNT\
                                      + TKIND_CTEST_B_CNT\
                                      + TKIND_CTEST_C_CNT\
                                      + TKIND_CTEST_F_CNT\
                                      + TKIND_CTEST_E_CNT\
                                      + TKIND_CTEST_D_CNT\
                                      + TKIND_CTEST_N_CNT\
                                      + TKIND_CTEST_H_CNT\
                                      + TKIND_CTEST_G_CNT\
                                      + TKIND_CTEST_J_CNT\
                                      + TKIND_CTEST_M_CNT\
                                      + TKIND_CTEST_K_CNT\
                                      + TKIND_CTEST_L_CNT)

/*******************************************************************************
 *
 * Test group TkindSm1State2.
 *
 ******************************************************************************/
TEST_GROUP(TkindSm1State2);

TEST_SETUP(TkindSm1State2)
{
    tkind_test_init_logger_buffer();
    tkind_ctest_init(&tkind_ctest_obj, &tkind_test_logger);
    tkind_test_init_logger_buffer();
}

TEST_TEAR_DOWN(TkindSm1State2)
{

}
/*================================TEST_CASES==================================*/
TEST(TkindSm1State2, InitResultsInInitialTransition)
{
    tkind_ctest_logger_expect(true, "Initial1 to State1\n"
                              "Enter State1\n"
                              "Initial3 to State2\n"
                              "Enter State2\n");
    tkind_ctest_logger_given(tkind_ctest_init(&tkind_ctest_obj,
                             &tkind_test_logger));
}

TEST(TkindSm1State2, enqueue_dequeue_full)
{
    for(int k = 0; k<10; ++k)
    {
        for(fifo_size_t j = 0u; j < TKIND_CTEST_I_CNT; ++j)
        {
            TEST_ASSERT_TRUE(tkind_ctest_i(&tkind_ctest_obj));
        }
        TEST_ASSERT_FALSE(tkind_ctest_i(&tkind_ctest_obj));

        for(fifo_size_t j = 0u; j < TKIND_CTEST_O_CNT; ++j)
        {
            TEST_ASSERT_TRUE(tkind_ctest_o(&tkind_ctest_obj));
        }
        TEST_ASSERT_FALSE(tkind_ctest_o(&tkind_ctest_obj));

        for(fifo_size_t j = 0u; j < TKIND_CTEST_A_CNT; ++j)
        {
            TEST_ASSERT_TRUE(tkind_ctest_a(&tkind_ctest_obj));
        }
        TEST_ASSERT_FALSE(tkind_ctest_a(&tkind_ctest_obj));

        for(fifo_size_t j = 0u; j < TKIND_CTEST_B_CNT; ++j)
        {
            TEST_ASSERT_TRUE(tkind_ctest_b(&tkind_ctest_obj));
        }
        TEST_ASSERT_FALSE(tkind_ctest_b(&tkind_ctest_obj));

        for(fifo_size_t j = 0u; j < TKIND_CTEST_C_CNT; ++j)
        {
            TEST_ASSERT_TRUE(tkind_ctest_c(&tkind_ctest_obj));
        }
        TEST_ASSERT_FALSE(tkind_ctest_c(&tkind_ctest_obj));

        for(fifo_size_t j = 0u; j < TKIND_CTEST_F_CNT; ++j)
        {
            TEST_ASSERT_TRUE(tkind_ctest_f(&tkind_ctest_obj));
        }
        TEST_ASSERT_FALSE(tkind_ctest_f(&tkind_ctest_obj));

        for(fifo_size_t j = 0u; j < TKIND_CTEST_E_CNT; ++j)
        {
            TEST_ASSERT_TRUE(tkind_ctest_e(&tkind_ctest_obj));
        }
        TEST_ASSERT_FALSE(tkind_ctest_e(&tkind_ctest_obj));

        for(fifo_size_t j = 0u; j < TKIND_CTEST_D_CNT; ++j)
        {
            TEST_ASSERT_TRUE(tkind_ctest_d(&tkind_ctest_obj));
        }
        TEST_ASSERT_FALSE(tkind_ctest_d(&tkind_ctest_obj));

        for(fifo_size_t j = 0u; j < TKIND_CTEST_N_CNT; ++j)
        {
            TEST_ASSERT_TRUE(tkind_ctest_n(&tkind_ctest_obj));
        }
        TEST_ASSERT_FALSE(tkind_ctest_n(&tkind_ctest_obj));

        for(fifo_size_t j = 0u; j < TKIND_CTEST_H_CNT; ++j)
        {
            TEST_ASSERT_TRUE(tkind_ctest_h(&tkind_ctest_obj));
        }
        TEST_ASSERT_FALSE(tkind_ctest_h(&tkind_ctest_obj));

        for(fifo_size_t j = 0u; j < TKIND_CTEST_G_CNT; ++j)
        {
            TEST_ASSERT_TRUE(tkind_ctest_g(&tkind_ctest_obj));
        }
        TEST_ASSERT_FALSE(tkind_ctest_g(&tkind_ctest_obj));

        for(fifo_size_t j = 0u; j < TKIND_CTEST_J_CNT; ++j)
        {
            TEST_ASSERT_TRUE(tkind_ctest_j(&tkind_ctest_obj));
        }
        TEST_ASSERT_FALSE(tkind_ctest_j(&tkind_ctest_obj));

        for(fifo_size_t j = 0u; j < TKIND_CTEST_M_CNT; ++j)
        {
            TEST_ASSERT_TRUE(tkind_ctest_m(&tkind_ctest_obj));
        }
        TEST_ASSERT_FALSE(tkind_ctest_m(&tkind_ctest_obj));

        for(fifo_size_t j = 0u; j < TKIND_CTEST_K_CNT; ++j)
        {
            TEST_ASSERT_TRUE(tkind_ctest_k(&tkind_ctest_obj));
        }
        TEST_ASSERT_FALSE(tkind_ctest_k(&tkind_ctest_obj));

        for(fifo_size_t j = 0u; j < TKIND_CTEST_L_CNT; ++j)
        {
            TEST_ASSERT_TRUE(tkind_ctest_l(&tkind_ctest_obj));
        }
        TEST_ASSERT_FALSE(tkind_ctest_l(&tkind_ctest_obj));

        for(fifo_size_t j = 0u; j<TKIND_CTEST_EVENT_COUNT_SUM; ++j)
        {
            tkind_test_init_logger_buffer();
            TEST_ASSERT_TRUE(tkind_ctest_fetch_event(&tkind_ctest_obj)
                            && tkind_ctest_dispatch_event(&tkind_ctest_obj)
                            && tkind_ctest_release_event(&tkind_ctest_obj));
        }

        TEST_ASSERT_FALSE(tkind_ctest_fetch_event(&tkind_ctest_obj));
    }
}

TEST(TkindSm1State2, DispatchA)
{
    tkind_ctest_logger_expect(true, "Exit State2\n"
                              "State2 to State3\n"
                              "Enter State3\n");
    tkind_ctest_logger_dispatch_given(tkind_ctest_a(&tkind_ctest_obj));
}

TEST(TkindSm1State2, DispatchB)
{
    tkind_ctest_logger_expect(true, "Exit State2\n"
                              "State2 to State4\n"
                              "Enter State4\n");
    tkind_ctest_logger_dispatch_given(tkind_ctest_b(&tkind_ctest_obj));
}

TEST(TkindSm1State2, DispatchC)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_dispatch_given(tkind_ctest_c(&tkind_ctest_obj));
}

TEST(TkindSm1State2, DispatchD)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_dispatch_given(tkind_ctest_d(&tkind_ctest_obj));
}

TEST(TkindSm1State2, DispatchE)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_dispatch_given(tkind_ctest_e(&tkind_ctest_obj));
}

TEST(TkindSm1State2, DispatchF)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_dispatch_given(tkind_ctest_f(&tkind_ctest_obj));
}

TEST(TkindSm1State2, DispatchG)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_dispatch_given(tkind_ctest_g(&tkind_ctest_obj));
}

TEST(TkindSm1State2, DispatchH)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_dispatch_given(tkind_ctest_h(&tkind_ctest_obj));
}

TEST(TkindSm1State2, DispatchI)
{
    tkind_ctest_logger_expect(true, "Exit State2\n"
                              "Exit State1\n"
                              "State1 to State7\n"
                              "Enter State1\n"
                              "Enter State7\n"
                              "Initial3 to State2\n"
                              "Enter State2\n");
    tkind_ctest_logger_dispatch_given(tkind_ctest_i(&tkind_ctest_obj));
}

TEST(TkindSm1State2, DispatchJ)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_dispatch_given(tkind_ctest_j(&tkind_ctest_obj));
}

TEST(TkindSm1State2, DispatchK)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_dispatch_given(tkind_ctest_k(&tkind_ctest_obj));
}

TEST(TkindSm1State2, DispatchL)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_dispatch_given(tkind_ctest_l(&tkind_ctest_obj));
}

TEST(TkindSm1State2, DispatchM)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_dispatch_given(tkind_ctest_m(&tkind_ctest_obj));
}

TEST(TkindSm1State2, DispatchN)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_dispatch_given(tkind_ctest_n(&tkind_ctest_obj));
}

TEST(TkindSm1State2, DispatchOWithFalseChoice1)
{
    tkind_ctest_logger_expect(true, "Exit State2\n"
                              "Exit State1\n"
                              "State1 to Choice1\n"
                              "Enter State1\n"
                              "Choice1 to State1\n"
                              "Initial3 to State2\n"
                              "Enter State2\n");
    tkind_ctest_obj.sm1.b_test_condition = false;
    tkind_ctest_logger_dispatch_given(tkind_ctest_o(&tkind_ctest_obj));
}

TEST(TkindSm1State2, DispatchOWithTrueChoice1)
{
    tkind_ctest_logger_expect(true, "Exit State2\n"
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

TEST(TkindSm1State2, FetchReturnsFalse)
{
    tkind_ctest_logger_expect(false, NULL);
    tkind_ctest_logger_given(tkind_ctest_fetch_event(&tkind_ctest_obj));
}

TEST(TkindSm1State2, DispatchReturnsFalse)
{
    tkind_ctest_logger_expect(false, NULL);
    tkind_ctest_logger_given(tkind_ctest_dispatch_event(&tkind_ctest_obj));
}

TEST(TkindSm1State2, ReleaseReturnsFalse)
{
    tkind_ctest_logger_expect(false, NULL);
    tkind_ctest_logger_given(tkind_ctest_release_event(&tkind_ctest_obj));
}


TEST_GROUP_RUNNER(TkindSm1State2)
{
    RUN_TEST_CASE(TkindSm1State2, InitResultsInInitialTransition);

    RUN_TEST_CASE(TkindSm1State2, enqueue_dequeue_full);

    RUN_TEST_CASE(TkindSm1State2, DispatchA);
    RUN_TEST_CASE(TkindSm1State2, DispatchB);
    RUN_TEST_CASE(TkindSm1State2, DispatchC);
    RUN_TEST_CASE(TkindSm1State2, DispatchD);
    RUN_TEST_CASE(TkindSm1State2, DispatchE);
    RUN_TEST_CASE(TkindSm1State2, DispatchF);
    RUN_TEST_CASE(TkindSm1State2, DispatchG);
    RUN_TEST_CASE(TkindSm1State2, DispatchH);
    RUN_TEST_CASE(TkindSm1State2, DispatchI);
    RUN_TEST_CASE(TkindSm1State2, DispatchJ);
    RUN_TEST_CASE(TkindSm1State2, DispatchK);
    RUN_TEST_CASE(TkindSm1State2, DispatchL);
    RUN_TEST_CASE(TkindSm1State2, DispatchM);
    RUN_TEST_CASE(TkindSm1State2, DispatchN);
    RUN_TEST_CASE(TkindSm1State2, DispatchOWithFalseChoice1);
    RUN_TEST_CASE(TkindSm1State2, DispatchOWithTrueChoice1);

    RUN_TEST_CASE(TkindSm1State2, FetchReturnsFalse);
    RUN_TEST_CASE(TkindSm1State2, DispatchReturnsFalse);
    RUN_TEST_CASE(TkindSm1State2, ReleaseReturnsFalse);
}

/*** end of file ***/
