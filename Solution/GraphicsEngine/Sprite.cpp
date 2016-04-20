#include "stdafx.h"

#include "Engine.h"
#include <SDL.h>
#include "Sprite.h"

namespace Quad_Engine
{
	Sprite::Sprite(SDL_Texture* aTexture, const CL::Math::Vector2<float> aSize)
		: myTexture(aTexture)
		, mySize(aSize)
	{
	}


	Sprite::~Sprite()
	{
	}

	void Sprite::Render(const CL::Math::Vector2<float>& aPosition)
	{
		SDL_Rect rect;
		rect.x = static_cast<int>(aPosition.myX - mySize.myX / 2.f);
		rect.y = static_cast<int>(aPosition.myY - mySize.myY / 2.f);
		rect.w = static_cast<int>(mySize.myX);
		rect.h = static_cast<int>(mySize.myY);
		SDL_RenderCopy(Engine::GetInstance()->GetRenderer(), myTexture, NULL, &rect);
	}
}