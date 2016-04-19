#include "stdafx.h"
#include <Engine.h>
#include "GameClient.h"

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
	printf("Update\n");
}

void GameClient::Render()
{
	printf("Render\n");
}