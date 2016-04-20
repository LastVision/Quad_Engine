#include "stdafx.h"
#include <Engine.h>
#include "GameClient.h"
#include "Level.h"

GameClient::GameClient()
{
	Quad_Engine::Engine::GetInstance()->AddCallback(eEngineCallbacks::UPDATE, std::bind(&GameClient::Update, this));
	Quad_Engine::Engine::GetInstance()->AddCallback(eEngineCallbacks::RENDER, std::bind(&GameClient::Render, this));

	myLevel = new Level();
}

GameClient::~GameClient()
{
	delete myLevel;
	myLevel = nullptr;
}

void GameClient::Update()
{
	myDeltaTime = Quad_Engine::Engine::GetInstance()->GetDeltaTime();
	
	myLevel->Update(myDeltaTime);
}

void GameClient::Render()
{
	myLevel->Render();
}