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

// ��������
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
	// sizeof(msg); ��ȡ����ռ�Ĵ�С
	return strlen(msg);
}

/// <summary>
/// ������C#�е���ʱ�����쳣����
/// </summary>
void TestExceptionCahch1()
{
	int* p = NULL;

	// �ᵼ��.NET�׳�һ��AccessViolation�쳣
	*p = 10;
}

/// <summary>
/// ������C#�е���ʱ�����쳣����
/// </summary>
void TestExceptionCahch2()
{
	int x = 10;
	int y = 0;
	int z = x / y;
}