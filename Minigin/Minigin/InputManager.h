#pragma once
#include <XInput.h>
#include "Singleton.h"
#include "Command.h"
#include <map>
namespace dae
{
	enum Buttons
	{
		BUTTONDOWN,
		BUTTONRIGHT,
		BUTTONLEFT,
		BUTTONUP,
		BUTTONW,
		BUTTONAKEY,
		BUTTONS,
		BUTTOND
	};

	class InputManager final : public Singleton<InputManager>
	{
	public:
		InputManager();
		~InputManager();
		void AddInputAction(Buttons button, Command* action);
		bool ProcessInput();
	private:
		XINPUT_STATE currentState{};
		Command* buttonLeft_;
		Command* buttonUp_;
		Command* buttonDown_;
		Command* buttonRight_;	
		Command* buttonW_;
		Command* buttonAKey_;
		Command* buttonS_;
		Command* buttonD_;
	};

}
