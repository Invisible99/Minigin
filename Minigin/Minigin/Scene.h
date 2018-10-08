#pragma once
#include "SceneManager.h"

namespace dae
{
	class GameObject;
	class Scene
	{
		//friend Scene& SceneManager::CreateScene(const std::string& name);
	public:
		void Add(GameObject* object);
		Scene(const std::string& name);

		void SetActive();
		void SetInactive();

		virtual ~Scene();

		virtual void Initialize() = 0;
		virtual void Update() = 0;
		virtual void Render() = 0;
	private:
		friend class SceneManager;
		std::string m_name{};
		std::vector <GameObject*> mObjects{};
		bool m_active;

		static unsigned int idCounter;

		void RootInitialze();
		void RootUpdate();
		void RootRender();
	};

}
