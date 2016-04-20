#pragma once
#include <Vector.h>

namespace Quad_Engine
{
	class Sprite;
}

class GameClient
{
public:
	GameClient();
	~GameClient();

	void Update();
	void Render();

private:
	float myDeltaTime;

	Quad_Engine::Sprite* myTestSprite;
	CL::Math::Vector2<float> myTestPosition;
};