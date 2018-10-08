#include "stdafx.h"
#include "EndGameComponent.h"


EndGameComponent::EndGameComponent(GameObject* endScreen): m_endScreen(endScreen)
{
}


EndGameComponent::~EndGameComponent()
{
}

void EndGameComponent::AddPlayer()
{
	m_players++;
}

void EndGameComponent::LastLive()
{
	m_deadPlayers++;
	if (m_deadPlayers == m_players) {
		m_endScreen->SwitchActive();
	}
}

void EndGameComponent::Initialize()
{
}

void EndGameComponent::Update()
{
}

void EndGameComponent::Render()
{
}
