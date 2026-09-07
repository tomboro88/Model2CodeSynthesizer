/*
 * @file Tkind_test.c
 *
 * @brief Source code of the Tkind package test cases.
 * @author tomboro88
 * @date   4 mar 2026
 * @copyright (c) 2026 tomboro88.
 * @license SPDX-License-Identifier: EPL-2.0
 * @project github.com/tomboro88/Model2CodeSynthesizer
 */

/*******************************************************************************
 *
 * Include statements.
 *
 ******************************************************************************/
#include <unity_fixture.h>
#include <Tkind.h>
#include <string.h>
#include <stddef.h>

/*******************************************************************************
 *
 * Data type, constant, and macro definitions.
 *
 ******************************************************************************/
#define TEST_LOGGER_BUFFER_SIZE 1024u
#define TEST_LOGGER_BUFFER_DATA_POS sizeof(forbidden_pattern)
#define TEST_LOGGER_BUFFER_GUARD2_POS \
                         (TEST_LOGGER_BUFFER_SIZE + TEST_LOGGER_BUFFER_DATA_POS)
#define TEST_LOGGER_BUFFER_FILL '\xA5'
/*******************************************************************************
 *
 * Private function prototypes.
 *
 ******************************************************************************/
static void test_capture_logger(plogger_logger_t* const p_obj,
                                                       const char* const p_str);
static void test_assert_logger(const char* p_str);
/*******************************************************************************
 *
 * Static data declarations.
 *
 ******************************************************************************/
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

/**
 * @brief The virtual table for our test logger object.
 */
static const plogger_logger_vt_t tkind_test_logger_funcs =
                                              {.p_record = test_capture_logger};

/**
 * @brief The logger object that will capture the logs from the tested state
 * machines.
 */
plogger_logger_t tkind_test_logger = {.p_vtable = &tkind_test_logger_funcs};

/**
 * @brief The ctest object that is tested.
 */
tkind_ctest_t tkind_ctest_obj = {0};

/*******************************************************************************
 *
 * Inline functions.
 *
 ******************************************************************************/

/*******************************************************************************
 *
 * Public function bodies.
 *
 ******************************************************************************/
/**
 * @brief Initializes the local buffer before capturing state machine logs.
 */
void
tkind_test_init_logger_buffer(void)
{
    memcpy(logger_buffer, forbidden_pattern, sizeof(forbidden_pattern));
    memcpy(&logger_buffer[TEST_LOGGER_BUFFER_SIZE + sizeof(forbidden_pattern)],
           forbidden_pattern, sizeof(forbidden_pattern));
    memset(&logger_buffer[TEST_LOGGER_BUFFER_DATA_POS], TEST_LOGGER_BUFFER_FILL,
           TEST_LOGGER_BUFFER_SIZE);

    logger_index = TEST_LOGGER_BUFFER_DATA_POS;

    p_expected_logger = NULL;
}

void
tkind_ctest_logger_expect(bool const b_is_result_ok, const char* const p_str)
{
    p_expected_logger = p_str;
    b_expected_result = b_is_result_ok;
}

void
tkind_ctest_logger_dispatch_given(bool const b_is_result_ok)
{
    if(b_expected_result)
    {
        TEST_ASSERT_TRUE(b_is_result_ok);
    }
    else
    {
        TEST_ASSERT_FALSE(b_is_result_ok);
    }

    test_assert_logger(NULL);
    TEST_ASSERT_TRUE(tkind_ctest_fetch_event(&tkind_ctest_obj));
    test_assert_logger(NULL);
    TEST_ASSERT_TRUE(tkind_ctest_fetch_event(&tkind_ctest_obj));
    test_assert_logger(NULL);
    TEST_ASSERT_TRUE(tkind_ctest_dispatch_event(&tkind_ctest_obj));
    test_assert_logger(p_expected_logger);
    TEST_ASSERT_FALSE(tkind_ctest_dispatch_event(&tkind_ctest_obj));
    test_assert_logger(p_expected_logger);
    TEST_ASSERT_TRUE(tkind_ctest_release_event(&tkind_ctest_obj));
    test_assert_logger(p_expected_logger);
    TEST_ASSERT_FALSE(tkind_ctest_release_event(&tkind_ctest_obj));
    test_assert_logger(p_expected_logger);
}

void
tkind_ctest_logger_given(bool const b_is_result_ok)
{
    if(b_expected_result)
    {
        TEST_ASSERT_TRUE(b_is_result_ok);
    }
    else
    {
        TEST_ASSERT_FALSE(b_is_result_ok);
    }

    test_assert_logger(p_expected_logger);
}
/*******************************************************************************
 *
 * Test group TkindLogger
 *
 ******************************************************************************/

TEST_GROUP(TkindLogger);

TEST_SETUP(TkindLogger)
{
    tkind_test_init_logger_buffer();
}

TEST_TEAR_DOWN(TkindLogger)
{

}

/*================================TEST_CASES==================================*/
TEST(TkindLogger, record_empty_string)
{
    plogger_logger_record(&tkind_test_logger, "");
    test_assert_logger("");
}

TEST(TkindLogger, record_nonempty_string)
{
    plogger_logger_record(&tkind_test_logger, "abc");
    test_assert_logger("abc");
}

TEST(TkindLogger, record_multiple_strings)
{
    tkind_ctest_logger_expect(true, "abcdefghi");
    plogger_logger_record(&tkind_test_logger, "abc");
    plogger_logger_record(&tkind_test_logger, "def");
    plogger_logger_record(&tkind_test_logger, "ghi");
    test_assert_logger("abcdefghi");
}

TEST_GROUP_RUNNER(TkindLogger)
{
    RUN_TEST_CASE(TkindLogger, record_empty_string);
    RUN_TEST_CASE(TkindLogger, record_nonempty_string);
    RUN_TEST_CASE(TkindLogger, record_multiple_strings);
}
/*******************************************************************************
 *
 * Private function bodies.
 *
 ******************************************************************************/
/**
 * @brief The function used to capture the logs from the tested state machines.
 * @param p_obj The pointer to the calling logger object
 * @param p_str The pointer to the captured string
 */
static void
test_capture_logger(plogger_logger_t* const p_obj, const char* const p_str)
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

static void
test_assert_logger(const char* const p_str)
{
    TEST_ASSERT_EQUAL_MEMORY(forbidden_pattern, logger_buffer,
                                                     sizeof(forbidden_pattern));
    if(NULL != p_str)
    {
        TEST_ASSERT_EQUAL_STRING(p_str,
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

/*** end of file ***/
