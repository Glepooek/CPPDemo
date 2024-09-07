// CPPDemo.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<string>  
#include <limits>  
using namespace std;

// 定义常量
#define LENGTH 10
#define WIDTH 5.6
#define NEWLINE 'a'

// 函数声明
int Max(int num1, int num2);

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
		num1 = num2;
	}

	return result;
}

const int MAX = 3;

/*
*main()是程序开始执行的入口
*/
int main()
{

	int  var[MAX] = { 10, 100, 200 };
	int  *ptr;

	// 指针中最后一个元素的地址
	ptr = &var[MAX - 1];
	for (int i = MAX; i > 0; i--)
	{
		cout << "Address of var[" << i << "] = ";
		cout << ptr << endl;

		cout << "Value of var[" << i << "] = ";
		cout << *ptr << endl;

		// 移动到下一个位置
		ptr--;
	}

	system("pause");

	return 0;
}

// 枚举
enum Color
{
	red,//默认值为0，下面一次递增
	green,
	blue
}aa;

/*
结构体
*/
struct Employee
{
	char first_name[16];
	int age;
}emp;



