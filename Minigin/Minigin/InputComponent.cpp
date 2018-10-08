#include "stdafx.h"
#include "InputComponent.h"
#include "Command.h"
#include "InputManager.h"

InputComponent::InputComponent(int player): m_player(player)
{
}


InputComponent::~InputComponent()
{
}

int InputComponent::GetPlayerID()
{
	return m_player;
}

void InputComponent::Initialize()
{
	MovementComponent* move = m_pGameObject->GetComponent<MovementComponent>();
	if (m_player == 0) {
		InputManager& input = InputManager::GetInstance();
		input.AddInputAction(Buttons::BUTTONAKEY, new CommandLeft(move));
		input.AddInputAction(Buttons::BUTTONW, new CommandUp(move));
		input.AddInputAction(Buttons::BUTTONS, new CommandDown(move));
		input.AddInputAction(Buttons::BUTTOND, new CommandRight(move));
	}
	if (m_player == 1) {
		InputManager& input = InputManager::GetInstance();
		input.AddInputAction(Buttons::BUTTONLEFT, new CommandLeft(move));
		input.AddInputAction(Buttons::BUTTONUP, new CommandUp(move));
		input.AddInputAction(Buttons::BUTTONDOWN, new CommandDown(move));
		input.AddInputAction(Buttons::BUTTONRIGHT, new CommandRight(move));
	}
}

void InputComponent::Update()
{
}

void InputComponent::Render()
{
}
