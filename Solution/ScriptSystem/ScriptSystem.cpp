#include "stdafx.h"

#include <angelscript.h>
#include "scriptstdstring.h"
#include "scriptbuilder.h"
#include "ScriptSystem.h"
#include <string>

void MessageCallback(const asSMessageInfo* aMessage, void* aParam)
{
	const char* type = "ERR ";
	if (aMessage->type == asMSGTYPE_WARNING)
	{
		type = "WARN";
	}
	else if (aMessage->type == asMSGTYPE_INFORMATION)
	{
		type = "INFO";
	}
	printf("%s (%d, %d) : %s : %s\n", aMessage->section, aMessage->row, aMessage->col, type, aMessage->message);
}



namespace Quad_Engine
{
	namespace Script
	{
		ScriptSystem* ScriptSystem::myInstance = nullptr;
		void ScriptSystem::Create()
		{
			if (myInstance == nullptr)
			{
				myInstance = new ScriptSystem();
			}
		}

		void ScriptSystem::Destroy()
		{
			delete myInstance;
			myInstance = nullptr;
		}

		ScriptSystem* ScriptSystem::GetInstance()
		{
			return myInstance;
		}

		ScriptSystem::ScriptSystem()
		{
			myScriptEngine = asCreateScriptEngine();

			int result = myScriptEngine->SetMessageCallback(asFUNCTION(MessageCallback), 0, asCALL_CDECL);
			if (result < 0)
			{
				printf("[ScriptSystem] Error: Failed to SetMessageCallback.\n");
			}

			RegisterStdString(myScriptEngine);

			myScriptBuilder = new CScriptBuilder();
			myScriptContext = myScriptEngine->CreateContext();
		}

		ScriptSystem::~ScriptSystem()
		{
			delete myScriptBuilder;
			myScriptBuilder = nullptr;

			myScriptContext->Release();
			myScriptEngine->ShutDownAndRelease();
		}

		void ScriptSystem::Init(const std::function<void()>& aRegisterCppFunction)
		{
			aRegisterCppFunction();
		}

		void ScriptSystem::LoadScript(const std::string& aFile)
		{
			int result = myScriptBuilder->StartNewModule(myScriptEngine, "ScriptModule");
			if (result < 0)
			{
				printf("[ScriptSystem] Error: Failed to start a new module.\n");
				return;
			}
			result = myScriptBuilder->AddSectionFromFile(aFile.c_str());
			if (result < 0)
			{
				printf("[ScriptSystem] Error: Failed to load %s script file.\n", aFile);
				return;
			}
			result = myScriptBuilder->BuildModule();
			if (result < 0)
			{
				printf("[ScriptSystem] Error: Failed to build the module.\n");
				return;
			}

			asIScriptModule* mod = myScriptEngine->GetModule("ScriptModule");
			asIScriptFunction* func = mod->GetFunctionByDecl("void main()");
			if (func == 0)
			{
				printf("[ScriptSystem] Error: Could not find the function 'void main()'. Add it and try again!\n");
				return;
			}
			myUpdateFunction = mod->GetFunctionByDecl("void Update(float)");
			if (myUpdateFunction == 0)
			{
				printf("[ScriptSystem] Error: Could not find the function 'void Update(float)'. Add it and try again!\n");
			}

			
			myScriptContext->Prepare(func);
			result = myScriptContext->Execute();
			if (result != asEXECUTION_FINISHED)
			{
				if (result == asEXECUTION_EXCEPTION)
				{
					printf("[ScriptSystem] Error: An execption %s occurred.\n", myScriptContext->GetExceptionString());
				}
			}

			printf("[ScriptSystem] Successfully loaded the script %s!\n", aFile.c_str());
		}

		void ScriptSystem::Update(const float aDeltaTime)
		{
			myScriptContext->Prepare(myUpdateFunction);
			myScriptContext->SetArgFloat(0, aDeltaTime);
			int result = myScriptContext->Execute();
			if (result != asEXECUTION_FINISHED)
			{
				if (result == asEXECUTION_EXCEPTION)
				{
					printf("[ScriptSystem] Error: An execption %s occurred.\n", myScriptContext->GetExceptionString());
				}
			}
		}

		void ScriptSystem::RegisterFunction(const char* aFunction,const asSFuncPtr& aFunctionPtr)
		{
			int result = myScriptEngine->RegisterGlobalFunction(aFunction, aFunctionPtr, asCALL_CDECL);
			if (result < 0)
			{
				printf("[ScriptSystem] Error: Failed to Register %s function.\n", aFunction);
			}
			printf("[ScriptSystem] Registered %s function successfully!\n", aFunction);
		}
	}
}