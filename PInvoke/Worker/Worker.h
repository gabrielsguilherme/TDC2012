#pragma once
#include "stdafx.h"
#include "WorkerResult.h"

using namespace std;

namespace TDC2012
{
	typedef void (__cdecl *WorkerCallback)(WorkerResult result);

	class Worker
	{
		public:
			Worker();
			virtual ~Worker();

			int Id() const;
			void Id(int val);

			string Name() const;
			void Name(string val);

			bool IsWorking() const;
			void IsWorking(bool val);

			WorkerCallback Callback() const;
			void Callback(WorkerCallback val);

			void DoSomething();

		private:
			int				_id;
			string			_name;
			bool			_isWorking;
			WorkerCallback	_callback;
	};
}