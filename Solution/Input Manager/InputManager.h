#pragma once
class InputManager
{
public:
	static void Create();
	static void Destroy();
	static InputManager* GetInstance();
private:
	static InputManager* myInstance;
	InputManager();
	~InputManager();
};

