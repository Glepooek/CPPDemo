#include "pch.h"
#include "TestMath.h"

// ��������
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
	// sizeof(msg); ��ȡ����ռ�Ĵ�С
	return strlen(msg);
}

/// <summary>
/// ������C#�е���ʱ�����쳣����
/// </summary>
MYLIBRARY_API void TestExceptionCahch1()
{
	int* p = NULL;

	// �ᵼ��.NET�׳�һ��AccessViolation�쳣
	*p = 10;
}

/// <summary>
/// ������C#�е���ʱ�����쳣����
/// </summary>
MYLIBRARY_API void TestExceptionCahch2()
{
	int x = 10;
	int y = 0;
	int z = x / y;
}