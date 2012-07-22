using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace TDC2012
{
    public class Program
    {
        static void Main(string[] args)
        {
            PInvokeManaged wrapper = new PInvokeManaged();

            wrapper.TrySomeArray();

            Console.ReadLine();

            wrapper.ExecuteUnmanaged();

            Console.ReadLine();
        }
    }
}
