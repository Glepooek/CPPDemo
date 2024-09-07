#include "pch.h"

extern "C"
{
	__declspec(dllexport) int Max(int num1, int num2);
	typedef void(__stdcall* ProgressCallback)(int);
	__declspec(dllexport) void DoWork(ProgressCallback callback);
	__declspec(dllexport) int GetLengthofString(char* msg);
	__declspec(dllexport) void TestExceptionCahch1();
	__declspec(dllexport) void TestExceptionCahch2();

};

// 函数定义
int Max(int num1, int num2)
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

void DoWork(ProgressCallback callback)
{
	for (int i = 0; i < 5; i++)
	{
		if (callback)
		{
			callback(i);
		}
	}
}

int GetLengthofString(char* msg)
{
	// sizeof(msg); 获取分配空间的大小
	return strlen(msg);
}

/// <summary>
/// 用于在C#中调用时测试异常捕获
/// </summary>
void TestExceptionCahch1()
{
	int* p = NULL;

	// 会导致.NET抛出一个AccessViolation异常
	*p = 10;
}

/// <summary>
/// 用于在C#中调用时测试异常捕获
/// </summary>
void TestExceptionCahch2()
{
	int x = 10;
	int y = 0;
	int z = x / y;
}