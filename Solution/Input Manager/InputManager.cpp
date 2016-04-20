#include "stdafx.h"
#include "InputManager.h"
#include <SDL_scancode.h>

namespace CommonLibs
{
	InputManager* InputManager::myInstance = nullptr;
	void InputManager::Create()
	{
		if (myInstance != nullptr)
		{
			//Assert here later
		}
		myInstance = new InputManager();
	}

	void InputManager::Destroy()
	{
		delete myInstance;
		myInstance = nullptr;
	}

	InputManager* InputManager::GetInstance()
	{
		if (myInstance == nullptr)
		{
			// Assert here later
		}
		return myInstance;
	}

	InputManager::InputManager()
	{
		for (int i = 0; i < SDL_NUM_SCANCODES; ++i)
		{
			myCurrentKeyStates[i] = false;
			myPreviousKeyStates[i] = false;
		}
	}

	InputManager::~InputManager()
	{
	}

	const bool InputManager::IsKeyDown(const KEY aKey) const
	{
		return (myCurrentKeyStates[static_cast<unsigned short>(aKey)] == true);
	}

	const bool InputManager::IsKeyPressed(const KEY aKey) const
	{
		return (myCurrentKeyStates[static_cast<unsigned short>(aKey)] == true) && (myPreviousKeyStates[static_cast<unsigned short>(aKey)] == false);
	}

	const bool InputManager::IsKeyReleased(const KEY aKey) const
	{
		return (myCurrentKeyStates[static_cast<unsigned short>(aKey)] == false) && (myPreviousKeyStates[static_cast<unsigned short>(aKey)] == true);
	}

	const bool InputManager::IsMouseButtonDown(const unsigned short aKey) const
	{
		return false;
	}

	const bool InputManager::IsMouseButtonPressed(const unsigned short aKey) const
	{
		return false;
	}

	const bool InputManager::IsMouseButtonReleased(const unsigned short aKey) const
	{
		return false;
	}

	void InputManager::OnSDLKeyDown(int aKey)
	{
		myCurrentKeyStates[aKey] = true;
	}

	void InputManager::OnSDLKeyUp(int aKey)
	{
		myCurrentKeyStates[aKey] = false;
	}

	void InputManager::OnBeginFrame()
	{
		for (int i = 0; i < SDL_NUM_SCANCODES; ++i)
		{
			myPreviousKeyStates[i] = myCurrentKeyStates[i];
		}
	}
}; 
namespace CL = CommonLibs;