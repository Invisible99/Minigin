#include "stdafx.h"
#include "Scene.h"
#include "GameObject.h"

void dae::Scene::Add(GameObject* object)
{
	mObjects.push_back(object);
}

dae::Scene::Scene(const std::string & name)
{
	m_name = name;
}

void dae::Scene::SetActive()
{
	m_active = true;
}

void dae::Scene::SetInactive()
{
	m_active = false;
}

dae::Scene::~Scene()
{
	for (GameObject* pChild : mObjects)
	{
		SafeDelete(pChild);
	}
}

void Scene::RootInitialze()
{
	Initialize();

	for (auto pChild : mObjects)
	{
		pChild->RootInitialize();
	}
}

void dae::Scene::RootUpdate()
{
	Update();

	for (auto gameObject : mObjects)
	{
		if(gameObject->IsActive()) gameObject->RootUpdate();
	}
}

void dae::Scene::RootRender()
{
	Render();

	for (const auto gameObject : mObjects)
	{
		if (gameObject->IsActive()) gameObject->RootRender();
	}
}

