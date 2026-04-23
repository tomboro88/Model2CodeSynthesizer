/*
 * @file Tkind_test_runner.c
 *
 * @brief Source code of the Tkind package test cases.
 * @author tomboro88
 * @date   4 mar 2026
 * @copyright (c) 2026 tomboro88. All rights reserved.
 * @license MIT – see LICENSE file in project root
 * @project github.com/tomboro88/M2T4Embedded
 */

#include <unity_fixture.h>

TEST_GROUP_RUNNER(Tkind)
{
    RUN_TEST_CASE(TkindLogger, record_empty_string);
    RUN_TEST_CASE(TkindLogger, record_nonempty_string);
    RUN_TEST_CASE(TkindLogger, record_multiple_strings);
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

TEST_GROUP_RUNNER(TkindSm1State2)
{
    RUN_TEST_CASE(TkindSm1State2, InitResultsInInitialTransition);
    RUN_TEST_CASE(TkindSm1State2, AReturnsTrue);
    RUN_TEST_CASE(TkindSm1State2, BReturnsTrue);
    RUN_TEST_CASE(TkindSm1State2, CReturnsTrue);
    RUN_TEST_CASE(TkindSm1State2, DReturnsTrue);
    RUN_TEST_CASE(TkindSm1State2, EReturnsTrue);
    RUN_TEST_CASE(TkindSm1State2, FReturnsTrue);
    RUN_TEST_CASE(TkindSm1State2, GReturnsTrue);
    RUN_TEST_CASE(TkindSm1State2, HReturnsTrue);
    RUN_TEST_CASE(TkindSm1State2, IReturnsTrue);
    RUN_TEST_CASE(TkindSm1State2, JReturnsTrue);
    RUN_TEST_CASE(TkindSm1State2, KReturnsTrue);
    RUN_TEST_CASE(TkindSm1State2, LReturnsTrue);
    RUN_TEST_CASE(TkindSm1State2, MReturnsTrue);
    RUN_TEST_CASE(TkindSm1State2, NReturnsTrue);
    RUN_TEST_CASE(TkindSm1State2, OReturnsTrue);
    RUN_TEST_CASE(TkindSm1State2, FetchReturnsFalse);
    RUN_TEST_CASE(TkindSm1State2, DispatchReturnsFalse);
    RUN_TEST_CASE(TkindSm1State2, ReleaseReturnsFalse);
}

TEST_GROUP_RUNNER(TkindSm1State2EventA)
{
    RUN_TEST_CASE(TkindSm1State2EventA, InitResultsInInitialTransition);
    RUN_TEST_CASE(TkindSm1State2EventA, AReturnsTrue);
    RUN_TEST_CASE(TkindSm1State2EventA, BReturnsTrue);
    RUN_TEST_CASE(TkindSm1State2EventA, CReturnsTrue);
    RUN_TEST_CASE(TkindSm1State2EventA, DReturnsTrue);
    RUN_TEST_CASE(TkindSm1State2EventA, EReturnsTrue);
    RUN_TEST_CASE(TkindSm1State2EventA, FReturnsTrue);
    RUN_TEST_CASE(TkindSm1State2EventA, GReturnsTrue);
    RUN_TEST_CASE(TkindSm1State2EventA, HReturnsTrue);
    RUN_TEST_CASE(TkindSm1State2EventA, IReturnsTrue);
    RUN_TEST_CASE(TkindSm1State2EventA, JReturnsTrue);
    RUN_TEST_CASE(TkindSm1State2EventA, KReturnsTrue);
    RUN_TEST_CASE(TkindSm1State2EventA, LReturnsTrue);
    RUN_TEST_CASE(TkindSm1State2EventA, MReturnsTrue);
    RUN_TEST_CASE(TkindSm1State2EventA, NReturnsTrue);
    RUN_TEST_CASE(TkindSm1State2EventA, OReturnsTrue);
    RUN_TEST_CASE(TkindSm1State2EventA, FetchReturnsTrue);
    RUN_TEST_CASE(TkindSm1State2EventA, DispatchReturnsFalse);
    RUN_TEST_CASE(TkindSm1State2EventA, ReleaseReturnsFalse);
}

TEST_GROUP_RUNNER(TkindSm1State2FetchEventA)
{
    RUN_TEST_CASE(TkindSm1State2FetchEventA, InitResultsInInitialTransition);
    RUN_TEST_CASE(TkindSm1State2FetchEventA, AReturnsTrue);
    RUN_TEST_CASE(TkindSm1State2FetchEventA, BReturnsTrue);
    RUN_TEST_CASE(TkindSm1State2FetchEventA, CReturnsTrue);
    RUN_TEST_CASE(TkindSm1State2FetchEventA, DReturnsTrue);
    RUN_TEST_CASE(TkindSm1State2FetchEventA, EReturnsTrue);
    RUN_TEST_CASE(TkindSm1State2FetchEventA, FReturnsTrue);
    RUN_TEST_CASE(TkindSm1State2FetchEventA, GReturnsTrue);
    RUN_TEST_CASE(TkindSm1State2FetchEventA, HReturnsTrue);
    RUN_TEST_CASE(TkindSm1State2FetchEventA, IReturnsTrue);
    RUN_TEST_CASE(TkindSm1State2FetchEventA, JReturnsTrue);
    RUN_TEST_CASE(TkindSm1State2FetchEventA, KReturnsTrue);
    RUN_TEST_CASE(TkindSm1State2FetchEventA, LReturnsTrue);
    RUN_TEST_CASE(TkindSm1State2FetchEventA, MReturnsTrue);
    RUN_TEST_CASE(TkindSm1State2FetchEventA, NReturnsTrue);
    RUN_TEST_CASE(TkindSm1State2FetchEventA, OReturnsTrue);
    RUN_TEST_CASE(TkindSm1State2FetchEventA, FetchReturnsTrue);
    RUN_TEST_CASE(TkindSm1State2FetchEventA, DispatchReturnsTrue);
    RUN_TEST_CASE(TkindSm1State2FetchEventA, ReleaseReturnsFalse);
}
/*** end of file ***/
