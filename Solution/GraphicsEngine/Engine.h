#pragma once
#include <functional>
#include <GrowingArray.h>
#include <StaticArray.h>
#include <Vector.h>
class SDLInterface;

struct SDL_Renderer;

namespace CommonLibs
{
	namespace Time
	{
		class TimerManager;
	}
}

enum class eEngineCallbacks : unsigned char
{
	UPDATE,
	RENDER,
	_COUNT,
};

namespace Quad_Engine
{
	class ResourceManager;
	class Engine
	{
	public:
		static void Create();
		static void Destroy();
		static Engine* GetInstance();

		void Run();
		void AddCallback(const eEngineCallbacks, const std::function<void()>& aFunction);

		void SetClearColor(const CommonLibs::Math::Vector4<float>& aClearColor);

		const float GetFPS() const;
		const float GetDeltaTime() const;

		SDL_Renderer* GetRenderer() const;
		ResourceManager* GetResourceManager() const;
	private:
		static Engine* myInstance;
		Engine();
		~Engine();

		void Render();
		void Update();

		SDLInterface* mySDLInterface;
		bool myIsRunning;

		float myFPS;
		float myDeltaTime;

		CL::Time::TimerManager* myTimerManager;
		CL::StaticArray<CL::GrowingArray<std::function<void()>>, static_cast<int>(eEngineCallbacks::_COUNT)> myCallbacks;

		ResourceManager* myResourceManager;
	};
};

namespace Quad_Engine
{
	inline const float Engine::GetFPS() const
	{
		return myFPS;
	}

	inline const float Engine::GetDeltaTime() const
	{
		return myDeltaTime;
	}

	inline ResourceManager* Engine::GetResourceManager() const
	{
		return myResourceManager;
	}
}