#pragma once
#include "BaseComponent.h"

class PowerupComponent : public BaseComponent
{
public:
	PowerupComponent(Map* current, GameObject* pacman, GameObject* ghostManager);
	~PowerupComponent();
protected:
	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render() override;

private:
	Map * m_mapStats;
	GameObject* m_pacman;
	GameObject* m_ghostManager;
};

