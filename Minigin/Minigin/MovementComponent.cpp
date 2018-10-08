#include "stdafx.h"
#include "MovementComponent.h"
#include "GameObject.h"
#include "Transform.h"
#include "PacmanComponent.h"
#include "GhostComponent.h"
#include "InputComponent.h"
#include "EndGameComponent.h"
#include "LiveManagerComponent.h"
MovementComponent::MovementComponent(vector<vector<Map*>> map, int i, int j): m_Map(map), m_iPlace(i), m_jPlace(j)
{
	m_wallNotFound = false;
	m_speed = 100.0f;
}

void MovementComponent::SetMovement(MOVE move)
{
	m_currentMovement = move;
	if (m_pGameObject->GetComponent<InputComponent>()) {
		if (m_pGameObject->GetComponent<InputComponent>()->GetPlayerID() == 1 && !m_pGameObject->IsActive()) {
			m_pGameObject->SwitchActive();
			m_pGameObject->GetComponent<PacmanComponent>()->GetEndGameObj()->GetComponent<EndGameComponent>()->AddPlayer();
			m_pGameObject->GetComponent<LiveManagerComponent>()->ShowLives();
		}
	}
}

vector<vector<Map*>> MovementComponent::GetMap()
{
	return m_Map;
}

Map * MovementComponent::GetPlace()
{
	return m_Map[m_iPlace][m_jPlace];
}

int MovementComponent::GetI()
{
	return m_iPlace;
}

void MovementComponent::SetI(int i)
{
	m_iPlace = i;
}

int MovementComponent::GetJ()
{
	return m_jPlace;
}

void MovementComponent::SetJ(int j)
{
	m_jPlace = j;
}


MovementComponent::~MovementComponent()
{
}

void MovementComponent::Initialize()
{
}

void MovementComponent::Update()
{
	m_wallNotFound = false;
	int oldiPlace = m_iPlace;
	int oldjPlace = m_jPlace;
	switch (m_currentMovement) {
	case LEFT:
		if (!m_Map[m_iPlace][m_jPlace - 1]->isWall) {
			if (GetTransform()->GetPosition().x < (m_jPlace - 1)*50.0) {

				m_jPlace--;				
			}			
			m_velocity = glm::vec2(-1.f, 0.f);
			m_wallNotFound = true;
		}
		break;
	case RIGHT:
		if (!m_Map[m_iPlace][m_jPlace + 1]->isWall) {
			if (GetTransform()->GetPosition().x > (m_jPlace + 1)*50.0) {

				m_jPlace++;
			}
			
			m_velocity = glm::vec2(1.f, 0.f);
			m_wallNotFound = true;
		}
		break;
	case UP:
		if (!m_Map[m_iPlace-1][m_jPlace]->isWall) {
			if (GetTransform()->GetPosition().y < (m_iPlace - 1)*50.0) {

				m_iPlace--;
			}
			m_velocity = glm::vec2(0.f, -1.f);
			m_wallNotFound = true;
		}
		break;
	case DOWN:
		if (!m_Map[m_iPlace+1][m_jPlace]->isWall) {
			if (GetTransform()->GetPosition().y > (m_iPlace + 1)*50.0) {
			
				m_iPlace++;
			}
			m_velocity = glm::vec2(0.f, 1.f);
			m_wallNotFound = true;
		}
		break;
	}

	if (m_pGameObject->GetComponent<PacmanComponent>()) {
		m_Map[oldiPlace][oldjPlace]->isPacman = false;
		m_Map[m_iPlace][m_jPlace]->isPacman = true;
	}
	if (m_pGameObject->GetComponent<GhostComponent>()) {
		m_Map[oldiPlace][oldjPlace]->isGhost = false;
		m_Map[m_iPlace][m_jPlace]->isGhost = true;
	}

	if (m_wallNotFound) {
		glm::vec2 pos = GetTransform()->GetPosition();

		pos += m_velocity * m_speed * Time::GetInstance().GetDeltaTime();

		GetTransform()->SetPosition(pos);
		
	}
}

void MovementComponent::Render()
{
}
