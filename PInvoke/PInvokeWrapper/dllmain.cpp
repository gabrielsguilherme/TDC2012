#include "stdafx.h"
#include "PInvokeWrapper.h"

using namespace TDC2012;

PInvokeWrapper* g_WorkerWrapper = nullptr;

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
					 )
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}

bool IsWorkerInit()
{
	return g_WorkerWrapper != nullptr;
}

bool __cdecl InitWorker()
{
	if(!IsWorkerInit())
	{
		g_WorkerWrapper = new PInvokeWrapper();
		return true;
	}
	return false;
}

bool __cdecl DisposeWorker()
{
	if(IsWorkerInit())
	{
		delete g_WorkerWrapper;
		g_WorkerWrapper = nullptr;
		return true;
	}
	return false;
}

string ParseManagedString(LPWSTR input)
{
	string ret;
	wstring temp;

	if(input != nullptr && *input)
	{
		temp = input;

		if(!temp.empty())
		{
			ret.assign(temp.begin(), temp.end());
		}
	}

	return ret;
}

bool __cdecl Execute(WorkerCallback callback, LPWSTR name)
{
	if(IsWorkerInit())
	{
		g_WorkerWrapper->SetWorkerName(ParseManagedString(name));
		::DebugBreak();
		g_WorkerWrapper->Work(callback);
		return true;
	}
	return false;
}

void __cdecl WorkWithArray(int size, int* container)
{
	if(IsWorkerInit())
	{
		for (int count = 0; count < size; ++count)
		{
			container[count] = count*size;
		}
		::DebugBreak();
	}
}