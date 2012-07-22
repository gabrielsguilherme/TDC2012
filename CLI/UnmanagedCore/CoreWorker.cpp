#include "stdafx.h"
#include "CoreWorker.h"

#define WORK_TIME 60

using namespace std;
using namespace POC;

CoreWorker::CoreWorker(ICoreCallback* callback)
{
	_handle = nullptr;
	_args = new AsyncWorkArgs(callback);
}

CoreWorker::~CoreWorker()
{
	if(_args != nullptr)
	{
		delete _args;
		_args = nullptr;
	}

	::CloseHandle(_handle);
}

DWORD WINAPI CoreWorker::AsyncWork(void* args)
{
	Sleep(WORK_TIME);
	AsyncWorkArgs* workArgs = (AsyncWorkArgs*)args;

	if(workArgs != nullptr)
	{
		if(workArgs->TextInput().empty() && workArgs->NumberInput() < 1)
		{
			::DebugBreak();
			workArgs->Callback()->Invoke();
		}
		else
		{
			::DebugBreak();
			string text = workArgs->TextInput();
			int number = workArgs->NumberInput();
			workArgs->Callback()->Invoke(text, number);
		}
	}

	return 0;
}

bool CoreWorker::Process()
{
	_handle = ::CreateThread(NULL, 0, &CoreWorker::AsyncWork, _args, 0, 0);

	::DebugBreak();

	if(_handle == nullptr)
	{
		return false;
	}

	return true;
}

bool CoreWorker::Process(string text, int number)
{
	_args->NumberInput(number);
	_args->TextInput(text);

	_handle = ::CreateThread(NULL, 0, &CoreWorker::AsyncWork, _args, 0, 0);

	::DebugBreak();

	if(_handle == nullptr)
	{
		return false;
	}

	return true;
}