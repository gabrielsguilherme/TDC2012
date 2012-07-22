#include "Stdafx.h"
#include "NativeHandler.h"

#pragma comment(lib,"UnmanagedCore.lib")

namespace POC
{
	NativeHandler::NativeHandler()
	{
		_managed = nullptr;
		_worker = new CoreWorker(this);
	}

	NativeHandler::NativeHandler(MixedWrapper^ input)
	{
		_managed = input;
		_worker = new CoreWorker(this);
	}

	NativeHandler::~NativeHandler()
	{
		if(_worker != nullptr)
		{
			delete _worker;
			_worker = nullptr;
		}
	}

	bool NativeHandler::Invoke()
	{	
		_managed->OnCallback();
		return true;
	}

	bool NativeHandler::Invoke(string text, int number)
	{
		String^ managedText = CharToString(text);
		_managed->OnParamCallback(managedText, number);
		return true;
	}

	void NativeHandler::ExecWorker()
	{
		_worker->Process();
	}

	void NativeHandler::ExecWorker(String^ text, int number)
	{
		string inputText = StringToChar(text);
		_worker->Process(inputText,  number);
	}

	char* NativeHandler::StringToChar(String^ param) 
	{ 
		if(String::IsNullOrEmpty(param))
		{
			return "";
		}

		return (char*)(void*)Marshal::StringToHGlobalAnsi(param);
	}

	String^ NativeHandler::CharToString(char* param) 
	{ 
		return gcnew String(param);
	}

	String^ NativeHandler::CharToString(string param) 
	{ 
		return gcnew String(param.c_str());
	}
}