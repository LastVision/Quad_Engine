#include "stdafx.h"
#include <Engine.h>
#include "GameClient.h"
#include <InputManager.h>
#include <ResourceManager.h>
#include <Sprite.h>

GameClient::GameClient()
{
	Quad_Engine::Engine::GetInstance()->AddCallback(eEngineCallbacks::UPDATE, std::bind(&GameClient::Update, this));
	Quad_Engine::Engine::GetInstance()->AddCallback(eEngineCallbacks::RENDER, std::bind(&GameClient::Render, this));

	myTestSprite = Quad_Engine::Engine::GetInstance()->GetResourceManager()->GetSprite("Data/Resources/Textures/brick.bmp");
}

GameClient::~GameClient()
{
}

void GameClient::Update()
{
	myDeltaTime = Quad_Engine::Engine::GetInstance()->GetDeltaTime();
	
	if (CL::InputManager::GetInstance()->IsKeyDown(KEY::KEY_UP) == true)
	{
		myTestPosition.myY -= 100.f * myDeltaTime;
	}
	else if (CL::InputManager::GetInstance()->IsKeyDown(KEY::KEY_DOWN) == true)
	{
		myTestPosition.myY += 100.f * myDeltaTime;
	}

	if (CL::InputManager::GetInstance()->IsKeyDown(KEY::KEY_LEFT) == true)
	{
		myTestPosition.myX -= 100.f * myDeltaTime;
	}
	else if (CL::InputManager::GetInstance()->IsKeyDown(KEY::KEY_RIGHT) == true)
	{
		myTestPosition.myX += 100.f * myDeltaTime;
	}

	printf("Pos: (X: %f, Y: %f)\n", myTestPosition.myX, myTestPosition.myY);
}

void GameClient::Render()
{
	myTestSprite->Render(myTestPosition);
}