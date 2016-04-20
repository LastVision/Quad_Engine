#include "stdafx.h"

#include "Engine.h"
#include <InputManager.h>
#include <TimerManager.h>
#include "ResourceManager.h"
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
		CL::InputManager::Create();
		myResourceManager = new ResourceManager();
		myTimerManager = new CL::Time::TimerManager();
	}

	Engine::~Engine()
	{
		CL::InputManager::Destroy();
		delete myTimerManager;
		myTimerManager = nullptr;
		delete myResourceManager;
		myResourceManager = nullptr;

		delete mySDLInterface;
		mySDLInterface = nullptr;
	}

	void Engine::Run()
	{
		SDL_Event event;
		while (myIsRunning == true)
		{
			myTimerManager->Update();
			/*myFPS = myTimerManager->GetMasterTimer().GetTime().GetFPS();*/
			myDeltaTime = myTimerManager->GetMasterTimer().GetTime().GetFrameTime();
			CL::InputManager::GetInstance()->OnBeginFrame();
			while (SDL_PollEvent(&event) != 0)
			{
				switch (event.type)	
				{
				case SDL_QUIT:
					myIsRunning = false;
					break;
				case SDL_KEYDOWN:
					CL::InputManager::GetInstance()->OnSDLKeyDown(event.key.keysym.scancode);
					break;
				case SDL_KEYUP:
					CL::InputManager::GetInstance()->OnSDLKeyUp(event.key.keysym.scancode);
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

	SDL_Renderer* Engine::GetRenderer() const
	{
		return mySDLInterface->GetRenderer();
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