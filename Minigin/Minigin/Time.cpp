#include "stdafx.h"
#include "Time.h"


void dae::Time::SetLastTime()
{
	m_LastTime = std::chrono::high_resolution_clock::now();
}

void dae::Time::Update()
{
	m_CurrentTime = std::chrono::high_resolution_clock::now();
	m_deltaTime = std::chrono::duration<float>(m_CurrentTime - m_LastTime).count();
	m_fpsTimer += m_deltaTime;
	if (m_fpsTimer >= 1.0f) {
		m_fps = 1.0f / m_deltaTime;
		m_fpsTimer -= 1.0f;
	}

	m_LastTime = m_CurrentTime;
}

float dae::Time::GetDeltaTime()
{
	return m_deltaTime;
}

float dae::Time::GetFPS()
{
	return m_fps;
}
