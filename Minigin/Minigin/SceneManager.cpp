#include "stdafx.h"
#include "SceneManager.h"
#include "Scene.h"



void dae::SceneManager::Initialize()
{
	for (auto scene : mScenes)
	{
		scene->RootInitialze();
	}
}

void dae::SceneManager::Update() // change this to only the active scene
{
	for (auto scene : mScenes)
	{
		if(scene->m_active)
			scene->RootUpdate();
	}
}

void dae::SceneManager::Render() //change this to only the active scene
{
	for (const auto scene : mScenes)
	{
		if(scene->m_active)
			scene->RootRender();
	}
}

dae::SceneManager::~SceneManager(void)
{
	for (Scene* scene : mScenes)
	{
		SafeDelete(scene);
	}
}

void dae::SceneManager::CreateScene(Scene* scene)
{
	mScenes.push_back(scene);
	scene->RootInitialze();
}
