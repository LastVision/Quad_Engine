#pragma once
#include "EntityEnum.h"
#include <GrowingArray.h>
#include <string>

class Component;
class Entity
{
public:
	Entity(const unsigned long long aGID, const std::string& aName = "", const eEntityTag aTag = eEntityTag::NONE);
	~Entity();

	void Init();

	void Update(const float aDeltaTime);

private:
	const unsigned long long myGID;
	const eEntityTag myTag;
	const std::string myName;
	CL::GrowingArray<Component*> myComponents;
};