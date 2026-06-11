/*
 * @file Tkindcbase2_test.c
 *
 * @brief Source code of the Tkind package cbase1 test cases.
 * @author tomboro88
 * @date   16 May 2026
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
static Tkind_cbase2_t                  cbase2_obj;
static const Tkind_cbase2_vt_t         cbase2_empty_vtable = {0};
static bool                            b_is_setup_ok = false;
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
TEST_GROUP(Tkindcbase2);

TEST_SETUP(Tkindcbase2)
{
    cbase2_obj.Property1 = TKIND_CBASE2_TEST_PROP1_DEFAULT;
    b_is_setup_ok = Tkind_cbase2_init(&cbase2_obj);
}

TEST_TEAR_DOWN(Tkindcbase2)
{

}

TEST(Tkindcbase2, InitReturnsTrue)
{
    TEST_ASSERT_TRUE(b_is_setup_ok);
}

TEST(Tkindcbase2, InitNullPtrReturnsFalse)
{
    TEST_ASSERT_FALSE(Tkind_cbase2_init(NULL));
}

TEST(Tkindcbase2, Property1Uninitialized)
{
    TEST_ASSERT_EQUAL_FLOAT(TKIND_CBASE2_TEST_PROP1_DEFAULT,
                            Tkind_cbase2_GetFloatProp(&cbase2_obj));
}

TEST(Tkindcbase2, Property1Set)
{
    Tkind_cbase2_SetFloatProp(&cbase2_obj, 2.71f);
    TEST_ASSERT_EQUAL_FLOAT(2.71f,
                            Tkind_cbase2_GetFloatProp(&cbase2_obj));
}

TEST(Tkindcbase2, GetFloatPropWithNullPtrIsSafe)
{
    TEST_ASSERT_EQUAL_FLOAT(0.0f, Tkind_cbase2_GetFloatProp(NULL));
}

TEST(Tkindcbase2, GetFloatPropOnZerosReturns0)
{
    memset(&cbase2_obj,0u,sizeof(cbase2_obj));
    Tkind_cbase2_SetFloatProp(&cbase2_obj, 5.0f);
    TEST_ASSERT_EQUAL_FLOAT(0.0f, Tkind_cbase2_GetFloatProp(&cbase2_obj));
}

TEST(Tkindcbase2, GetFloatPropOnEmptyVtReturns0)
{
    memset(&cbase2_obj,0u,sizeof(cbase2_obj));
    cbase2_obj.p_vtable = &cbase2_empty_vtable;
    Tkind_cbase2_SetFloatProp(&cbase2_obj, 5.0f);
    TEST_ASSERT_EQUAL_FLOAT(0.0f, Tkind_cbase2_GetFloatProp(&cbase2_obj));
}

TEST_GROUP_RUNNER(Tkindcbase2)
{
    RUN_TEST_CASE(Tkindcbase2, InitReturnsTrue);
    RUN_TEST_CASE(Tkindcbase2, InitNullPtrReturnsFalse);
    RUN_TEST_CASE(Tkindcbase2, Property1Uninitialized);
    RUN_TEST_CASE(Tkindcbase2, Property1Set);
    RUN_TEST_CASE(Tkindcbase2, GetFloatPropWithNullPtrIsSafe);
    RUN_TEST_CASE(Tkindcbase2, GetFloatPropOnZerosReturns0);
    RUN_TEST_CASE(Tkindcbase2, GetFloatPropOnEmptyVtReturns0);
}
/*******************************************************************************
 *
 * Private function bodies.
 *
 ******************************************************************************/
