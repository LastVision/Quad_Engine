#include "stdafx.h"
#include <Engine.h>

void main()
{
	Quad_Engine::Engine* engine = new Quad_Engine::Engine();

	engine->Run();

	delete engine;
	engine = nullptr;
}