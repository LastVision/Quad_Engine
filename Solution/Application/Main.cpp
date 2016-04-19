#include "stdafx.h"
#include <Engine.h>
#include <GameClient.h>

void main()
{
	Quad_Engine::Engine::Create();
	GameClient* game = new GameClient();
	Quad_Engine::Engine::GetInstance()->Run();
	delete game;
	game = nullptr;
	Quad_Engine::Engine::Destroy();
}