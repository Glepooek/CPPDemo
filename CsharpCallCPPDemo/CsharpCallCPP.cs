using System;
using System.Runtime.ExceptionServices;
using System.Runtime.InteropServices;
using System.Security;

namespace CsharpCallCPPDemo
{
    // 被调用方清理堆栈
    [UnmanagedFunctionPointer(CallingConvention.StdCall)]
    public delegate void TestCallback(int currentNum);

    /// <summary>
    /// C#通过P/Invoke方式调用C++动态链接库实现类
    /// </summary>
    public class CsharpCallCPP
    {
        private const string DLL_FILE_NAME = "CPPDemoLib.dll";
        private static TestCallback mTestCallback = null;

        /// <summary>
        /// 获取两个数之间的最大值
        /// </summary>
        /// <param name="x"></param>
        /// <param name="y"></param>
        /// <returns></returns>
        public static void GetMaxValue(int x, int y)
        {
            Console.WriteLine("获取两个数之间的最大值");
            Console.WriteLine($"{Max(x, y)}");
            Console.WriteLine();
        }

        /// <summary>
        /// 获取处理进度。C#委托传入C++
        /// </summary>
        public static void GetProgressValue()
        {
            Console.WriteLine("获取处理进度");
            mTestCallback = new TestCallback(GetCallbackData);
            DoWork(mTestCallback);
            Console.WriteLine();
        }

        /// <summary>
        /// 获取字符串长度
        /// </summary>
        public static void GetLength()
        {
            Console.WriteLine("获取字符串长度");
            Console.WriteLine($"{GetLengthofString("hello world")}");
            Console.WriteLine($"{GetLengthofString("获取字符串长度")}");
            Console.WriteLine();
        }

        public static void TestExceptionCahch()
        {
            /**
             .net不会捕获AccessViolationException异常。
             因为它们被认为是进程状态损坏的异常。
             要捕获这些异常，可以使用 HandleProcessCorruptedStateExceptions 特性和 SecurityCritical 特性。       
             */

            try
            {
                Console.WriteLine("捕获C++异常");
                //TestExceptionCahch1();
                //TestExceptionCahch2();
            }
            catch (Exception ex)
            {
                Console.WriteLine(ex.Message);
            }
        }

        private static void GetCallbackData(int currentNum)
        {
            Console.WriteLine(currentNum);
        }

        #region C++ Methods

        [DllImport(DLL_FILE_NAME, CallingConvention = CallingConvention.Cdecl)]
        extern static int Max(int x, int y);
        [DllImport(DLL_FILE_NAME, CallingConvention = CallingConvention.Cdecl)]
        extern static void DoWork([MarshalAs(UnmanagedType.FunctionPtr)] TestCallback callback);
        [DllImport(DLL_FILE_NAME, CallingConvention = CallingConvention.Cdecl)]
        extern static int GetLengthofString(string msg);
        /// <summary>
        /// 用于在C#中调用时测试异常捕获
        /// </summary>
        [DllImport(DLL_FILE_NAME, CallingConvention = CallingConvention.Cdecl)]
        private extern static void TestExceptionCahch1();
        /// <summary>
        /// 用于在C#中调用时测试异常捕获
        /// </summary>
        [DllImport(DLL_FILE_NAME, CallingConvention = CallingConvention.Cdecl)]
        private extern static void TestExceptionCahch2();

        #endregion
    }
}
