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
