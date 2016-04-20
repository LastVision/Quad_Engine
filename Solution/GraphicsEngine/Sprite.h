#pragma once
#include <Vector.h>

struct SDL_Texture;

namespace Quad_Engine
{
	class Sprite
	{
	public:
		Sprite(SDL_Texture* aTexture, const CL::Math::Vector2<float> aSize);
		~Sprite();

		void Render(const CL::Math::Vector2<float>& aPosition);
	private:
		SDL_Texture* myTexture;
		CL::Math::Vector2<float> mySize;
	};
};