#pragma once
#include <string>

using namespace std;

namespace POC
{
	class ICoreCallback
	{
		public:
			virtual ~ICoreCallback() {};
			virtual bool Invoke() = 0;
			virtual bool Invoke(string text, int number) = 0;
	};
}