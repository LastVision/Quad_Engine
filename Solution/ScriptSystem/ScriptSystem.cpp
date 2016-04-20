#include "stdafx.h"

#include <lualib.h>
#include <lauxlib.h>
#include "ScriptSystem.h"

#include <numeric>
#include <algorithm>

int PrintFromLua(lua_State* aState)
{
	std::string stringArg = lua_tostring(aState, 1);

	Quad_Engine::Script::ScriptSystem::GetInstance()->PrintToFile(stringArg);

	return 0;
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
		}

		ScriptSystem::~ScriptSystem()
		{
			myOutputFile.close();
			PrintDocumentation();
		}
		void ScriptSystem::Init(const std::function<void(lua_State*)>& aRegisterFunction)
		{
			myOutputFile.open("luaOutput.txt", std::ios::out);
			myCppRegisterFunction = aRegisterFunction;
			myCurrentState = nullptr;

			myArgumentsCount.clear();
			myCallbacks.clear();

			AddLuaFunction("OnInit", 0);
			AddLuaFunction("Update", 1);

			AddLuaFunction("Prepare", 0);
			AddLuaFunction("Run", 3);
		}

		lua_State* ScriptSystem::CreateLuaState()
		{
			lua_State* state = luaL_newstate();
			luaL_openlibs(state);
			myCppRegisterFunction(state);
			SetCurrentLuaState(state);
			RegisterFunction("Print", PrintFromLua, "aString", "Prints message into file");

			return state;
		}

		void ScriptSystem::RegisterFunction(const std::string& aNameInLua, lua_CFunction aFunction
			, const std::string& aArguments, const std::string& aHelpText)
		{
			Documentation doc;
			doc.myFunction = aNameInLua;
			doc.myArguments = aArguments;
			doc.myHelpText = aHelpText;
			myDocumentation.Add(doc);

			lua_register(myCurrentState, aNameInLua.c_str(), aFunction);
		}

		void ScriptSystem::RegisterCallback(const std::string& aCppName, const CallbackData& someCallbackData)
		{
			if (myCallbacks.find(aCppName) == myCallbacks.end())
			{
				myCallbacks[aCppName].Init(16);
			}
			myCallbacks[aCppName].Add(someCallbackData);

			myArgumentsCount[someCallbackData.myLuaFunction] = 2;
		}

		void ScriptSystem::CallCallback(const std::string& aCppName,const unsigned long long aTreeID)
		{
			if (myCallbacks.find(aCppName) != myCallbacks.end())
			{
				for (unsigned int i = 0; i < myCallbacks[aCppName].Size(); ++i)
				{
					CallbackData& callback = myCallbacks[aCppName][i];
					if (callback.myTreeID == aTreeID)
					{
						SetCurrentLuaState(callback.myState);
						CallFunction(callback.myLuaFunction, callback.myID, callback.myTreeID);
					}
				}
			}
			else
			{
				//MessageBox(NULL, std::string("Failed to call CallBack " + aCppName + ", function not found").c_str(), "LUAError", MB_ICONERROR);
			}
		}

		void ScriptSystem::UseFile(const std::string& aFileName)
		{
			CheckError(luaL_dofile(myCurrentState, aFileName.c_str()), myCurrentState);
		}

		void ScriptSystem::PrintToFile(const std::string& aString)
		{
			myOutputFile << aString << std::endl;
		}


		void ScriptSystem::PushInternal(int& aCount, int aInt)
		{
			++aCount;
			lua_pushnumber(myCurrentState, aInt);
		}

		void ScriptSystem::PushInternal(int& aCount, float aFloat)
		{
			++aCount;
			lua_pushnumber(myCurrentState, aFloat);
		}

		void ScriptSystem::PushInternal(int& aCount, const std::string& aString)
		{
			++aCount;
			lua_pushstring(myCurrentState, aString.c_str());
		}

		void ScriptSystem::PushInternal(int& aCount, const char* aString)
		{
			++aCount;
			lua_pushstring(myCurrentState, aString);
		}

		void ScriptSystem::PushInternal(int& aCount, bool aBool)
		{
			++aCount;
			lua_pushboolean(myCurrentState, aBool);
		}

		void ScriptSystem::PushInternal(int& aCount, long long aLongLong)
		{
			++aCount;
			char buffer[64];
			sprintf_s(buffer, "%llu", aLongLong);
			lua_pushstring(myCurrentState, buffer);
		}

		void ScriptSystem::PushInternal(int& aCount, unsigned long long aLongLong)
		{
			++aCount;
			char buffer[64];
			sprintf_s(buffer, "%l64u", aLongLong);
			lua_pushstring(myCurrentState, buffer);
		}

		void ScriptSystem::CheckError(int aCode, lua_State* aState)
		{
			if (aCode != 0)
			{
				//MessageBox(NULL, lua_tostring(aState, -1), "LUAError", MB_ICONERROR);
			}
		}

		void ScriptSystem::CheckFunctionError(int aCode, lua_State* aState)
		{
			if (aCode != 0)
			{
				std::string error = lua_tostring(aState, -1);
				lua_remove(aState, -1);
				int firstFnutt = error.find_first_of("'");
				int secondFnutt = error.find_first_of("'", firstFnutt + 1);

				std::string failedFunction(error.substr(firstFnutt + 1, secondFnutt - firstFnutt - 1));
				std::string suggestion = FindClosestFunction(failedFunction);

				int lineStartIndex = error.find_first_of(":");
				int lineEndIndex = error.find_first_of(":", lineStartIndex + 1);

				std::string file(error.substr(0, lineStartIndex));
				std::string line(error.substr(lineStartIndex + 1, lineEndIndex - lineStartIndex - 1));

				//MessageBox(NULL, std::string("In File: " + file + " at line: " + line + ",  you tried to call [" + failedFunction + "], did you mean [" + suggestion + "]").c_str(), "LUA-Error", MB_ICONERROR);
			}

		}

		void ScriptSystem::AddLuaFunction(const std::string& aNameInLua, int aNumberOfArgs)
		{
			myArgumentsCount[aNameInLua] = aNumberOfArgs;
		}

		void ScriptSystem::PrintDocumentation()
		{
			std::fstream file;
			file.open("exposedScriptFunctions.txt", std::ios::out);
			for (unsigned int i = 0; i < myDocumentation.Size(); ++i)
			{
				file << myDocumentation[i].myFunction << "(" << myDocumentation[i].myArguments << ") --" << myDocumentation[i].myHelpText << std::endl;
			}

			file.flush();
			file.close();
		}

		std::string ScriptSystem::FindClosestFunction(const std::string& aFailedFunction)
		{
			int closest = INT_MAX;
			std::string bestString;

			for (unsigned int i = 0; i < myDocumentation.Size(); ++i)
			{
				int dist = levenshtein_distance(aFailedFunction, myDocumentation[i].myFunction);

				if (dist < closest)
				{
					closest = dist;
					bestString = myDocumentation[i].myFunction;
				}
			}

			return bestString;
		}
#undef min
		int ScriptSystem::levenshtein_distance(const std::string &s1, const std::string &s2)
		{
			// To change the type this function manipulates and returns, change
			// the return type and the types of the two variables below.
			int s1len = s1.size();
			int s2len = s2.size();

			auto column_start = (decltype(s1len))1;

			auto column = new decltype(s1len)[s1len + 1];
			std::iota(column + column_start, column + s1len + 1, column_start);

			for (auto x = column_start; x <= s2len; x++) {
				column[0] = x;
				auto last_diagonal = x - column_start;
				for (auto y = column_start; y <= s1len; y++) {
					auto old_diagonal = column[y];
					auto possibilities = {
						column[y] + 1,
						column[y - 1] + 1,
						last_diagonal + (s1[y - 1] == s2[x - 1] ? 0 : 1)
					};
					column[y] = std::min(possibilities);
					last_diagonal = old_diagonal;
				}
			}
			auto result = column[s1len];
			delete[] column;
			return result;
		}
	};
};