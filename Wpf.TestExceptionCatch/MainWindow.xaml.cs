using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.ExceptionServices;
using System.Runtime.InteropServices;
using System.Security;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace Wpf.TestExceptionCatch
{
    /// <summary>
    /// MainWindow.xaml 的交互逻辑
    /// </summary>
    public partial class MainWindow : Window
    {
        [DllImport("CPPDemoLib.dll", CallingConvention = CallingConvention.Cdecl)]
        private extern static void TestExceptionCahch1();
        [DllImport("CPPDemoLib.dll", CallingConvention = CallingConvention.Cdecl)]
        private extern static void TestExceptionCahch2();

        public MainWindow()
        {
            InitializeComponent();
            Test();
        }

        [SecurityCritical, HandleProcessCorruptedStateExceptions]
        private void Test()
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

            }

        }
    }
}
