/*
 * @file TkindSm1ZeroInit_test.c
 *
 * @brief Source code of the TkindSm1ZeroInit group test cases.
 * @author tomboro88
 * @date   1 may 2026
 * @copyright (c) 2026 tomboro88. All rights reserved.
 * @license MIT – see LICENSE file in project root
 * @project github.com/tomboro88/M2T4Embedded
 */
#include "Tkind_test.h"

/*******************************************************************************
 *
 * Test group TkindSm1ZeroInit - checks the behavior of all functions on an
 * object initialized with zeros.
 *
 ******************************************************************************/
TEST_GROUP(TkindSm1ZeroInit);

TEST_SETUP(TkindSm1ZeroInit)
{
    tkind_test_init_logger_buffer();
    tkind_ctest_obj = (Tkind_ctest_t) {0};
}

TEST_TEAR_DOWN(TkindSm1ZeroInit)
{

}

/*================================TEST_CASES==================================*/
TEST(TkindSm1ZeroInit, InitNullArgsGiveFalse)
{
    tkind_ctest_logger_expect(false, NULL);
    tkind_ctest_logger_given(Tkind_ctest_init(NULL, NULL));
}

TEST(TkindSm1ZeroInit, InitNullPtrGivesFalse)
{
    tkind_ctest_logger_expect(false, NULL);
    tkind_ctest_logger_given(Tkind_ctest_init(NULL, &tkind_test_logger));
}

TEST(TkindSm1ZeroInit, InitNullLoggerGivesTrue)
{
    tkind_ctest_logger_expect(true, NULL);
    tkind_ctest_logger_given(Tkind_ctest_init(&tkind_ctest_obj, NULL));
}

TEST(TkindSm1ZeroInit, InitResultsInInitialTransition)
{
    tkind_ctest_logger_expect(true, "Initial1 to State1\n"
                              "Enter State1\n"
                              "Initial3 to State2\n"
                              "Enter State2\n");
    tkind_ctest_logger_given(Tkind_ctest_init(&tkind_ctest_obj, &tkind_test_logger));
}

TEST(TkindSm1ZeroInit, ANullPtrResultsInFalse)
{
    tkind_ctest_logger_expect(false, NULL);
    tkind_ctest_logger_given(Tkind_ctest_a(NULL));
}

TEST(TkindSm1ZeroInit, AResultsInFalse)
{
    tkind_ctest_logger_expect(false, NULL);
    tkind_ctest_logger_given(Tkind_ctest_a(&tkind_ctest_obj));
}

TEST(TkindSm1ZeroInit, BNullPtrResultsInFalse)
{
    tkind_ctest_logger_expect(false, NULL);
    tkind_ctest_logger_given(Tkind_ctest_b(NULL));
}

TEST(TkindSm1ZeroInit, BResultsInFalse)
{
    tkind_ctest_logger_expect(false, NULL);
    tkind_ctest_logger_given(Tkind_ctest_b(&tkind_ctest_obj));
}

TEST(TkindSm1ZeroInit, CNullPtrResultsInFalse)
{
    tkind_ctest_logger_expect(false, NULL);
    tkind_ctest_logger_given(Tkind_ctest_c(NULL));
}

TEST(TkindSm1ZeroInit, CResultsInFalse)
{
    tkind_ctest_logger_expect(false, NULL);
    tkind_ctest_logger_given(Tkind_ctest_c(&tkind_ctest_obj));
}

TEST(TkindSm1ZeroInit, DNullPtrResultsInFalse)
{
    tkind_ctest_logger_expect(false, NULL);
    tkind_ctest_logger_given(Tkind_ctest_d(NULL));
}

TEST(TkindSm1ZeroInit, DResultsInFalse)
{
    tkind_ctest_logger_expect(false, NULL);
    tkind_ctest_logger_given(Tkind_ctest_d(&tkind_ctest_obj));
}

TEST(TkindSm1ZeroInit, ENullPtrResultsInFalse)
{
    tkind_ctest_logger_expect(false, NULL);
    tkind_ctest_logger_given(Tkind_ctest_e(NULL));
}

TEST(TkindSm1ZeroInit, EResultsInFalse)
{
    tkind_ctest_logger_expect(false, NULL);
    tkind_ctest_logger_given(Tkind_ctest_e(&tkind_ctest_obj));
}

TEST(TkindSm1ZeroInit, FNullPtrResultsInFalse)
{
    tkind_ctest_logger_expect(false, NULL);
    tkind_ctest_logger_given(Tkind_ctest_f(NULL));
}

TEST(TkindSm1ZeroInit, FResultsInFalse)
{
    tkind_ctest_logger_expect(false, NULL);
    tkind_ctest_logger_given(Tkind_ctest_f(&tkind_ctest_obj));
}

TEST(TkindSm1ZeroInit, GNullPtrResultsInFalse)
{
    tkind_ctest_logger_expect(false, NULL);
    tkind_ctest_logger_given(Tkind_ctest_g(NULL));
}

TEST(TkindSm1ZeroInit, GResultsInFalse)
{
    tkind_ctest_logger_expect(false, NULL);
    tkind_ctest_logger_given(Tkind_ctest_g(&tkind_ctest_obj));
}

TEST(TkindSm1ZeroInit, HNullPtrResultsInFalse)
{
    tkind_ctest_logger_expect(false, NULL);
    tkind_ctest_logger_given(Tkind_ctest_h(NULL));
}

TEST(TkindSm1ZeroInit, HResultsInFalse)
{
    tkind_ctest_logger_expect(false, NULL);
    tkind_ctest_logger_given(Tkind_ctest_h(&tkind_ctest_obj));
}

TEST(TkindSm1ZeroInit, INullPtrResultsInFalse)
{
    tkind_ctest_logger_expect(false, NULL);
    tkind_ctest_logger_given(Tkind_ctest_i(NULL));
}

TEST(TkindSm1ZeroInit, IResultsInFalse)
{
    tkind_ctest_logger_expect(false, NULL);
    tkind_ctest_logger_given(Tkind_ctest_i(&tkind_ctest_obj));
}

TEST(TkindSm1ZeroInit, JNullPtrResultsInFalse)
{
    tkind_ctest_logger_expect(false, NULL);
    tkind_ctest_logger_given(Tkind_ctest_j(NULL));
}

TEST(TkindSm1ZeroInit, JResultsInFalse)
{
    tkind_ctest_logger_expect(false, NULL);
    tkind_ctest_logger_given(Tkind_ctest_j(&tkind_ctest_obj));
}

TEST(TkindSm1ZeroInit, KNullPtrResultsInFalse)
{
    tkind_ctest_logger_expect(false, NULL);
    tkind_ctest_logger_given(Tkind_ctest_k(NULL));
}

TEST(TkindSm1ZeroInit, KResultsInFalse)
{
    tkind_ctest_logger_expect(false, NULL);
    tkind_ctest_logger_given(Tkind_ctest_k(&tkind_ctest_obj));
}

TEST(TkindSm1ZeroInit, LNullPtrResultsInFalse)
{
    tkind_ctest_logger_expect(false, NULL);
    tkind_ctest_logger_given(Tkind_ctest_l(NULL));
}

TEST(TkindSm1ZeroInit, LResultsInFalse)
{
    tkind_ctest_logger_expect(false, NULL);
    tkind_ctest_logger_given(Tkind_ctest_l(&tkind_ctest_obj));
}

TEST(TkindSm1ZeroInit, MNullPtrResultsInFalse)
{
    tkind_ctest_logger_expect(false, NULL);
    tkind_ctest_logger_given(Tkind_ctest_m(NULL));
}

TEST(TkindSm1ZeroInit, MResultsInFalse)
{
    tkind_ctest_logger_expect(false, NULL);
    tkind_ctest_logger_given(Tkind_ctest_m(&tkind_ctest_obj));
}

TEST(TkindSm1ZeroInit, NNullPtrResultsInFalse)
{
    tkind_ctest_logger_expect(false, NULL);
    tkind_ctest_logger_given(Tkind_ctest_n(NULL));
}

TEST(TkindSm1ZeroInit, NResultsInFalse)
{
    tkind_ctest_logger_expect(false, NULL);
    tkind_ctest_logger_given(Tkind_ctest_n(&tkind_ctest_obj));
}

TEST(TkindSm1ZeroInit, ONullPtrResultsInFalse)
{
    tkind_ctest_logger_expect(false, NULL);
    tkind_ctest_logger_given(Tkind_ctest_o(NULL));
}

TEST(TkindSm1ZeroInit, OResultsInFalse)
{
    tkind_ctest_logger_expect(false, NULL);
    tkind_ctest_logger_given(Tkind_ctest_o(&tkind_ctest_obj));
}

TEST(TkindSm1ZeroInit, FetchNullPtrResultsInFalse)
{
    tkind_ctest_logger_expect(false, NULL);
    tkind_ctest_logger_given(Tkind_ctest_fetch_event(NULL));
}

TEST(TkindSm1ZeroInit, FetchResultsInFalse)
{
    tkind_ctest_logger_expect(false, NULL);
    tkind_ctest_logger_given(Tkind_ctest_fetch_event(&tkind_ctest_obj));
}

TEST(TkindSm1ZeroInit, DispatchNullPtrResultsInFalse)
{
    tkind_ctest_logger_expect(false, NULL);
    tkind_ctest_logger_given(Tkind_ctest_dispatch_event(NULL));
}

TEST(TkindSm1ZeroInit, DispatchResultsInFalse)
{
    tkind_ctest_logger_expect(false, NULL);
    tkind_ctest_logger_given(Tkind_ctest_dispatch_event(&tkind_ctest_obj));
}

TEST(TkindSm1ZeroInit, ReleaseNullPtrResultsInFalse)
{
    tkind_ctest_logger_expect(false, NULL);
    tkind_ctest_logger_given(Tkind_ctest_release_event(NULL));
}

TEST(TkindSm1ZeroInit, ReleaseResultsInFalse)
{
    tkind_ctest_logger_expect(false, NULL);
    tkind_ctest_logger_given(Tkind_ctest_release_event(&tkind_ctest_obj));
}


TEST_GROUP_RUNNER(TkindSm1ZeroInit)
{
    RUN_TEST_CASE(TkindSm1ZeroInit, InitNullArgsGiveFalse);
    RUN_TEST_CASE(TkindSm1ZeroInit, InitNullPtrGivesFalse);
    RUN_TEST_CASE(TkindSm1ZeroInit, InitNullLoggerGivesTrue);
    RUN_TEST_CASE(TkindSm1ZeroInit, InitResultsInInitialTransition);

    RUN_TEST_CASE(TkindSm1ZeroInit, ANullPtrResultsInFalse);
    RUN_TEST_CASE(TkindSm1ZeroInit, AResultsInFalse);

    RUN_TEST_CASE(TkindSm1ZeroInit, BNullPtrResultsInFalse);
    RUN_TEST_CASE(TkindSm1ZeroInit, BResultsInFalse);

    RUN_TEST_CASE(TkindSm1ZeroInit, CNullPtrResultsInFalse);
    RUN_TEST_CASE(TkindSm1ZeroInit, CResultsInFalse);

    RUN_TEST_CASE(TkindSm1ZeroInit, DNullPtrResultsInFalse);
    RUN_TEST_CASE(TkindSm1ZeroInit, DResultsInFalse);

    RUN_TEST_CASE(TkindSm1ZeroInit, ENullPtrResultsInFalse);
    RUN_TEST_CASE(TkindSm1ZeroInit, EResultsInFalse);

    RUN_TEST_CASE(TkindSm1ZeroInit, FNullPtrResultsInFalse);
    RUN_TEST_CASE(TkindSm1ZeroInit, FResultsInFalse);

    RUN_TEST_CASE(TkindSm1ZeroInit, GNullPtrResultsInFalse);
    RUN_TEST_CASE(TkindSm1ZeroInit, GResultsInFalse);

    RUN_TEST_CASE(TkindSm1ZeroInit, HNullPtrResultsInFalse);
    RUN_TEST_CASE(TkindSm1ZeroInit, HResultsInFalse);

    RUN_TEST_CASE(TkindSm1ZeroInit, INullPtrResultsInFalse);
    RUN_TEST_CASE(TkindSm1ZeroInit, IResultsInFalse);

    RUN_TEST_CASE(TkindSm1ZeroInit, JNullPtrResultsInFalse);
    RUN_TEST_CASE(TkindSm1ZeroInit, JResultsInFalse);

    RUN_TEST_CASE(TkindSm1ZeroInit, KNullPtrResultsInFalse);
    RUN_TEST_CASE(TkindSm1ZeroInit, KResultsInFalse);

    RUN_TEST_CASE(TkindSm1ZeroInit, LNullPtrResultsInFalse);
    RUN_TEST_CASE(TkindSm1ZeroInit, LResultsInFalse);

    RUN_TEST_CASE(TkindSm1ZeroInit, MNullPtrResultsInFalse);
    RUN_TEST_CASE(TkindSm1ZeroInit, MResultsInFalse);

    RUN_TEST_CASE(TkindSm1ZeroInit, NNullPtrResultsInFalse);
    RUN_TEST_CASE(TkindSm1ZeroInit, NResultsInFalse);

    RUN_TEST_CASE(TkindSm1ZeroInit, ONullPtrResultsInFalse);
    RUN_TEST_CASE(TkindSm1ZeroInit, OResultsInFalse);

    RUN_TEST_CASE(TkindSm1ZeroInit, FetchNullPtrResultsInFalse);
    RUN_TEST_CASE(TkindSm1ZeroInit, FetchResultsInFalse);

    RUN_TEST_CASE(TkindSm1ZeroInit, DispatchNullPtrResultsInFalse);
    RUN_TEST_CASE(TkindSm1ZeroInit, DispatchResultsInFalse);

    RUN_TEST_CASE(TkindSm1ZeroInit, ReleaseNullPtrResultsInFalse);
    RUN_TEST_CASE(TkindSm1ZeroInit, ReleaseResultsInFalse);
}

/*** end of file ***/
