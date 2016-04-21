#pragma once
#include <functional>

struct asSFuncPtr;

class asIScriptContext;
class asIScriptEngine;
class asIScriptFunction;
class CScriptBuilder;

namespace Quad_Engine
{
	namespace Script
	{
		class ScriptSystem
		{
		public:
			static void Create();
			static void Destroy();
			static ScriptSystem* GetInstance();

			void Init(const std::function<void()>& aRegisterCppFunction);

			void LoadScript(const std::string& aFile);

			void Update(const float aDeltaTime);

			void RegisterFunction(const char* aFunction, const asSFuncPtr& aFunctionPtr);
		private:
			static ScriptSystem* myInstance;
			ScriptSystem();
			~ScriptSystem();

		private:
			asIScriptEngine* myScriptEngine;
			asIScriptContext* myScriptContext;
			asIScriptFunction* myUpdateFunction;
			CScriptBuilder* myScriptBuilder;
		};
	}
}