#pragma once
#include "stdafx.h"
#include "..\Worker\Worker.h"
#include "..\Worker\WorkerResult.h"

using namespace std;

namespace TDC2012
{
	class PInvokeWrapper
	{
		public:
			PInvokeWrapper();
			virtual ~PInvokeWrapper();

			void SetWorkerName(string name);
			void Work(WorkerCallback callback);

		private:
			Worker*	_worker;
	};
}