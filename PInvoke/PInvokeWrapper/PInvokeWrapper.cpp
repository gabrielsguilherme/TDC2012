#include "stdafx.h"
#include "PInvokeWrapper.h"

#pragma comment(lib, "Worker.lib")

using namespace TDC2012;

PInvokeWrapper::PInvokeWrapper()
{
	_worker = new Worker();
	_worker->Id(1);
	_worker->Name("PInvokeWorker");
	_worker->IsWorking(false);
	_worker->Callback(nullptr);
}

PInvokeWrapper::~PInvokeWrapper()
{
	if(_worker != nullptr)
	{
		delete _worker;
		_worker = nullptr;
	}
}

void PInvokeWrapper::SetWorkerName(string name)
{
	_worker->Name(name);
}

void PInvokeWrapper::Work(WorkerCallback callback)
{
	_worker->Callback(callback);
	_worker->DoSomething();
}