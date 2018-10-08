#pragma once
#include "BaseComponent.h"
#include "GameObject.h"
class LiveManagerComponent : public BaseComponent
{
public:
	LiveManagerComponent();
	~LiveManagerComponent();
	void AddLive(GameObject* live);
	void LostLive(int i);
	void ShowLives();

protected:
	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render() override;

private:
	vector<GameObject*> m_lives;
};

