#include "stdafx.h"


#include "Engine.h"
#include <SDL.h>
namespace Quad_Engine
{
	Engine* Engine::myInstance = nullptr;
	void Engine::Create()
	{
		if (myInstance != nullptr)
		{
			assert("Can't Create Instance twice.");
		}
		myInstance = new Engine();
	}

	void Engine::Destroy()
	{
		if (myInstance != nullptr)
		{
			delete myInstance;
			myInstance = nullptr;
		}
	}

	Engine* Engine::GetInstance()
	{
		if (myInstance == nullptr)
		{
			assert("The instance is not created yet.");
		}
		return myInstance;
	}

	Engine::Engine()
	{
		mySDLInterface = new SDLInterface();
		mySDLInterface->Setup("Quad Engine", 1280, 720);
		myIsRunning = true;
		for (int i = 0; i < static_cast<int>(eEngineCallbacks::_COUNT); ++i)
		{
			myCallbacks[i].Init(16);
		}
	}

	Engine::~Engine()
	{
		delete mySDLInterface;
		mySDLInterface = nullptr;
	}

	void Engine::Run()
	{
		SDL_Event event;
		while (myIsRunning == true)
		{
			while (SDL_PollEvent(&event) != 0)
			{
				switch (event.type)	
				{
				case SDL_QUIT:
					myIsRunning = false;
					break;
				default:
					break;
				}
			}

			Update();
			Render();
		}
	}

	void Engine::AddCallback(const eEngineCallbacks aCallbackType, const std::function<void()>& aFunction)
	{
		switch (aCallbackType)
		{
		case eEngineCallbacks::UPDATE:
			myCallbacks[static_cast<int>(eEngineCallbacks::UPDATE)].Add(aFunction);
			break;
		case eEngineCallbacks::RENDER:
			myCallbacks[static_cast<int>(eEngineCallbacks::RENDER)].Add(aFunction);
			break;
		default:
			printf("Could not add callback to unkown types!");
			break;
		}
	}

	void Engine::SetClearColor(const CommonLibs::Math::Vector4<float>& aClearColor)
	{
		mySDLInterface->SetClearColor(aClearColor);
	}

	void Engine::Render()
	{
		mySDLInterface->Clear();
		
		for each(const std::function<void()>& function in myCallbacks[static_cast<int>(eEngineCallbacks::RENDER)])
		{
			function();
		}

		mySDLInterface->Present();
	}

	void Engine::Update()
	{
		for each(const std::function<void()>& function in myCallbacks[static_cast<int>(eEngineCallbacks::UPDATE)])
		{
			function();
		}
	}

}