#pragma once
#include "BaseComponent.h"
class InputComponent : public BaseComponent
{
public:
	InputComponent(int player);
	~InputComponent();

	int GetPlayerID();
protected:
	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render() override;

	int m_player;
};

