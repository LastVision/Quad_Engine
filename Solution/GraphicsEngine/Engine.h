#pragma once
#include <functional>
#include <GrowingArray.h>
#include <StaticArray.h>
#include <Vector.h>
class SDLInterface;

enum class eEngineCallbacks : unsigned char
{
	UPDATE,
	RENDER,
	_COUNT,
};

namespace Quad_Engine
{
	class Engine
	{
	public:
		static void Create();
		static void Destroy();
		static Engine* GetInstance();

		void Run();
		void AddCallback(const eEngineCallbacks, const std::function<void()>& aFunction);

		void SetClearColor(const CommonLibs::Math::Vector4<float>& aClearColor);

	private:
		static Engine* myInstance;
		Engine();
		~Engine();

		void Render();
		void Update();

		SDLInterface* mySDLInterface;
		bool myIsRunning;

		CommonLibs::StaticArray<CommonLibs::GrowingArray<std::function<void()>>, static_cast<int>(eEngineCallbacks::_COUNT)> myCallbacks;
	};
}