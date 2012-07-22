using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using POC;

namespace POC
{
    public class Program
    {
        static void Main(string[] args)
        {
            MixedWrapper wrapper = new MixedWrapper();

            wrapper.StartProcess();

            Console.ReadLine();
            
            wrapper.StartParameterizedProcess("Param", new Random().Next());

            Console.ReadLine();
        }
    }
}
