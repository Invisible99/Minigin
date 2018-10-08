#include "stdafx.h"
#include "Transform.h"


void dae::Transform::SetPosition(const float x, const float y)
{
	mPosition.x = x;
	mPosition.y = y;
}

void dae::Transform::SetPosition(glm::vec2 pos)
{
	mPosition = pos;
}

void dae::Transform::SetRotation(float x)
{
	m_Rotation = x;
}

dae::Transform::Transform()
{
}

dae::Transform::Transform(const Transform & other)
{
	mPosition = other.mPosition;
	m_Rotation = other.m_Rotation;
}

dae::Transform::Transform(Transform && other)
{
	mPosition = other.mPosition;
	m_Rotation = other.m_Rotation;
}

void dae::Transform::Initialize()
{
}

void dae::Transform::Update()
{
}

void dae::Transform::Render()
{
}


