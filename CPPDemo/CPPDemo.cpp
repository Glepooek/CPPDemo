// CPPDemo.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<string>  
#include <limits>  
using namespace std;

// ���峣��
#define LENGTH 10
#define WIDTH 5.6
#define NEWLINE 'a'

// ��������
int Max(int num1, int num2);

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
		num1 = num2;
	}

	return result;
}

const int MAX = 3;

/*
*main()�ǳ���ʼִ�е����
*/
int main()
{

	int  var[MAX] = { 10, 100, 200 };
	int  *ptr;

	// ָ�������һ��Ԫ�صĵ�ַ
	ptr = &var[MAX - 1];
	for (int i = MAX; i > 0; i--)
	{
		cout << "Address of var[" << i << "] = ";
		cout << ptr << endl;

		cout << "Value of var[" << i << "] = ";
		cout << *ptr << endl;

		// �ƶ�����һ��λ��
		ptr--;
	}

	system("pause");

	return 0;
}

// ö��
enum Color
{
	red,//Ĭ��ֵΪ0������һ�ε���
	green,
	blue
}aa;

/*
�ṹ��
*/
struct Employee
{
	char first_name[16];
	int age;
}emp;



