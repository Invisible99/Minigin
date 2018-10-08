#include "stdafx.h"
#include "PowerupComponent.h"
#include "GameObject.h"
#include "PacmanComponent.h"
#include "GhostManagerComponent.h"
PowerupComponent::PowerupComponent(Map* current, GameObject* pacman, GameObject* ghostManager) : m_mapStats(current), m_pacman(pacman), m_ghostManager(ghostManager)
{
}


PowerupComponent::~PowerupComponent()
{
}

void PowerupComponent::Initialize()
{
}

void PowerupComponent::Update()
{
	if (m_mapStats->isPacman && m_mapStats->isPowerUp) {
		m_mapStats->isPowerUp = false;
		m_pGameObject->SwitchActive();
		m_pacman->GetComponent<PacmanComponent>()->AddScore(20);
		m_ghostManager->GetComponent<GhostManagerComponent>()->EatenPill();
	}
}

void PowerupComponent::Render()
{
}
