#include "stdafx.h"
#include "Command.h"
Command::Command(MovementComponent * object)
{
	m_pObject = object;
}
Command::~Command()
{
}

CommandLeft::CommandLeft(MovementComponent * object) : Command(object)
{
}

void CommandLeft::Execute()
{
	m_pObject->SetMovement(MovementComponent::LEFT);
	m_pObject->GetTransform()->SetRotation(180.0f);
}

CommandRight::CommandRight(MovementComponent * object) : Command(object)
{
}

void CommandRight::Execute()
{
	m_pObject->SetMovement(MovementComponent::RIGHT);
	m_pObject->GetTransform()->SetRotation(0.f);
}

CommandUp::CommandUp(MovementComponent * object) : Command(object)
{
}

void CommandUp::Execute()
{
	m_pObject->SetMovement(MovementComponent::UP);
	m_pObject->GetTransform()->SetRotation(-90.0f);
}

CommandDown::CommandDown(MovementComponent * object) : Command(object)
{
}

void CommandDown::Execute()
{
	m_pObject->SetMovement(MovementComponent::DOWN);
	m_pObject->GetTransform()->SetRotation(90.f);
}
