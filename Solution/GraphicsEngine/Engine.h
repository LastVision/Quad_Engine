#pragma once

class SDLInterface;

namespace Quad_Engine
{
	class Engine
	{
	public:
		Engine();
		~Engine();

		void Run();

	private:
		void Render();
		void Update();

		SDLInterface* mySDLInterface;
		bool myIsRunning;
	};
}