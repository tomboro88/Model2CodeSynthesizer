/*
 * @file TkindSm1State4_test.c
 *
 * @brief Source code of the TkindSm1State4 group test cases.
 * @author tomboro88
 * @date   1 may 2026
 * @copyright (c) 2026 tomboro88. All rights reserved.
 * @license MIT – see LICENSE file in project root
 * @project github.com/tomboro88/M2T4Embedded
 */
#include "Tkind_test.h"

/*******************************************************************************
 *
 * Test group TkindSm1State4.
 *
 ******************************************************************************/
TEST_GROUP(TkindSm1State4);

void tkind_test_enter_State4(void)
{
    tkind_test_init_logger_buffer();
    Tkind_ctest_init(&tkind_ctest_obj, &tkind_test_logger);

    Tkind_ctest_b(&tkind_ctest_obj);
    Tkind_ctest_fetch_event(&tkind_ctest_obj);
    Tkind_ctest_dispatch_event(&tkind_ctest_obj);
    Tkind_ctest_release_event(&tkind_ctest_obj);
}

TEST_SETUP(TkindSm1State4)
{
    tkind_test_init_logger_buffer();
    tkind_test_enter_State4();
    tkind_test_init_logger_buffer();
}

TEST_TEAR_DOWN(TkindSm1State4)
{

}

/*================================TEST_CASES==================================*/
TEST(TkindSm1State4, InitResultsInInitialTransition)
{
    tkind_ctest_logger_expect(true, "Initial1 to State1\n"
                              "Enter State1\n"
                              "Initial3 to State2\n"
                              "Enter State2\n");
    tkind_ctest_logger_given(Tkind_ctest_init(&tkind_ctest_obj, 
                                              &tkind_test_logger));
}


/* --------------------------------- Event A -------------------------------- */
TEST(TkindSm1State4, AReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_a(&tkind_ctest_obj));
}

TEST(TkindSm1State4, FetchAReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_a(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj));
}

TEST(TkindSm1State4, DispatchAReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL); 
    tkind_ctest_logger_given(Tkind_ctest_a(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj)
                       && Tkind_ctest_dispatch_event(&tkind_ctest_obj));
}

TEST(TkindSm1State4, ReleaseAReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_a(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj)
                       && Tkind_ctest_dispatch_event(&tkind_ctest_obj)
                       && Tkind_ctest_release_event(&tkind_ctest_obj));
}


/* --------------------------------- Event B -------------------------------- */
TEST(TkindSm1State4, BReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_b(&tkind_ctest_obj));
}

TEST(TkindSm1State4, FetchBReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_b(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj));
}

TEST(TkindSm1State4, DispatchBReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL); 
    tkind_ctest_logger_given(Tkind_ctest_b(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj)
                       && Tkind_ctest_dispatch_event(&tkind_ctest_obj));
}

TEST(TkindSm1State4, ReleaseBReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_b(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj)
                       && Tkind_ctest_dispatch_event(&tkind_ctest_obj)
                       && Tkind_ctest_release_event(&tkind_ctest_obj));
}


/* --------------------------------- Event C -------------------------------- */
TEST(TkindSm1State4, CReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_c(&tkind_ctest_obj));
}

TEST(TkindSm1State4, FetchCReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_c(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj));
}

TEST(TkindSm1State4, DispatchCReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL); 
    tkind_ctest_logger_given(Tkind_ctest_c(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj)
                       && Tkind_ctest_dispatch_event(&tkind_ctest_obj));
}

TEST(TkindSm1State4, ReleaseCReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_c(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj)
                       && Tkind_ctest_dispatch_event(&tkind_ctest_obj)
                       && Tkind_ctest_release_event(&tkind_ctest_obj));
}


/* --------------------------------- Event D -------------------------------- */
TEST(TkindSm1State4, DReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_d(&tkind_ctest_obj));
}

TEST(TkindSm1State4, FetchDReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_d(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj));
}

TEST(TkindSm1State4, DispatchDReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL); 
    tkind_ctest_logger_given(Tkind_ctest_d(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj)
                       && Tkind_ctest_dispatch_event(&tkind_ctest_obj));
}

TEST(TkindSm1State4, ReleaseDReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_d(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj)
                       && Tkind_ctest_dispatch_event(&tkind_ctest_obj)
                       && Tkind_ctest_release_event(&tkind_ctest_obj));
}


/* --------------------------------- Event E -------------------------------- */
TEST(TkindSm1State4, EReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_e(&tkind_ctest_obj));
}

TEST(TkindSm1State4, FetchEReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_e(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj));
}

TEST(TkindSm1State4, DispatchEReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL); 
    tkind_ctest_logger_given(Tkind_ctest_e(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj)
                       && Tkind_ctest_dispatch_event(&tkind_ctest_obj));
}

TEST(TkindSm1State4, ReleaseEReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_e(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj)
                       && Tkind_ctest_dispatch_event(&tkind_ctest_obj)
                       && Tkind_ctest_release_event(&tkind_ctest_obj));
}


/* --------------------------------- Event F -------------------------------- */
TEST(TkindSm1State4, FReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_f(&tkind_ctest_obj));
}

TEST(TkindSm1State4, FetchFReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_f(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj));
}

TEST(TkindSm1State4, DispatchFReturnsTrue)
{
    tkind_ctest_logger_expect(true, "Exit State4\n"
                                    "State4 to State6\n"
                                    "Enter State4\n"
                                    "Enter State6\n");
    tkind_ctest_logger_given(Tkind_ctest_f(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj)
                       && Tkind_ctest_dispatch_event(&tkind_ctest_obj));
}

TEST(TkindSm1State4, ReleaseFReturnsTrue)
{
    tkind_ctest_logger_expect(true, "Exit State4\n"
                                    "State4 to State6\n"
                                    "Enter State4\n"
                                    "Enter State6\n");
    tkind_ctest_logger_given(Tkind_ctest_f(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj)
                       && Tkind_ctest_dispatch_event(&tkind_ctest_obj)
                       && Tkind_ctest_release_event(&tkind_ctest_obj));
}


/* --------------------------------- Event G -------------------------------- */
TEST(TkindSm1State4, GReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_g(&tkind_ctest_obj));
}

TEST(TkindSm1State4, FetchGReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_g(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj));
}

TEST(TkindSm1State4, DispatchGReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL); 
    tkind_ctest_logger_given(Tkind_ctest_g(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj)
                       && Tkind_ctest_dispatch_event(&tkind_ctest_obj));
}

TEST(TkindSm1State4, ReleaseGReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_g(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj)
                       && Tkind_ctest_dispatch_event(&tkind_ctest_obj)
                       && Tkind_ctest_release_event(&tkind_ctest_obj));
}


/* --------------------------------- Event H -------------------------------- */
TEST(TkindSm1State4, HReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_h(&tkind_ctest_obj));
}

TEST(TkindSm1State4, FetchHReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_h(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj));
}

TEST(TkindSm1State4, DispatchHReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL); 
    tkind_ctest_logger_given(Tkind_ctest_h(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj)
                       && Tkind_ctest_dispatch_event(&tkind_ctest_obj));
}

TEST(TkindSm1State4, ReleaseHReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_h(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj)
                       && Tkind_ctest_dispatch_event(&tkind_ctest_obj)
                       && Tkind_ctest_release_event(&tkind_ctest_obj));
}


/* --------------------------------- Event I -------------------------------- */
TEST(TkindSm1State4, IReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_i(&tkind_ctest_obj));
}

TEST(TkindSm1State4, FetchIReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_i(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj));
}

TEST(TkindSm1State4, DispatchIReturnsTrue)
{
    tkind_ctest_logger_expect(true, "Exit State4\n"
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

TEST(TkindSm1State4, ReleaseIReturnsTrue)
{
    tkind_ctest_logger_expect(true, "Exit State4\n"
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
TEST(TkindSm1State4, JReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_j(&tkind_ctest_obj));
}

TEST(TkindSm1State4, FetchJReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_j(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj));
}

TEST(TkindSm1State4, DispatchJReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL); 
    tkind_ctest_logger_given(Tkind_ctest_j(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj)
                       && Tkind_ctest_dispatch_event(&tkind_ctest_obj));
}

TEST(TkindSm1State4, ReleaseJReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_j(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj)
                       && Tkind_ctest_dispatch_event(&tkind_ctest_obj)
                       && Tkind_ctest_release_event(&tkind_ctest_obj));
}


/* --------------------------------- Event K -------------------------------- */
TEST(TkindSm1State4, KReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_k(&tkind_ctest_obj));
}

TEST(TkindSm1State4, FetchKReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_k(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj));
}

TEST(TkindSm1State4, DispatchKReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL); 
    tkind_ctest_logger_given(Tkind_ctest_k(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj)
                       && Tkind_ctest_dispatch_event(&tkind_ctest_obj));
}

TEST(TkindSm1State4, ReleaseKReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_k(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj)
                       && Tkind_ctest_dispatch_event(&tkind_ctest_obj)
                       && Tkind_ctest_release_event(&tkind_ctest_obj));
}


/* --------------------------------- Event L -------------------------------- */
TEST(TkindSm1State4, LReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_l(&tkind_ctest_obj));
}

TEST(TkindSm1State4, FetchLReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_l(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj));
}

TEST(TkindSm1State4, DispatchLReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL); 
    tkind_ctest_logger_given(Tkind_ctest_l(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj)
                       && Tkind_ctest_dispatch_event(&tkind_ctest_obj));
}

TEST(TkindSm1State4, ReleaseLReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_l(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj)
                       && Tkind_ctest_dispatch_event(&tkind_ctest_obj)
                       && Tkind_ctest_release_event(&tkind_ctest_obj));
}


/* --------------------------------- Event M -------------------------------- */
TEST(TkindSm1State4, MReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_m(&tkind_ctest_obj));
}

TEST(TkindSm1State4, FetchMReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_m(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj));
}

TEST(TkindSm1State4, DispatchMReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL); 
    tkind_ctest_logger_given(Tkind_ctest_m(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj)
                       && Tkind_ctest_dispatch_event(&tkind_ctest_obj));
}

TEST(TkindSm1State4, ReleaseMReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_m(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj)
                       && Tkind_ctest_dispatch_event(&tkind_ctest_obj)
                       && Tkind_ctest_release_event(&tkind_ctest_obj));
}


/* --------------------------------- Event N -------------------------------- */
TEST(TkindSm1State4, NReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_n(&tkind_ctest_obj));
}

TEST(TkindSm1State4, FetchNReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_n(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj));
}

TEST(TkindSm1State4, DispatchNReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL); 
    tkind_ctest_logger_given(Tkind_ctest_n(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj)
                       && Tkind_ctest_dispatch_event(&tkind_ctest_obj));
}

TEST(TkindSm1State4, ReleaseNReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_n(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj)
                       && Tkind_ctest_dispatch_event(&tkind_ctest_obj)
                       && Tkind_ctest_release_event(&tkind_ctest_obj));
}


/* --------------------------------- Event O -------------------------------- */
TEST(TkindSm1State4, OReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_o(&tkind_ctest_obj));
}

TEST(TkindSm1State4, FetchOWithFalseChoice1ReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_obj.sm1.b_test_condition = false;
    tkind_ctest_logger_given(Tkind_ctest_o(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj));
}

TEST(TkindSm1State4, DispatchOWithFalseChoice1ReturnsTrue)
{
    tkind_ctest_logger_expect(true, "Exit State4\n"
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

TEST(TkindSm1State4, ReleaseOWithFalseChoice1ReturnsTrue)
{
    tkind_ctest_logger_expect(true, "Exit State4\n"
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

TEST(TkindSm1State4, FetchOWithTrueChoice1ReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_obj.sm1.b_test_condition = true;
    tkind_ctest_logger_given(Tkind_ctest_o(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj));
}

TEST(TkindSm1State4, DispatchOWithTrueChoice1ReturnsTrue)
{
    tkind_ctest_logger_expect(true, "Exit State4\n"
                                    "Exit State1\n"
                                    "State1 to Choice1\n"
                                    "Enter State1\n"
                                    "Choice1 to State8\n"
                                    "Enter State8\n"
                                    "Enter State9\n"
                                    "Initial3 to State2\n"
                                    "Enter State2\n");
    tkind_ctest_obj.sm1.b_test_condition = true;
    tkind_ctest_logger_given(Tkind_ctest_o(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj)
                       && Tkind_ctest_dispatch_event(&tkind_ctest_obj));
}

TEST(TkindSm1State4, ReleaseOWithTrueChoice1ReturnsTrue)
{
    tkind_ctest_logger_expect(true, "Exit State4\n"
                                    "Exit State1\n"
                                    "State1 to Choice1\n"
                                    "Enter State1\n"
                                    "Choice1 to State8\n"
                                    "Enter State8\n"
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
TEST(TkindSm1State4, FetchReturnsFalse)
{
    tkind_ctest_logger_expect(false, NULL);
    tkind_ctest_logger_given(Tkind_ctest_fetch_event(&tkind_ctest_obj));
}

TEST(TkindSm1State4, DispatchReturnsFalse)
{
    tkind_ctest_logger_expect(false, NULL);
    tkind_ctest_logger_given(Tkind_ctest_dispatch_event(&tkind_ctest_obj));
}

TEST(TkindSm1State4, ReleaseReturnsFalse)
{
    tkind_ctest_logger_expect(false, NULL);
    tkind_ctest_logger_given(Tkind_ctest_release_event(&tkind_ctest_obj));
}

/*==============================TEST_GROUP_RUNNER=============================*/

TEST_GROUP_RUNNER(TkindSm1State4)
{
    RUN_TEST_CASE(TkindSm1State4, InitResultsInInitialTransition);

    RUN_TEST_CASE(TkindSm1State4, AReturnsTrue);
    RUN_TEST_CASE(TkindSm1State4, FetchAReturnsTrue);
    RUN_TEST_CASE(TkindSm1State4, DispatchAReturnsTrue);
    RUN_TEST_CASE(TkindSm1State4, ReleaseAReturnsTrue);

    RUN_TEST_CASE(TkindSm1State4, BReturnsTrue);
    RUN_TEST_CASE(TkindSm1State4, FetchBReturnsTrue);
    RUN_TEST_CASE(TkindSm1State4, DispatchBReturnsTrue);
    RUN_TEST_CASE(TkindSm1State4, ReleaseBReturnsTrue);

    RUN_TEST_CASE(TkindSm1State4, CReturnsTrue);
    RUN_TEST_CASE(TkindSm1State4, FetchCReturnsTrue);
    RUN_TEST_CASE(TkindSm1State4, DispatchCReturnsTrue);
    RUN_TEST_CASE(TkindSm1State4, ReleaseCReturnsTrue);

    RUN_TEST_CASE(TkindSm1State4, DReturnsTrue);
    RUN_TEST_CASE(TkindSm1State4, FetchDReturnsTrue);
    RUN_TEST_CASE(TkindSm1State4, DispatchDReturnsTrue);
    RUN_TEST_CASE(TkindSm1State4, ReleaseDReturnsTrue);

    RUN_TEST_CASE(TkindSm1State4, EReturnsTrue);
    RUN_TEST_CASE(TkindSm1State4, FetchEReturnsTrue);
    RUN_TEST_CASE(TkindSm1State4, DispatchEReturnsTrue);
    RUN_TEST_CASE(TkindSm1State4, ReleaseEReturnsTrue);

    RUN_TEST_CASE(TkindSm1State4, FReturnsTrue);
    RUN_TEST_CASE(TkindSm1State4, FetchFReturnsTrue);
    RUN_TEST_CASE(TkindSm1State4, DispatchFReturnsTrue);
    RUN_TEST_CASE(TkindSm1State4, ReleaseFReturnsTrue);

    RUN_TEST_CASE(TkindSm1State4, GReturnsTrue);
    RUN_TEST_CASE(TkindSm1State4, FetchGReturnsTrue);
    RUN_TEST_CASE(TkindSm1State4, DispatchGReturnsTrue);
    RUN_TEST_CASE(TkindSm1State4, ReleaseGReturnsTrue);

    RUN_TEST_CASE(TkindSm1State4, HReturnsTrue);
    RUN_TEST_CASE(TkindSm1State4, FetchHReturnsTrue);
    RUN_TEST_CASE(TkindSm1State4, DispatchHReturnsTrue);
    RUN_TEST_CASE(TkindSm1State4, ReleaseHReturnsTrue);

    RUN_TEST_CASE(TkindSm1State4, IReturnsTrue);
    RUN_TEST_CASE(TkindSm1State4, FetchIReturnsTrue);
    RUN_TEST_CASE(TkindSm1State4, DispatchIReturnsTrue);
    RUN_TEST_CASE(TkindSm1State4, ReleaseIReturnsTrue);

    RUN_TEST_CASE(TkindSm1State4, JReturnsTrue);
    RUN_TEST_CASE(TkindSm1State4, FetchJReturnsTrue);
    RUN_TEST_CASE(TkindSm1State4, DispatchJReturnsTrue);
    RUN_TEST_CASE(TkindSm1State4, ReleaseJReturnsTrue);

    RUN_TEST_CASE(TkindSm1State4, KReturnsTrue);
    RUN_TEST_CASE(TkindSm1State4, FetchKReturnsTrue);
    RUN_TEST_CASE(TkindSm1State4, DispatchKReturnsTrue);
    RUN_TEST_CASE(TkindSm1State4, ReleaseKReturnsTrue);

    RUN_TEST_CASE(TkindSm1State4, LReturnsTrue);
    RUN_TEST_CASE(TkindSm1State4, FetchLReturnsTrue);
    RUN_TEST_CASE(TkindSm1State4, DispatchLReturnsTrue);
    RUN_TEST_CASE(TkindSm1State4, ReleaseLReturnsTrue);

    RUN_TEST_CASE(TkindSm1State4, MReturnsTrue);
    RUN_TEST_CASE(TkindSm1State4, FetchMReturnsTrue);
    RUN_TEST_CASE(TkindSm1State4, DispatchMReturnsTrue);
    RUN_TEST_CASE(TkindSm1State4, ReleaseMReturnsTrue);

    RUN_TEST_CASE(TkindSm1State4, NReturnsTrue);
    RUN_TEST_CASE(TkindSm1State4, FetchNReturnsTrue);
    RUN_TEST_CASE(TkindSm1State4, DispatchNReturnsTrue);
    RUN_TEST_CASE(TkindSm1State4, ReleaseNReturnsTrue);

    RUN_TEST_CASE(TkindSm1State4, OReturnsTrue);
    RUN_TEST_CASE(TkindSm1State4, FetchOWithFalseChoice1ReturnsTrue);
    RUN_TEST_CASE(TkindSm1State4, DispatchOWithFalseChoice1ReturnsTrue);
    RUN_TEST_CASE(TkindSm1State4, ReleaseOWithFalseChoice1ReturnsTrue);
    RUN_TEST_CASE(TkindSm1State4, FetchOWithTrueChoice1ReturnsTrue);
    RUN_TEST_CASE(TkindSm1State4, DispatchOWithTrueChoice1ReturnsTrue);
    RUN_TEST_CASE(TkindSm1State4, ReleaseOWithTrueChoice1ReturnsTrue);

    RUN_TEST_CASE(TkindSm1State4, FetchReturnsFalse);
    RUN_TEST_CASE(TkindSm1State4, DispatchReturnsFalse);
    RUN_TEST_CASE(TkindSm1State4, ReleaseReturnsFalse);
}
