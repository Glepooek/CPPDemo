#include "stdafx.h"

extern "C"
{
	__declspec(dllexport) int Max(int x, int y);
}

// º¯Êı¶¨Òå
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