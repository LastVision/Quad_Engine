#pragma once
class InputManager
{
public:
	static void Create();
	static void Destroy();
	static InputManager* GetInstance();

	const bool IsKeyDown(const unsigned short aKey) const;
	const bool IsKeyPressed(const unsigned short aKey) const;
	const bool IsKeyReleased(const unsigned short aKey) const;

	const bool IsMouseButtonDown(const unsigned short aKey) const;
	const bool IsMouseButtonPressed(const unsigned short aKey) const;
	const bool IsMouseButtonReleased(const unsigned short aKey) const;

private:
	static InputManager* myInstance;
	InputManager();
	~InputManager();
};

