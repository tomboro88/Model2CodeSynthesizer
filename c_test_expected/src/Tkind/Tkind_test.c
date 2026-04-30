/*
 * @file Tkind_test.c
 *
 * @brief Source code of the Tkind package test cases.
 * @author tomboro88
 * @date   4 mar 2026
 * @copyright (c) 2026 tomboro88. All rights reserved.
 * @license MIT – see LICENSE file in project root
 * @project github.com/tomboro88/M2T4Embedded
 */

#include <unity_fixture.h>
#include <Tkind.h>
#include <string.h>
#include <stddef.h>

/*******************************************************************************
 *
 * Test helper code
 *
 ******************************************************************************/
#define TEST_LOGGER_BUFFER_SIZE 256u
#define TEST_LOGGER_BUFFER_DATA_POS sizeof(forbidden_pattern)
#define TEST_LOGGER_BUFFER_GUARD2_POS \
                         (TEST_LOGGER_BUFFER_SIZE + TEST_LOGGER_BUFFER_DATA_POS)
#define TEST_LOGGER_BUFFER_FILL '\xA5'

static const char forbidden_pattern[] =
                                       {'\xDE', '\xAD', '\xBE', '\xEF', '\x00'};

static char logger_buffer[TEST_LOGGER_BUFFER_SIZE
                          + (2*sizeof(forbidden_pattern))];

/**
 * @brief Holds the current write pointer to the local test buffer.
 */
static size_t logger_index = 0;

/**
 * @brief The pointer to the string expected in the buffer.
 */
static const char* p_expected_logger = NULL;

/**
 * @brief the expected boolean result of the called function.
 */
static bool b_expected_result = false;

static void test_capture_logger(Tkind_logger_t* const p_obj,
                                                       const char* const p_str);
/**
 * @brief The virtual table for our test logger object.
 */
static const Tkind_logger_vt_t test_logger_funcs =
                                              {.p_record = test_capture_logger};

/**
 * @brief The logger object that will capture the logs from the tested state
 * machines.
 */
static Tkind_logger_t test_logger = {.p_vtable = &test_logger_funcs};

/**
 * @brief The ctest object that is tested.
 */
static Tkind_ctest_t ctest_obj = {0};

/**
 * @brief Initializes the local buffer before capturing state machine logs.
 */
static void
test_init_logger_buffer(void)
{
    memcpy(logger_buffer, forbidden_pattern, sizeof(forbidden_pattern));
    memcpy(&logger_buffer[TEST_LOGGER_BUFFER_SIZE + sizeof(forbidden_pattern)],
           forbidden_pattern, sizeof(forbidden_pattern));
    memset(&logger_buffer[TEST_LOGGER_BUFFER_DATA_POS], TEST_LOGGER_BUFFER_FILL,
           TEST_LOGGER_BUFFER_SIZE);

    logger_index = TEST_LOGGER_BUFFER_DATA_POS;
}

/**
 * @brief The function used to capture the logs from the tested state machines.
 * @param p_obj The pointer to the calling logger object
 * @param p_str The pointer to the captured string
 */
static void
test_capture_logger(Tkind_logger_t* const p_obj, const char* const p_str)
{
    TEST_ASSERT_NOT_NULL(p_obj);
    TEST_ASSERT_NOT_NULL(p_str);
    size_t src_len = strlen(p_str);

    if((logger_index + src_len) < TEST_LOGGER_BUFFER_GUARD2_POS)
    {
        strcpy(&logger_buffer[logger_index], p_str);
        logger_index += src_len;
    }
    else
    {
        UnityPrint("Trying to log a string: ");
        UnityPrint(p_str);
        UNITY_PRINT_EOL();
        TEST_FAIL_MESSAGE("Captured string doesnt' fit into the buffer");
    }
}

void
test_assert_logger(void)
{
    TEST_ASSERT_EQUAL_MEMORY(forbidden_pattern, logger_buffer,
                                                     sizeof(forbidden_pattern));
    if(NULL != p_expected_logger)
    {
        TEST_ASSERT_EQUAL_STRING(p_expected_logger,
                                   &logger_buffer[TEST_LOGGER_BUFFER_DATA_POS]);

        if((TEST_LOGGER_BUFFER_GUARD2_POS-logger_index-1) > 0)
        {
            TEST_ASSERT_EACH_EQUAL_HEX8(TEST_LOGGER_BUFFER_FILL,
                                  &logger_buffer[logger_index+1],
                                  TEST_LOGGER_BUFFER_GUARD2_POS-logger_index-1);
        }
    }
    else
    {
        TEST_ASSERT_EACH_EQUAL_HEX8(TEST_LOGGER_BUFFER_FILL,
                                    &logger_buffer[TEST_LOGGER_BUFFER_DATA_POS],
                                    TEST_LOGGER_BUFFER_SIZE);
    }

    TEST_ASSERT_EQUAL_MEMORY(forbidden_pattern,
                             &logger_buffer[TEST_LOGGER_BUFFER_GUARD2_POS],
                                                     sizeof(forbidden_pattern));
}

void
ctest_logger_expect(bool const b_is_result_ok, const char* const p_str)
{
    p_expected_logger = p_str;
    b_expected_result = b_is_result_ok;
}

void
ctest_logger_given(bool const b_is_result_ok)
{
    if(b_expected_result)
    {
        TEST_ASSERT_TRUE(b_is_result_ok);
    }
    else
    {
        TEST_ASSERT_FALSE(b_is_result_ok);
    }

    test_assert_logger();
}
/*******************************************************************************
 *
 * Test group TkindLogger.
 *
 ******************************************************************************/

TEST_GROUP(TkindLogger);

TEST_SETUP(TkindLogger)
{
    test_init_logger_buffer();
    p_expected_logger = NULL;
}

TEST_TEAR_DOWN(TkindLogger)
{

}

/*================================TEST_CASES==================================*/
TEST(TkindLogger, record_empty_string)
{
    ctest_logger_expect(true, "");
    Tkind_logger_record(&test_logger, "");
    ctest_logger_given(true);
}

TEST(TkindLogger, record_nonempty_string)
{
    ctest_logger_expect(true, "abc");
    Tkind_logger_record(&test_logger, "abc");
    ctest_logger_given(true);
}

TEST(TkindLogger, record_multiple_strings)
{
    ctest_logger_expect(true, "abcdefghi");
    Tkind_logger_record(&test_logger, "abc");
    Tkind_logger_record(&test_logger, "def");
    Tkind_logger_record(&test_logger, "ghi");
    ctest_logger_given(true);
}

/*******************************************************************************
 *
 * Test group TkindSm1ZeroInit - checks the behavior of all functions on an
 * object initialized with zeros.
 *
 ******************************************************************************/
TEST_GROUP(TkindSm1ZeroInit);

TEST_SETUP(TkindSm1ZeroInit)
{
    test_init_logger_buffer();
    p_expected_logger = NULL;
    ctest_obj = (Tkind_ctest_t) {0};
}

TEST_TEAR_DOWN(TkindSm1ZeroInit)
{

}

/*================================TEST_CASES==================================*/
TEST(TkindSm1ZeroInit, InitNullArgsGiveFalse)
{
    ctest_logger_expect(false, NULL);
    ctest_logger_given(Tkind_ctest_init(NULL, NULL));
}

TEST(TkindSm1ZeroInit, InitNullPtrGivesFalse)
{
    ctest_logger_expect(false, NULL);
    ctest_logger_given(Tkind_ctest_init(NULL, &test_logger));
}

TEST(TkindSm1ZeroInit, InitNullLoggerGivesTrue)
{
    ctest_logger_expect(true, NULL);
    ctest_logger_given(Tkind_ctest_init(&ctest_obj, NULL));
}

TEST(TkindSm1ZeroInit, InitResultsInInitialTransition)
{
    ctest_logger_expect(true, "Initial1 to State1\n"
                              "Enter State1\n"
                              "Initial3 to State2\n"
                              "Enter State2\n");
    ctest_logger_given(Tkind_ctest_init(&ctest_obj, &test_logger));
}

TEST(TkindSm1ZeroInit, ANullPtrResultsInFalse)
{
    ctest_logger_expect(false, NULL);
    ctest_logger_given(Tkind_ctest_a(NULL));
}

TEST(TkindSm1ZeroInit, AResultsInFalse)
{
    ctest_logger_expect(false, NULL);
    ctest_logger_given(Tkind_ctest_a(&ctest_obj));
}

TEST(TkindSm1ZeroInit, BNullPtrResultsInFalse)
{
    ctest_logger_expect(false, NULL);
    ctest_logger_given(Tkind_ctest_b(NULL));
}

TEST(TkindSm1ZeroInit, BResultsInFalse)
{
    ctest_logger_expect(false, NULL);
    ctest_logger_given(Tkind_ctest_b(&ctest_obj));
}

TEST(TkindSm1ZeroInit, CNullPtrResultsInFalse)
{
    ctest_logger_expect(false, NULL);
    ctest_logger_given(Tkind_ctest_c(NULL));
}

TEST(TkindSm1ZeroInit, CResultsInFalse)
{
    ctest_logger_expect(false, NULL);
    ctest_logger_given(Tkind_ctest_c(&ctest_obj));
}

TEST(TkindSm1ZeroInit, DNullPtrResultsInFalse)
{
    ctest_logger_expect(false, NULL);
    ctest_logger_given(Tkind_ctest_d(NULL));
}

TEST(TkindSm1ZeroInit, DResultsInFalse)
{
    ctest_logger_expect(false, NULL);
    ctest_logger_given(Tkind_ctest_d(&ctest_obj));
}

TEST(TkindSm1ZeroInit, ENullPtrResultsInFalse)
{
    ctest_logger_expect(false, NULL);
    ctest_logger_given(Tkind_ctest_e(NULL));
}

TEST(TkindSm1ZeroInit, EResultsInFalse)
{
    ctest_logger_expect(false, NULL);
    ctest_logger_given(Tkind_ctest_e(&ctest_obj));
}

TEST(TkindSm1ZeroInit, FNullPtrResultsInFalse)
{
    ctest_logger_expect(false, NULL);
    ctest_logger_given(Tkind_ctest_f(NULL));
}

TEST(TkindSm1ZeroInit, FResultsInFalse)
{
    ctest_logger_expect(false, NULL);
    ctest_logger_given(Tkind_ctest_f(&ctest_obj));
}

TEST(TkindSm1ZeroInit, GNullPtrResultsInFalse)
{
    ctest_logger_expect(false, NULL);
    ctest_logger_given(Tkind_ctest_g(NULL));
}

TEST(TkindSm1ZeroInit, GResultsInFalse)
{
    ctest_logger_expect(false, NULL);
    ctest_logger_given(Tkind_ctest_g(&ctest_obj));
}

TEST(TkindSm1ZeroInit, HNullPtrResultsInFalse)
{
    ctest_logger_expect(false, NULL);
    ctest_logger_given(Tkind_ctest_h(NULL));
}

TEST(TkindSm1ZeroInit, HResultsInFalse)
{
    ctest_logger_expect(false, NULL);
    ctest_logger_given(Tkind_ctest_h(&ctest_obj));
}

TEST(TkindSm1ZeroInit, INullPtrResultsInFalse)
{
    ctest_logger_expect(false, NULL);
    ctest_logger_given(Tkind_ctest_i(NULL));
}

TEST(TkindSm1ZeroInit, IResultsInFalse)
{
    ctest_logger_expect(false, NULL);
    ctest_logger_given(Tkind_ctest_i(&ctest_obj));
}

TEST(TkindSm1ZeroInit, JNullPtrResultsInFalse)
{
    ctest_logger_expect(false, NULL);
    ctest_logger_given(Tkind_ctest_j(NULL));
}

TEST(TkindSm1ZeroInit, JResultsInFalse)
{
    ctest_logger_expect(false, NULL);
    ctest_logger_given(Tkind_ctest_j(&ctest_obj));
}

TEST(TkindSm1ZeroInit, KNullPtrResultsInFalse)
{
    ctest_logger_expect(false, NULL);
    ctest_logger_given(Tkind_ctest_k(NULL));
}

TEST(TkindSm1ZeroInit, KResultsInFalse)
{
    ctest_logger_expect(false, NULL);
    ctest_logger_given(Tkind_ctest_k(&ctest_obj));
}

TEST(TkindSm1ZeroInit, LNullPtrResultsInFalse)
{
    ctest_logger_expect(false, NULL);
    ctest_logger_given(Tkind_ctest_l(NULL));
}

TEST(TkindSm1ZeroInit, LResultsInFalse)
{
    ctest_logger_expect(false, NULL);
    ctest_logger_given(Tkind_ctest_l(&ctest_obj));
}

TEST(TkindSm1ZeroInit, MNullPtrResultsInFalse)
{
    ctest_logger_expect(false, NULL);
    ctest_logger_given(Tkind_ctest_m(NULL));
}

TEST(TkindSm1ZeroInit, MResultsInFalse)
{
    ctest_logger_expect(false, NULL);
    ctest_logger_given(Tkind_ctest_m(&ctest_obj));
}

TEST(TkindSm1ZeroInit, NNullPtrResultsInFalse)
{
    ctest_logger_expect(false, NULL);
    ctest_logger_given(Tkind_ctest_n(NULL));
}

TEST(TkindSm1ZeroInit, NResultsInFalse)
{
    ctest_logger_expect(false, NULL);
    ctest_logger_given(Tkind_ctest_n(&ctest_obj));
}

TEST(TkindSm1ZeroInit, ONullPtrResultsInFalse)
{
    ctest_logger_expect(false, NULL);
    ctest_logger_given(Tkind_ctest_o(NULL));
}

TEST(TkindSm1ZeroInit, OResultsInFalse)
{
    ctest_logger_expect(false, NULL);
    ctest_logger_given(Tkind_ctest_o(&ctest_obj));
}

TEST(TkindSm1ZeroInit, FetchNullPtrResultsInFalse)
{
    ctest_logger_expect(false, NULL);
    ctest_logger_given(Tkind_ctest_fetch_event(NULL));
}

TEST(TkindSm1ZeroInit, FetchResultsInFalse)
{
    ctest_logger_expect(false, NULL);
    ctest_logger_given(Tkind_ctest_fetch_event(&ctest_obj));
}

TEST(TkindSm1ZeroInit, DispatchNullPtrResultsInFalse)
{
    ctest_logger_expect(false, NULL);
    ctest_logger_given(Tkind_ctest_dispatch_event(NULL));
}

TEST(TkindSm1ZeroInit, DispatchResultsInFalse)
{
    ctest_logger_expect(false, NULL);
    ctest_logger_given(Tkind_ctest_dispatch_event(&ctest_obj));
}

TEST(TkindSm1ZeroInit, ReleaseNullPtrResultsInFalse)
{
    ctest_logger_expect(false, NULL);
    ctest_logger_given(Tkind_ctest_release_event(NULL));
}

TEST(TkindSm1ZeroInit, ReleaseResultsInFalse)
{
    ctest_logger_expect(false, NULL);
    ctest_logger_given(Tkind_ctest_release_event(&ctest_obj));
}

/*******************************************************************************
 *
 * Test group TkindSm1State2.
 *
 ******************************************************************************/
TEST_GROUP(TkindSm1State2);

TEST_SETUP(TkindSm1State2)
{
    p_expected_logger = NULL;
    test_init_logger_buffer();
    Tkind_ctest_init(&ctest_obj, &test_logger);
    test_init_logger_buffer();
}

TEST_TEAR_DOWN(TkindSm1State2)
{

}
/*================================TEST_CASES==================================*/
TEST(TkindSm1State2, InitResultsInInitialTransition)
{
    ctest_logger_expect(true, "Initial1 to State1\n"
                              "Enter State1\n"
                              "Initial3 to State2\n"
                              "Enter State2\n");
    ctest_logger_given(Tkind_ctest_init(&ctest_obj, &test_logger));
}

TEST(TkindSm1State2, AReturnsTrue)
{
    ctest_logger_expect(true, NULL);
    ctest_logger_given(Tkind_ctest_a(&ctest_obj));
}

TEST(TkindSm1State2, FetchAReturnsTrue)
{
    ctest_logger_expect(true, NULL);
    ctest_logger_given(Tkind_ctest_a(&ctest_obj)
                       && Tkind_ctest_fetch_event(&ctest_obj));
}

TEST(TkindSm1State2, DispatchAReturnsTrue)
{
    ctest_logger_expect(true, "Exit State2\n"
                              "State2 to State3\n"
                              "Enter State3\n");
    ctest_logger_given(Tkind_ctest_a(&ctest_obj)
                       && Tkind_ctest_fetch_event(&ctest_obj)
                       && Tkind_ctest_dispatch_event(&ctest_obj));
}

TEST(TkindSm1State2, ReleaseAReturnsTrue)
{
    ctest_logger_expect(true, "Exit State2\n"
                              "State2 to State3\n"
                              "Enter State3\n");
    ctest_logger_given(Tkind_ctest_a(&ctest_obj)
                       && Tkind_ctest_fetch_event(&ctest_obj)
                       && Tkind_ctest_dispatch_event(&ctest_obj)
                       && Tkind_ctest_release_event(&ctest_obj));
}

TEST(TkindSm1State2, BReturnsTrue)
{
    ctest_logger_expect(true, NULL);
    ctest_logger_given(Tkind_ctest_b(&ctest_obj));
}

TEST(TkindSm1State2, FetchBReturnsTrue)
{
    ctest_logger_expect(true, NULL);
    ctest_logger_given(Tkind_ctest_b(&ctest_obj)
                       && Tkind_ctest_fetch_event(&ctest_obj));
}

TEST(TkindSm1State2, DispatchBReturnsTrue)
{
    ctest_logger_expect(true, "Exit State2\n"
                              "State2 to State4\n"
                              "Enter State4\n");
    ctest_logger_given(Tkind_ctest_b(&ctest_obj)
                       && Tkind_ctest_fetch_event(&ctest_obj)
                       && Tkind_ctest_dispatch_event(&ctest_obj));
}

TEST(TkindSm1State2, ReleaseBReturnsTrue)
{
    ctest_logger_expect(true, "Exit State2\n"
                              "State2 to State4\n"
                              "Enter State4\n");
    ctest_logger_given(Tkind_ctest_b(&ctest_obj)
                       && Tkind_ctest_fetch_event(&ctest_obj)
                       && Tkind_ctest_dispatch_event(&ctest_obj)
                       && Tkind_ctest_release_event(&ctest_obj));
}

TEST(TkindSm1State2, CReturnsTrue)
{
    ctest_logger_expect(true, NULL);
    ctest_logger_given(Tkind_ctest_c(&ctest_obj));
}

TEST(TkindSm1State2, FetchCReturnsTrue)
{
    ctest_logger_expect(true, NULL);
    ctest_logger_given(Tkind_ctest_c(&ctest_obj)
                       && Tkind_ctest_fetch_event(&ctest_obj));
}

TEST(TkindSm1State2, DispatchCReturnsTrue)
{
    ctest_logger_expect(true, NULL);
    ctest_logger_given(Tkind_ctest_c(&ctest_obj)
                       && Tkind_ctest_fetch_event(&ctest_obj)
                       && Tkind_ctest_dispatch_event(&ctest_obj));
}

TEST(TkindSm1State2, ReleaseCReturnsTrue)
{
    ctest_logger_expect(true, NULL);
    ctest_logger_given(Tkind_ctest_c(&ctest_obj)
                       && Tkind_ctest_fetch_event(&ctest_obj)
                       && Tkind_ctest_dispatch_event(&ctest_obj)
                       && Tkind_ctest_release_event(&ctest_obj));
}

TEST(TkindSm1State2, DReturnsTrue)
{
    ctest_logger_expect(true, NULL);
    ctest_logger_given(Tkind_ctest_d(&ctest_obj));
}

TEST(TkindSm1State2, FetchDReturnsTrue)
{
    ctest_logger_expect(true, NULL);
    ctest_logger_given(Tkind_ctest_d(&ctest_obj)
                       && Tkind_ctest_fetch_event(&ctest_obj));
}

TEST(TkindSm1State2, DispatchDReturnsTrue)
{
    ctest_logger_expect(true, NULL);
    ctest_logger_given(Tkind_ctest_d(&ctest_obj)
                       && Tkind_ctest_fetch_event(&ctest_obj)
                       && Tkind_ctest_dispatch_event(&ctest_obj));
}

TEST(TkindSm1State2, ReleaseDReturnsTrue)
{
    ctest_logger_expect(true, NULL);
    ctest_logger_given(Tkind_ctest_d(&ctest_obj)
                       && Tkind_ctest_fetch_event(&ctest_obj)
                       && Tkind_ctest_dispatch_event(&ctest_obj)
                       && Tkind_ctest_release_event(&ctest_obj));
}

TEST(TkindSm1State2, EReturnsTrue)
{
    ctest_logger_expect(true, NULL);
    ctest_logger_given(Tkind_ctest_e(&ctest_obj));
}

TEST(TkindSm1State2, FetchEReturnsTrue)
{
    ctest_logger_expect(true, NULL);
    ctest_logger_given(Tkind_ctest_e(&ctest_obj)
                       && Tkind_ctest_fetch_event(&ctest_obj));
}

TEST(TkindSm1State2, DispatchEReturnsTrue)
{
    ctest_logger_expect(true, NULL);
    ctest_logger_given(Tkind_ctest_e(&ctest_obj)
                       && Tkind_ctest_fetch_event(&ctest_obj)
                       && Tkind_ctest_dispatch_event(&ctest_obj));
}

TEST(TkindSm1State2, ReleaseEReturnsTrue)
{
    ctest_logger_expect(true, NULL);
    ctest_logger_given(Tkind_ctest_e(&ctest_obj)
                       && Tkind_ctest_fetch_event(&ctest_obj)
                       && Tkind_ctest_dispatch_event(&ctest_obj)
                       && Tkind_ctest_release_event(&ctest_obj));
}

TEST(TkindSm1State2, FReturnsTrue)
{
    ctest_logger_expect(true, NULL);
    ctest_logger_given(Tkind_ctest_f(&ctest_obj));
}

TEST(TkindSm1State2, FetchFReturnsTrue)
{
    ctest_logger_expect(true, NULL);
    ctest_logger_given(Tkind_ctest_f(&ctest_obj)
                       && Tkind_ctest_fetch_event(&ctest_obj));
}

TEST(TkindSm1State2, DispatchFReturnsTrue)
{
    ctest_logger_expect(true, NULL);
    ctest_logger_given(Tkind_ctest_f(&ctest_obj)
                       && Tkind_ctest_fetch_event(&ctest_obj)
                       && Tkind_ctest_dispatch_event(&ctest_obj));
}

TEST(TkindSm1State2, ReleaseFReturnsTrue)
{
    ctest_logger_expect(true, NULL);
    ctest_logger_given(Tkind_ctest_f(&ctest_obj)
                       && Tkind_ctest_fetch_event(&ctest_obj)
                       && Tkind_ctest_dispatch_event(&ctest_obj)
                       && Tkind_ctest_release_event(&ctest_obj));
}

TEST(TkindSm1State2, GReturnsTrue)
{
    ctest_logger_expect(true, NULL);
    ctest_logger_given(Tkind_ctest_g(&ctest_obj));
}

TEST(TkindSm1State2, FetchGReturnsTrue)
{
    ctest_logger_expect(true, NULL);
    ctest_logger_given(Tkind_ctest_g(&ctest_obj)
                       && Tkind_ctest_fetch_event(&ctest_obj));
}

TEST(TkindSm1State2, DispatchGReturnsTrue)
{
    ctest_logger_expect(true, NULL);
    ctest_logger_given(Tkind_ctest_g(&ctest_obj)
                       && Tkind_ctest_fetch_event(&ctest_obj)
                       && Tkind_ctest_dispatch_event(&ctest_obj));
}

TEST(TkindSm1State2, ReleaseGReturnsTrue)
{
    ctest_logger_expect(true, NULL);
    ctest_logger_given(Tkind_ctest_g(&ctest_obj)
                       && Tkind_ctest_fetch_event(&ctest_obj)
                       && Tkind_ctest_dispatch_event(&ctest_obj)
                       && Tkind_ctest_release_event(&ctest_obj));
}

TEST(TkindSm1State2, HReturnsTrue)
{
    ctest_logger_expect(true, NULL);
    ctest_logger_given(Tkind_ctest_h(&ctest_obj));
}

TEST(TkindSm1State2, FetchHReturnsTrue)
{
    ctest_logger_expect(true, NULL);
    ctest_logger_given(Tkind_ctest_h(&ctest_obj)
                       && Tkind_ctest_fetch_event(&ctest_obj));
}

TEST(TkindSm1State2, DispatchHReturnsTrue)
{
    ctest_logger_expect(true, NULL);
    ctest_logger_given(Tkind_ctest_h(&ctest_obj)
                       && Tkind_ctest_fetch_event(&ctest_obj)
                       && Tkind_ctest_dispatch_event(&ctest_obj));
}

TEST(TkindSm1State2, ReleaseHReturnsTrue)
{
    ctest_logger_expect(true, NULL);
    ctest_logger_given(Tkind_ctest_h(&ctest_obj)
                       && Tkind_ctest_fetch_event(&ctest_obj)
                       && Tkind_ctest_dispatch_event(&ctest_obj)
                       && Tkind_ctest_release_event(&ctest_obj));
}

TEST(TkindSm1State2, IReturnsTrue)
{
    ctest_logger_expect(true, NULL);
    ctest_logger_given(Tkind_ctest_i(&ctest_obj));
}

TEST(TkindSm1State2, FetchIReturnsTrue)
{
    ctest_logger_expect(true, NULL);
    ctest_logger_given(Tkind_ctest_i(&ctest_obj)
                       && Tkind_ctest_fetch_event(&ctest_obj));
}

TEST(TkindSm1State2, DispatchIReturnsTrue)
{
    ctest_logger_expect(true, "Exit State2\n"
    		                  "Exit State1\n"
    		                  "State1 to State7\n"
    		                  "Enter State1\n"
                              "Enter State7\n"
    		                  "Initial3 to State2\n"
    		                  "Enter State2\n");
    ctest_logger_given(Tkind_ctest_i(&ctest_obj)
                       && Tkind_ctest_fetch_event(&ctest_obj)
                       && Tkind_ctest_dispatch_event(&ctest_obj));
}

TEST(TkindSm1State2, ReleaseIReturnsTrue)
{
    ctest_logger_expect(true, "Exit State2\n"
                              "Exit State1\n"
                              "State1 to State7\n"
                              "Enter State1\n"
                              "Enter State7\n"
                              "Initial3 to State2\n"
                              "Enter State2\n");
    ctest_logger_given(Tkind_ctest_i(&ctest_obj)
                       && Tkind_ctest_fetch_event(&ctest_obj)
                       && Tkind_ctest_dispatch_event(&ctest_obj)
                       && Tkind_ctest_release_event(&ctest_obj));
}

TEST(TkindSm1State2, JReturnsTrue)
{
    ctest_logger_expect(true, NULL);
    ctest_logger_given(Tkind_ctest_j(&ctest_obj));
}

TEST(TkindSm1State2, FetchJReturnsTrue)
{
    ctest_logger_expect(true, NULL);
    ctest_logger_given(Tkind_ctest_j(&ctest_obj)
                       && Tkind_ctest_fetch_event(&ctest_obj));
}

TEST(TkindSm1State2, DispatchJReturnsTrue)
{
    ctest_logger_expect(true, NULL);
    ctest_logger_given(Tkind_ctest_j(&ctest_obj)
                       && Tkind_ctest_fetch_event(&ctest_obj)
                       && Tkind_ctest_dispatch_event(&ctest_obj));
}

TEST(TkindSm1State2, ReleaseJReturnsTrue)
{
    ctest_logger_expect(true, NULL);
    ctest_logger_given(Tkind_ctest_j(&ctest_obj)
                       && Tkind_ctest_fetch_event(&ctest_obj)
                       && Tkind_ctest_dispatch_event(&ctest_obj)
					   && Tkind_ctest_release_event(&ctest_obj));
}

TEST(TkindSm1State2, KReturnsTrue)
{
    ctest_logger_expect(true, NULL);
    ctest_logger_given(Tkind_ctest_k(&ctest_obj));
}

TEST(TkindSm1State2, FetchKReturnsTrue)
{
    ctest_logger_expect(true, NULL);
    ctest_logger_given(Tkind_ctest_k(&ctest_obj)
                       && Tkind_ctest_fetch_event(&ctest_obj));
}

TEST(TkindSm1State2, DispatchKReturnsTrue)
{
    ctest_logger_expect(true, NULL);
    ctest_logger_given(Tkind_ctest_k(&ctest_obj)
                       && Tkind_ctest_fetch_event(&ctest_obj)
                       && Tkind_ctest_dispatch_event(&ctest_obj));
}

TEST(TkindSm1State2, ReleaseKReturnsTrue)
{
    ctest_logger_expect(true, NULL);
    ctest_logger_given(Tkind_ctest_k(&ctest_obj)
                       && Tkind_ctest_fetch_event(&ctest_obj)
                       && Tkind_ctest_dispatch_event(&ctest_obj)
                       && Tkind_ctest_release_event(&ctest_obj));
}

TEST(TkindSm1State2, LReturnsTrue)
{
    ctest_logger_expect(true, NULL);
    ctest_logger_given(Tkind_ctest_l(&ctest_obj));
}

TEST(TkindSm1State2, FetchLReturnsTrue)
{
    ctest_logger_expect(true, NULL);
    ctest_logger_given(Tkind_ctest_l(&ctest_obj)
                       && Tkind_ctest_fetch_event(&ctest_obj));
}

TEST(TkindSm1State2, DispatchLReturnsTrue)
{
    ctest_logger_expect(true, NULL);
    ctest_logger_given(Tkind_ctest_l(&ctest_obj)
                       && Tkind_ctest_fetch_event(&ctest_obj)
                       && Tkind_ctest_dispatch_event(&ctest_obj));
}

TEST(TkindSm1State2, MReturnsTrue)
{
    ctest_logger_expect(true, NULL);
    ctest_logger_given(Tkind_ctest_m(&ctest_obj));
}

TEST(TkindSm1State2, FetchMReturnsTrue)
{
    ctest_logger_expect(true, NULL);
    ctest_logger_given(Tkind_ctest_m(&ctest_obj)
                       && Tkind_ctest_fetch_event(&ctest_obj));
}

TEST(TkindSm1State2, DispatchMReturnsTrue)
{
    ctest_logger_expect(true, NULL);
    ctest_logger_given(Tkind_ctest_m(&ctest_obj)
                       && Tkind_ctest_fetch_event(&ctest_obj)
                       && Tkind_ctest_dispatch_event(&ctest_obj));
}

TEST(TkindSm1State2, ReleaseMReturnsTrue)
{
    ctest_logger_expect(true, NULL);
    ctest_logger_given(Tkind_ctest_m(&ctest_obj)
                       && Tkind_ctest_fetch_event(&ctest_obj)
                       && Tkind_ctest_dispatch_event(&ctest_obj)
                       && Tkind_ctest_release_event(&ctest_obj));
}

TEST(TkindSm1State2, NReturnsTrue)
{
    ctest_logger_expect(true, NULL);
    ctest_logger_given(Tkind_ctest_n(&ctest_obj));
}

TEST(TkindSm1State2, FetchNReturnsTrue)
{
    ctest_logger_expect(true, NULL);
    ctest_logger_given(Tkind_ctest_n(&ctest_obj)
                       && Tkind_ctest_fetch_event(&ctest_obj));
}

TEST(TkindSm1State2, DispatchNReturnsTrue)
{
    ctest_logger_expect(true, NULL);
    ctest_logger_given(Tkind_ctest_n(&ctest_obj)
                       && Tkind_ctest_fetch_event(&ctest_obj)
                       && Tkind_ctest_dispatch_event(&ctest_obj));
}

TEST(TkindSm1State2, ReleaseNReturnsTrue)
{
    ctest_logger_expect(true, NULL);
    ctest_logger_given(Tkind_ctest_n(&ctest_obj)
                       && Tkind_ctest_fetch_event(&ctest_obj)
                       && Tkind_ctest_dispatch_event(&ctest_obj)
                       && Tkind_ctest_release_event(&ctest_obj));
}

TEST(TkindSm1State2, OReturnsTrue)
{
    ctest_logger_expect(true, NULL);
    ctest_logger_given(Tkind_ctest_o(&ctest_obj));
}

TEST(TkindSm1State2, FetchOWithFalseChoice1ReturnsTrue)
{
    ctest_logger_expect(true, NULL);
    ctest_obj.sm1.b_test_condition = false;
    ctest_logger_given(Tkind_ctest_o(&ctest_obj)
                       && Tkind_ctest_fetch_event(&ctest_obj));
}

TEST(TkindSm1State2, DispatchOWithFalseChoice1ReturnsTrue)
{
    ctest_logger_expect(true, "Exit State2\n"
    		                  "Exit State1\n"
                              "State1 to Choice1\n"
                              "Enter State1\n"
                              "Choice1 to State1\n"
    		                  "Initial3 to State2\n"
                              "Enter State2\n");
    ctest_obj.sm1.b_test_condition = false;
    ctest_logger_given(Tkind_ctest_o(&ctest_obj)
                       && Tkind_ctest_fetch_event(&ctest_obj)
                       && Tkind_ctest_dispatch_event(&ctest_obj));
}

TEST(TkindSm1State2, ReleaseOWithFalseChoice1ReturnsTrue)
{
    ctest_logger_expect(true, "Exit State2\n"
                              "Exit State1\n"
                              "State1 to Choice1\n"
                              "Enter State1\n"
                              "Choice1 to State1\n"
                              "Initial3 to State2\n"
                              "Enter State2\n");
    ctest_obj.sm1.b_test_condition = false;
    ctest_logger_given(Tkind_ctest_o(&ctest_obj)
                       && Tkind_ctest_fetch_event(&ctest_obj)
                       && Tkind_ctest_dispatch_event(&ctest_obj)
                       && Tkind_ctest_release_event(&ctest_obj));
}

TEST(TkindSm1State2, FetchOWithTrueChoice1ReturnsTrue)
{
    ctest_logger_expect(true, NULL);
    ctest_obj.sm1.b_test_condition = true;
    ctest_logger_given(Tkind_ctest_o(&ctest_obj)
                       && Tkind_ctest_fetch_event(&ctest_obj));
}

TEST(TkindSm1State2, DispatchOWithTrueChoice1ReturnsTrue)
{
    ctest_logger_expect(true, "Exit State2\n"
                              "Exit State1\n"
                              "State1 to Choice1\n"
                              "Enter State1\n"
                              "Choice1 to State8\n"
                              "Enter State8\n"
                              "Enter State9\n"
                              "Initial3 to State2\n"
                              "Enter State2\n");
    ctest_obj.sm1.b_test_condition = true;
    ctest_logger_given(Tkind_ctest_o(&ctest_obj)
                       && Tkind_ctest_fetch_event(&ctest_obj)
                       && Tkind_ctest_dispatch_event(&ctest_obj));
}

TEST(TkindSm1State2, ReleaseOWithTrueChoice1ReturnsTrue)
{
    ctest_logger_expect(true, "Exit State2\n"
                              "Exit State1\n"
                              "State1 to Choice1\n"
                              "Enter State1\n"
                              "Choice1 to State8\n"
                              "Enter State8\n"
                              "Enter State9\n"
                              "Initial3 to State2\n"
                              "Enter State2\n");
    ctest_obj.sm1.b_test_condition = true;
    ctest_logger_given(Tkind_ctest_o(&ctest_obj)
                       && Tkind_ctest_fetch_event(&ctest_obj)
                       && Tkind_ctest_dispatch_event(&ctest_obj)
                       && Tkind_ctest_release_event(&ctest_obj));
}

TEST(TkindSm1State2, FetchReturnsFalse)
{
    ctest_logger_expect(false, NULL);
    ctest_logger_given(Tkind_ctest_fetch_event(&ctest_obj));
}

TEST(TkindSm1State2, DispatchReturnsFalse)
{
    ctest_logger_expect(false, NULL);
    ctest_logger_given(Tkind_ctest_dispatch_event(&ctest_obj));
}

TEST(TkindSm1State2, ReleaseReturnsFalse)
{
    ctest_logger_expect(false, NULL);
    ctest_logger_given(Tkind_ctest_release_event(&ctest_obj));
}

/*******************************************************************************
 *
 * Test group TkindSm1State3.
 *
 ******************************************************************************/
static void test_enter_state3(void)
{
    test_init_logger_buffer();
    Tkind_ctest_init(&ctest_obj, &test_logger);

    Tkind_ctest_a(&ctest_obj);
    Tkind_ctest_fetch_event(&ctest_obj);
    Tkind_ctest_dispatch_event(&ctest_obj);
    Tkind_ctest_release_event(&ctest_obj);
}

TEST_GROUP(TkindSm1State3);

TEST_SETUP(TkindSm1State3)
{
    p_expected_logger = NULL;
    test_enter_state3();
    test_init_logger_buffer();
}

TEST_TEAR_DOWN(TkindSm1State3)
{

}

/*================================TEST_CASES==================================*/
TEST(TkindSm1State3, InitResultsInInitialTransition)
{
    ctest_logger_expect(true, "Initial1 to State1\n"
                              "Enter State1\n"
                              "Initial3 to State2\n"
                              "Enter State2\n");
    ctest_logger_given(Tkind_ctest_init(&ctest_obj, &test_logger));
}

TEST(TkindSm1State3, AReturnsTrue)
{
    ctest_logger_expect(true, NULL);
    ctest_logger_given(Tkind_ctest_a(&ctest_obj));
}

TEST(TkindSm1State3, FetchAReturnsTrue)
{
    ctest_logger_expect(true, NULL);
    ctest_logger_given(Tkind_ctest_a(&ctest_obj)
                       && Tkind_ctest_fetch_event(&ctest_obj));
}

TEST(TkindSm1State3, DispatchAReturnsTrue)
{
    ctest_logger_expect(true, NULL);
    ctest_logger_given(Tkind_ctest_a(&ctest_obj)
                       && Tkind_ctest_fetch_event(&ctest_obj)
                       && Tkind_ctest_dispatch_event(&ctest_obj));
}

TEST(TkindSm1State3, ReleaseAReturnsTrue)
{
    ctest_logger_expect(true, NULL);
    ctest_logger_given(Tkind_ctest_a(&ctest_obj)
                       && Tkind_ctest_fetch_event(&ctest_obj)
                       && Tkind_ctest_dispatch_event(&ctest_obj)
                       && Tkind_ctest_release_event(&ctest_obj));
}

TEST(TkindSm1State3, BReturnsTrue)
{
    ctest_logger_expect(true, NULL);
    ctest_logger_given(Tkind_ctest_b(&ctest_obj));
}

TEST(TkindSm1State3, FetchBReturnsTrue)
{
    ctest_logger_expect(true, NULL);
    ctest_logger_given(Tkind_ctest_b(&ctest_obj)
                       && Tkind_ctest_fetch_event(&ctest_obj));
}

TEST(TkindSm1State3, DispatchBReturnsTrue)
{
    ctest_logger_expect(true, NULL);
    ctest_logger_given(Tkind_ctest_b(&ctest_obj)
                       && Tkind_ctest_fetch_event(&ctest_obj)
                       && Tkind_ctest_dispatch_event(&ctest_obj));
}

TEST(TkindSm1State3, ReleaseBReturnsTrue)
{
    ctest_logger_expect(true, NULL);
    ctest_logger_given(Tkind_ctest_b(&ctest_obj)
                       && Tkind_ctest_fetch_event(&ctest_obj)
                       && Tkind_ctest_dispatch_event(&ctest_obj)
                       && Tkind_ctest_release_event(&ctest_obj));
}

TEST(TkindSm1State3, CReturnsTrue)
{
    ctest_logger_expect(true, NULL);
    ctest_logger_given(Tkind_ctest_c(&ctest_obj));
}

TEST(TkindSm1State3, FetchCReturnsTrue)
{
    ctest_logger_expect(true, NULL);
    ctest_logger_given(Tkind_ctest_c(&ctest_obj)
                       && Tkind_ctest_fetch_event(&ctest_obj));
}

TEST(TkindSm1State3, DispatchCReturnsTrue)
{
    ctest_logger_expect(true, "State3 to State5\n"
                              "Enter State5\n");
    ctest_logger_given(Tkind_ctest_c(&ctest_obj)
                       && Tkind_ctest_fetch_event(&ctest_obj)
                       && Tkind_ctest_dispatch_event(&ctest_obj));
}

TEST(TkindSm1State3, ReleaseCReturnsTrue)
{
    ctest_logger_expect(true, "State3 to State5\n"
                              "Enter State5\n");
    ctest_logger_given(Tkind_ctest_c(&ctest_obj)
                       && Tkind_ctest_fetch_event(&ctest_obj)
                       && Tkind_ctest_dispatch_event(&ctest_obj)
                       && Tkind_ctest_release_event(&ctest_obj));
}

TEST(TkindSm1State3, DReturnsTrue)
{
    ctest_logger_expect(true, NULL);
    ctest_logger_given(Tkind_ctest_d(&ctest_obj));
}

TEST(TkindSm1State3, FetchDReturnsTrue)
{
    ctest_logger_expect(true, NULL);
    ctest_logger_given(Tkind_ctest_d(&ctest_obj)
                       && Tkind_ctest_fetch_event(&ctest_obj));
}

TEST(TkindSm1State3, DispatchDReturnsTrue)
{
    ctest_logger_expect(true, NULL);
    ctest_logger_given(Tkind_ctest_d(&ctest_obj)
                       && Tkind_ctest_fetch_event(&ctest_obj)
                       && Tkind_ctest_dispatch_event(&ctest_obj));
}

TEST(TkindSm1State3, ReleaseDReturnsTrue)
{
    ctest_logger_expect(true, NULL);
    ctest_logger_given(Tkind_ctest_d(&ctest_obj)
                       && Tkind_ctest_fetch_event(&ctest_obj)
                       && Tkind_ctest_dispatch_event(&ctest_obj)
                       && Tkind_ctest_release_event(&ctest_obj));
}

TEST(TkindSm1State3, EReturnsTrue)
{
    ctest_logger_expect(true, NULL);
    ctest_logger_given(Tkind_ctest_e(&ctest_obj));
}

TEST(TkindSm1State3, FetchEReturnsTrue)
{
    ctest_logger_expect(true, NULL);
    ctest_logger_given(Tkind_ctest_e(&ctest_obj)
                       && Tkind_ctest_fetch_event(&ctest_obj));
}

TEST(TkindSm1State3, DispatchEReturnsTrue)
{
    ctest_logger_expect(true, NULL);
    ctest_logger_given(Tkind_ctest_e(&ctest_obj)
                       && Tkind_ctest_fetch_event(&ctest_obj)
                       && Tkind_ctest_dispatch_event(&ctest_obj));
}

TEST(TkindSm1State3, ReleaseEReturnsTrue)
{
    ctest_logger_expect(true, NULL);
    ctest_logger_given(Tkind_ctest_e(&ctest_obj)
                       && Tkind_ctest_fetch_event(&ctest_obj)
                       && Tkind_ctest_dispatch_event(&ctest_obj)
                       && Tkind_ctest_release_event(&ctest_obj));
}

TEST(TkindSm1State3, FReturnsTrue)
{
    ctest_logger_expect(true, NULL);
    ctest_logger_given(Tkind_ctest_f(&ctest_obj));
}

TEST(TkindSm1State3, FetchFReturnsTrue)
{
    ctest_logger_expect(true, NULL);
    ctest_logger_given(Tkind_ctest_f(&ctest_obj)
                       && Tkind_ctest_fetch_event(&ctest_obj));
}

TEST(TkindSm1State3, DispatchFReturnsTrue)
{
    ctest_logger_expect(true, NULL);
    ctest_logger_given(Tkind_ctest_f(&ctest_obj)
                       && Tkind_ctest_fetch_event(&ctest_obj)
                       && Tkind_ctest_dispatch_event(&ctest_obj));
}

TEST(TkindSm1State3, ReleaseFReturnsTrue)
{
    ctest_logger_expect(true, NULL);
    ctest_logger_given(Tkind_ctest_f(&ctest_obj)
                       && Tkind_ctest_fetch_event(&ctest_obj)
                       && Tkind_ctest_dispatch_event(&ctest_obj)
                       && Tkind_ctest_release_event(&ctest_obj));
}

TEST(TkindSm1State3, GReturnsTrue)
{
    ctest_logger_expect(true, NULL);
    ctest_logger_given(Tkind_ctest_g(&ctest_obj));
}

TEST(TkindSm1State3, FetchGReturnsTrue)
{
    ctest_logger_expect(true, NULL);
    ctest_logger_given(Tkind_ctest_g(&ctest_obj)
                       && Tkind_ctest_fetch_event(&ctest_obj));
}

TEST(TkindSm1State3, DispatchGReturnsTrue)
{
    ctest_logger_expect(true, NULL);
    ctest_logger_given(Tkind_ctest_g(&ctest_obj)
                       && Tkind_ctest_fetch_event(&ctest_obj)
                       && Tkind_ctest_dispatch_event(&ctest_obj));
}

TEST(TkindSm1State3, ReleaseGReturnsTrue)
{
    ctest_logger_expect(true, NULL);
    ctest_logger_given(Tkind_ctest_g(&ctest_obj)
                       && Tkind_ctest_fetch_event(&ctest_obj)
                       && Tkind_ctest_dispatch_event(&ctest_obj)
                       && Tkind_ctest_release_event(&ctest_obj));
}

TEST(TkindSm1State3, HReturnsTrue)
{
    ctest_logger_expect(true, NULL);
    ctest_logger_given(Tkind_ctest_h(&ctest_obj));
}

TEST(TkindSm1State3, FetchHReturnsTrue)
{
    ctest_logger_expect(true, NULL);
    ctest_logger_given(Tkind_ctest_h(&ctest_obj)
                       && Tkind_ctest_fetch_event(&ctest_obj));
}

TEST(TkindSm1State3, DispatchHReturnsTrue)
{
    ctest_logger_expect(true, NULL);
    ctest_logger_given(Tkind_ctest_h(&ctest_obj)
                       && Tkind_ctest_fetch_event(&ctest_obj)
                       && Tkind_ctest_dispatch_event(&ctest_obj));
}

TEST(TkindSm1State3, ReleaseHReturnsTrue)
{
    ctest_logger_expect(true, NULL);
    ctest_logger_given(Tkind_ctest_h(&ctest_obj)
                       && Tkind_ctest_fetch_event(&ctest_obj)
                       && Tkind_ctest_dispatch_event(&ctest_obj)
                       && Tkind_ctest_release_event(&ctest_obj));
}

TEST(TkindSm1State3, IReturnsTrue)
{
    ctest_logger_expect(true, NULL);
    ctest_logger_given(Tkind_ctest_i(&ctest_obj));
}

TEST(TkindSm1State3, FetchIReturnsTrue)
{
    ctest_logger_expect(true, NULL);
    ctest_logger_given(Tkind_ctest_i(&ctest_obj)
                       && Tkind_ctest_fetch_event(&ctest_obj));
}

TEST(TkindSm1State3, DispatchIReturnsTrue)
{
    ctest_logger_expect(true, "Exit State3\n"
                              "Exit State1\n"
                              "State1 to State7\n"
                              "Enter State1\n"
                              "Enter State7\n"
                              "Initial3 to State2\n"
                              "Enter State2\n");
    ctest_logger_given(Tkind_ctest_i(&ctest_obj)
                       && Tkind_ctest_fetch_event(&ctest_obj)
                       && Tkind_ctest_dispatch_event(&ctest_obj));
}

TEST(TkindSm1State3, ReleaseIReturnsTrue)
{
    ctest_logger_expect(true, "Exit State3\n"
                              "Exit State1\n"
                              "State1 to State7\n"
                              "Enter State1\n"
                              "Enter State7\n"
                              "Initial3 to State2\n"
                              "Enter State2\n");
    ctest_logger_given(Tkind_ctest_i(&ctest_obj)
                       && Tkind_ctest_fetch_event(&ctest_obj)
                       && Tkind_ctest_dispatch_event(&ctest_obj)
                       && Tkind_ctest_release_event(&ctest_obj));
}

TEST(TkindSm1State3, JReturnsTrue)
{
    ctest_logger_expect(true, NULL);
    ctest_logger_given(Tkind_ctest_j(&ctest_obj));
}

TEST(TkindSm1State3, FetchJReturnsTrue)
{
    ctest_logger_expect(true, NULL);
    ctest_logger_given(Tkind_ctest_j(&ctest_obj)
                       && Tkind_ctest_fetch_event(&ctest_obj));
}

TEST(TkindSm1State3, DispatchJReturnsTrue)
{
    ctest_logger_expect(true, NULL);
    ctest_logger_given(Tkind_ctest_j(&ctest_obj)
                       && Tkind_ctest_fetch_event(&ctest_obj)
                       && Tkind_ctest_dispatch_event(&ctest_obj));
}

TEST(TkindSm1State3, ReleaseJReturnsTrue)
{
    ctest_logger_expect(true, NULL);
    ctest_logger_given(Tkind_ctest_j(&ctest_obj)
                       && Tkind_ctest_fetch_event(&ctest_obj)
                       && Tkind_ctest_dispatch_event(&ctest_obj)
                       && Tkind_ctest_release_event(&ctest_obj));
}

TEST(TkindSm1State3, KReturnsTrue)
{
    ctest_logger_expect(true, NULL);
    ctest_logger_given(Tkind_ctest_k(&ctest_obj));
}

TEST(TkindSm1State3, FetchKReturnsTrue)
{
    ctest_logger_expect(true, NULL);
    ctest_logger_given(Tkind_ctest_k(&ctest_obj)
                       && Tkind_ctest_fetch_event(&ctest_obj));
}

TEST(TkindSm1State3, DispatchKReturnsTrue)
{
    ctest_logger_expect(true, NULL);
    ctest_logger_given(Tkind_ctest_k(&ctest_obj)
                       && Tkind_ctest_fetch_event(&ctest_obj)
                       && Tkind_ctest_dispatch_event(&ctest_obj));
}

TEST(TkindSm1State3, ReleaseKReturnsTrue)
{
    ctest_logger_expect(true, NULL);
    ctest_logger_given(Tkind_ctest_k(&ctest_obj)
                       && Tkind_ctest_fetch_event(&ctest_obj)
                       && Tkind_ctest_dispatch_event(&ctest_obj)
                       && Tkind_ctest_release_event(&ctest_obj));
}

TEST(TkindSm1State3, LReturnsTrue)
{
    ctest_logger_expect(true, NULL);
    ctest_logger_given(Tkind_ctest_l(&ctest_obj));
}

TEST(TkindSm1State3, FetchLReturnsTrue)
{
    ctest_logger_expect(true, NULL);
    ctest_logger_given(Tkind_ctest_l(&ctest_obj)
                       && Tkind_ctest_fetch_event(&ctest_obj));
}

TEST(TkindSm1State3, DispatchLReturnsTrue)
{
    ctest_logger_expect(true, NULL);
    ctest_logger_given(Tkind_ctest_l(&ctest_obj)
                       && Tkind_ctest_fetch_event(&ctest_obj)
                       && Tkind_ctest_dispatch_event(&ctest_obj));
}

TEST(TkindSm1State3, MReturnsTrue)
{
    ctest_logger_expect(true, NULL);
    ctest_logger_given(Tkind_ctest_m(&ctest_obj));
}

TEST(TkindSm1State3, FetchMReturnsTrue)
{
    ctest_logger_expect(true, NULL);
    ctest_logger_given(Tkind_ctest_m(&ctest_obj)
                       && Tkind_ctest_fetch_event(&ctest_obj));
}

TEST(TkindSm1State3, DispatchMReturnsTrue)
{
    ctest_logger_expect(true, NULL);
    ctest_logger_given(Tkind_ctest_m(&ctest_obj)
                       && Tkind_ctest_fetch_event(&ctest_obj)
                       && Tkind_ctest_dispatch_event(&ctest_obj));
}

TEST(TkindSm1State3, ReleaseMReturnsTrue)
{
    ctest_logger_expect(true, NULL);
    ctest_logger_given(Tkind_ctest_m(&ctest_obj)
                       && Tkind_ctest_fetch_event(&ctest_obj)
                       && Tkind_ctest_dispatch_event(&ctest_obj)
                       && Tkind_ctest_release_event(&ctest_obj));
}

TEST(TkindSm1State3, NReturnsTrue)
{
    ctest_logger_expect(true, NULL);
    ctest_logger_given(Tkind_ctest_n(&ctest_obj));
}

TEST(TkindSm1State3, FetchNReturnsTrue)
{
    ctest_logger_expect(true, NULL);
    ctest_logger_given(Tkind_ctest_n(&ctest_obj)
                       && Tkind_ctest_fetch_event(&ctest_obj));
}

TEST(TkindSm1State3, DispatchNReturnsTrue)
{
    ctest_logger_expect(true, NULL);
    ctest_logger_given(Tkind_ctest_n(&ctest_obj)
                       && Tkind_ctest_fetch_event(&ctest_obj)
                       && Tkind_ctest_dispatch_event(&ctest_obj));
}

TEST(TkindSm1State3, ReleaseNReturnsTrue)
{
    ctest_logger_expect(true, NULL);
    ctest_logger_given(Tkind_ctest_n(&ctest_obj)
                       && Tkind_ctest_fetch_event(&ctest_obj)
                       && Tkind_ctest_dispatch_event(&ctest_obj)
                       && Tkind_ctest_release_event(&ctest_obj));
}

TEST(TkindSm1State3, OReturnsTrue)
{
    ctest_logger_expect(true, NULL);
    ctest_logger_given(Tkind_ctest_o(&ctest_obj));
}

TEST(TkindSm1State3, FetchOWithFalseChoice1ReturnsTrue)
{
    ctest_logger_expect(true, NULL);
    ctest_obj.sm1.b_test_condition = false;
    ctest_logger_given(Tkind_ctest_o(&ctest_obj)
                       && Tkind_ctest_fetch_event(&ctest_obj));
}

TEST(TkindSm1State3, DispatchOWithFalseChoice1ReturnsTrue)
{
    ctest_logger_expect(true, "Exit State3\n"
                              "Exit State1\n"
                              "State1 to Choice1\n"
                              "Enter State1\n"
                              "Choice1 to State1\n"
                              "Initial3 to State2\n"
                              "Enter State2\n");
    ctest_obj.sm1.b_test_condition = false;
    ctest_logger_given(Tkind_ctest_o(&ctest_obj)
                       && Tkind_ctest_fetch_event(&ctest_obj)
                       && Tkind_ctest_dispatch_event(&ctest_obj));
}

TEST(TkindSm1State3, ReleaseOWithFalseChoice1ReturnsTrue)
{
    ctest_logger_expect(true, "Exit State3\n"
                              "Exit State1\n"
                              "State1 to Choice1\n"
                              "Enter State1\n"
                              "Choice1 to State1\n"
                              "Initial3 to State2\n"
                              "Enter State2\n");
    ctest_obj.sm1.b_test_condition = false;
    ctest_logger_given(Tkind_ctest_o(&ctest_obj)
                       && Tkind_ctest_fetch_event(&ctest_obj)
                       && Tkind_ctest_dispatch_event(&ctest_obj)
                       && Tkind_ctest_release_event(&ctest_obj));
}

TEST(TkindSm1State3, FetchOWithTrueChoice1ReturnsTrue)
{
    ctest_logger_expect(true, NULL);
    ctest_obj.sm1.b_test_condition = true;
    ctest_logger_given(Tkind_ctest_o(&ctest_obj)
                       && Tkind_ctest_fetch_event(&ctest_obj));
}

TEST(TkindSm1State3, DispatchOWithTrueChoice1ReturnsTrue)
{
    ctest_logger_expect(true, "Exit State3\n"
                              "Exit State1\n"
                              "State1 to Choice1\n"
                              "Enter State1\n"
                              "Choice1 to State8\n"
                              "Enter State8\n"
                              "Enter State9\n"
                              "Initial3 to State2\n"
                              "Enter State2\n");
    ctest_obj.sm1.b_test_condition = true;
    ctest_logger_given(Tkind_ctest_o(&ctest_obj)
                       && Tkind_ctest_fetch_event(&ctest_obj)
                       && Tkind_ctest_dispatch_event(&ctest_obj));
}

TEST(TkindSm1State3, ReleaseOWithTrueChoice1ReturnsTrue)
{
    ctest_logger_expect(true, "Exit State3\n"
                              "Exit State1\n"
                              "State1 to Choice1\n"
                              "Enter State1\n"
                              "Choice1 to State8\n"
                              "Enter State8\n"
                              "Enter State9\n"
                              "Initial3 to State2\n"
                              "Enter State2\n");
    ctest_obj.sm1.b_test_condition = true;
    ctest_logger_given(Tkind_ctest_o(&ctest_obj)
                       && Tkind_ctest_fetch_event(&ctest_obj)
                       && Tkind_ctest_dispatch_event(&ctest_obj)
                       && Tkind_ctest_release_event(&ctest_obj));
}

TEST(TkindSm1State3, FetchReturnsFalse)
{
    ctest_logger_expect(false, NULL);
    ctest_logger_given(Tkind_ctest_fetch_event(&ctest_obj));
}

TEST(TkindSm1State3, DispatchReturnsFalse)
{
    ctest_logger_expect(false, NULL);
    ctest_logger_given(Tkind_ctest_dispatch_event(&ctest_obj));
}

TEST(TkindSm1State3, ReleaseReturnsFalse)
{
    ctest_logger_expect(false, NULL);
    ctest_logger_given(Tkind_ctest_release_event(&ctest_obj));
}

