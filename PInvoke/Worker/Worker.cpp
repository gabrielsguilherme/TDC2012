#include "stdafx.h"
#include "Worker.h"

#define SLEEP_TIME 60

using namespace TDC2012;

Worker::Worker()
{
}

Worker::~Worker()
{
}

bool Worker::IsWorking() const 
{ 
	return _isWorking; 
}

void Worker::IsWorking(bool val) 
{ 
	_isWorking = val; 
}

string Worker::Name() const 
{
	return _name; 
}

void Worker::Name(string val) 
{ 
	_name = val; 
}

int Worker::Id() const 
{ 
	return _id; 
}

void Worker::Id(int val) 
{ 
	_id = val; 
}

WorkerCallback Worker::Callback() const 
{ 
	return _callback; 
}

void Worker::Callback(WorkerCallback val) 
{ 
	_callback = val; 
}

void Worker::DoSomething()
{
	Sleep(SLEEP_TIME);
	
	if(_callback != nullptr)
	{
		WorkerResult result;
		result.Id = _id;
		result.IsWorking = _isWorking;
		result.Name = (LPSTR)_name.c_str();

		_callback(result);
	}
}