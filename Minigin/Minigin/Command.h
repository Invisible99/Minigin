#pragma once
#include "GameObject.h"
#include "MovementComponent.h"
class Command
{
public:
	Command(MovementComponent* object);
	~Command();
	virtual void Execute() = 0;
protected:
	MovementComponent * m_pObject;
};

class CommandLeft: public Command{
public:
	CommandLeft(MovementComponent* object);
	virtual void Execute();
};

class CommandRight : public Command {
public:
	CommandRight(MovementComponent* object);
	virtual void Execute();
};

class CommandUp : public Command {
public:
	CommandUp(MovementComponent* object);
	virtual void Execute();
};

class CommandDown : public Command {
public:
	CommandDown(MovementComponent* object);
	virtual void Execute();
};