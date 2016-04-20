#pragma once
#include <Vector.h>

class Level;

class GameClient
{
public:
	GameClient();
	~GameClient();

	void Update();
	void Render();

private:
	float myDeltaTime;

	Level* myLevel;
};