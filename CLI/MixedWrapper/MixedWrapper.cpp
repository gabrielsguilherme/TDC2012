#include "stdafx.h"
#include "MixedWrapper.h"

namespace POC
{
	MixedWrapper::MixedWrapper()
	{
		//Define metodos de callback para um metodo de um classe
		OnCallback += gcnew ManagedCallback(this, &MixedWrapper::UnManagedTarget);
		OnParamCallback += gcnew ParameterizedCallback(this, &MixedWrapper::ParameterizedTarget);
		
		_nativeHndl = new NativeHandler(this);
	}

	MixedWrapper::~MixedWrapper()
	{
		GC::KeepAlive(onCallback);
		GC::KeepAlive(onParamCallback);

		if(_nativeHndl != nullptr)
		{
			delete _nativeHndl;
			_nativeHndl = nullptr;
		}
	}

	bool MixedWrapper::UnManagedTarget()
	{
		System::Console::WriteLine("UnManagedTarget - Ok");
		return true;
	}

	bool MixedWrapper::ParameterizedTarget(String^ text, int number)
	{
		System::Console::WriteLine("ParameterizedTarget - text: {0} - number: {1}", text, number);
		return true;
	}

	void MixedWrapper::StartProcess()
	{
		_nativeHndl->ExecWorker();
	}

	void MixedWrapper::StartParameterizedProcess(String^ text, int number)
	{
		_nativeHndl->ExecWorker(text, number);
	}
}