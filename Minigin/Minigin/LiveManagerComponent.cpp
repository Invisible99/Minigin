#include "stdafx.h"
#include "LiveManagerComponent.h"


LiveManagerComponent::LiveManagerComponent()
{
}


LiveManagerComponent::~LiveManagerComponent()
{
}

void LiveManagerComponent::AddLive(GameObject * live)
{
	m_lives.push_back(live);
}

void LiveManagerComponent::LostLive(int i)
{
	m_lives[i]->SwitchActive();
}

void LiveManagerComponent::ShowLives()
{
	for (auto g : m_lives) g->SwitchActive();
}

void LiveManagerComponent::Initialize()
{
}

void LiveManagerComponent::Update()
{
}

void LiveManagerComponent::Render()
{
}
