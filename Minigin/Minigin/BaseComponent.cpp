#include "stdafx.h"
#include "BaseComponent.h"
#include "GameObject.h"

BaseComponent::BaseComponent()
{
	active = true;
}

dae::BaseComponent::~BaseComponent()
{
}

Transform* BaseComponent::GetTransform() const
{
	return m_pGameObject->GetTransform();
}

bool dae::BaseComponent::IsActive()
{
	return active;
}

void dae::BaseComponent::SwitchActive()
{
	active = !active;
}

void BaseComponent::RootInitialize()
{
	Initialize();
}
