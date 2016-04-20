#pragma once
#include <string>
#include <unordered_map>

struct SDL_Texture;
namespace Quad_Engine
{
	class Sprite;
	class ResourceManager
	{
	public:
		ResourceManager();
		~ResourceManager();

		Sprite* GetSprite(const std::string& aPath);

	private:
		void LoadSprite(const std::string& aPath);

		std::unordered_map<std::string, Sprite*> mySprites;
	};
}