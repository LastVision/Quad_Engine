#include "stdafx.h"
#include "Component.h"
#include <ScriptSystem.h>

Component::Component(const std::string& aFilePath)
	: myScriptFile(aFilePath)
{
}


Component::~Component()
{
}

void Component::Init()
{
	Quad_Engine::Script::ScriptSystem::GetInstance()->LoadScript(myScriptFile);
}

void Component::Update(const float aDeltaTime)
{
	Quad_Engine::Script::ScriptSystem::GetInstance()->Update(aDeltaTime);
}