#pragma once
#include "Stdafx.h"
#include "NativeHandler.h"
#include "..\UnmanagedCore\CoreWorker.h"
#include "..\UnmanagedCore\ICoreCallback.h"

namespace POC 
{
	class NativeHandler;

	public ref class MixedWrapper 
	{
		public:
			delegate bool ManagedCallback();
			delegate bool ParameterizedCallback(String^ text, int number);

			ManagedCallback^ onCallback;
			ParameterizedCallback^ onParamCallback;

			event ManagedCallback^ OnCallback
			{
				void add(ManagedCallback^ input)
				{
					onCallback += input;
				}

				void remove(ManagedCallback^ input)
				{
					onCallback -= input;
				}

				bool raise()
				{
					if(onCallback != nullptr)
					{
						return onCallback->Invoke();
					}

					return false;
				}
			};

			event ParameterizedCallback^ OnParamCallback
			{
				void add(ParameterizedCallback^ input)
				{
					onParamCallback += input;
				}

				void remove(ParameterizedCallback^ input)
				{
					onParamCallback -= input;
				}

				bool raise(String^ text, int number)
				{
					if(onParamCallback != nullptr)
					{
						return onParamCallback->Invoke(text, number);
					}

					return false;
				}
			};

			MixedWrapper();
			virtual ~MixedWrapper();
			
			void StartProcess();
			void StartParameterizedProcess(String^ text, int number);
			
			bool UnManagedTarget();
			bool ParameterizedTarget(String^ text, int number);

		private:
			NativeHandler* _nativeHndl;
	};
}
