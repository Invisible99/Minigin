#pragma once
#include "Singleton.h"
#include <chrono>
namespace dae
{

	class Time final : public dae::Singleton<Time>
	{
	public:
		void SetLastTime();
		void Update();
		float GetDeltaTime();
		float GetFPS();

	private:
		std::chrono::high_resolution_clock::time_point m_LastTime;
		std::chrono::high_resolution_clock::time_point m_CurrentTime;
		float m_fps;
		float m_fpsTimer;
		float m_deltaTime;
	};
}
