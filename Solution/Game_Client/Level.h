#pragma once
#include <Vector.h>

struct b2Vec2;
struct b2BodyDef;
struct b2FixtureDef;

class b2World;
class b2Body;
class b2PolygonShape;

class Entity;

namespace Quad_Engine
{
	class Sprite;
}

class Level
{
public:
	Level();
	~Level();

	void Update(const float aDeltaTime);
	void Render();
private:
	CL::Math::Vector2<float> ConvertToFromBox2DVecToVector(const b2Vec2& aVector);

	b2Vec2* myGravity;
	b2World* myWorld;

	//Ground
	b2BodyDef* myGroundBodyDef;
	b2Body* myGroundBody;
	b2PolygonShape* myGroundBox;

	//Dynamic
	b2BodyDef* myCharacterBodyDef;
	b2Body* myCharacterBody;
	b2PolygonShape* myCharacterBox;
	b2FixtureDef* myCharacterFixtureDef;

	//Sprite
	Quad_Engine::Sprite* myTestSprite;
	CL::Math::Vector2<float> myTestPosition;

	Entity* myPlayer;
};

