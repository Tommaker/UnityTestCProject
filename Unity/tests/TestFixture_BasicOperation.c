/* =========================================================================
    Unity - A Test Framework for C
    ThrowTheSwitch.org
    Copyright (c) 2007-24 Mike Karlesky, Mark VanderVoord, & Greg Williams
    SPDX-License-Identifier: MIT
========================================================================= */
#include "unity_fixture.h"
#include "BasicOperation.h"

TEST_GROUP(BasicOperation);

TEST_SETUP(BasicOperation)
{
	  /* This is run before EACH TEST */
}

TEST_TEAR_DOWN(BasicOperation)
{
}

TEST(BasicOperation, test_GetMax)
{
	  /* All of these should pass */
	  TEST_ASSERT_EQUAL(0, GetMax(0,0));
	  TEST_ASSERT_EQUAL(2, GetMax(2,1));
	  TEST_ASSERT_EQUAL(3, GetMax(1,3));
	  TEST_ASSERT_EQUAL(5, GetMax(-1,5));
	  TEST_ASSERT_EQUAL(1, GetMax(-5,1));
}


TEST(BasicOperation, test_GetMin)
{
	  /* All of these should pass */
	  TEST_ASSERT_EQUAL(0, GetMin(0,0));
	  TEST_ASSERT_EQUAL(2, GetMin(2,1));
	  TEST_ASSERT_EQUAL(1, GetMin(1,3));
	  TEST_ASSERT_EQUAL(-1, GetMin(-1,5));
	  TEST_ASSERT_EQUAL(-5, GetMin(-5,1));
}



TEST_GROUP_RUNNER(BasicOperation)
{
    RUN_TEST_CASE(BasicOperation, test_GetMax);
    RUN_TEST_CASE(BasicOperation, test_GetMin);
}
