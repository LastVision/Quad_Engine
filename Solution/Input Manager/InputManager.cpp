#include "stdafx.h"
#include "InputManager.h"

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
}

InputManager::~InputManager()
{
}

const bool InputManager::IsKeyDown(const unsigned short aKey) const
{

}

const bool InputManager::IsKeyPressed(const unsigned short aKey) const
{

}

const bool InputManager::IsKeyReleased(const unsigned short aKey) const
{

}

const bool InputManager::IsMouseButtonDown(const unsigned short aKey) const
{

}

const bool InputManager::IsMouseButtonPressed(const unsigned short aKey) const
{

}

const bool InputManager::IsMouseButtonReleased(const unsigned short aKey) const
{

}