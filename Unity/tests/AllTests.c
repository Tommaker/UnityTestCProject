/* =========================================================================
    Unity - A Test Framework for C
    ThrowTheSwitch.org
    Copyright (c) 2007-24 Mike Karlesky, Mark VanderVoord, & Greg Williams
    SPDX-License-Identifier: MIT
========================================================================= */

#include "unity_fixture.h"

static void runAllTests(void)
{
	// 将所有的RUN_TEST_GROUP添加到此处
    RUN_TEST_GROUP(ProductionCode);
    RUN_TEST_GROUP(BasicOperation);
}

#ifdef _UNITY_TEST_
int main(int argc, const char* argv[])
{
    return UnityMain(argc, argv, runAllTests);
}
#endif
