#include "stdafx.h"
#include <Engine.h>
#include "GameClient.h"
#include <InputManager.h>

GameClient::GameClient()
{
	Quad_Engine::Engine::GetInstance()->AddCallback(eEngineCallbacks::UPDATE, std::bind(&GameClient::Update, this));
	Quad_Engine::Engine::GetInstance()->AddCallback(eEngineCallbacks::RENDER, std::bind(&GameClient::Render, this));
}

GameClient::~GameClient()
{
}

void GameClient::Update()
{
	if (CL::InputManager::GetInstance()->IsKeyReleased(KEY::KEY_UP) == true)
	{
		printf("Up key is released\n");
	}
	else if (CL::InputManager::GetInstance()->IsKeyPressed(KEY::KEY_UP) == true)
	{
		printf("Up key is pressed\n");
	}

	
}

void GameClient::Render()
{
	
}