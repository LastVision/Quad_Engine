#include "stdafx.h"

#include <Engine.h>
#include <Entity.h>
#include <Box2D.h>
#include "Level.h"
#include <InputManager.h>
#include <ResourceManager.h>
#include <Sprite.h>

Level::Level()
{
	myTestSprite = Quad_Engine::Engine::GetInstance()->GetResourceManager()->GetSprite("Data/Resources/Textures/brick.bmp");

	myGravity = new b2Vec2(0.0f, 10.0f);
	myWorld = new b2World(*myGravity);

	myGroundBodyDef = new b2BodyDef;
	myGroundBodyDef->position.Set(0.0f, 700.0f);

	myGroundBody = myWorld->CreateBody(myGroundBodyDef);

	myGroundBox = new b2PolygonShape();
	myGroundBox->SetAsBox(50.0f, 50.f);

	myGroundBody->CreateFixture(myGroundBox, 0.0f);

	myCharacterBodyDef = new b2BodyDef;
	myCharacterBodyDef->type = b2_dynamicBody;
	myCharacterBodyDef->position.Set(0.0f, 4.0f);
	myCharacterBody = myWorld->CreateBody(myCharacterBodyDef);

	myCharacterBox = new b2PolygonShape();
	myCharacterBox->SetAsBox(1.0f, 1.0f);

	myCharacterFixtureDef = new b2FixtureDef();
	myCharacterFixtureDef->shape = myCharacterBox;
	myCharacterFixtureDef->density = 1.0f;
	myCharacterFixtureDef->friction = 0.3f;

	myCharacterBody->CreateFixture(myCharacterFixtureDef);

	myPlayer = new Entity(0);
	myPlayer->AddComponent("Data/Script/helloWorld.as");
	myPlayer->Init();
}

Level::~Level()
{
	delete myGroundBodyDef;
	myGroundBodyDef = nullptr;


	delete myGravity;
	myGravity = nullptr;

	delete myWorld;
	myWorld = nullptr;
}

void Level::Update(const float aDeltaTime)
{
	myWorld->Step(aDeltaTime, 6, 2);
	myTestPosition = ConvertToFromBox2DVecToVector(myCharacterBody->GetPosition());
	myPlayer->Update(aDeltaTime);
	//printf("Pos: (X: %f, Y: %f)\n", myTestPosition.myX, myTestPosition.myY);

	if (CL::InputManager::GetInstance()->IsKeyDown(KEY::KEY_UP) == true)
	{
		//myTestPosition.myY -= 100.f * aDeltaTime;
	}
	else if (CL::InputManager::GetInstance()->IsKeyDown(KEY::KEY_DOWN) == true)
	{
		//myTestPosition.myY += 100.f * aDeltaTime;
	}

	if (CL::InputManager::GetInstance()->IsKeyDown(KEY::KEY_LEFT) == true)
	{
		//myTestPosition.myX -= 100.f * aDeltaTime;
	}
	else if (CL::InputManager::GetInstance()->IsKeyDown(KEY::KEY_RIGHT) == true)
	{
		//myTestPosition.myX += 100.f * aDeltaTime;
	}

}

void Level::Render()
{
	myTestSprite->Render(myTestPosition);
}

CL::Math::Vector2<float> Level::ConvertToFromBox2DVecToVector(const b2Vec2& aVector)
{
	return CL::Math::Vector2<float>(aVector.x, aVector.y);
}