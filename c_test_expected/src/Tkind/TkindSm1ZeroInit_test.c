/*
 * @file TkindSm1ZeroInit_test.c
 *
 * @brief Source code of the TkindSm1ZeroInit group test cases.
 * @author tomboro88
 * @date   1 may 2026
 * @copyright (c) 2026 tomboro88. 
 * @license SPDX-License-Identifier: EPL-2.0
 * @project github.com/tomboro88/Model2CodeSynthesizer
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
    plogger_test_init_buffer();
    tkind_ctest_obj = (tkind_ctest_t) {0};
}

TEST_TEAR_DOWN(TkindSm1ZeroInit)
{

}

/*================================TEST_CASES==================================*/
TEST(TkindSm1ZeroInit, InitNullArgsGiveFalse)
{
    plogger_test_expect(false, NULL);
    plogger_test_given(tkind_ctest_init(NULL, NULL));
}

TEST(TkindSm1ZeroInit, InitNullPtrGivesFalse)
{
    plogger_test_expect(false, NULL);
    plogger_test_given(tkind_ctest_init(NULL, &plogger_test_logger));
}

TEST(TkindSm1ZeroInit, InitNullLoggerGivesTrue)
{
    plogger_test_expect(true, NULL);
    plogger_test_given(tkind_ctest_init(&tkind_ctest_obj, NULL));
}

TEST(TkindSm1ZeroInit, InitResultsInInitialTransition)
{
    tkind_ctest_logger_expect_initial();
    plogger_test_given(tkind_ctest_init(&tkind_ctest_obj,
                                        &plogger_test_logger));
}

TEST(TkindSm1ZeroInit, ANullPtrResultsInFalse)
{
    plogger_test_expect(false, NULL);
    plogger_test_given(tkind_ctest_a(NULL));
}

TEST(TkindSm1ZeroInit, AResultsInFalse)
{
    plogger_test_expect(false, NULL);
    plogger_test_given(tkind_ctest_a(&tkind_ctest_obj));
}

TEST(TkindSm1ZeroInit, BNullPtrResultsInFalse)
{
    plogger_test_expect(false, NULL);
    plogger_test_given(tkind_ctest_b(NULL));
}

TEST(TkindSm1ZeroInit, BResultsInFalse)
{
    plogger_test_expect(false, NULL);
    plogger_test_given(tkind_ctest_b(&tkind_ctest_obj));
}

TEST(TkindSm1ZeroInit, CNullPtrResultsInFalse)
{
    plogger_test_expect(false, NULL);
    plogger_test_given(tkind_ctest_c(NULL));
}

TEST(TkindSm1ZeroInit, CResultsInFalse)
{
    plogger_test_expect(false, NULL);
    plogger_test_given(tkind_ctest_c(&tkind_ctest_obj));
}

TEST(TkindSm1ZeroInit, DNullPtrResultsInFalse)
{
    plogger_test_expect(false, NULL);
    plogger_test_given(tkind_ctest_d(NULL));
}

TEST(TkindSm1ZeroInit, DResultsInFalse)
{
    plogger_test_expect(false, NULL);
    plogger_test_given(tkind_ctest_d(&tkind_ctest_obj));
}

TEST(TkindSm1ZeroInit, ENullPtrResultsInFalse)
{
    plogger_test_expect(false, NULL);
    plogger_test_given(tkind_ctest_e(NULL));
}

TEST(TkindSm1ZeroInit, EResultsInFalse)
{
    plogger_test_expect(false, NULL);
    plogger_test_given(tkind_ctest_e(&tkind_ctest_obj));
}

TEST(TkindSm1ZeroInit, FNullPtrResultsInFalse)
{
    plogger_test_expect(false, NULL);
    plogger_test_given(tkind_ctest_f(NULL));
}

TEST(TkindSm1ZeroInit, FResultsInFalse)
{
    plogger_test_expect(false, NULL);
    plogger_test_given(tkind_ctest_f(&tkind_ctest_obj));
}

TEST(TkindSm1ZeroInit, GNullPtrResultsInFalse)
{
    plogger_test_expect(false, NULL);
    plogger_test_given(tkind_ctest_g(NULL, 25, 'a'));
}

TEST(TkindSm1ZeroInit, GResultsInFalse)
{
    plogger_test_expect(false, NULL);
    plogger_test_given(tkind_ctest_g(&tkind_ctest_obj, 25, 'a'));
}

TEST(TkindSm1ZeroInit, HNullPtrResultsInFalse)
{
    plogger_test_expect(false, NULL);
    plogger_test_given(tkind_ctest_h(NULL, 16));
}

TEST(TkindSm1ZeroInit, HResultsInFalse)
{
    plogger_test_expect(false, NULL);
    plogger_test_given(tkind_ctest_h(&tkind_ctest_obj,16));
}

TEST(TkindSm1ZeroInit, INullPtrResultsInFalse)
{
    plogger_test_expect(false, NULL);
    plogger_test_given(tkind_ctest_i(NULL));
}

TEST(TkindSm1ZeroInit, IResultsInFalse)
{
    plogger_test_expect(false, NULL);
    plogger_test_given(tkind_ctest_i(&tkind_ctest_obj));
}

TEST(TkindSm1ZeroInit, JNullPtrResultsInFalse)
{
    plogger_test_expect(false, NULL);
    plogger_test_given(tkind_ctest_j(NULL));
}

TEST(TkindSm1ZeroInit, JResultsInFalse)
{
    plogger_test_expect(false, NULL);
    plogger_test_given(tkind_ctest_j(&tkind_ctest_obj));
}

TEST(TkindSm1ZeroInit, KNullPtrResultsInFalse)
{
    plogger_test_expect(false, NULL);
    plogger_test_given(tkind_ctest_k(NULL));
}

TEST(TkindSm1ZeroInit, KResultsInFalse)
{
    plogger_test_expect(false, NULL);
    plogger_test_given(tkind_ctest_k(&tkind_ctest_obj));
}

TEST(TkindSm1ZeroInit, LNullPtrResultsInFalse)
{
    plogger_test_expect(false, NULL);
    plogger_test_given(tkind_ctest_l(NULL));
}

TEST(TkindSm1ZeroInit, LResultsInFalse)
{
    plogger_test_expect(false, NULL);
    plogger_test_given(tkind_ctest_l(&tkind_ctest_obj));
}

TEST(TkindSm1ZeroInit, MNullPtrResultsInFalse)
{
    plogger_test_expect(false, NULL);
    plogger_test_given(tkind_ctest_m(NULL));
}

TEST(TkindSm1ZeroInit, MResultsInFalse)
{
    plogger_test_expect(false, NULL);
    plogger_test_given(tkind_ctest_m(&tkind_ctest_obj));
}

TEST(TkindSm1ZeroInit, NNullPtrResultsInFalse)
{
    plogger_test_expect(false, NULL);
    plogger_test_given(tkind_ctest_n(NULL));
}

TEST(TkindSm1ZeroInit, NResultsInFalse)
{
    plogger_test_expect(false, NULL);
    plogger_test_given(tkind_ctest_n(&tkind_ctest_obj));
}

TEST(TkindSm1ZeroInit, ONullPtrResultsInFalse)
{
    plogger_test_expect(false, NULL);
    plogger_test_given(tkind_ctest_o(NULL));
}

TEST(TkindSm1ZeroInit, OResultsInFalse)
{
    plogger_test_expect(false, NULL);
    plogger_test_given(tkind_ctest_o(&tkind_ctest_obj));
}

TEST(TkindSm1ZeroInit, FetchNullPtrResultsInFalse)
{
    plogger_test_expect(false, NULL);
    plogger_test_given(tkind_ctest_fetch_event(NULL));
}

TEST(TkindSm1ZeroInit, FetchResultsInFalse)
{
    plogger_test_expect(false, NULL);
    plogger_test_given(tkind_ctest_fetch_event(&tkind_ctest_obj));
}

TEST(TkindSm1ZeroInit, DispatchNullPtrResultsInFalse)
{
    plogger_test_expect(false, NULL);
    plogger_test_given(tkind_ctest_dispatch_event(NULL));
}

TEST(TkindSm1ZeroInit, DispatchResultsInFalse)
{
    plogger_test_expect(false, NULL);
    plogger_test_given(tkind_ctest_dispatch_event(&tkind_ctest_obj));
}

TEST(TkindSm1ZeroInit, ReleaseNullPtrResultsInFalse)
{
    plogger_test_expect(false, NULL);
    plogger_test_given(tkind_ctest_release_event(NULL));
}

TEST(TkindSm1ZeroInit, ReleaseResultsInFalse)
{
    plogger_test_expect(false, NULL);
    plogger_test_given(tkind_ctest_release_event(&tkind_ctest_obj));
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
