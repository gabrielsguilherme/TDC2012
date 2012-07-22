#pragma once
#include "stdafx.h"
#include "ICoreCallback.h"

using namespace std;

namespace POC
{
	class AsyncWorkArgs
	{
	private:
		int				_numberInput;
		string			_textInput;		
		ICoreCallback*	_callback;

	public:
		AsyncWorkArgs(ICoreCallback* callback);
		virtual ~AsyncWorkArgs();

		int NumberInput() const;
		void NumberInput(int val);

		std::string TextInput() const;
		void TextInput(std::string val);

		ICoreCallback* Callback() const;
	};
}