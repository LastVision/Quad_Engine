#include "stdafx.h"


#include "Engine.h"
#include <SDL.h>
namespace Quad_Engine
{
	Engine::Engine()
	{
		mySDLInterface = new SDLInterface();
		mySDLInterface->Setup("Quad Engine", 1280, 720);
		myIsRunning = true;
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

	void Engine::Render()
	{
		mySDLInterface->Clear();
		//TODO: callback on render function

		mySDLInterface->Present();
	}

	void Engine::Update()
	{
		//TODO: callback on Update function
	}

}