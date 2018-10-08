#include "stdafx.h"
#include "PacmanComponent.h"
#include "TextComponent.h"
#include "SpriteComponent.h"
#include "LiveManagerComponent.h"
#include "EndGameComponent.h"
PacmanComponent::PacmanComponent(GameObject* score, GameObject* end): m_scoreText(score), m_EndGame(end)
{
}


PacmanComponent::~PacmanComponent()
{
}

void PacmanComponent::AddScore(int score)
{
	m_score += score;
	m_scoreText->GetComponent<TextComponent>()->SetText(to_string(m_score));
}

void PacmanComponent::Died()
{
	m_moveComponent->SwitchActive();
	m_moveComponent->GetPlace()->isPacman = false;
	m_pGameObject->GetComponent<LiveManagerComponent>()->LostLive(m_lives);
	m_pGameObject->GetComponent<SpriteComponent>()->SwitchActive();
	
	if (m_lives != 0) {
		m_timeDeath = 0.f;
		m_currentState = DEAD;
	}
	else {
		//SHOW END GAME
		m_EndGame->GetComponent<EndGameComponent>()->LastLive();
	}
	--m_lives;

}

bool PacmanComponent::IsDead()
{
	if (m_currentState == DEAD)	return true;
	
	return false;
}

GameObject * PacmanComponent::GetEndGameObj()
{
	return m_EndGame;
}

void PacmanComponent::Initialize()
{
	m_lives = 2;
	m_moveComponent = m_pGameObject->GetComponent<MovementComponent>();
	m_startingPosX = m_moveComponent->GetJ();
	m_startingPosY = m_moveComponent->GetI();
}

void PacmanComponent::Update()
{
	switch (m_currentState)
	{
	case ALIVE:
		break;
	case DEAD:
		m_timeDeath += Time::GetInstance().GetDeltaTime();
		if (m_timeDeath >= m_totalTimeDeath) {
			//respawn at starting place for now this
			Respawn();
		}
		break;
	default:
		break;
	}
}

void PacmanComponent::Render()
{
}

void PacmanComponent::Respawn()
{
	m_pGameObject->GetComponent<SpriteComponent>()->SwitchActive();
	m_pGameObject->GetTransform()->SetPosition(m_startingPosX * 50.f, m_startingPosY * 50.f);
	m_moveComponent->GetMap()[m_startingPosY][m_startingPosX]->isPacman = true;
	m_moveComponent->SetI(m_startingPosY);
	m_moveComponent->SetJ(m_startingPosX);
	m_moveComponent->SwitchActive();
	m_currentState = ALIVE;
}
