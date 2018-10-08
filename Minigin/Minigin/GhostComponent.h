#pragma once
#include "BaseComponent.h"
#include "MovementComponent.h"
#include <thread>
class GhostComponent : public BaseComponent
{
public:
	enum STATE {
		WALKING,
		POWERUP,
		DEAD
	};
	GhostComponent(GameObject* pacman, GameObject* pacwoman);
	~GhostComponent();

	void PowerUp();
protected:
	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render() override;
private:
	void Movement();
	void RandomMovement();
	void Died();
	void Respawn();

	MovementComponent* m_moveComponent;
	vector<vector<Map*>> m_map;
	int m_startingPosX;
	int m_startingPosY;
	GameObject* m_pacman;
	GameObject* m_pacwoman;

	std::thread m_moveThread;

	float m_powerupTime;
	float const m_powerupTotal = 5.f;

	float m_timer;
	float const m_timerTotal = 2.f;

	float m_timeDeath;
	float const m_totalTimeDeath = 5.0f;

	STATE m_currentstate;
};

