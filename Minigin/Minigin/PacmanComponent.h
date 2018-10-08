#pragma once
#include "BaseComponent.h"
#include "GameObject.h"
#include "MovementComponent.h"
class PacmanComponent : public BaseComponent
{
public:
	enum STATE {
		ALIVE,
		DEAD
	};
	PacmanComponent(GameObject* score, GameObject* end);
	~PacmanComponent();

	void AddScore(int score);
	void Died();
	bool IsDead();
	GameObject* GetEndGameObj();

protected:
	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render() override;

private:
	int m_score;
	int m_lives;
	int m_startingPosX;
	int m_startingPosY;
	GameObject* m_scoreText;
	GameObject* m_EndGame;
	MovementComponent * m_moveComponent;

	STATE m_currentState;

	float m_timeDeath;
	float const m_totalTimeDeath = 5.0f;

	void Respawn();
};

