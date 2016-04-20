#pragma once
#include "KeyEnums.h"
namespace CommonLibs
{
	class InputManager
	{
	public:
		static void Create();
		static void Destroy();
		static InputManager* GetInstance();

		const bool IsKeyDown(const KEY aKey) const;
		const bool IsKeyPressed(const KEY aKey) const;
		const bool IsKeyReleased(const KEY aKey) const;

		const bool IsMouseButtonDown(const unsigned short aKey) const;
		const bool IsMouseButtonPressed(const unsigned short aKey) const;
		const bool IsMouseButtonReleased(const unsigned short aKey) const;

		void OnSDLKeyDown(int aKey);
		void OnSDLKeyUp(int aKey);
		void OnBeginFrame();

	private:
		static InputManager* myInstance;
		InputManager();
		~InputManager();

		bool myCurrentKeyStates[512];
		bool myPreviousKeyStates[512];
	};
};
namespace CL = CommonLibs;