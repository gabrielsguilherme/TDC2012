#include "stdafx.h"
#include "AsyncWorkArgs.h"

using namespace std;
using namespace POC;

AsyncWorkArgs::AsyncWorkArgs(ICoreCallback* callback)
{
	_callback = callback;
}

AsyncWorkArgs::~AsyncWorkArgs()
{
}

int AsyncWorkArgs::NumberInput() const 
{ 
	return _numberInput; 
}

void AsyncWorkArgs::NumberInput(int val) 
{ 
	_numberInput = val; 
}

string AsyncWorkArgs::TextInput() const 
{
	return _textInput; 
}

void AsyncWorkArgs::TextInput(string val) 
{
	_textInput = val; 
}

ICoreCallback* AsyncWorkArgs::Callback() const 
{ 
	return _callback; 
}
