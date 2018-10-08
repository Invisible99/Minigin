#include "stdafx.h"
#include "GhostManagerComponent.h"
#include "GhostComponent.h"

GhostManagerComponent::GhostManagerComponent()
{
}


GhostManagerComponent::~GhostManagerComponent()
{
}

void GhostManagerComponent::AddGhost(GameObject * ghost)
{
	m_ghosts.push_back(ghost);
}

vector<GameObject*> GhostManagerComponent::GetGhosts()
{
	return m_ghosts;
}

void GhostManagerComponent::EatenPill()
{
	for(GameObject* g : m_ghosts)
	{
		//Probably thread stuff here
		g->GetComponent<GhostComponent>()->PowerUp();
	}
}

void GhostManagerComponent::Initialize()
{
}

void GhostManagerComponent::Update()
{
}

void GhostManagerComponent::Render()
{
}
