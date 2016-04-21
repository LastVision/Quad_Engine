#include "stdafx.h"
#include <Engine.h>
#include "GameClient.h"
#include "Level.h"
#include "ScriptInterface.h"
#include <ScriptSystem.h>

GameClient::GameClient()
{
	Quad_Engine::Engine::GetInstance()->AddCallback(eEngineCallbacks::UPDATE, std::bind(&GameClient::Update, this));
	Quad_Engine::Engine::GetInstance()->AddCallback(eEngineCallbacks::RENDER, std::bind(&GameClient::Render, this));

	Quad_Engine::Script::ScriptSystem::Create();
	Quad_Engine::Script::ScriptSystem::GetInstance()->Init(&ScriptInterface::RegisterCppFunction);

	myLevel = new Level();
	
}

GameClient::~GameClient()
{
	Quad_Engine::Script::ScriptSystem::Destroy();

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