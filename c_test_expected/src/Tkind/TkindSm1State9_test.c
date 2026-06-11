/*
 * @file TkindSm1State9_test.c
 *
 * @brief Source code of the TkindSm1State9 group test cases.
 * @author tomboro88
 * @date   13 may 2026
 * @copyright (c) 2026 tomboro88. All rights reserved.
 * @license MIT – see LICENSE file in project root
 * @project github.com/tomboro88/M2T4Embedded
 */
#include "Tkind_test.h"

/*******************************************************************************
 *
 * Test group TkindSm1State9.
 *
 ******************************************************************************/
TEST_GROUP(TkindSm1State9);

void tkind_test_enter_state9(void)
{
    tkind_test_enter_state7();

    Tkind_ctest_j(&tkind_ctest_obj);
    Tkind_ctest_fetch_event(&tkind_ctest_obj);
    Tkind_ctest_dispatch_event(&tkind_ctest_obj);
    Tkind_ctest_release_event(&tkind_ctest_obj);
}

TEST_SETUP(TkindSm1State9)
{
    tkind_test_init_logger_buffer();
    tkind_test_enter_state9();
    tkind_test_init_logger_buffer();
}

TEST_TEAR_DOWN(TkindSm1State9)
{

}

/*================================TEST_CASES==================================*/
TEST(TkindSm1State9, InitResultsInInitialTransition)
{
    tkind_ctest_logger_expect(true, "Initial1 to State1\n"
                              "Enter State1\n"
                              "Initial3 to State2\n"
                              "Enter State2\n");
    tkind_ctest_logger_given(Tkind_ctest_init(&tkind_ctest_obj, 
                                              &tkind_test_logger));
}

/* --------------------------------- Event A -------------------------------- */
TEST(TkindSm1State9, AReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_a(&tkind_ctest_obj));
}

TEST(TkindSm1State9, FetchAReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_a(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj));
}

TEST(TkindSm1State9, DispatchAReturnsTrue)
{
    tkind_ctest_logger_expect(true, "Exit State2\n"
                                    "State2 to State3\n"
                                    "Enter State3\n");
    tkind_ctest_logger_given(Tkind_ctest_a(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj)
                       && Tkind_ctest_dispatch_event(&tkind_ctest_obj));
}

TEST(TkindSm1State9, ReleaseAReturnsTrue)
{
    tkind_ctest_logger_expect(true, "Exit State2\n"
                                    "State2 to State3\n"
                                    "Enter State3\n");
    tkind_ctest_logger_given(Tkind_ctest_a(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj)
                       && Tkind_ctest_dispatch_event(&tkind_ctest_obj)
                       && Tkind_ctest_release_event(&tkind_ctest_obj));
}

/* --------------------------------- Event B -------------------------------- */
TEST(TkindSm1State9, BReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_b(&tkind_ctest_obj));
}

TEST(TkindSm1State9, FetchBReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_b(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj));
}

TEST(TkindSm1State9, DispatchBReturnsTrue)
{
    tkind_ctest_logger_expect(true, "Exit State2\n"
                                    "State2 to State4\n"
                                    "Enter State4\n");
    tkind_ctest_logger_given(Tkind_ctest_b(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj)
                       && Tkind_ctest_dispatch_event(&tkind_ctest_obj));
}

TEST(TkindSm1State9, ReleaseBReturnsTrue)
{
    tkind_ctest_logger_expect(true, "Exit State2\n"
                                    "State2 to State4\n"
                                    "Enter State4\n");
    tkind_ctest_logger_given(Tkind_ctest_b(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj)
                       && Tkind_ctest_dispatch_event(&tkind_ctest_obj)
                       && Tkind_ctest_release_event(&tkind_ctest_obj));
}

/* --------------------------------- Event C -------------------------------- */
TEST(TkindSm1State9, CReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_c(&tkind_ctest_obj));
}

TEST(TkindSm1State9, FetchCReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_c(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj));
}

TEST(TkindSm1State9, DispatchCReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_c(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj)
                       && Tkind_ctest_dispatch_event(&tkind_ctest_obj));
}

TEST(TkindSm1State9, ReleaseCReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_c(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj)
                       && Tkind_ctest_dispatch_event(&tkind_ctest_obj)
                       && Tkind_ctest_release_event(&tkind_ctest_obj));
}

/* --------------------------------- Event D -------------------------------- */
TEST(TkindSm1State9, DReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_d(&tkind_ctest_obj));
}

TEST(TkindSm1State9, FetchDReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_d(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj));
}

TEST(TkindSm1State9, DispatchDReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_d(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj)
                       && Tkind_ctest_dispatch_event(&tkind_ctest_obj));
}

TEST(TkindSm1State9, ReleaseDReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_d(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj)
                       && Tkind_ctest_dispatch_event(&tkind_ctest_obj)
                       && Tkind_ctest_release_event(&tkind_ctest_obj));
}

/* --------------------------------- Event E -------------------------------- */
TEST(TkindSm1State9, EReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_e(&tkind_ctest_obj));
}

TEST(TkindSm1State9, FetchEReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_e(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj));
}

TEST(TkindSm1State9, DispatchEReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_e(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj)
                       && Tkind_ctest_dispatch_event(&tkind_ctest_obj));
}

TEST(TkindSm1State9, ReleaseEReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_e(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj)
                       && Tkind_ctest_dispatch_event(&tkind_ctest_obj)
                       && Tkind_ctest_release_event(&tkind_ctest_obj));
}

/* --------------------------------- Event F -------------------------------- */
TEST(TkindSm1State9, FReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_f(&tkind_ctest_obj));
}

TEST(TkindSm1State9, FetchFReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_f(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj));
}

TEST(TkindSm1State9, DispatchFReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_f(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj)
                       && Tkind_ctest_dispatch_event(&tkind_ctest_obj));
}

TEST(TkindSm1State9, ReleaseFReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_f(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj)
                       && Tkind_ctest_dispatch_event(&tkind_ctest_obj)
                       && Tkind_ctest_release_event(&tkind_ctest_obj));
}

/* --------------------------------- Event G -------------------------------- */
TEST(TkindSm1State9, GReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_g(&tkind_ctest_obj));
}

TEST(TkindSm1State9, FetchGReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_g(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj));
}

TEST(TkindSm1State9, DispatchGReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_g(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj)
                       && Tkind_ctest_dispatch_event(&tkind_ctest_obj));
}

TEST(TkindSm1State9, ReleaseGReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_g(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj)
                       && Tkind_ctest_dispatch_event(&tkind_ctest_obj)
                       && Tkind_ctest_release_event(&tkind_ctest_obj));
}

/* --------------------------------- Event H -------------------------------- */
TEST(TkindSm1State9, HReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_h(&tkind_ctest_obj));
}

TEST(TkindSm1State9, FetchHReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_h(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj));
}

TEST(TkindSm1State9, DispatchHReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_h(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj)
                       && Tkind_ctest_dispatch_event(&tkind_ctest_obj));
}

TEST(TkindSm1State9, ReleaseHReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_h(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj)
                       && Tkind_ctest_dispatch_event(&tkind_ctest_obj)
                       && Tkind_ctest_release_event(&tkind_ctest_obj));
}

/* --------------------------------- Event I -------------------------------- */
TEST(TkindSm1State9, IReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_i(&tkind_ctest_obj));
}

TEST(TkindSm1State9, FetchIReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_i(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj));
}

TEST(TkindSm1State9, DispatchIReturnsTrue)
{
    tkind_ctest_logger_expect(true, "Exit State2\n"
                                    "Exit State9\n"
                                    "Exit State8\n"
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

TEST(TkindSm1State9, ReleaseIReturnsTrue)
{
    tkind_ctest_logger_expect(true, "Exit State2\n"
                                    "Exit State9\n"
                                    "Exit State8\n"
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
TEST(TkindSm1State9, JReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_j(&tkind_ctest_obj));
}

TEST(TkindSm1State9, FetchJReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_j(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj));
}

TEST(TkindSm1State9, DispatchJReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_j(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj)
                       && Tkind_ctest_dispatch_event(&tkind_ctest_obj));
}

TEST(TkindSm1State9, ReleaseJReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_j(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj)
                       && Tkind_ctest_dispatch_event(&tkind_ctest_obj)
                       && Tkind_ctest_release_event(&tkind_ctest_obj));
}

/* --------------------------------- Event K -------------------------------- */
TEST(TkindSm1State9, KReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_k(&tkind_ctest_obj));
}

TEST(TkindSm1State9, FetchKReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_k(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj));
}

TEST(TkindSm1State9, DispatchKReturnsTrue)
{
    tkind_ctest_logger_expect(true, "Exit State9\n"
                                    "Exit State8\n"
                                    "State9 to State8\n"
                                    "Enter State8\n"
                                    "Initial4 to State9\n"
                                    "Enter State9\n");
    tkind_ctest_logger_given(Tkind_ctest_k(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj)
                       && Tkind_ctest_dispatch_event(&tkind_ctest_obj));
}

TEST(TkindSm1State9, ReleaseKReturnsTrue)
{
    tkind_ctest_logger_expect(true, "Exit State9\n"
                                    "Exit State8\n"
                                    "State9 to State8\n"
                                    "Enter State8\n"
                                    "Initial4 to State9\n"
                                    "Enter State9\n");
    tkind_ctest_logger_given(Tkind_ctest_k(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj)
                       && Tkind_ctest_dispatch_event(&tkind_ctest_obj)
                       && Tkind_ctest_release_event(&tkind_ctest_obj));
}

/* --------------------------------- Event L -------------------------------- */
TEST(TkindSm1State9, LReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_l(&tkind_ctest_obj));
}

TEST(TkindSm1State9, FetchLReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_l(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj));
}

TEST(TkindSm1State9, DispatchLReturnsTrue)
{
    tkind_ctest_logger_expect(true, "Exit State2\n"
                                    "Exit State9\n"
                                    "Exit State8\n"
                                    "Exit State1\n"
                                    "State9 to State1\n"
                                    "Enter State1\n"
                                    "Initial3 to State2\n"
                                    "Enter State2\n");
    tkind_ctest_logger_given(Tkind_ctest_l(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj)
                       && Tkind_ctest_dispatch_event(&tkind_ctest_obj));
}

TEST(TkindSm1State9, ReleaseLReturnsTrue)
{
    tkind_ctest_logger_expect(true, "Exit State2\n"
                                    "Exit State9\n"
                                    "Exit State8\n"
                                    "Exit State1\n"
                                    "State9 to State1\n"
                                    "Enter State1\n"
                                    "Initial3 to State2\n"
                                    "Enter State2\n");
    tkind_ctest_logger_given(Tkind_ctest_l(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj)
                       && Tkind_ctest_dispatch_event(&tkind_ctest_obj)
                       && Tkind_ctest_release_event(&tkind_ctest_obj));
}

/* --------------------------------- Event M -------------------------------- */
TEST(TkindSm1State9, MReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_m(&tkind_ctest_obj));
}

TEST(TkindSm1State9, FetchMReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_m(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj));
}

TEST(TkindSm1State9, DispatchMReturnsTrue)
{
    tkind_ctest_logger_expect(true, "Exit State2\n"
                                    "Exit State9\n"
                                    "Exit State8\n"
                                    "Exit State1\n"
                                    "State8 to State1\n"
                                    "Enter State1\n"
                                    "Initial3 to State2\n"
                                    "Enter State2\n");
    tkind_ctest_logger_given(Tkind_ctest_m(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj)
                       && Tkind_ctest_dispatch_event(&tkind_ctest_obj));
}

TEST(TkindSm1State9, ReleaseMReturnsTrue)
{
    tkind_ctest_logger_expect(true, "Exit State2\n"
                                    "Exit State9\n"
                                    "Exit State8\n"
                                    "Exit State1\n"
                                    "State8 to State1\n"
                                    "Enter State1\n"
                                    "Initial3 to State2\n"
                                    "Enter State2\n");
    tkind_ctest_logger_given(Tkind_ctest_m(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj)
                       && Tkind_ctest_dispatch_event(&tkind_ctest_obj)
                       && Tkind_ctest_release_event(&tkind_ctest_obj));
}

/* --------------------------------- Event N -------------------------------- */
TEST(TkindSm1State9, NReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_n(&tkind_ctest_obj));
}

TEST(TkindSm1State9, FetchNReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_n(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj));
}

TEST(TkindSm1State9, DispatchNReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_n(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj)
                       && Tkind_ctest_dispatch_event(&tkind_ctest_obj));
}

TEST(TkindSm1State9, ReleaseNReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_n(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj)
                       && Tkind_ctest_dispatch_event(&tkind_ctest_obj)
                       && Tkind_ctest_release_event(&tkind_ctest_obj));
}

/* --------------------------------- Event O -------------------------------- */
TEST(TkindSm1State9, OReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_o(&tkind_ctest_obj));
}

TEST(TkindSm1State9, FetchOWithFalseChoice1ReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_obj.sm1.b_test_condition = false;
    tkind_ctest_logger_given(Tkind_ctest_o(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj));
}

TEST(TkindSm1State9, DispatchOWithFalseChoice1ReturnsTrue)
{
    tkind_ctest_logger_expect(true, "Exit State2\n"
                                    "Exit State9\n"
                                    "Exit State8\n"
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

TEST(TkindSm1State9, ReleaseOWithFalseChoice1ReturnsTrue)
{
    tkind_ctest_logger_expect(true, "Exit State2\n"
                                    "Exit State9\n"
                                    "Exit State8\n"
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

TEST(TkindSm1State9, FetchOWithTrueChoice1ReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_obj.sm1.b_test_condition = true;
    tkind_ctest_logger_given(Tkind_ctest_o(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj));
}

TEST(TkindSm1State9, DispatchOWithTrueChoice1ReturnsTrue)
{
    tkind_ctest_logger_expect(true, "Exit State2\n"
                                    "Exit State9\n"
                                    "Exit State8\n"
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

TEST(TkindSm1State9, ReleaseOWithTrueChoice1ReturnsTrue)
{
    tkind_ctest_logger_expect(true, "Exit State2\n"
                                    "Exit State9\n"
                                    "Exit State8\n"
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
TEST(TkindSm1State9, FetchReturnsFalse)
{
    tkind_ctest_logger_expect(false, NULL);
    tkind_ctest_logger_given(Tkind_ctest_fetch_event(&tkind_ctest_obj));
}

TEST(TkindSm1State9, DispatchReturnsFalse)
{
    tkind_ctest_logger_expect(false, NULL);
    tkind_ctest_logger_given(Tkind_ctest_dispatch_event(&tkind_ctest_obj));
}

TEST(TkindSm1State9, ReleaseReturnsFalse)
{
    tkind_ctest_logger_expect(false, NULL);
    tkind_ctest_logger_given(Tkind_ctest_release_event(&tkind_ctest_obj));
}

/*==============================TEST_GROUP_RUNNER=============================*/

TEST_GROUP_RUNNER(TkindSm1State9)
{
    RUN_TEST_CASE(TkindSm1State9, InitResultsInInitialTransition);

    RUN_TEST_CASE(TkindSm1State9, AReturnsTrue);
    RUN_TEST_CASE(TkindSm1State9, FetchAReturnsTrue);
    RUN_TEST_CASE(TkindSm1State9, DispatchAReturnsTrue);
    RUN_TEST_CASE(TkindSm1State9, ReleaseAReturnsTrue);
    
    RUN_TEST_CASE(TkindSm1State9, BReturnsTrue);
    RUN_TEST_CASE(TkindSm1State9, FetchBReturnsTrue);
    RUN_TEST_CASE(TkindSm1State9, DispatchBReturnsTrue);
    RUN_TEST_CASE(TkindSm1State9, ReleaseBReturnsTrue);
    
    RUN_TEST_CASE(TkindSm1State9, CReturnsTrue);
    RUN_TEST_CASE(TkindSm1State9, FetchCReturnsTrue);
    RUN_TEST_CASE(TkindSm1State9, DispatchCReturnsTrue);
    RUN_TEST_CASE(TkindSm1State9, ReleaseCReturnsTrue);
    
    RUN_TEST_CASE(TkindSm1State9, DReturnsTrue);
    RUN_TEST_CASE(TkindSm1State9, FetchDReturnsTrue);
    RUN_TEST_CASE(TkindSm1State9, DispatchDReturnsTrue);
    RUN_TEST_CASE(TkindSm1State9, ReleaseDReturnsTrue);
    
    RUN_TEST_CASE(TkindSm1State9, EReturnsTrue);
    RUN_TEST_CASE(TkindSm1State9, FetchEReturnsTrue);
    RUN_TEST_CASE(TkindSm1State9, DispatchEReturnsTrue);
    RUN_TEST_CASE(TkindSm1State9, ReleaseEReturnsTrue);
    
    RUN_TEST_CASE(TkindSm1State9, FReturnsTrue);
    RUN_TEST_CASE(TkindSm1State9, FetchFReturnsTrue);
    RUN_TEST_CASE(TkindSm1State9, DispatchFReturnsTrue);
    RUN_TEST_CASE(TkindSm1State9, ReleaseFReturnsTrue);
    
    RUN_TEST_CASE(TkindSm1State9, GReturnsTrue);
    RUN_TEST_CASE(TkindSm1State9, FetchGReturnsTrue);
    RUN_TEST_CASE(TkindSm1State9, DispatchGReturnsTrue);
    RUN_TEST_CASE(TkindSm1State9, ReleaseGReturnsTrue);
    
    RUN_TEST_CASE(TkindSm1State9, HReturnsTrue);
    RUN_TEST_CASE(TkindSm1State9, FetchHReturnsTrue);
    RUN_TEST_CASE(TkindSm1State9, DispatchHReturnsTrue);
    RUN_TEST_CASE(TkindSm1State9, ReleaseHReturnsTrue);
    
    RUN_TEST_CASE(TkindSm1State9, IReturnsTrue);
    RUN_TEST_CASE(TkindSm1State9, FetchIReturnsTrue);
    RUN_TEST_CASE(TkindSm1State9, DispatchIReturnsTrue);
    RUN_TEST_CASE(TkindSm1State9, ReleaseIReturnsTrue);
    
    RUN_TEST_CASE(TkindSm1State9, JReturnsTrue);
    RUN_TEST_CASE(TkindSm1State9, FetchJReturnsTrue);
    RUN_TEST_CASE(TkindSm1State9, DispatchJReturnsTrue);
    RUN_TEST_CASE(TkindSm1State9, ReleaseJReturnsTrue);
    
    RUN_TEST_CASE(TkindSm1State9, KReturnsTrue);
    RUN_TEST_CASE(TkindSm1State9, FetchKReturnsTrue);
    RUN_TEST_CASE(TkindSm1State9, DispatchKReturnsTrue);
    RUN_TEST_CASE(TkindSm1State9, ReleaseKReturnsTrue);
    
    RUN_TEST_CASE(TkindSm1State9, LReturnsTrue);
    RUN_TEST_CASE(TkindSm1State9, FetchLReturnsTrue);
    RUN_TEST_CASE(TkindSm1State9, DispatchLReturnsTrue);
    RUN_TEST_CASE(TkindSm1State9, ReleaseLReturnsTrue);
    
    RUN_TEST_CASE(TkindSm1State9, MReturnsTrue);
    RUN_TEST_CASE(TkindSm1State9, FetchMReturnsTrue);
    RUN_TEST_CASE(TkindSm1State9, DispatchMReturnsTrue);
    RUN_TEST_CASE(TkindSm1State9, ReleaseMReturnsTrue);
    
    RUN_TEST_CASE(TkindSm1State9, NReturnsTrue);
    RUN_TEST_CASE(TkindSm1State9, FetchNReturnsTrue);
    RUN_TEST_CASE(TkindSm1State9, DispatchNReturnsTrue);
    RUN_TEST_CASE(TkindSm1State9, ReleaseNReturnsTrue);
    
    RUN_TEST_CASE(TkindSm1State9, OReturnsTrue);
    RUN_TEST_CASE(TkindSm1State9, FetchOWithFalseChoice1ReturnsTrue);
    RUN_TEST_CASE(TkindSm1State9, DispatchOWithFalseChoice1ReturnsTrue);
    RUN_TEST_CASE(TkindSm1State9, ReleaseOWithFalseChoice1ReturnsTrue);
    RUN_TEST_CASE(TkindSm1State9, FetchOWithTrueChoice1ReturnsTrue);
    RUN_TEST_CASE(TkindSm1State9, DispatchOWithTrueChoice1ReturnsTrue);
    RUN_TEST_CASE(TkindSm1State9, ReleaseOWithTrueChoice1ReturnsTrue);
    
    RUN_TEST_CASE(TkindSm1State9, FetchReturnsFalse);
    RUN_TEST_CASE(TkindSm1State9, DispatchReturnsFalse);
    RUN_TEST_CASE(TkindSm1State9, ReleaseReturnsFalse);
}
