#include "stdafx.h"
#include <Engine.h>
#include <GameClient.h>

void main()
{
	Quad_Engine::Engine::Create();
	Quad_Engine::Engine::GetInstance()->SetClearColor({ 0xFF, 0x00, 0x00, 0xFF });
	GameClient* game = new GameClient();
	Quad_Engine::Engine::GetInstance()->Run();
	delete game;
	game = nullptr;
	Quad_Engine::Engine::Destroy();
}