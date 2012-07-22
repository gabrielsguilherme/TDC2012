#pragma once
#include "stdafx.h"
#include "ICoreCallback.h"
#include "AsyncWorkArgs.h"

using namespace std;

namespace POC
{
	class CoreWorker
	{
		public:
			CoreWorker(ICoreCallback* callback);
			virtual ~CoreWorker();
			
			bool Process();
			bool Process(string text, int number);
			
		protected:
			static DWORD WINAPI AsyncWork(void* args);

		private:
			HANDLE			_handle;
			AsyncWorkArgs*	_args;
	};
}