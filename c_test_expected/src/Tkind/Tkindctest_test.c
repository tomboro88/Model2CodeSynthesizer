/*
 * @file Tkindctest_test.c
 *
 * @brief Source code of the Tkind package ctest class test cases.
 * @author tomboro88
 * @date   22 May 2026
 * @copyright (c) 2026 tomboro88. All rights reserved.
 * @license MIT – see LICENSE file in project root
 * @project github.com/tomboro88/M2T4Embedded
 */

/*******************************************************************************
 *
 * Include statements.
 *
 ******************************************************************************/
#include "Tkind_test.h"
#include <stddef.h>
#include <string.h>

/*******************************************************************************
 *
 * Data type, constant, and macro definitions.
 *
 ******************************************************************************/

 /*******************************************************************************
 *
 * Private function prototypes.
 *
 ******************************************************************************/

/*******************************************************************************
 *
 * Static data declarations.
 *
 ******************************************************************************/

/*******************************************************************************
 *
 * Inline functions.
 *
 ******************************************************************************/

/*******************************************************************************
 *
 * Test cases
 *
 ******************************************************************************/
TEST_GROUP(Tkindctest);

TEST_SETUP(Tkindctest)
{
    tkind_test_init_logger_buffer();
    tkind_ctest_obj.cbase1.Property1 = TKIND_CBASE1_TEST_PROP1_DEFAULT;
    tkind_ctest_obj.cbase2.Property1 = TKIND_CBASE2_TEST_PROP1_DEFAULT;
    Tkind_ctest_init(&tkind_ctest_obj, &tkind_test_logger);
}

TEST_TEAR_DOWN(Tkindctest)
{

}

TEST(Tkindctest, InitReturnsTrue)
{
    TEST_ASSERT_TRUE(Tkind_ctest_init(&tkind_ctest_obj, &tkind_test_logger));
}

TEST(Tkindctest, InitCtestNullPtrReturnsFalse)
{
    TEST_ASSERT_FALSE(Tkind_ctest_init(NULL, &tkind_test_logger));
}

TEST(Tkindctest, InitLoggerNullPtrReturnsTrue)
{
    TEST_ASSERT_TRUE(Tkind_ctest_init(&tkind_ctest_obj, NULL));
}

TEST(Tkindctest, Cbase1Property1Uninitialized)
{
    TEST_ASSERT_EQUAL_UINT32(TKIND_CBASE1_TEST_PROP1_DEFAULT,
                             Tkind_cbase1_GetUintProp(&tkind_ctest_obj.cbase1));
}

TEST(Tkindctest, Cbase2Property1Uninitialized)
{
    TEST_ASSERT_EQUAL_FLOAT((float)TKIND_CBASE1_TEST_PROP1_DEFAULT,
                            Tkind_cbase2_GetFloatProp(&tkind_ctest_obj.cbase2));
}

TEST(Tkindctest, Cbase1Property1Set)
{
    Tkind_cbase1_SetUintProp(&tkind_ctest_obj.cbase1, 5u);
    TEST_ASSERT_EQUAL_UINT32(6u,
                             Tkind_cbase1_GetUintProp(&tkind_ctest_obj.cbase1));
}

TEST_GROUP_RUNNER(Tkindctest)
{
    RUN_TEST_CASE(Tkindctest, InitReturnsTrue);
    RUN_TEST_CASE(Tkindctest, InitCtestNullPtrReturnsFalse);
    RUN_TEST_CASE(Tkindctest, InitLoggerNullPtrReturnsTrue);
    RUN_TEST_CASE(Tkindctest, Cbase1Property1Uninitialized);
    RUN_TEST_CASE(Tkindctest, Cbase2Property1Uninitialized);
    RUN_TEST_CASE(Tkindctest, Cbase1Property1Set);
}
/*******************************************************************************
 *
 * Private function bodies.
 *
 ******************************************************************************/

/*** end of file ***/
