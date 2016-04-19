#pragma once
#include <Vector.h>

struct SDL_Window;
struct SDL_Renderer;

namespace Quad_Engine
{
	class SDLInterface
	{
	public:
		SDLInterface();
		~SDLInterface();

		void Setup(const std::string& aTitle, int aWidth, int aHeight);

		void SetClearColor(const CL::Math::Vector4<float>& aClearColor);

		void Clear();
		void Present();

		SDL_Window* GetWindow() const;
		SDL_Renderer* GetRenderer() const;
	private:
		void CreateRenderer();

		SDL_Renderer* myRenderer;
		SDL_Window* myWindow;
	};

	inline SDL_Window* SDLInterface::GetWindow() const
	{
		return myWindow;
	}

	inline SDL_Renderer* SDLInterface::GetRenderer() const
	{
		return myRenderer;
	}
};