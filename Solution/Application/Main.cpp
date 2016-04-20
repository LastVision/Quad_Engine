#include "stdafx.h"
#include <Engine.h>
#include <GameClient.h>

void main()
{
	Quad_Engine::Engine::Create();
	Quad_Engine::Engine::GetInstance()->SetClearColor({ 255, 100, 100, 255 });
	GameClient* game = new GameClient();
	Quad_Engine::Engine::GetInstance()->Run();
	delete game;
	game = nullptr;
	Quad_Engine::Engine::Destroy();
}