#include "stdafx.h"
#include "GameObject.h"
#include "ResourceManager.h"
#include "Renderer.h"
#include "BaseComponent.h"
#include "Transform.h"

dae::GameObject::GameObject()
{
	//auto transform = new Transform();
	m_active = true;
	m_pTransform = new Transform();;
	AddComponent(m_pTransform);
}

void dae::GameObject::AddComponent(BaseComponent* pComp)
{
	m_pComponents.push_back(pComp);
	pComp->m_pGameObject = this;
}

dae::GameObject::~GameObject() {
	//Component Cleanup
	for (BaseComponent* pComp : m_pComponents)
	{
		SafeDelete(pComp);
	}

	//Object Cleanup
	for (GameObject* pChild : m_pChildren)
	{
		SafeDelete(pChild);
	}
}

dae::GameObject::GameObject(const GameObject & other)
{
	m_pTransform = other.m_pTransform;
	m_pChildren = other.m_pChildren;
	m_pComponents = other.m_pComponents;
}

dae::GameObject::GameObject(GameObject && other)
{
	m_pTransform = other.m_pTransform;
	m_pChildren = other.m_pChildren;
	m_pComponents = other.m_pComponents;
}

bool dae::GameObject::IsActive()
{
	return m_active;
}

void dae::GameObject::SwitchActive()
{
	m_active = !m_active;
}

void dae::GameObject::RootInitialize()
{
	Initialize();

	for (auto pComp : m_pComponents)
	{
		pComp->RootInitialize();
	}

	//Root-Object Initialization
	for (auto pChild : m_pChildren)
	{
		pChild->RootInitialize();
	}
}

void dae::GameObject::RootUpdate()
{
	Update();

	for (auto pComp : m_pComponents)
	{
		if (pComp->IsActive()) pComp->Update();
	}

	//Root-Object Initialization
	for (auto pChild : m_pChildren)
	{
		pChild->RootUpdate();
	}
}

void dae::GameObject::RootRender()
{
	Render();

	for (auto pComp : m_pComponents)
	{
		if (pComp->IsActive()) pComp->Render();
	}

	//Root-Object Initialization
	for (auto pChild : m_pChildren)
	{
		pChild->RootRender();
	}
}
