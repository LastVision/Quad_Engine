#include "stdafx.h"
#include <iostream>
#include "SDLInterface.h"
#include <SDL.h>

namespace Quad_Engine
{
	SDLInterface::SDLInterface()
		: myRenderer(nullptr)
		, myWindow(nullptr)
	{
	}

	SDLInterface::~SDLInterface()
	{
		SDL_DestroyRenderer(myRenderer);
		myRenderer = nullptr;

		SDL_DestroyWindow(myWindow);
		SDL_Quit();
	}

	void SDLInterface::Setup(const std::string& aTitle, int aWidth, int aHeight)
	{
		if (SDL_Init(SDL_INIT_VIDEO) < 0)
		{
			printf("SDL could not initialize! Error: %s", SDL_GetError());
		}
		else
		{
			myWindow = SDL_CreateWindow(aTitle.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, aWidth, aHeight, SDL_WINDOW_SHOWN);
			if (myWindow == NULL)
			{
				printf("SDL could not create window! Error: %s", SDL_GetError());
			}
		}
		CreateRenderer();
	}

	void SDLInterface::Clear()
	{
		SDL_RenderClear(myRenderer);
	}

	void SDLInterface::Present()
	{
		SDL_RenderPresent(myRenderer);
	}

	void SDLInterface::CreateRenderer()
	{
		myRenderer = SDL_CreateRenderer(myWindow, -1, SDL_RENDERER_ACCELERATED);
		if (myRenderer == NULL)
		{
			printf("SDLRender could not be created! Error: %s", SDL_GetError());
		}
		else
		{
			SDL_SetRenderDrawColor(myRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
		}
	}
}