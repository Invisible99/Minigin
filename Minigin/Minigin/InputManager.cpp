#include "stdafx.h"
#include "InputManager.h"
#include <SDL.h>


dae::InputManager::InputManager()
{
}

dae::InputManager::~InputManager()
{
	SafeDelete(buttonDown_);
	SafeDelete(buttonRight_);
	SafeDelete(buttonLeft_);
	SafeDelete(buttonUp_);
	SafeDelete(buttonW_);
	SafeDelete(buttonAKey_);
	SafeDelete(buttonS_);
	SafeDelete(buttonD_);
}

void dae::InputManager::AddInputAction(Buttons button, Command * action)
{
	switch (button)
	{
	case Buttons::BUTTONDOWN:
		buttonDown_ = action;
		break;
	case Buttons::BUTTONRIGHT:
		buttonRight_ = action;
		break;
	case Buttons::BUTTONLEFT:
		buttonLeft_ = action;
		break;
	case Buttons::BUTTONUP:
		buttonUp_ = action;
		break;
	case Buttons::BUTTONW:
		buttonW_ = action;
		break;
	case Buttons::BUTTONAKEY:
		buttonAKey_ = action;
		break;
	case Buttons::BUTTONS:
		buttonS_ = action;
		break;
	case Buttons::BUTTOND:
		buttonD_ = action;
		break;
	}
}

bool dae::InputManager::ProcessInput()
{

	ZeroMemory(&currentState, sizeof(XINPUT_STATE));
	XInputGetState(0, &currentState);

	if (currentState.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_DOWN && buttonDown_ != nullptr)
	{
		buttonDown_->Execute();
	}
	if (currentState.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_RIGHT && buttonRight_ != nullptr)
	{
		buttonRight_->Execute();
	}
	if (currentState.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_LEFT && buttonLeft_ != nullptr)
	{
		buttonLeft_->Execute();
	}
	if (currentState.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_UP && buttonUp_ != nullptr)
	{
		buttonUp_->Execute();
	}

	SDL_Event e;
	while (SDL_PollEvent(&e)) {
		if (e.type == SDL_QUIT) {
			return false;
		}
		if (e.type == SDL_KEYDOWN) {
			if (e.key.keysym.sym == 97 && buttonAKey_ != nullptr) {
				buttonAKey_->Execute();
			}
			if (e.key.keysym.sym == 100 && buttonD_ != nullptr) {
				buttonD_->Execute();
			}
			if (e.key.keysym.sym == 115 && buttonS_ != nullptr) {
				buttonS_->Execute();
			}
			if (e.key.keysym.sym == 119 && buttonW_ != nullptr) {
				buttonW_->Execute();
			}
			
		}
		if (e.type == SDL_MOUSEBUTTONDOWN) {

		}
	}

	return true;
}

