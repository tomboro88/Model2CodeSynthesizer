/*
 * @file TkindSm1State2_test.c
 *
 * @brief Source code of the TkindSm1State2 group test cases.
 * @author tomboro88
 * @date   1 may 2026
 * @copyright (c) 2026 tomboro88. All rights reserved.
 * @license MIT – see LICENSE file in project root
 * @project github.com/tomboro88/M2T4Embedded
 */
#include "Tkind_test.h"


/*******************************************************************************
 *
 * Test group TkindSm1State3.
 *
 ******************************************************************************/
void tkind_test_enter_state3(void)
{
    tkind_test_init_logger_buffer();
    Tkind_ctest_init(&tkind_ctest_obj, &tkind_test_logger);

    Tkind_ctest_a(&tkind_ctest_obj);
    Tkind_ctest_fetch_event(&tkind_ctest_obj);
    Tkind_ctest_dispatch_event(&tkind_ctest_obj);
    Tkind_ctest_release_event(&tkind_ctest_obj);
}

TEST_GROUP(TkindSm1State3);

TEST_SETUP(TkindSm1State3)
{
    tkind_test_enter_state3();
    tkind_test_init_logger_buffer();
}

TEST_TEAR_DOWN(TkindSm1State3)
{

}

/*================================TEST_CASES==================================*/
TEST(TkindSm1State3, InitResultsInInitialTransition)
{
    tkind_ctest_logger_expect(true, "Initial1 to State1\n"
                              "Enter State1\n"
                              "Initial3 to State2\n"
                              "Enter State2\n");
    tkind_ctest_logger_given(Tkind_ctest_init(&tkind_ctest_obj, &tkind_test_logger));
}

TEST(TkindSm1State3, AReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_a(&tkind_ctest_obj));
}

TEST(TkindSm1State3, FetchAReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_a(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj));
}

TEST(TkindSm1State3, DispatchAReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_a(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj)
                       && Tkind_ctest_dispatch_event(&tkind_ctest_obj));
}

TEST(TkindSm1State3, ReleaseAReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_a(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj)
                       && Tkind_ctest_dispatch_event(&tkind_ctest_obj)
                       && Tkind_ctest_release_event(&tkind_ctest_obj));
}

TEST(TkindSm1State3, BReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_b(&tkind_ctest_obj));
}

TEST(TkindSm1State3, FetchBReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_b(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj));
}

TEST(TkindSm1State3, DispatchBReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_b(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj)
                       && Tkind_ctest_dispatch_event(&tkind_ctest_obj));
}

TEST(TkindSm1State3, ReleaseBReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_b(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj)
                       && Tkind_ctest_dispatch_event(&tkind_ctest_obj)
                       && Tkind_ctest_release_event(&tkind_ctest_obj));
}

TEST(TkindSm1State3, CReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_c(&tkind_ctest_obj));
}

TEST(TkindSm1State3, FetchCReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_c(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj));
}

TEST(TkindSm1State3, DispatchCReturnsTrue)
{
    tkind_ctest_logger_expect(true, "State3 to State5\n"
                              "Enter State5\n");
    tkind_ctest_logger_given(Tkind_ctest_c(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj)
                       && Tkind_ctest_dispatch_event(&tkind_ctest_obj));
}

TEST(TkindSm1State3, ReleaseCReturnsTrue)
{
    tkind_ctest_logger_expect(true, "State3 to State5\n"
                              "Enter State5\n");
    tkind_ctest_logger_given(Tkind_ctest_c(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj)
                       && Tkind_ctest_dispatch_event(&tkind_ctest_obj)
                       && Tkind_ctest_release_event(&tkind_ctest_obj));
}

TEST(TkindSm1State3, DReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_d(&tkind_ctest_obj));
}

TEST(TkindSm1State3, FetchDReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_d(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj));
}

TEST(TkindSm1State3, DispatchDReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_d(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj)
                       && Tkind_ctest_dispatch_event(&tkind_ctest_obj));
}

TEST(TkindSm1State3, ReleaseDReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_d(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj)
                       && Tkind_ctest_dispatch_event(&tkind_ctest_obj)
                       && Tkind_ctest_release_event(&tkind_ctest_obj));
}

TEST(TkindSm1State3, EReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_e(&tkind_ctest_obj));
}

TEST(TkindSm1State3, FetchEReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_e(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj));
}

TEST(TkindSm1State3, DispatchEReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_e(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj)
                       && Tkind_ctest_dispatch_event(&tkind_ctest_obj));
}

TEST(TkindSm1State3, ReleaseEReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_e(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj)
                       && Tkind_ctest_dispatch_event(&tkind_ctest_obj)
                       && Tkind_ctest_release_event(&tkind_ctest_obj));
}

TEST(TkindSm1State3, FReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_f(&tkind_ctest_obj));
}

TEST(TkindSm1State3, FetchFReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_f(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj));
}

TEST(TkindSm1State3, DispatchFReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_f(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj)
                       && Tkind_ctest_dispatch_event(&tkind_ctest_obj));
}

TEST(TkindSm1State3, ReleaseFReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_f(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj)
                       && Tkind_ctest_dispatch_event(&tkind_ctest_obj)
                       && Tkind_ctest_release_event(&tkind_ctest_obj));
}

TEST(TkindSm1State3, GReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_g(&tkind_ctest_obj));
}

TEST(TkindSm1State3, FetchGReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_g(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj));
}

TEST(TkindSm1State3, DispatchGReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_g(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj)
                       && Tkind_ctest_dispatch_event(&tkind_ctest_obj));
}

TEST(TkindSm1State3, ReleaseGReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_g(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj)
                       && Tkind_ctest_dispatch_event(&tkind_ctest_obj)
                       && Tkind_ctest_release_event(&tkind_ctest_obj));
}

TEST(TkindSm1State3, HReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_h(&tkind_ctest_obj));
}

TEST(TkindSm1State3, FetchHReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_h(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj));
}

TEST(TkindSm1State3, DispatchHReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_h(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj)
                       && Tkind_ctest_dispatch_event(&tkind_ctest_obj));
}

TEST(TkindSm1State3, ReleaseHReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_h(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj)
                       && Tkind_ctest_dispatch_event(&tkind_ctest_obj)
                       && Tkind_ctest_release_event(&tkind_ctest_obj));
}

TEST(TkindSm1State3, IReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_i(&tkind_ctest_obj));
}

TEST(TkindSm1State3, FetchIReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_i(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj));
}

TEST(TkindSm1State3, DispatchIReturnsTrue)
{
    tkind_ctest_logger_expect(true, "Exit State3\n"
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

TEST(TkindSm1State3, ReleaseIReturnsTrue)
{
    tkind_ctest_logger_expect(true, "Exit State3\n"
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

TEST(TkindSm1State3, JReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_j(&tkind_ctest_obj));
}

TEST(TkindSm1State3, FetchJReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_j(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj));
}

TEST(TkindSm1State3, DispatchJReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_j(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj)
                       && Tkind_ctest_dispatch_event(&tkind_ctest_obj));
}

TEST(TkindSm1State3, ReleaseJReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_j(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj)
                       && Tkind_ctest_dispatch_event(&tkind_ctest_obj)
                       && Tkind_ctest_release_event(&tkind_ctest_obj));
}

TEST(TkindSm1State3, KReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_k(&tkind_ctest_obj));
}

TEST(TkindSm1State3, FetchKReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_k(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj));
}

TEST(TkindSm1State3, DispatchKReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_k(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj)
                       && Tkind_ctest_dispatch_event(&tkind_ctest_obj));
}

TEST(TkindSm1State3, ReleaseKReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_k(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj)
                       && Tkind_ctest_dispatch_event(&tkind_ctest_obj)
                       && Tkind_ctest_release_event(&tkind_ctest_obj));
}

TEST(TkindSm1State3, LReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_l(&tkind_ctest_obj));
}

TEST(TkindSm1State3, FetchLReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_l(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj));
}

TEST(TkindSm1State3, DispatchLReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_l(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj)
                       && Tkind_ctest_dispatch_event(&tkind_ctest_obj));
}

TEST(TkindSm1State3, ReleaseLReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_l(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj)
                       && Tkind_ctest_dispatch_event(&tkind_ctest_obj)
                       && Tkind_ctest_release_event(&tkind_ctest_obj));
}

TEST(TkindSm1State3, MReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_m(&tkind_ctest_obj));
}

TEST(TkindSm1State3, FetchMReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_m(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj));
}

TEST(TkindSm1State3, DispatchMReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_m(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj)
                       && Tkind_ctest_dispatch_event(&tkind_ctest_obj));
}

TEST(TkindSm1State3, ReleaseMReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_m(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj)
                       && Tkind_ctest_dispatch_event(&tkind_ctest_obj)
                       && Tkind_ctest_release_event(&tkind_ctest_obj));
}

TEST(TkindSm1State3, NReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_n(&tkind_ctest_obj));
}

TEST(TkindSm1State3, FetchNReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_n(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj));
}

TEST(TkindSm1State3, DispatchNReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_n(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj)
                       && Tkind_ctest_dispatch_event(&tkind_ctest_obj));
}

TEST(TkindSm1State3, ReleaseNReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_n(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj)
                       && Tkind_ctest_dispatch_event(&tkind_ctest_obj)
                       && Tkind_ctest_release_event(&tkind_ctest_obj));
}

TEST(TkindSm1State3, OReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_o(&tkind_ctest_obj));
}

TEST(TkindSm1State3, FetchOWithFalseChoice1ReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_obj.sm1.b_test_condition = false;
    tkind_ctest_logger_given(Tkind_ctest_o(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj));
}

TEST(TkindSm1State3, DispatchOWithFalseChoice1ReturnsTrue)
{
    tkind_ctest_logger_expect(true, "Exit State3\n"
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

TEST(TkindSm1State3, ReleaseOWithFalseChoice1ReturnsTrue)
{
    tkind_ctest_logger_expect(true, "Exit State3\n"
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

TEST(TkindSm1State3, FetchOWithTrueChoice1ReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_obj.sm1.b_test_condition = true;
    tkind_ctest_logger_given(Tkind_ctest_o(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj));
}

TEST(TkindSm1State3, DispatchOWithTrueChoice1ReturnsTrue)
{
    tkind_ctest_logger_expect(true, "Exit State3\n"
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

TEST(TkindSm1State3, ReleaseOWithTrueChoice1ReturnsTrue)
{
    tkind_ctest_logger_expect(true, "Exit State3\n"
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

TEST(TkindSm1State3, FetchReturnsFalse)
{
    tkind_ctest_logger_expect(false, NULL);
    tkind_ctest_logger_given(Tkind_ctest_fetch_event(&tkind_ctest_obj));
}

TEST(TkindSm1State3, DispatchReturnsFalse)
{
    tkind_ctest_logger_expect(false, NULL);
    tkind_ctest_logger_given(Tkind_ctest_dispatch_event(&tkind_ctest_obj));
}

TEST(TkindSm1State3, ReleaseReturnsFalse)
{
    tkind_ctest_logger_expect(false, NULL);
    tkind_ctest_logger_given(Tkind_ctest_release_event(&tkind_ctest_obj));
}


TEST_GROUP_RUNNER(TkindSm1State3)
{
    RUN_TEST_CASE(TkindSm1State3, InitResultsInInitialTransition);

    RUN_TEST_CASE(TkindSm1State3, AReturnsTrue);
    RUN_TEST_CASE(TkindSm1State3, FetchAReturnsTrue);
    RUN_TEST_CASE(TkindSm1State3, DispatchAReturnsTrue);
    RUN_TEST_CASE(TkindSm1State3, ReleaseAReturnsTrue);

    RUN_TEST_CASE(TkindSm1State3, BReturnsTrue);
    RUN_TEST_CASE(TkindSm1State3, FetchBReturnsTrue);
    RUN_TEST_CASE(TkindSm1State3, DispatchBReturnsTrue);
    RUN_TEST_CASE(TkindSm1State3, ReleaseBReturnsTrue);

    RUN_TEST_CASE(TkindSm1State3, CReturnsTrue);
    RUN_TEST_CASE(TkindSm1State3, FetchCReturnsTrue);
    RUN_TEST_CASE(TkindSm1State3, DispatchCReturnsTrue);
    RUN_TEST_CASE(TkindSm1State3, ReleaseCReturnsTrue);

    RUN_TEST_CASE(TkindSm1State3, DReturnsTrue);
    RUN_TEST_CASE(TkindSm1State3, FetchDReturnsTrue);
    RUN_TEST_CASE(TkindSm1State3, DispatchDReturnsTrue);
    RUN_TEST_CASE(TkindSm1State3, ReleaseDReturnsTrue);

    RUN_TEST_CASE(TkindSm1State3, EReturnsTrue);
    RUN_TEST_CASE(TkindSm1State3, FetchEReturnsTrue);
    RUN_TEST_CASE(TkindSm1State3, DispatchEReturnsTrue);
    RUN_TEST_CASE(TkindSm1State3, ReleaseEReturnsTrue);

    RUN_TEST_CASE(TkindSm1State3, FReturnsTrue);
    RUN_TEST_CASE(TkindSm1State3, FetchFReturnsTrue);
    RUN_TEST_CASE(TkindSm1State3, DispatchFReturnsTrue);
    RUN_TEST_CASE(TkindSm1State3, ReleaseFReturnsTrue);

    RUN_TEST_CASE(TkindSm1State3, GReturnsTrue);
    RUN_TEST_CASE(TkindSm1State3, FetchGReturnsTrue);
    RUN_TEST_CASE(TkindSm1State3, DispatchGReturnsTrue);
    RUN_TEST_CASE(TkindSm1State3, ReleaseGReturnsTrue);

    RUN_TEST_CASE(TkindSm1State3, HReturnsTrue);
    RUN_TEST_CASE(TkindSm1State3, FetchHReturnsTrue);
    RUN_TEST_CASE(TkindSm1State3, DispatchHReturnsTrue);
    RUN_TEST_CASE(TkindSm1State3, ReleaseHReturnsTrue);

    RUN_TEST_CASE(TkindSm1State3, IReturnsTrue);
    RUN_TEST_CASE(TkindSm1State3, FetchIReturnsTrue);
    RUN_TEST_CASE(TkindSm1State3, DispatchIReturnsTrue);
    RUN_TEST_CASE(TkindSm1State3, ReleaseIReturnsTrue);

    RUN_TEST_CASE(TkindSm1State3, JReturnsTrue);
    RUN_TEST_CASE(TkindSm1State3, FetchJReturnsTrue);
    RUN_TEST_CASE(TkindSm1State3, DispatchJReturnsTrue);
    RUN_TEST_CASE(TkindSm1State3, ReleaseJReturnsTrue);

    RUN_TEST_CASE(TkindSm1State3, KReturnsTrue);
    RUN_TEST_CASE(TkindSm1State3, FetchKReturnsTrue);
    RUN_TEST_CASE(TkindSm1State3, DispatchKReturnsTrue);
    RUN_TEST_CASE(TkindSm1State3, ReleaseKReturnsTrue);

    RUN_TEST_CASE(TkindSm1State3, LReturnsTrue);
    RUN_TEST_CASE(TkindSm1State3, FetchLReturnsTrue);
    RUN_TEST_CASE(TkindSm1State3, DispatchLReturnsTrue);
    RUN_TEST_CASE(TkindSm1State3, ReleaseLReturnsTrue);

    RUN_TEST_CASE(TkindSm1State3, MReturnsTrue);
    RUN_TEST_CASE(TkindSm1State3, FetchMReturnsTrue);
    RUN_TEST_CASE(TkindSm1State3, DispatchMReturnsTrue);
    RUN_TEST_CASE(TkindSm1State3, ReleaseMReturnsTrue);

    RUN_TEST_CASE(TkindSm1State3, NReturnsTrue);
    RUN_TEST_CASE(TkindSm1State3, FetchNReturnsTrue);
    RUN_TEST_CASE(TkindSm1State3, DispatchNReturnsTrue);
    RUN_TEST_CASE(TkindSm1State3, ReleaseNReturnsTrue);

    RUN_TEST_CASE(TkindSm1State3, OReturnsTrue);
    RUN_TEST_CASE(TkindSm1State3, FetchOWithFalseChoice1ReturnsTrue);
    RUN_TEST_CASE(TkindSm1State3, DispatchOWithFalseChoice1ReturnsTrue);
    RUN_TEST_CASE(TkindSm1State3, ReleaseOWithFalseChoice1ReturnsTrue);
    RUN_TEST_CASE(TkindSm1State3, FetchOWithTrueChoice1ReturnsTrue);
    RUN_TEST_CASE(TkindSm1State3, DispatchOWithTrueChoice1ReturnsTrue);
    RUN_TEST_CASE(TkindSm1State3, ReleaseOWithTrueChoice1ReturnsTrue);

    RUN_TEST_CASE(TkindSm1State3, FetchReturnsFalse);
    RUN_TEST_CASE(TkindSm1State3, DispatchReturnsFalse);
    RUN_TEST_CASE(TkindSm1State3, ReleaseReturnsFalse);
}

/*** end of file ***/
