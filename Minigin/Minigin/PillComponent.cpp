#include "stdafx.h"
#include "PillComponent.h"
#include "GameObject.h"
#include "PacmanComponent.h"
PillComponent::PillComponent(Map* current, GameObject* pacman): m_mapStats(current), m_pacman(pacman)
{
}

PillComponent::~PillComponent()
{
}

void PillComponent::Initialize()
{
}

void PillComponent::Update()
{
	if (m_mapStats->isPacman && m_mapStats->isPill) {
		m_mapStats->isPill = false;
		m_pGameObject->SwitchActive();
		m_pacman->GetComponent<PacmanComponent>()->AddScore(10);
	}
}

void PillComponent::Render()
{
}
