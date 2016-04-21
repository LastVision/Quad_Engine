#include "stdafx.h"
#include <angelscript.h>
#include "ScriptInterface.h"
#include <ScriptSystem.h>

namespace ScriptInterface
{
	void Print(const std::string& aString)
	{
		printf("[Script]: %s\n", aString);
	}

	void Print(float aFloat)
	{
		printf("[Script]: %f\n", aFloat);
	}

	void Print(int aInt)
	{
		printf("[Script]: %i\n", aInt);
	}
};

namespace ScriptInterface
{
	void RegisterCppFunction()
	{
		Quad_Engine::Script::ScriptSystem* system = Quad_Engine::Script::ScriptSystem::GetInstance();

		//Debug Functions
		system->RegisterFunction("void Print(const string &in)", asFUNCTIONPR(Print, (const std::string&), void));
		system->RegisterFunction("void Print(float)", asFUNCTIONPR(Print, (float), void));
		system->RegisterFunction("void Print(int)", asFUNCTIONPR(Print, (int), void));
		//Gameplay Functions

		//Math Functions

		//Rendering Functions

		//Utilities Function

	}
};