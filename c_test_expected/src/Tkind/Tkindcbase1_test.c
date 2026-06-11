/*
 * @file Tkindcbase1_test.c
 *
 * @brief Source code of the Tkind package cbase1 test cases.
 * @author tomboro88
 * @date   15 May 2026
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
static Tkind_cbase1_t                  cbase1_obj;
static const Tkind_cbase1_vt_t         empty_vtable = {0};
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
TEST_GROUP(Tkindcbase1);

TEST_SETUP(Tkindcbase1)
{
    cbase1_obj.Property1 = TKIND_CBASE1_TEST_PROP1_DEFAULT;
    Tkind_cbase1_init(&cbase1_obj);
}

TEST_TEAR_DOWN(Tkindcbase1)
{

}

TEST(Tkindcbase1, InitReturnsTrue)
{
    TEST_ASSERT_TRUE(Tkind_cbase1_init(&cbase1_obj));
}

TEST(Tkindcbase1, InitNullPtrReturnsFalse)
{
    TEST_ASSERT_FALSE(Tkind_cbase1_init(NULL));
}

TEST(Tkindcbase1, Property1Uninitialized)
{
    TEST_ASSERT_EQUAL_UINT32(TKIND_CBASE1_TEST_PROP1_DEFAULT,
                             Tkind_cbase1_GetUintProp(&cbase1_obj));
}

TEST(Tkindcbase1, Property1Set)
{
    Tkind_cbase1_SetUintProp(&cbase1_obj, 5u);
    TEST_ASSERT_EQUAL_UINT32(5u,
                             Tkind_cbase1_GetUintProp(&cbase1_obj));
}

TEST(Tkindcbase1, SetUintPropWithNullPtrIsSafe)
{
    Tkind_cbase1_SetUintProp(NULL, 5u);
    TEST_ASSERT_TRUE(true);
}

TEST(Tkindcbase1, SetUintPropOnZerosIsSafe)
{
    memset(&cbase1_obj,0u,sizeof(cbase1_obj));
    Tkind_cbase1_SetUintProp(&cbase1_obj, 5u);
    TEST_ASSERT_EQUAL_UINT32(0u, Tkind_cbase1_GetUintProp(&cbase1_obj));
}

TEST(Tkindcbase1, SetUintPropOnEmptyVtIsSafe)
{
    memset(&cbase1_obj,0u,sizeof(cbase1_obj));
    cbase1_obj.p_vtable = &empty_vtable;
    Tkind_cbase1_SetUintProp(&cbase1_obj, 5u);
    TEST_ASSERT_EQUAL_UINT32(0u, Tkind_cbase1_GetUintProp(&cbase1_obj));
}

TEST_GROUP_RUNNER(Tkindcbase1)
{
    RUN_TEST_CASE(Tkindcbase1, InitReturnsTrue);
    RUN_TEST_CASE(Tkindcbase1, InitNullPtrReturnsFalse);
    RUN_TEST_CASE(Tkindcbase1, Property1Uninitialized);
    RUN_TEST_CASE(Tkindcbase1, Property1Set);
    RUN_TEST_CASE(Tkindcbase1, SetUintPropWithNullPtrIsSafe);
    RUN_TEST_CASE(Tkindcbase1, SetUintPropOnZerosIsSafe);
    RUN_TEST_CASE(Tkindcbase1, SetUintPropOnEmptyVtIsSafe);
}
/*******************************************************************************
 *
 * Private function bodies.
 *
 ******************************************************************************/
