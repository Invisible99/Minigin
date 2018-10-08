#include "stdafx.h"
#include "GhostComponent.h"
#include "GameObject.h"
#include <stdio.h> 
#include <stdlib.h>   
#include <time.h> 
#include "PacmanComponent.h"
#include "SpriteComponent.h"
#include "Transform.h"
#include <thread>
#include <chrono>
GhostComponent::GhostComponent(GameObject* pacman, GameObject* pacwoman): m_pacman(pacman), m_pacwoman(pacwoman)
{
}


GhostComponent::~GhostComponent()
{
	this_thread::sleep_for(chrono::milliseconds(10));
	if (m_moveThread.joinable()) m_moveThread.join();
}

void GhostComponent::PowerUp()
{
	m_currentstate = POWERUP;
	m_powerupTime = 0.f;
}

void GhostComponent::Initialize()
{
	m_moveComponent = m_pGameObject->GetComponent<MovementComponent>();
	m_startingPosX = m_moveComponent->GetJ();
	m_startingPosY = m_moveComponent->GetI();
	m_map = m_moveComponent->GetMap();

	m_moveThread = thread(&GhostComponent::Movement, this);

	srand((int)time(NULL));
}

void GhostComponent::Update()
{
	switch (m_currentstate)
	{
	case WALKING:
		if (m_moveThread.joinable()) {
			m_moveThread.join();
		}
		else {
			this_thread::sleep_for(chrono::milliseconds(rand() % 10));
			m_moveThread = thread(&GhostComponent::Movement, this);
		}
		break;
	case POWERUP:
		if (m_moveThread.joinable()) {
			m_moveThread.join();
		}
		else {
			m_moveThread = thread(&GhostComponent::Movement, this);
		}
		m_powerupTime += Time::GetInstance().GetDeltaTime();
		if (m_powerupTime >= m_powerupTotal) {
			m_currentstate = WALKING;
		}
		break;
	case DEAD:
		m_timeDeath += Time::GetInstance().GetDeltaTime();
		if (m_timeDeath >= m_totalTimeDeath) {
			Respawn();
		
		}
		break;
	default:
		break;
	}
	
	//Collision
	if (m_map[m_moveComponent->GetI()][m_moveComponent->GetJ()]->isPacman && !m_pacman->GetComponent<PacmanComponent>()->IsDead() && m_currentstate != DEAD) {
		//PACMAN DIES
		if (m_currentstate == POWERUP) Died();
		else {
			if (m_pacman->GetComponent<MovementComponent>()->GetPlace() == m_moveComponent->GetPlace()) {
				m_pacman->GetComponent<PacmanComponent>()->Died();
			}
			if (m_pacwoman->IsActive() && m_pacwoman->GetComponent<MovementComponent>()->GetPlace() == m_moveComponent->GetPlace()) {
				m_pacwoman->GetComponent<PacmanComponent>()->Died();
			}		
		} 
	}
}

void GhostComponent::Render()
{
}

void GhostComponent::Movement()
{
	bool wallInBetween = false;
	bool foundPacman = false;
	UINT x = m_moveComponent->GetJ();
	UINT y = m_moveComponent->GetI();	
	
	for (UINT i(0); i < m_map.size(); i++) {
		if (m_map[i][x]->isPacman) {
			if (i < y) {
				for (UINT j(y); j > i; j--) {
					if (m_map[j][x]->isWall) wallInBetween = true;
				}
				if (!wallInBetween) {
					if(m_currentstate != POWERUP) m_moveComponent->SetMovement(MovementComponent::UP);
					else m_moveComponent->SetMovement(MovementComponent::DOWN);
				}
			}
			else {
				for (UINT j(y); j < i; j++) {
					if (m_map[j][x]->isWall) wallInBetween = true;
				}
				if (!wallInBetween) {
					if (m_currentstate != POWERUP) m_moveComponent->SetMovement(MovementComponent::DOWN);
					else m_moveComponent->SetMovement(MovementComponent::UP);
				}
			}
			foundPacman = true;
			break;
		}
	}
	for (UINT j(0); j < m_map[y].size(); j++) {
		if (m_map[y][j]->isPacman) {
			if (j < x) {
				for (UINT k(x); k > j; k--) {
					if (m_map[y][k]->isWall) wallInBetween = true;
				}
				if (!wallInBetween) {
					if (m_currentstate != POWERUP) m_moveComponent->SetMovement(MovementComponent::LEFT);
					else m_moveComponent->SetMovement(MovementComponent::RIGHT);
				}
			}
			else {
				for (UINT k(x); k < j; k++) {
					if (m_map[y][k]->isWall) wallInBetween = true;
				}
				if (!wallInBetween) { 
					if (m_currentstate != POWERUP) m_moveComponent->SetMovement(MovementComponent::RIGHT);
					else m_moveComponent->SetMovement(MovementComponent::LEFT);
				}
			}
			foundPacman = true;
			break;
		}
	}

	if (!foundPacman) {
		RandomMovement();
	}
}

void GhostComponent::RandomMovement()
{
	if (m_timer <= 0) {
		int x = m_moveComponent->GetJ();
		int y = m_moveComponent->GetI();
		MovementComponent::MOVE toMove = MovementComponent::NONE;
		while (toMove == MovementComponent::NONE) {
			int r = rand() % 4;
			switch (r + 1) {
			case MovementComponent::LEFT:
				if (!m_map[y][x - 1]->isWall) toMove = MovementComponent::LEFT;
				break;
			case MovementComponent::RIGHT:
				if (!m_map[y][x + 1]->isWall) toMove = MovementComponent::RIGHT;
				break;
			case MovementComponent::UP:
				if (!m_map[y - 1][x]->isWall) toMove = MovementComponent::UP;
				break;
			case MovementComponent::DOWN:
				if (!m_map[y + 1][x]->isWall) toMove = MovementComponent::DOWN;
				break;
			}
		}
	
		m_moveComponent->SetMovement(toMove);

		m_timer = m_timerTotal;
	}
	else {
		m_timer -= Time::GetInstance().GetDeltaTime();
	}
}

void GhostComponent::Died()
{
	m_timeDeath = 0.f;
	m_moveComponent->SwitchActive();
	m_moveComponent->GetPlace()->isGhost = false;
	m_pGameObject->GetComponent<SpriteComponent>()->SwitchActive();
	m_pacman->GetComponent<PacmanComponent>()->AddScore(50);
	m_currentstate = DEAD;
}

void GhostComponent::Respawn()
{
	m_currentstate = WALKING;
	m_moveComponent->SwitchActive();
	m_pGameObject->GetComponent<SpriteComponent>()->SwitchActive();
	m_pGameObject->GetTransform()->SetPosition(m_startingPosX * 50.f, m_startingPosY * 50.f);
	m_moveComponent->SetI(m_startingPosY);
	m_moveComponent->SetJ(m_startingPosX);
	m_map[m_startingPosY][m_startingPosX]->isGhost = true;
}
