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
	RUN_TEST_GROUP(TkindLogger);
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
}

int main(int argc, const char* argv[])
{
	return UnityMain(argc, argv, run_all_tests);
}

/*** end of file ***/
