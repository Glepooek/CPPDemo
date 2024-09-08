#include "pch.h"
#include "TestMath.h"

// 函数定义
MYLIBRARY_API int Max(int num1, int num2)
{
	int result = 0;
	if (num1 > num2)
	{
		result = num1;
	}
	else
	{
		result = num2;
	}

	return result;
}

MYLIBRARY_API void DoWork(ProgressCallback callback)
{
	for (int i = 0; i < 5; i++)
	{
		if (callback)
		{
			callback(i);
		}
	}
}

MYLIBRARY_API int GetLengthofString(char* msg)
{
	// sizeof(msg); 获取分配空间的大小
	return strlen(msg);
}

/// <summary>
/// 用于在C#中调用时测试异常捕获
/// </summary>
MYLIBRARY_API void TestExceptionCahch1()
{
	int* p = NULL;

	// 会导致.NET抛出一个AccessViolation异常
	*p = 10;
}

/// <summary>
/// 用于在C#中调用时测试异常捕获
/// </summary>
MYLIBRARY_API void TestExceptionCahch2()
{
	int x = 10;
	int y = 0;
	int z = x / y;
}