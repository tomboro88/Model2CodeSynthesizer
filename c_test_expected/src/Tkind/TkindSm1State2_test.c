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
 * Test group TkindSm1State2.
 *
 ******************************************************************************/
TEST_GROUP(TkindSm1State2);

TEST_SETUP(TkindSm1State2)
{
    tkind_test_init_logger_buffer();
    Tkind_ctest_init(&tkind_ctest_obj, &tkind_test_logger);
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
    tkind_ctest_logger_given(Tkind_ctest_init(&tkind_ctest_obj, &tkind_test_logger));
}

TEST(TkindSm1State2, AReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_a(&tkind_ctest_obj));
}

TEST(TkindSm1State2, FetchAReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_a(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj));
}

TEST(TkindSm1State2, DispatchAReturnsTrue)
{
    tkind_ctest_logger_expect(true, "Exit State2\n"
                              "State2 to State3\n"
                              "Enter State3\n");
    tkind_ctest_logger_given(Tkind_ctest_a(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj)
                       && Tkind_ctest_dispatch_event(&tkind_ctest_obj));
}

TEST(TkindSm1State2, ReleaseAReturnsTrue)
{
    tkind_ctest_logger_expect(true, "Exit State2\n"
                              "State2 to State3\n"
                              "Enter State3\n");
    tkind_ctest_logger_given(Tkind_ctest_a(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj)
                       && Tkind_ctest_dispatch_event(&tkind_ctest_obj)
                       && Tkind_ctest_release_event(&tkind_ctest_obj));
}

TEST(TkindSm1State2, BReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_b(&tkind_ctest_obj));
}

TEST(TkindSm1State2, FetchBReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_b(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj));
}

TEST(TkindSm1State2, DispatchBReturnsTrue)
{
    tkind_ctest_logger_expect(true, "Exit State2\n"
                              "State2 to State4\n"
                              "Enter State4\n");
    tkind_ctest_logger_given(Tkind_ctest_b(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj)
                       && Tkind_ctest_dispatch_event(&tkind_ctest_obj));
}

TEST(TkindSm1State2, ReleaseBReturnsTrue)
{
    tkind_ctest_logger_expect(true, "Exit State2\n"
                              "State2 to State4\n"
                              "Enter State4\n");
    tkind_ctest_logger_given(Tkind_ctest_b(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj)
                       && Tkind_ctest_dispatch_event(&tkind_ctest_obj)
                       && Tkind_ctest_release_event(&tkind_ctest_obj));
}

TEST(TkindSm1State2, CReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_c(&tkind_ctest_obj));
}

TEST(TkindSm1State2, FetchCReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_c(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj));
}

TEST(TkindSm1State2, DispatchCReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_c(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj)
                       && Tkind_ctest_dispatch_event(&tkind_ctest_obj));
}

TEST(TkindSm1State2, ReleaseCReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_c(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj)
                       && Tkind_ctest_dispatch_event(&tkind_ctest_obj)
                       && Tkind_ctest_release_event(&tkind_ctest_obj));
}

TEST(TkindSm1State2, DReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_d(&tkind_ctest_obj));
}

TEST(TkindSm1State2, FetchDReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_d(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj));
}

TEST(TkindSm1State2, DispatchDReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_d(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj)
                       && Tkind_ctest_dispatch_event(&tkind_ctest_obj));
}

TEST(TkindSm1State2, ReleaseDReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_d(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj)
                       && Tkind_ctest_dispatch_event(&tkind_ctest_obj)
                       && Tkind_ctest_release_event(&tkind_ctest_obj));
}

TEST(TkindSm1State2, EReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_e(&tkind_ctest_obj));
}

TEST(TkindSm1State2, FetchEReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_e(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj));
}

TEST(TkindSm1State2, DispatchEReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_e(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj)
                       && Tkind_ctest_dispatch_event(&tkind_ctest_obj));
}

TEST(TkindSm1State2, ReleaseEReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_e(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj)
                       && Tkind_ctest_dispatch_event(&tkind_ctest_obj)
                       && Tkind_ctest_release_event(&tkind_ctest_obj));
}

TEST(TkindSm1State2, FReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_f(&tkind_ctest_obj));
}

TEST(TkindSm1State2, FetchFReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_f(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj));
}

TEST(TkindSm1State2, DispatchFReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_f(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj)
                       && Tkind_ctest_dispatch_event(&tkind_ctest_obj));
}

TEST(TkindSm1State2, ReleaseFReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_f(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj)
                       && Tkind_ctest_dispatch_event(&tkind_ctest_obj)
                       && Tkind_ctest_release_event(&tkind_ctest_obj));
}

TEST(TkindSm1State2, GReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_g(&tkind_ctest_obj));
}

TEST(TkindSm1State2, FetchGReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_g(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj));
}

TEST(TkindSm1State2, DispatchGReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_g(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj)
                       && Tkind_ctest_dispatch_event(&tkind_ctest_obj));
}

TEST(TkindSm1State2, ReleaseGReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_g(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj)
                       && Tkind_ctest_dispatch_event(&tkind_ctest_obj)
                       && Tkind_ctest_release_event(&tkind_ctest_obj));
}

TEST(TkindSm1State2, HReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_h(&tkind_ctest_obj));
}

TEST(TkindSm1State2, FetchHReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_h(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj));
}

TEST(TkindSm1State2, DispatchHReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_h(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj)
                       && Tkind_ctest_dispatch_event(&tkind_ctest_obj));
}

TEST(TkindSm1State2, ReleaseHReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_h(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj)
                       && Tkind_ctest_dispatch_event(&tkind_ctest_obj)
                       && Tkind_ctest_release_event(&tkind_ctest_obj));
}

TEST(TkindSm1State2, IReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_i(&tkind_ctest_obj));
}

TEST(TkindSm1State2, FetchIReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_i(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj));
}

TEST(TkindSm1State2, DispatchIReturnsTrue)
{
    tkind_ctest_logger_expect(true, "Exit State2\n"
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

TEST(TkindSm1State2, ReleaseIReturnsTrue)
{
    tkind_ctest_logger_expect(true, "Exit State2\n"
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

TEST(TkindSm1State2, JReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_j(&tkind_ctest_obj));
}

TEST(TkindSm1State2, FetchJReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_j(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj));
}

TEST(TkindSm1State2, DispatchJReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_j(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj)
                       && Tkind_ctest_dispatch_event(&tkind_ctest_obj));
}

TEST(TkindSm1State2, ReleaseJReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_j(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj)
                       && Tkind_ctest_dispatch_event(&tkind_ctest_obj)
                       && Tkind_ctest_release_event(&tkind_ctest_obj));/*** end of file ***/
}

TEST(TkindSm1State2, KReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_k(&tkind_ctest_obj));
}

TEST(TkindSm1State2, FetchKReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_k(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj));
}

TEST(TkindSm1State2, DispatchKReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_k(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj)
                       && Tkind_ctest_dispatch_event(&tkind_ctest_obj));
}

TEST(TkindSm1State2, ReleaseKReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_k(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj)
                       && Tkind_ctest_dispatch_event(&tkind_ctest_obj)
                       && Tkind_ctest_release_event(&tkind_ctest_obj));
}

TEST(TkindSm1State2, LReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_l(&tkind_ctest_obj));
}

TEST(TkindSm1State2, FetchLReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_l(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj));
}

TEST(TkindSm1State2, DispatchLReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_l(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj)
                       && Tkind_ctest_dispatch_event(&tkind_ctest_obj));
}

TEST(TkindSm1State2, ReleaseLReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_l(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj)
                       && Tkind_ctest_dispatch_event(&tkind_ctest_obj)
                       && Tkind_ctest_release_event(&tkind_ctest_obj));
}

TEST(TkindSm1State2, MReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_m(&tkind_ctest_obj));
}

TEST(TkindSm1State2, FetchMReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_m(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj));
}

TEST(TkindSm1State2, DispatchMReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_m(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj)
                       && Tkind_ctest_dispatch_event(&tkind_ctest_obj));
}

TEST(TkindSm1State2, ReleaseMReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_m(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj)
                       && Tkind_ctest_dispatch_event(&tkind_ctest_obj)
                       && Tkind_ctest_release_event(&tkind_ctest_obj));
}

TEST(TkindSm1State2, NReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_n(&tkind_ctest_obj));
}

TEST(TkindSm1State2, FetchNReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_n(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj));
}

TEST(TkindSm1State2, DispatchNReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_n(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj)
                       && Tkind_ctest_dispatch_event(&tkind_ctest_obj));
}

TEST(TkindSm1State2, ReleaseNReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_n(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj)
                       && Tkind_ctest_dispatch_event(&tkind_ctest_obj)
                       && Tkind_ctest_release_event(&tkind_ctest_obj));
}

TEST(TkindSm1State2, OReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_o(&tkind_ctest_obj));
}

TEST(TkindSm1State2, FetchOWithFalseChoice1ReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_obj.sm1.b_test_condition = false;
    tkind_ctest_logger_given(Tkind_ctest_o(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj));
}

TEST(TkindSm1State2, DispatchOWithFalseChoice1ReturnsTrue)
{
    tkind_ctest_logger_expect(true, "Exit State2\n"
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

TEST(TkindSm1State2, ReleaseOWithFalseChoice1ReturnsTrue)
{
    tkind_ctest_logger_expect(true, "Exit State2\n"
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

TEST(TkindSm1State2, FetchOWithTrueChoice1ReturnsTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_obj.sm1.b_test_condition = true;
    tkind_ctest_logger_given(Tkind_ctest_o(&tkind_ctest_obj)
                       && Tkind_ctest_fetch_event(&tkind_ctest_obj));
}

TEST(TkindSm1State2, DispatchOWithTrueChoice1ReturnsTrue)
{
    tkind_ctest_logger_expect(true, "Exit State2\n"
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

TEST(TkindSm1State2, ReleaseOWithTrueChoice1ReturnsTrue)
{
    tkind_ctest_logger_expect(true, "Exit State2\n"
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

TEST(TkindSm1State2, FetchReturnsFalse)
{
    tkind_ctest_logger_expect(false, NULL);
    tkind_ctest_logger_given(Tkind_ctest_fetch_event(&tkind_ctest_obj));
}

TEST(TkindSm1State2, DispatchReturnsFalse)
{
    tkind_ctest_logger_expect(false, NULL);
    tkind_ctest_logger_given(Tkind_ctest_dispatch_event(&tkind_ctest_obj));
}

TEST(TkindSm1State2, ReleaseReturnsFalse)
{
    tkind_ctest_logger_expect(false, NULL);
    tkind_ctest_logger_given(Tkind_ctest_release_event(&tkind_ctest_obj));
}


TEST_GROUP_RUNNER(TkindSm1State2)
{
    RUN_TEST_CASE(TkindSm1State2, InitResultsInInitialTransition);

    RUN_TEST_CASE(TkindSm1State2, AReturnsTrue);
    RUN_TEST_CASE(TkindSm1State2, FetchAReturnsTrue);
    RUN_TEST_CASE(TkindSm1State2, DispatchAReturnsTrue);
    RUN_TEST_CASE(TkindSm1State2, ReleaseAReturnsTrue);

    RUN_TEST_CASE(TkindSm1State2, BReturnsTrue);
    RUN_TEST_CASE(TkindSm1State2, FetchBReturnsTrue);
    RUN_TEST_CASE(TkindSm1State2, DispatchBReturnsTrue);
    RUN_TEST_CASE(TkindSm1State2, ReleaseBReturnsTrue);

    RUN_TEST_CASE(TkindSm1State2, CReturnsTrue);
    RUN_TEST_CASE(TkindSm1State2, FetchCReturnsTrue);
    RUN_TEST_CASE(TkindSm1State2, DispatchCReturnsTrue);
    RUN_TEST_CASE(TkindSm1State2, ReleaseCReturnsTrue);

    RUN_TEST_CASE(TkindSm1State2, DReturnsTrue);
    RUN_TEST_CASE(TkindSm1State2, FetchDReturnsTrue);
    RUN_TEST_CASE(TkindSm1State2, DispatchDReturnsTrue);
    RUN_TEST_CASE(TkindSm1State2, ReleaseDReturnsTrue);

    RUN_TEST_CASE(TkindSm1State2, EReturnsTrue);
    RUN_TEST_CASE(TkindSm1State2, FetchEReturnsTrue);
    RUN_TEST_CASE(TkindSm1State2, DispatchEReturnsTrue);
    RUN_TEST_CASE(TkindSm1State2, ReleaseEReturnsTrue);

    RUN_TEST_CASE(TkindSm1State2, FReturnsTrue);
    RUN_TEST_CASE(TkindSm1State2, FetchFReturnsTrue);
    RUN_TEST_CASE(TkindSm1State2, DispatchFReturnsTrue);
    RUN_TEST_CASE(TkindSm1State2, ReleaseFReturnsTrue);

    RUN_TEST_CASE(TkindSm1State2, GReturnsTrue);
    RUN_TEST_CASE(TkindSm1State2, FetchGReturnsTrue);
    RUN_TEST_CASE(TkindSm1State2, DispatchGReturnsTrue);
    RUN_TEST_CASE(TkindSm1State2, ReleaseGReturnsTrue);

    RUN_TEST_CASE(TkindSm1State2, HReturnsTrue);
    RUN_TEST_CASE(TkindSm1State2, FetchHReturnsTrue);
    RUN_TEST_CASE(TkindSm1State2, DispatchHReturnsTrue);
    RUN_TEST_CASE(TkindSm1State2, ReleaseHReturnsTrue);

    RUN_TEST_CASE(TkindSm1State2, IReturnsTrue);
    RUN_TEST_CASE(TkindSm1State2, FetchIReturnsTrue);
    RUN_TEST_CASE(TkindSm1State2, DispatchIReturnsTrue);
    RUN_TEST_CASE(TkindSm1State2, ReleaseIReturnsTrue);

    RUN_TEST_CASE(TkindSm1State2, JReturnsTrue);
    RUN_TEST_CASE(TkindSm1State2, FetchJReturnsTrue);
    RUN_TEST_CASE(TkindSm1State2, DispatchJReturnsTrue);
    RUN_TEST_CASE(TkindSm1State2, ReleaseJReturnsTrue);

    RUN_TEST_CASE(TkindSm1State2, KReturnsTrue);
    RUN_TEST_CASE(TkindSm1State2, FetchKReturnsTrue);
    RUN_TEST_CASE(TkindSm1State2, DispatchKReturnsTrue);
    RUN_TEST_CASE(TkindSm1State2, ReleaseKReturnsTrue);

    RUN_TEST_CASE(TkindSm1State2, LReturnsTrue);
    RUN_TEST_CASE(TkindSm1State2, FetchLReturnsTrue);
    RUN_TEST_CASE(TkindSm1State2, DispatchLReturnsTrue);
    RUN_TEST_CASE(TkindSm1State2, ReleaseLReturnsTrue);

    RUN_TEST_CASE(TkindSm1State2, MReturnsTrue);
    RUN_TEST_CASE(TkindSm1State2, FetchMReturnsTrue);
    RUN_TEST_CASE(TkindSm1State2, DispatchMReturnsTrue);
    RUN_TEST_CASE(TkindSm1State2, ReleaseMReturnsTrue);

    RUN_TEST_CASE(TkindSm1State2, NReturnsTrue);
    RUN_TEST_CASE(TkindSm1State2, FetchNReturnsTrue);
    RUN_TEST_CASE(TkindSm1State2, DispatchNReturnsTrue);
    RUN_TEST_CASE(TkindSm1State2, ReleaseNReturnsTrue);

    RUN_TEST_CASE(TkindSm1State2, OReturnsTrue);
    RUN_TEST_CASE(TkindSm1State2, FetchOWithFalseChoice1ReturnsTrue);
    RUN_TEST_CASE(TkindSm1State2, DispatchOWithFalseChoice1ReturnsTrue);
    RUN_TEST_CASE(TkindSm1State2, ReleaseOWithFalseChoice1ReturnsTrue);
    RUN_TEST_CASE(TkindSm1State2, FetchOWithTrueChoice1ReturnsTrue);
    RUN_TEST_CASE(TkindSm1State2, DispatchOWithTrueChoice1ReturnsTrue);
    RUN_TEST_CASE(TkindSm1State2, ReleaseOWithTrueChoice1ReturnsTrue);

    RUN_TEST_CASE(TkindSm1State2, FetchReturnsFalse);
    RUN_TEST_CASE(TkindSm1State2, DispatchReturnsFalse);
    RUN_TEST_CASE(TkindSm1State2, ReleaseReturnsFalse);
}

/*** end of file ***/
