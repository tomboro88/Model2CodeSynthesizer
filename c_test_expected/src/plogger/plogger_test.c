/*
 * @file plogger_test.c
 *
 * @brief Source code of the test logger shared by all package test cases.
 * @author tomboro88
 * @date   22 november 2026
 * @copyright (c) 2026 tomboro88.
 * @license SPDX-License-Identifier: EPL-2.0
 * @project github.com/tomboro88/Model2CodeSynthesizer
 */

/*******************************************************************************
 *
 * Include statements.
 *
 ******************************************************************************/
#include "plogger_test.h"
#include <string.h>
#include <stddef.h>
#include <stdio.h>

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
static void test_capture_logger_dbl(plogger_logger_t* const p_obj,
                                      const char* const p_str, double const dbl);
static void test_capture_logger_u16_char(plogger_logger_t* const p_obj,
                                      const char* const p_str,
                                      uint16_t const u16_param,
                                      char const char_param);
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
 * @brief The expected boolean result of the called function.
 */
static bool b_expected_result = false;

/**
 * @brief The virtual table for our test logger object.
 */
static const plogger_logger_vt_t plogger_test_logger_funcs =
                          {.p_record = test_capture_logger,
                           .p_record_dbl = test_capture_logger_dbl,
                           .p_record_u16_char = test_capture_logger_u16_char};

/**
 * @brief The logger object that will capture the logs from the tested state
 * machines.
 */
plogger_logger_t plogger_test_logger = {.p_vtable = &plogger_test_logger_funcs};

/*******************************************************************************
 *
 * Public function bodies.
 *
 ******************************************************************************/
/**
 * @brief Initializes the local buffer before capturing state machine logs,
 * and clears the expected logger contents.
 */
void
plogger_test_init_buffer(void)
{
    memcpy(logger_buffer, forbidden_pattern, sizeof(forbidden_pattern));
    memcpy(&logger_buffer[TEST_LOGGER_BUFFER_SIZE + sizeof(forbidden_pattern)],
           forbidden_pattern, sizeof(forbidden_pattern));
    memset(&logger_buffer[TEST_LOGGER_BUFFER_DATA_POS], TEST_LOGGER_BUFFER_FILL,
           TEST_LOGGER_BUFFER_SIZE);

    logger_index = TEST_LOGGER_BUFFER_DATA_POS;

    p_expected_logger = NULL;
}

/**
 * @brief Stores the expectations verified by the plogger_test_given() and
 * plogger_test_assert_* functions.
 * @param b_is_result_ok The expected result of the tested function.
 * @param p_str The expected logger contents, or NULL when nothing should be
 * logged.
 */
void
plogger_test_expect(bool const b_is_result_ok, const char* const p_str)
{
    p_expected_logger = p_str;
    b_expected_result = b_is_result_ok;
}

/**
 * @brief Verifies the result of the tested function against the expected one.
 * @param b_is_result_ok The result returned by the tested function.
 */
void
plogger_test_assert_result(bool const b_is_result_ok)
{
    if(b_expected_result)
    {
        TEST_ASSERT_TRUE(b_is_result_ok);
    }
    else
    {
        TEST_ASSERT_FALSE(b_is_result_ok);
    }
}

/**
 * @brief Verifies the logger buffer against the expected contents.
 */
void
plogger_test_assert_expected(void)
{
    plogger_test_assert(p_expected_logger);
}

/**
 * @brief Verifies both the result of the tested function and the logger
 * buffer against the expectations.
 * @param b_is_result_ok The result returned by the tested function.
 */
void
plogger_test_given(bool const b_is_result_ok)
{
    plogger_test_assert_result(b_is_result_ok);
    plogger_test_assert_expected();
}

/**
 * @brief Verifies the contents of the logger buffer.
 * @param p_str The expected buffer contents, or NULL when nothing should have
 * been logged.
 */
void
plogger_test_assert(const char* const p_str)
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

/*******************************************************************************
 *
 * Test group PloggerTest
 *
 ******************************************************************************/

TEST_GROUP(PloggerTest);

TEST_SETUP(PloggerTest)
{
    plogger_test_init_buffer();
}

TEST_TEAR_DOWN(PloggerTest)
{

}

/*================================TEST_CASES==================================*/
TEST(PloggerTest, record_empty_string)
{
    plogger_logger_record(&plogger_test_logger, "");
    plogger_test_assert("");
}

TEST(PloggerTest, record_nonempty_string)
{
    plogger_logger_record(&plogger_test_logger, "abc");
    plogger_test_assert("abc");
}

TEST(PloggerTest, record_multiple_strings)
{
    plogger_logger_record(&plogger_test_logger, "abc");
    plogger_logger_record(&plogger_test_logger, "def");
    plogger_logger_record(&plogger_test_logger, "ghi");
    plogger_test_assert("abcdefghi");
}

TEST_GROUP_RUNNER(PloggerTest)
{
    RUN_TEST_CASE(PloggerTest, record_empty_string);
    RUN_TEST_CASE(PloggerTest, record_nonempty_string);
    RUN_TEST_CASE(PloggerTest, record_multiple_strings);
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
test_capture_logger_dbl(plogger_logger_t* const p_obj,
                        const char* const p_str, double const dbl)
{
    TEST_ASSERT_NOT_NULL(p_obj);
    TEST_ASSERT_NOT_NULL(p_str);

    size_t const maxlen = TEST_LOGGER_BUFFER_GUARD2_POS - logger_index;
    int const written = snprintf(&logger_buffer[logger_index], maxlen, p_str,
                                 dbl);

    if(written < 0)
    {
        UnityPrint("Trying to log a string: ");
        UnityPrint(p_str);
        UNITY_PRINT_EOL();
        TEST_FAIL_MESSAGE("Captured string formatting failed.");
    }
    else if((size_t)written < maxlen)
    {
        logger_index += written;
    }
    else
    {
        UnityPrint("Trying to log a string: ");
        UnityPrint(p_str);
        UNITY_PRINT_EOL();
        TEST_FAIL_MESSAGE("Captured string doesn't fit into the buffer");
    }
}

static void
test_capture_logger_u16_char(plogger_logger_t* const p_obj,
                             const char* const p_str,
                             uint16_t const u16_param,
                             char const char_param)
{
    TEST_ASSERT_NOT_NULL(p_obj);
    TEST_ASSERT_NOT_NULL(p_str);

    size_t const maxlen = TEST_LOGGER_BUFFER_GUARD2_POS - logger_index;
    int const written = snprintf(&logger_buffer[logger_index], maxlen, p_str,
                                 u16_param, char_param);

    if(written < 0)
    {
        UnityPrint("Trying to log a string: ");
        UnityPrint(p_str);
        UNITY_PRINT_EOL();
        TEST_FAIL_MESSAGE("Captured string formatting failed.");
    }
    else if((size_t)written < maxlen)
    {
        logger_index += written;
    }
    else
    {
        UnityPrint("Trying to log a string: ");
        UnityPrint(p_str);
        UNITY_PRINT_EOL();
        TEST_FAIL_MESSAGE("Captured string doesn't fit into the buffer");
    }
}

/*** end of file ***/
