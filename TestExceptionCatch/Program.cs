using System;
using System.Runtime.ExceptionServices;
using System.Runtime.InteropServices;
using System.Security;

namespace TestExceptionCatch
{
    class Program
    {
        [DllImport("CPPDemoLib.dll", CallingConvention = CallingConvention.Cdecl)]
        private extern static void TestExceptionCahch1();
        [DllImport("CPPDemoLib.dll", CallingConvention = CallingConvention.Cdecl)]
        private extern static void TestExceptionCahch2();

        [SecurityCritical, HandleProcessCorruptedStateExceptions]
        static void Main(string[] args)
        {
            try
            {
                // 在.NET4.0中破坏性异常不能直接被捕获
                // 解决方案一：在方法上加标签[SecurityCritical, HandleProcessCorruptedStateExceptions]
                // 解决方案二：告诉CLR 4.0，整个.NET程序都要使用老的异常捕捉机制
                // 在app.config中增加：
                // < runtime >
                // < legacyCorruptedStateExceptionsPolicy enabled = "true" />
                //</ runtime >
                TestExceptionCahch1();
                // 在.NET4.0中该异常可以直接被捕获
                //TestExceptionCahch2();
            }
            catch (Exception ex)
            {
                Console.WriteLine(ex.Message);
            }
            finally
            {
                Console.ReadLine();
            }
        }
    }
}
