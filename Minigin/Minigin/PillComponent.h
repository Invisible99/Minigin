#pragma once
#include "BaseComponent.h"
class PillComponent : public BaseComponent
{
public:
	PillComponent(Map* current, GameObject* pacman);
	~PillComponent();

protected:
	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render() override;

private:
	Map* m_mapStats;
	GameObject* m_pacman;
};

