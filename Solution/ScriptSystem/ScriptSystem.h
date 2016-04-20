#pragma once
#include <fstream>
#include <functional>
#include <lua.hpp>
#include <string>
#include <unordered_map>
#include <GrowingArray.h>
namespace Quad_Engine
{
	namespace Script
	{
		struct CallbackData
		{
			lua_State* myState;
			unsigned long long myID;
			unsigned long long myTreeID;
			std::string myLuaFunction;
		};

		class ScriptSystem
		{
		public:
			static void Create();
			static void Destroy();
			static ScriptSystem* GetInstance();

			void Init(const std::function<void(lua_State*)>& aRegisterFunction);

			lua_State* CreateLuaState();
			void SetCurrentLuaState(lua_State* aState);

			void RegisterFunction(const std::string& aNameInLua, lua_CFunction aFunction,
				const std::string& aArguments, const std::string& aHelpText);

			void RegisterCallback(const std::string& aCppName, const CallbackData& someCallbackData);
			void CallCallback(const std::string& aCppName, const unsigned long long aTreeID);

			void UseFile(const std::string& aFileName);
			void PrintToFile(const std::string& aString);

			void Update();

			template<typename ...args>
			void CallFunction(const std::string& aLuaName, const args... someArgs);

			template<typename ...ret>
			std::tuple<ret...> Pop();

			template<typename T, typename ...args>
			void Push(int& aCount, const T aArg, const args... someArgs);

		private:
			static ScriptSystem* myInstance;
			ScriptSystem();
			~ScriptSystem();

			void PushInternal(int& aCount, int aInt);
			void PushInternal(int& aCount, float aFloat);
			void PushInternal(int& aCount, const std::string& aString);
			void PushInternal(int& aCount, const char* aString);
			void PushInternal(int& aCount, bool aBool);
			void PushInternal(int& aCount, long long aLongLong);
			void Push(int&){};

			template<typename T>T PopTop(){ return T; };
			template<> int PopTop<int>();
			template<> float PopTop<float>();
			template<> unsigned long long PopTop<unsigned long long>();
			template<> const char* PopTop<const char*>();

			void CheckError(int aCode, lua_State* aState);
			void CheckFunctionError(int aCode, lua_State* aState);

			void AddLuaFunction(const std::string& aNameInLua, int aNumberOfArgs);

			void PrintDocumentation();
			int levenshtein_distance(const std::string &s1, const std::string &s2);
			std::string FindClosestFunction(const std::string& aFailedFunction);
		private:
			struct Documentation
			{
				std::string myFunction;
				std::string myArguments;
				std::string myHelpText;
			};

			std::unordered_map<std::string, int> myArgumentsCount;
			std::function<void(lua_State*)> myCppRegisterFunction;

			CL::GrowingArray<Documentation> myDocumentation;
			std::unordered_map<std::string, CL::GrowingArray<CallbackData>> myCallbacks;

			lua_State* myCurrentState;
			std::fstream myOutputFile;
		};
	};
};

namespace Quad_Engine
{
	namespace Script
	{
		template <typename ...args>
		void ScriptSystem::CallFunction(const std::string& aLuaName, const args... someArgs)
		{
			if (myArgumentsCount.find(aLuaName) == myArgumentsCount.end())
			{
				//MessageBox(NULL, std::string("Failed to call Function " + aLuaName + ", function not found").c_str(), "LUAError", MB_ICONERROR);
			}
			else
			{
				lua_getglobal(myCurrentState, aLuaName.c_str());

				if (lua_isnil(myCurrentState, -1) == true)
				{
					lua_remove(myCurrentState, -1);
					//MessageBox(NULL, std::string("Function " + aLuaName + ", function not found").c_str(), "LUAError", MB_ICONERROR);
				}

				int count = 0;
				Push(count, someArgs...);

				if (myArgumentsCount[aLuaName] != count)
				{
					//MessageBox(NULL, std::string("Failed to call Function " + aLuaName + ", missmatched number of arguments").c_str(), "LUAError", MB_ICONERROR);
				}
				else
				{
					CheckFunctionError(lua_pcall(myCurrentState, count, 0, 0), myCurrentState);
				}
			}
		}

		template <typename ...ret>
		std::tuple<ret...> ScriptSystem::Pop()
		{
			return std::make_tuple(PopTop<ret>()...);
		}

		template<>
		int ScriptSystem::PopTop<int>()
		{
			int returnValue = static_cast<int>(lua_tonumber(myCurrentState, -1));
			lua_pop(myCurrentState, 1);
			return returnValue;
		}

		template<>
		float ScriptSystem::PopTop<float>()
		{
			float returnValue = static_cast<float>(lua_tonumber(myCurrentState, -1));
			lua_pop(myCurrentState, 1);
			return returnValue;
		}

		template<>
		unsigned long long ScriptSystem::PopTop<unsigned long long>()
		{
			std::string longString = lua_tostring(myCurrentState, -1);
			lua_pop(myCurrentState, 1);

			return std::atoll(longString.c_str());
		}

		template<>
		const char* ScriptSystem::PopTop<const char*>()
		{
			const char* string = lua_tostring(myCurrentState, -1);
			lua_pop(myCurrentState, 1);

			return string;
		}

		template <typename T, typename ...args>
		void ScriptSystem::Push(int& aCount, const T aArg, const args... someArgs)
		{
			PushInternal(aCount, aArg);
			Push(aCount, someArgs...);
		}

		inline void ScriptSystem::SetCurrentLuaState(lua_State* aState)
		{
			myCurrentState = aState;
		}
	};
};