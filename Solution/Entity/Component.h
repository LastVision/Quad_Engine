#pragma once
#include <string>

class Component
{
public:
	Component(const std::string& aFilePath);
	~Component();

	void Init();

	void Update(const float aDeltaTime);

private:
	std::string myScriptFile;
};

