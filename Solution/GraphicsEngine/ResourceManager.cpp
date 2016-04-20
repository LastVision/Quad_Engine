#include "stdafx.h"

#include "Engine.h"
#include <SDL.h>
#include "Sprite.h"
#include "ResourceManager.h"

namespace Quad_Engine
{
	ResourceManager::ResourceManager()
	{
	}

	ResourceManager::~ResourceManager()
	{
		for (auto it = mySprites.begin(); it != mySprites.end(); ++it)
		{
			delete it->second;
		}
	}

	Sprite* ResourceManager::GetSprite(const std::string& aPath)
	{
		if (mySprites.find(aPath) == mySprites.end())
		{
			LoadSprite(aPath);
		}
		return mySprites[aPath];
	}

	void ResourceManager::LoadSprite(const std::string& aPath)
	{
		CL::Math::Vector2<float> size;

		SDL_Texture* texture = NULL;
		SDL_Surface* loadedSurface = SDL_LoadBMP(aPath.c_str());

		if (loadedSurface == NULL)
		{
			printf("Failed to LoadSprite(%s)! Error: %s", aPath.c_str(), SDL_GetError());
		}
		else
		{
			texture = SDL_CreateTextureFromSurface(Engine::GetInstance()->GetRenderer(), loadedSurface);
			if (texture == NULL)
			{
				printf("Failed to create texture from %s! Error: %s", aPath.c_str(), SDL_GetError());
			}

			size.myX = static_cast<float>(loadedSurface->w);
			size.myY = static_cast<float>(loadedSurface->h);

			SDL_FreeSurface(loadedSurface);
		}

		mySprites[aPath] = new Sprite(texture, size);
	}
}