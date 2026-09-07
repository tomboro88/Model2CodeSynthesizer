/*
 * @file Tkindcbase1_test.c
 *
 * @brief Source code of the Tkind package cbase1 test cases.
 * @author tomboro88
 * @date   15 May 2026
 * @copyright (c) 2026 tomboro88. 
 * @license SPDX-License-Identifier: EPL-2.0
 * @project github.com/tomboro88/Model2CodeSynthesizer
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
static tkind_cbase1_t                  cbase1_obj;
static const tkind_cbase1_vt_t         empty_vtable = {0};
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
    tkind_cbase1_init(&cbase1_obj);
}

TEST_TEAR_DOWN(Tkindcbase1)
{

}

TEST(Tkindcbase1, InitReturnsTrue)
{
    TEST_ASSERT_TRUE(tkind_cbase1_init(&cbase1_obj));
}

TEST(Tkindcbase1, InitNullPtrReturnsFalse)
{
    TEST_ASSERT_FALSE(tkind_cbase1_init(NULL));
}

TEST(Tkindcbase1, Property1Uninitialized)
{
    TEST_ASSERT_EQUAL_UINT32(TKIND_CBASE1_TEST_PROP1_DEFAULT,
                             tkind_cbase1_getuintprop(&cbase1_obj));
}

TEST(Tkindcbase1, Property1Set)
{
    tkind_cbase1_setuintprop(&cbase1_obj, 5u);
    TEST_ASSERT_EQUAL_UINT32(5u,
                             tkind_cbase1_getuintprop(&cbase1_obj));
}

TEST(Tkindcbase1, SetUintPropWithNullPtrIsSafe)
{
    tkind_cbase1_setuintprop(NULL, 5u);
    TEST_ASSERT_TRUE(true);
}

TEST(Tkindcbase1, SetUintPropOnZerosIsSafe)
{
    memset(&cbase1_obj,0u,sizeof(cbase1_obj));
    tkind_cbase1_setuintprop(&cbase1_obj, 5u);
    TEST_ASSERT_EQUAL_UINT32(0u, tkind_cbase1_getuintprop(&cbase1_obj));
}

TEST(Tkindcbase1, SetUintPropOnEmptyVtIsSafe)
{
    memset(&cbase1_obj,0u,sizeof(cbase1_obj));
    cbase1_obj.p_vtable = &empty_vtable;
    tkind_cbase1_setuintprop(&cbase1_obj, 5u);
    TEST_ASSERT_EQUAL_UINT32(0u, tkind_cbase1_getuintprop(&cbase1_obj));
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
