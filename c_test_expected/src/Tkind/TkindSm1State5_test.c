/*
 * @file TkindSm1State5_test.c
 *
 * @brief Source code of the TkindSm1State5 group test cases.
 * @author tomboro88
 * @date   1 may 2026
 * @copyright (c) 2026 tomboro88. All rights reserved.
 * @license MIT – see LICENSE file in project root
 * @project github.com/tomboro88/M2T4Embedded
 */
#include "Tkind_test.h"

/*******************************************************************************
 *
 * Test group TkindSm1State5.
 *
 ******************************************************************************/
TEST_GROUP(TkindSm1State5);

static void tkind_test_enter_State5(void)
{
    tkind_test_enter_state3();

    Tkind_ctest_c(&tkind_ctest_obj);
    Tkind_ctest_fetch_event(&tkind_ctest_obj);
    Tkind_ctest_dispatch_event(&tkind_ctest_obj);
    Tkind_ctest_release_event(&tkind_ctest_obj);
}

TEST_SETUP(TkindSm1State5)
{
    tkind_test_init_logger_buffer();
    tkind_test_enter_State5();
    tkind_test_init_logger_buffer();
}

TEST_TEAR_DOWN(TkindSm1State5)
{

}

/*================================TEST_CASES==================================*/
TEST(TkindSm1State5, InitResultsInInitialTransition)
{
    tkind_ctest_logger_expect(true, "Initial1 to State1\n"
                              "Enter State1\n"
                              "Initial3 to State2\n"
                              "Enter State2\n");
    tkind_ctest_logger_given(Tkind_ctest_init(&tkind_ctest_obj, 
                                              &tkind_test_logger));
}

/* --------------------------------- Event A -------------------------------- */
TEST(TkindSm1State5, AReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_a(&tkind_ctest_obj));
}

TEST(TkindSm1State5, FetchAReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_a(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj));
}

TEST(TkindSm1State5, DispatchAReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_a(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj)
                       && Tkind_ctest_dispatch_event(&tkind_ctest_obj));
}

TEST(TkindSm1State5, ReleaseAReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_a(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj)
                       && Tkind_ctest_dispatch_event(&tkind_ctest_obj)
                       && Tkind_ctest_release_event(&tkind_ctest_obj));
}

/* --------------------------------- Event B -------------------------------- */
TEST(TkindSm1State5, BReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_b(&tkind_ctest_obj));
}

TEST(TkindSm1State5, FetchBReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_b(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj));
}

TEST(TkindSm1State5, DispatchBReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_b(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj)
                       && Tkind_ctest_dispatch_event(&tkind_ctest_obj));
}

TEST(TkindSm1State5, ReleaseBReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_b(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj)
                       && Tkind_ctest_dispatch_event(&tkind_ctest_obj)
                       && Tkind_ctest_release_event(&tkind_ctest_obj));
}

/* --------------------------------- Event C -------------------------------- */
TEST(TkindSm1State5, CReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_c(&tkind_ctest_obj));
}

TEST(TkindSm1State5, FetchCReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_c(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj));
}

TEST(TkindSm1State5, DispatchCReturnsTrue)
{
    tkind_ctest_logger_expect(true, "Exit State5\n"
                                    "State3 to State5\n"
                                    "Enter State5\n");
    tkind_ctest_logger_given(Tkind_ctest_c(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj)
                       && Tkind_ctest_dispatch_event(&tkind_ctest_obj));
}

TEST(TkindSm1State5, ReleaseCReturnsTrue)
{
    tkind_ctest_logger_expect(true, "Exit State5\n"
                                    "State3 to State5\n"
                                    "Enter State5\n");
    tkind_ctest_logger_given(Tkind_ctest_c(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj)
                       && Tkind_ctest_dispatch_event(&tkind_ctest_obj)
                       && Tkind_ctest_release_event(&tkind_ctest_obj));
}

/* --------------------------------- Event D -------------------------------- */
TEST(TkindSm1State5, DReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_d(&tkind_ctest_obj));
}

TEST(TkindSm1State5, FetchDReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_d(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj));
}

TEST(TkindSm1State5, DispatchDReturnsTrue)
{
    tkind_ctest_logger_expect(true, "Exit State5\n"
                                    "State5 to State3\n");
    tkind_ctest_logger_given(Tkind_ctest_d(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj)
                       && Tkind_ctest_dispatch_event(&tkind_ctest_obj));
}

TEST(TkindSm1State5, ReleaseDReturnsTrue)
{
    tkind_ctest_logger_expect(true, "Exit State5\n"
                                    "State5 to State3\n");
    tkind_ctest_logger_given(Tkind_ctest_d(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj)
                       && Tkind_ctest_dispatch_event(&tkind_ctest_obj)
                       && Tkind_ctest_release_event(&tkind_ctest_obj));
}

/* --------------------------------- Event E -------------------------------- */
TEST(TkindSm1State5, EReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_e(&tkind_ctest_obj));
}

TEST(TkindSm1State5, FetchEReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_e(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj));
}

TEST(TkindSm1State5, DispatchEReturnsTrue)
{
    tkind_ctest_logger_expect(true, "Exit State5\n"
                                    "Exit State3\n"
                                    "State5 to State1\n"
                                    "Initial3 to State2\n"
                                    "Enter State2\n");
    tkind_ctest_logger_given(Tkind_ctest_e(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj)
                       && Tkind_ctest_dispatch_event(&tkind_ctest_obj));
}

TEST(TkindSm1State5, ReleaseEReturnsTrue)
{
    tkind_ctest_logger_expect(true, "Exit State5\n"
                                    "Exit State3\n"
                                    "State5 to State1\n"
                                    "Initial3 to State2\n"
                                    "Enter State2\n");
    tkind_ctest_logger_given(Tkind_ctest_e(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj)
                       && Tkind_ctest_dispatch_event(&tkind_ctest_obj)
                       && Tkind_ctest_release_event(&tkind_ctest_obj));
}

/* --------------------------------- Event F -------------------------------- */
TEST(TkindSm1State5, FReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_f(&tkind_ctest_obj));
}

TEST(TkindSm1State5, FetchFReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_f(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj));
}

TEST(TkindSm1State5, DispatchFReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_f(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj)
                       && Tkind_ctest_dispatch_event(&tkind_ctest_obj));
}

TEST(TkindSm1State5, ReleaseFReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_f(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj)
                       && Tkind_ctest_dispatch_event(&tkind_ctest_obj)
                       && Tkind_ctest_release_event(&tkind_ctest_obj));
}

/* --------------------------------- Event G -------------------------------- */
TEST(TkindSm1State5, GReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_g(&tkind_ctest_obj));
}

TEST(TkindSm1State5, FetchGReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_g(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj));
}

TEST(TkindSm1State5, DispatchGReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_g(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj)
                       && Tkind_ctest_dispatch_event(&tkind_ctest_obj));
}

TEST(TkindSm1State5, ReleaseGReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_g(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj)
                       && Tkind_ctest_dispatch_event(&tkind_ctest_obj)
                       && Tkind_ctest_release_event(&tkind_ctest_obj));
}

/* --------------------------------- Event H -------------------------------- */
TEST(TkindSm1State5, HReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_h(&tkind_ctest_obj));
}

TEST(TkindSm1State5, FetchHReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_h(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj));
}

TEST(TkindSm1State5, DispatchHReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_h(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj)
                       && Tkind_ctest_dispatch_event(&tkind_ctest_obj));
}

TEST(TkindSm1State5, ReleaseHReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_h(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj)
                       && Tkind_ctest_dispatch_event(&tkind_ctest_obj)
                       && Tkind_ctest_release_event(&tkind_ctest_obj));
}

/* --------------------------------- Event I -------------------------------- */
TEST(TkindSm1State5, IReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_i(&tkind_ctest_obj));
}

TEST(TkindSm1State5, FetchIReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_i(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj));
}

TEST(TkindSm1State5, DispatchIReturnsTrue)
{
    tkind_ctest_logger_expect(true, "Exit State5\n"
                                    "Exit State3\n"
                                    "Exit State1\n"
                                    "State1 to State7\n"
                                    "Enter State1\n"
                                    "Enter State7\n"
                                    "Initial3 to State2\n"
                                    "Enter State2\n");
    tkind_ctest_logger_given(Tkind_ctest_i(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj)
                       && Tkind_ctest_dispatch_event(&tkind_ctest_obj));
}

TEST(TkindSm1State5, ReleaseIReturnsTrue)
{
    tkind_ctest_logger_expect(true, "Exit State5\n"
                                    "Exit State3\n"
                                    "Exit State1\n"
                                    "State1 to State7\n"
                                    "Enter State1\n"
                                    "Enter State7\n"
                                    "Initial3 to State2\n"
                                    "Enter State2\n");
    tkind_ctest_logger_given(Tkind_ctest_i(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj)
                       && Tkind_ctest_dispatch_event(&tkind_ctest_obj)
                       && Tkind_ctest_release_event(&tkind_ctest_obj));
}

/* --------------------------------- Event J -------------------------------- */
TEST(TkindSm1State5, JReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_j(&tkind_ctest_obj));
}

TEST(TkindSm1State5, FetchJReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_j(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj));
}

TEST(TkindSm1State5, DispatchJReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_j(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj)
                       && Tkind_ctest_dispatch_event(&tkind_ctest_obj));
}

TEST(TkindSm1State5, ReleaseJReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_j(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj)
                       && Tkind_ctest_dispatch_event(&tkind_ctest_obj)
                       && Tkind_ctest_release_event(&tkind_ctest_obj));
}

/* --------------------------------- Event K -------------------------------- */
TEST(TkindSm1State5, KReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_k(&tkind_ctest_obj));
}

TEST(TkindSm1State5, FetchKReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_k(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj));
}

TEST(TkindSm1State5, DispatchKReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_k(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj)
                       && Tkind_ctest_dispatch_event(&tkind_ctest_obj));
}

TEST(TkindSm1State5, ReleaseKReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_k(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj)
                       && Tkind_ctest_dispatch_event(&tkind_ctest_obj)
                       && Tkind_ctest_release_event(&tkind_ctest_obj));
}

/* --------------------------------- Event L -------------------------------- */
TEST(TkindSm1State5, LReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_l(&tkind_ctest_obj));
}

TEST(TkindSm1State5, FetchLReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_l(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj));
}

TEST(TkindSm1State5, DispatchLReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_l(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj)
                       && Tkind_ctest_dispatch_event(&tkind_ctest_obj));
}

TEST(TkindSm1State5, ReleaseLReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_l(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj)
                       && Tkind_ctest_dispatch_event(&tkind_ctest_obj)
                       && Tkind_ctest_release_event(&tkind_ctest_obj));
}

/* --------------------------------- Event M -------------------------------- */
TEST(TkindSm1State5, MReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_m(&tkind_ctest_obj));
}

TEST(TkindSm1State5, FetchMReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_m(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj));
}

TEST(TkindSm1State5, DispatchMReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_m(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj)
                       && Tkind_ctest_dispatch_event(&tkind_ctest_obj));
}

TEST(TkindSm1State5, ReleaseMReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_m(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj)
                       && Tkind_ctest_dispatch_event(&tkind_ctest_obj)
                       && Tkind_ctest_release_event(&tkind_ctest_obj));
}

/* --------------------------------- Event N -------------------------------- */
TEST(TkindSm1State5, NReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_n(&tkind_ctest_obj));
}

TEST(TkindSm1State5, FetchNReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_n(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj));
}

TEST(TkindSm1State5, DispatchNReturnsTrue)
{
    tkind_ctest_logger_expect(true, "Exit State5\n"
                                    "Exit State3\n"
                                    "State5 to State6\n"
                                    "Enter State4\n"
                                    "Enter State6\n");
    tkind_ctest_logger_given(Tkind_ctest_n(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj)
                       && Tkind_ctest_dispatch_event(&tkind_ctest_obj));
}

TEST(TkindSm1State5, ReleaseNReturnsTrue)
{
    tkind_ctest_logger_expect(true, "Exit State5\n"
                                    "Exit State3\n"
                                    "State5 to State6\n"
                                    "Enter State4\n"
                                    "Enter State6\n");
    tkind_ctest_logger_given(Tkind_ctest_n(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj)
                       && Tkind_ctest_dispatch_event(&tkind_ctest_obj)
                       && Tkind_ctest_release_event(&tkind_ctest_obj));
}

/* --------------------------------- Event O -------------------------------- */
TEST(TkindSm1State5, OReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_o(&tkind_ctest_obj));
}

TEST(TkindSm1State5, FetchOWithFalseChoice1ReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_obj.sm1.b_test_condition = false;
    tkind_ctest_logger_given(Tkind_ctest_o(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj));
}

TEST(TkindSm1State5, DispatchOWithFalseChoice1ReturnsTrue)
{
    tkind_ctest_logger_expect(true, "Exit State5\n"
                                    "Exit State3\n"
                                    "Exit State1\n"
                                    "State1 to Choice1\n"
                                    "Enter State1\n"
                                    "Choice1 to State1\n"
                                    "Initial3 to State2\n"
                                    "Enter State2\n");
    tkind_ctest_obj.sm1.b_test_condition = false;
    tkind_ctest_logger_given(Tkind_ctest_o(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj)
                       && Tkind_ctest_dispatch_event(&tkind_ctest_obj));
}

TEST(TkindSm1State5, ReleaseOWithFalseChoice1ReturnsTrue)
{
    tkind_ctest_logger_expect(true, "Exit State5\n"
                                    "Exit State3\n"
                                    "Exit State1\n"
                                    "State1 to Choice1\n"
                                    "Enter State1\n"
                                    "Choice1 to State1\n"
                                    "Initial3 to State2\n"
                                    "Enter State2\n");
    tkind_ctest_obj.sm1.b_test_condition = false;
    tkind_ctest_logger_given(Tkind_ctest_o(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj)
                       && Tkind_ctest_dispatch_event(&tkind_ctest_obj)
                       && Tkind_ctest_release_event(&tkind_ctest_obj));
}

TEST(TkindSm1State5, FetchOWithTrueChoice1ReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_obj.sm1.b_test_condition = true;
    tkind_ctest_logger_given(Tkind_ctest_o(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj));
}

TEST(TkindSm1State5, DispatchOWithTrueChoice1ReturnsTrue)
{
    tkind_ctest_logger_expect(true, "Exit State5\n"
                                    "Exit State3\n"
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
    tkind_ctest_logger_given(Tkind_ctest_o(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj)
                       && Tkind_ctest_dispatch_event(&tkind_ctest_obj));
}

TEST(TkindSm1State5, ReleaseOWithTrueChoice1ReturnsTrue)
{
    tkind_ctest_logger_expect(true, "Exit State5\n"
                                    "Exit State3\n"
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
    tkind_ctest_logger_given(Tkind_ctest_o(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj)
                       && Tkind_ctest_dispatch_event(&tkind_ctest_obj)
                       && Tkind_ctest_release_event(&tkind_ctest_obj));
}

/* ------------------------------ Queue errors ------------------------------ */
TEST(TkindSm1State5, FetchReturnsFalse)
{
    tkind_ctest_logger_expect(false, NULL);
    tkind_ctest_logger_given(Tkind_ctest_fetch_event(&tkind_ctest_obj));
}

TEST(TkindSm1State5, DispatchReturnsFalse)
{
    tkind_ctest_logger_expect(false, NULL);
    tkind_ctest_logger_given(Tkind_ctest_dispatch_event(&tkind_ctest_obj));
}

TEST(TkindSm1State5, ReleaseReturnsFalse)
{
    tkind_ctest_logger_expect(false, NULL);
    tkind_ctest_logger_given(Tkind_ctest_release_event(&tkind_ctest_obj));
}

/*==============================TEST_GROUP_RUNNER=============================*/

TEST_GROUP_RUNNER(TkindSm1State5)
{
    RUN_TEST_CASE(TkindSm1State5, InitResultsInInitialTransition);

    RUN_TEST_CASE(TkindSm1State5, AReturnsTrue);
    RUN_TEST_CASE(TkindSm1State5, FetchAReturnsTrue);
    RUN_TEST_CASE(TkindSm1State5, DispatchAReturnsTrue);
    RUN_TEST_CASE(TkindSm1State5, ReleaseAReturnsTrue);
    
    RUN_TEST_CASE(TkindSm1State5, BReturnsTrue);
    RUN_TEST_CASE(TkindSm1State5, FetchBReturnsTrue);
    RUN_TEST_CASE(TkindSm1State5, DispatchBReturnsTrue);
    RUN_TEST_CASE(TkindSm1State5, ReleaseBReturnsTrue);
    
    RUN_TEST_CASE(TkindSm1State5, CReturnsTrue);
    RUN_TEST_CASE(TkindSm1State5, FetchCReturnsTrue);
    RUN_TEST_CASE(TkindSm1State5, DispatchCReturnsTrue);
    RUN_TEST_CASE(TkindSm1State5, ReleaseCReturnsTrue);
    
    RUN_TEST_CASE(TkindSm1State5, DReturnsTrue);
    RUN_TEST_CASE(TkindSm1State5, FetchDReturnsTrue);
    RUN_TEST_CASE(TkindSm1State5, DispatchDReturnsTrue);
    RUN_TEST_CASE(TkindSm1State5, ReleaseDReturnsTrue);
    
    RUN_TEST_CASE(TkindSm1State5, EReturnsTrue);
    RUN_TEST_CASE(TkindSm1State5, FetchEReturnsTrue);
    RUN_TEST_CASE(TkindSm1State5, DispatchEReturnsTrue);
    RUN_TEST_CASE(TkindSm1State5, ReleaseEReturnsTrue);
    
    RUN_TEST_CASE(TkindSm1State5, FReturnsTrue);
    RUN_TEST_CASE(TkindSm1State5, FetchFReturnsTrue);
    RUN_TEST_CASE(TkindSm1State5, DispatchFReturnsTrue);
    RUN_TEST_CASE(TkindSm1State5, ReleaseFReturnsTrue);
    
    RUN_TEST_CASE(TkindSm1State5, GReturnsTrue);
    RUN_TEST_CASE(TkindSm1State5, FetchGReturnsTrue);
    RUN_TEST_CASE(TkindSm1State5, DispatchGReturnsTrue);
    RUN_TEST_CASE(TkindSm1State5, ReleaseGReturnsTrue);
    
    RUN_TEST_CASE(TkindSm1State5, HReturnsTrue);
    RUN_TEST_CASE(TkindSm1State5, FetchHReturnsTrue);
    RUN_TEST_CASE(TkindSm1State5, DispatchHReturnsTrue);
    RUN_TEST_CASE(TkindSm1State5, ReleaseHReturnsTrue);
    
    RUN_TEST_CASE(TkindSm1State5, IReturnsTrue);
    RUN_TEST_CASE(TkindSm1State5, FetchIReturnsTrue);
    RUN_TEST_CASE(TkindSm1State5, DispatchIReturnsTrue);
    RUN_TEST_CASE(TkindSm1State5, ReleaseIReturnsTrue);
    
    RUN_TEST_CASE(TkindSm1State5, JReturnsTrue);
    RUN_TEST_CASE(TkindSm1State5, FetchJReturnsTrue);
    RUN_TEST_CASE(TkindSm1State5, DispatchJReturnsTrue);
    RUN_TEST_CASE(TkindSm1State5, ReleaseJReturnsTrue);
    
    RUN_TEST_CASE(TkindSm1State5, KReturnsTrue);
    RUN_TEST_CASE(TkindSm1State5, FetchKReturnsTrue);
    RUN_TEST_CASE(TkindSm1State5, DispatchKReturnsTrue);
    RUN_TEST_CASE(TkindSm1State5, ReleaseKReturnsTrue);
    
    RUN_TEST_CASE(TkindSm1State5, LReturnsTrue);
    RUN_TEST_CASE(TkindSm1State5, FetchLReturnsTrue);
    RUN_TEST_CASE(TkindSm1State5, DispatchLReturnsTrue);
    RUN_TEST_CASE(TkindSm1State5, ReleaseLReturnsTrue);
    
    RUN_TEST_CASE(TkindSm1State5, MReturnsTrue);
    RUN_TEST_CASE(TkindSm1State5, FetchMReturnsTrue);
    RUN_TEST_CASE(TkindSm1State5, DispatchMReturnsTrue);
    RUN_TEST_CASE(TkindSm1State5, ReleaseMReturnsTrue);
    
    RUN_TEST_CASE(TkindSm1State5, NReturnsTrue);
    RUN_TEST_CASE(TkindSm1State5, FetchNReturnsTrue);
    RUN_TEST_CASE(TkindSm1State5, DispatchNReturnsTrue);
    RUN_TEST_CASE(TkindSm1State5, ReleaseNReturnsTrue);
    
    RUN_TEST_CASE(TkindSm1State5, OReturnsTrue);
    RUN_TEST_CASE(TkindSm1State5, FetchOWithFalseChoice1ReturnsTrue);
    RUN_TEST_CASE(TkindSm1State5, DispatchOWithFalseChoice1ReturnsTrue);
    RUN_TEST_CASE(TkindSm1State5, ReleaseOWithFalseChoice1ReturnsTrue);
    RUN_TEST_CASE(TkindSm1State5, FetchOWithTrueChoice1ReturnsTrue);
    RUN_TEST_CASE(TkindSm1State5, DispatchOWithTrueChoice1ReturnsTrue);
    RUN_TEST_CASE(TkindSm1State5, ReleaseOWithTrueChoice1ReturnsTrue);
    
    RUN_TEST_CASE(TkindSm1State5, FetchReturnsFalse);
    RUN_TEST_CASE(TkindSm1State5, DispatchReturnsFalse);
    RUN_TEST_CASE(TkindSm1State5, ReleaseReturnsFalse);
}
