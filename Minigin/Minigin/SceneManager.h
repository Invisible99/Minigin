#pragma once
#include "Singleton.h"

namespace dae
{
	class Scene;
	class SceneManager final : public Singleton<SceneManager>
	{
	public:
		~SceneManager(void);

		void CreateScene(Scene* name);

		void Initialize();
		void Update();
		void Render();

	private:
		std::vector<Scene*> mScenes;
	};

}
