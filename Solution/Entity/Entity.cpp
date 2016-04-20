#include "stdafx.h"

#include "Component.h"
#include "Entity.h"

Entity::Entity(const unsigned long long aGID, const std::string& aName, const eEntityTag aTag)
	: myGID(aGID)
	, myName(aName)
	, myTag(aTag)
	, myComponents(8)
{
}

Entity::~Entity()
{
	myComponents.DeleteAll();
}

void Entity::Init()
{
	for each(Component* component in myComponents)
	{
		component->Init();
	}
}

void Entity::Update(const float aDeltaTime)
{
	for each (Component* component in myComponents)
	{
		component->Update(aDeltaTime);
	}
}