/**
 * @file all_tests.c
 *
 * @brief The entry point for unit tests for c_expected project code.
 */

#include <unity_fixture.h>

void run_all_tests(void)
{
    RUN_TEST_GROUP(fifo);
    RUN_TEST_GROUP(event_pool);
    RUN_TEST_GROUP(event_pool_single);
    RUN_TEST_GROUP(PloggerTest);
    RUN_TEST_GROUP(Tkindcbase1);
    RUN_TEST_GROUP(Tkindcbase2);
    RUN_TEST_GROUP(Tkindctest);
    RUN_TEST_GROUP(TkindSm1ZeroInit);
    RUN_TEST_GROUP(TkindSm1State2);
    RUN_TEST_GROUP(TkindSm1State3);
    RUN_TEST_GROUP(TkindSm1State4);
    RUN_TEST_GROUP(TkindSm1State5);
    RUN_TEST_GROUP(TkindSm1State6);
    RUN_TEST_GROUP(TkindSm1State7);
    RUN_TEST_GROUP(TkindSm1State9);
    RUN_TEST_GROUP(TkindSm1State11);
    RUN_TEST_GROUP(TkindSm1State12);
    RUN_TEST_GROUP(TkindSm1State5State11);
    RUN_TEST_GROUP(TkindSm1Region1Failure);
    RUN_TEST_GROUP(TkindSm1Region2Failure);
    RUN_TEST_GROUP(TkindSm1Failure);
    RUN_TEST_GROUP(TkindSm1Region3Failure);
    RUN_TEST_GROUP(TkindSm1Region4Failure);
    RUN_TEST_GROUP(TkindSm1Region5Failure);
    RUN_TEST_GROUP(TkindSm1Region6Failure);
    RUN_TEST_GROUP(TkindSm1Region7Failure);
    RUN_TEST_GROUP(TkindSm1Region8Failure);
    RUN_TEST_GROUP(TkindSm1Region9Failure);
    RUN_TEST_GROUP(SafeSmSm1State1);
    RUN_TEST_GROUP(SafeSmSm1State3);
    RUN_TEST_GROUP(SafeSmSm1SafeState);
    RUN_TEST_GROUP(SafeSmSm1Region1Failure);
    RUN_TEST_GROUP(SafeSmSm1Region2Failure);
    RUN_TEST_GROUP(SafeSmSm1Region4Failure);
    RUN_TEST_GROUP(SafeSmSm1Region3Failure);
}

int main(int argc, const char* argv[])
{
    return UnityMain(argc, argv, run_all_tests);
}

/*** end of file ***/
