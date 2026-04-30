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
