# 如何添加一个单元测试用例
1. 拷贝一份TestFixture_ProductionCode.c，并重命名为TestFixture_XYZ.c
2. 将需要测试的函数所在的头文件包含到TestFixture_XYZ.c中，如#include "XYZ.h"
3. 将文件中的ProductionCode替换为自定义的测试用例集相关的字符串，如XYZ；
4. 为需要执行单元测试的函数编写对应的单元测试用例，如函数XYZ_func1可以写为TEST(XYZ, test_XYZ_func1)；
5. TEST(XYZ, test_XYZ_func1)中可以执行XYZ_func1的返回值执行检查，可以使用TEST_ASSERT_EQUAL，TEST_ASSERT_NOT_EQUAL之类的断言判断；
6. 若TEST(XYZ, test_XYZ_func1)中某个断言判断失败，则此用例立即中断并退出，并在最终的打印中通过文件名和行号打印；
7. 若TEST(XYZ, test_XYZ_func1)中的所有断言均通过，则不会打印任何信息；
8. 按此方法对每个XYZ相关的函数执行函数级别的单元测试用例编写；
9. 最后编写TEST_GROUP_RUNNER(XYZ)，将每个编写的单元测试加入到TEST_GROUP_RUNNER(XYZ)的函数中，如RUN_TEST_CASE(XYZ, test_XYZ_func1);
10. 在AllTests.c中将TEST_GROUP_RUNNER(XYZ);添加到runAllTests函数中；
11. 将_UNITY_TEST_宏添加到C的预编译器中（右键点击工程名称-> Properties->C/C++ Builder->Settings->GNU RISC-V Cross C Compiler->Preprocessor->Defined symbols），重选编译工程（用于区分当前运行的是单元测试main函数）
12. 在Simulator中运行单元测试：右键点击工程名称-> Launch Qemu Debug->弹出Edit Configuration->点击Debug（保持默认配置）-> 点击工具类中的绿色三角形（恢复Resume按钮）继续执行debug流程

示例：
=============== 复制一份TestFixture_ProductionCode.c，并修改为如下文件内容，名称TestFixture_BasicOperation.c =============
TestFixture_BasicOperation.c（说明中的XYZ就是BasicOperation）
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
}


TEST_GROUP_RUNNER(BasicOperation)
{
    RUN_TEST_CASE(BasicOperation, test_GetMax);
}



=============== AllTests.c修改 =============
#include "unity_fixture.h"

static void runAllTests(void)
{
	// 将所有的RUN_TEST_GROUP添加到此处
    RUN_TEST_GROUP(ProductionCode);
    RUN_TEST_GROUP(BasicOperation); // 添加此行
}

#ifdef _UNITY_TEST_
int main(int argc, const char* argv[])
{
    return UnityMain(argc, argv, runAllTests);
}
#endif
