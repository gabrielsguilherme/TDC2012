using System;
using System.Runtime.InteropServices;

namespace TDC2012
{
    [StructLayout(LayoutKind.Sequential)]
    public struct WorkerResult
    {
        public int Id;
        public bool IsWorking;

        [MarshalAs(UnmanagedType.LPStr)]
        public string Name;
    }

    [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
    public delegate void WorkerCallback(WorkerResult result);

    public class PInvokeManaged : IDisposable
    {
        public WorkerCallback Callback { get; private set; }

        public PInvokeManaged()
        {            
            InitWorker();
        }

        public void WorkerCallbackHandler(WorkerResult result)
        {
            Console.WriteLine(result.Id);
            Console.WriteLine(result.IsWorking);
            Console.WriteLine(result.Name);
        }

        public void Dispose()
        {
            DisposeWorker();
        }

        public bool ExecuteUnmanaged()
        {
            Callback = new WorkerCallback(WorkerCallbackHandler);
            return Execute(Callback, "Pass an String");
        }

        public void TrySomeArray()
        {
            int[] container = new int[5];
            
            for (int count = 0; count < 5; ++count)
            {
                container[count] = count;
                Console.WriteLine(container[count]);
            }

            WorkWithArray(5, container);

            foreach (int value in container)
            {
                Console.WriteLine(value);
            }

            GC.KeepAlive(container);
        }


        [DllImport("PInvokeWrapper.dll", EntryPoint = "InitWorker", CharSet = CharSet.Auto, CallingConvention = CallingConvention.Cdecl)]
        public static extern bool InitWorker();

        [DllImport("PInvokeWrapper.dll", EntryPoint = "DisposeWorker", CharSet = CharSet.Auto, CallingConvention = CallingConvention.Cdecl)]
        public static extern bool DisposeWorker();

        [DllImport("PInvokeWrapper.dll", EntryPoint = "Execute", CharSet = CharSet.Auto, CallingConvention = CallingConvention.Cdecl)]
        public static extern bool Execute(WorkerCallback callback, string name);

        [DllImport("PInvokeWrapper.dll", EntryPoint = "WorkWithArray", CharSet = CharSet.Auto, CallingConvention = CallingConvention.Cdecl)]
        public static extern void WorkWithArray(int size,[In, Out]int[] container);
    }
}
