using System;

// C# 中的结构有以下特点：

// 结构可带有方法、字段、索引、属性、运算符方法和事件。
//结构可定义构造函数，但不能定义析构函数。但是，您不能为结构定义无参构造函数。无参构造函数(默认)是自动定义的，且不能被改变。
//与类不同，结构不能继承其他的结构或类。
//结构不能作为其他结构或类的基础结构。
//结构可实现一个或多个接口。
//结构成员不能指定为 abstract、virtual 或 protected。
//当您使用 New 操作符创建一个结构对象时，会调用适当的构造函数来创建结构。与类不同，结构可以不使用 New 操作符即可被实例化。

namespace CsharpCallCPPDemo
{
	struct Student
	{
		public string name;
		public int age;
		public Sex sex;

		public void SetStudent(string name, int age, Sex sex)
		{
			this.name = name;
			this.age = age;
			this.sex = sex;
		}

		public void Display()
		{
			Console.WriteLine($"{this.name} {this.age} {this.sex}");
		}
	}

	enum Sex
	{
		Male,
		Female
	}
}
