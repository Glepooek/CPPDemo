using System;

namespace CsharpCallCPPDemo
{
	class Program
	{
		static void Main(string[] args)
		{
			// 获取两个数间的最大值
			CsharpCallCPP.GetMaxValue(6, 7);
			// 获取进度
			CsharpCallCPP.GetProgressValue();
			// 获取字符串长度
			CsharpCallCPP.GetLength();

			//CsharpCallCPP.TestExceptionCahch();

			Console.ReadLine();
		}
	}
}
