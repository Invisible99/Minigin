#pragma once
#include "BaseComponent.h"
#include "GameObject.h"
class GhostManagerComponent : public BaseComponent
{
public:
	GhostManagerComponent();
	~GhostManagerComponent();

	void AddGhost(GameObject* ghost);
	vector<GameObject*> GetGhosts();
	void EatenPill();

protected:
	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render() override;

private:
	vector<GameObject*> m_ghosts;
};

