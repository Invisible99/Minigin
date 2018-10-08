#pragma once
#include "BaseComponent.h"
#include "GameObject.h"
class EndGameComponent : public BaseComponent
{
public:
	EndGameComponent(GameObject* endScreen);
	~EndGameComponent();

	void AddPlayer();
	void LastLive();
protected:
	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render() override;

private:
	int m_players;
	int m_deadPlayers;
	
	GameObject* m_endScreen;
};

