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
	RUN_TEST_GROUP(Tkind);
	RUN_TEST_GROUP(TkindSm1ZeroInit);
	RUN_TEST_GROUP(TkindSm1State2);
	RUN_TEST_GROUP(TkindSm1State2EventA);
	RUN_TEST_GROUP(TkindSm1State2FetchEventA);
}

int main(int argc, const char* argv[])
{
	return UnityMain(argc, argv, run_all_tests);
}

/*** end of file ***/
