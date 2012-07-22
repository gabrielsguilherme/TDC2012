#pragma once
#include "Stdafx.h"
#include "MixedWrapper.h"
#include "..\UnmanagedCore\CoreWorker.h"
#include "..\UnmanagedCore\ICoreCallback.h"

namespace POC 
{
	ref class MixedWrapper;

	class NativeHandler : ICoreCallback
	{
	public:
		NativeHandler();
		NativeHandler(MixedWrapper^ input);
		~NativeHandler();
		
		bool Invoke();
		bool Invoke(string text, int number);
		
		void ExecWorker();
		void ExecWorker(String^ text, int number);

	protected:
		char* StringToChar(String^ param);
		String^ CharToString(char* param); 
		String^ CharToString(string param);

	private:
		CoreWorker* _worker;
		msclr::auto_gcroot<MixedWrapper^> _managed;			
	};
}