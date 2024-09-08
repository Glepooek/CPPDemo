#pragma once

#ifdef MYLIBRARY_EXPORTS
#define MYLIBRARY_API __declspec(dllexport)
#else
#define MYLIBRARY_API __declspec(dllimport)
#endif

// ¶¨ÒåÎ¯ÍÐ
typedef void(__stdcall* ProgressCallback)(int);

extern "C"
{
	MYLIBRARY_API int Max(int num1, int num2);
	MYLIBRARY_API void DoWork(ProgressCallback callback);
	MYLIBRARY_API int GetLengthofString(char* msg);
	MYLIBRARY_API void TestExceptionCahch1();
	MYLIBRARY_API void TestExceptionCahch2();
};

class TestMath
{
public:
};
