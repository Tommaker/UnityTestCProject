/* =========================================================================
    Unity - A Test Framework for C
    ThrowTheSwitch.org
    Copyright (c) 2007-24 Mike Karlesky, Mark VanderVoord, & Greg Williams
    SPDX-License-Identifier: MIT
========================================================================= */

#include "unity_fixture.h"
#include "ProductionCode.h"

/***************************固定的定义部分，每个测试文件中都必须带**********************************/
// ProductionCode为需要测试的TestSuite Name，一个测试用例集合
TEST_GROUP(ProductionCode);

TEST_SETUP(ProductionCode)
{
	  /* This is run before EACH TEST */
	  Counter = 0x5a5a;
}

TEST_TEAR_DOWN(ProductionCode)
{
}

/***************************定义测试函数在如下位置**********************************/
/*****
	每个TEST是一个用例，每个用例运行前先执行对应的TEST_SETUP，用例运行结束后执行TEST_TEAR_DOWN;
	若用例的中间某个检查失败则用例执行失败!
***/
TEST(ProductionCode, test_WhichIsBroken_ShouldReturnZeroIfItemIsNotInList)
{
	  /* All of these should pass */
	  TEST_ASSERT_EQUAL(0, FindFunction_WhichIsBroken(78));
	  TEST_ASSERT_EQUAL(0, FindFunction_WhichIsBroken(2));
	  TEST_ASSERT_EQUAL(0, FindFunction_WhichIsBroken(33));
	  TEST_ASSERT_EQUAL(0, FindFunction_WhichIsBroken(999));
	  TEST_ASSERT_EQUAL(0, FindFunction_WhichIsBroken(-1));
}


TEST(ProductionCode, test_WhichIsBroken_ShouldReturnTheIndexForItemsInList)
{
	  /* You should see this line fail in your test summary */
	  TEST_ASSERT_EQUAL(1, FindFunction_WhichIsBroken(34));

	  /* Notice the rest of these didn't get a chance to run because the line above failed.
	   * Unit tests abort each test function on the first sign of trouble.
	   * Then NEXT test function runs as normal. */
	  TEST_ASSERT_EQUAL(8, FindFunction_WhichIsBroken(8888));
}

TEST(ProductionCode, test_ShouldReturnTheCurrentCounterValue)
{
    /* This should be true because setUp set this up for us before this test */
    TEST_ASSERT_EQUAL_HEX(0x5a5a, FunctionWhichReturnsLocalVariable());

    /* This should be true because we can still change our answer */
    Counter = 0x1234;
    TEST_ASSERT_EQUAL_HEX(0x1234, FunctionWhichReturnsLocalVariable());
}

TEST(ProductionCode, test_ShouldReturnTheCurrentCounterValueAgain)
{
    /* This should be true again because setup was rerun before this test (and after we changed it to 0x1234) */
    TEST_ASSERT_EQUAL_HEX(0x5a5a, FunctionWhichReturnsLocalVariable());
}


TEST(ProductionCode, test_ShouldReturnCurrentCounter)
{
    /* Sometimes you get the test wrong.  When that happens, you get a failure too... and a quick look should tell
     * you what actually happened...which in this case was a failure to setup the initial condition. */
    TEST_ASSERT_EQUAL_HEX(0x1234, FunctionWhichReturnsLocalVariable());
}


/***************************将需要运行的用例填写在用例集合中**********************************/
/***** 一个RUN_TEST_CASE对应一条用例，用例运行结束后的统计也是根据RUN_TEST_CASE计算的 ***/
/***** TEST_GROUP_RUNNER需要放到AllTests.c中调用方可执行! ***/
TEST_GROUP_RUNNER(ProductionCode)
{
    RUN_TEST_CASE(ProductionCode, test_WhichIsBroken_ShouldReturnZeroIfItemIsNotInList);
    RUN_TEST_CASE(ProductionCode, test_WhichIsBroken_ShouldReturnTheIndexForItemsInList);
    RUN_TEST_CASE(ProductionCode, test_ShouldReturnTheCurrentCounterValue);
    RUN_TEST_CASE(ProductionCode, test_ShouldReturnTheCurrentCounterValueAgain);
    RUN_TEST_CASE(ProductionCode, test_ShouldReturnCurrentCounter);
}
