#pragma once
#include "Transform.h"

namespace dae
{
	class BaseComponent;
	//class Transform;

	class GameObject {
	public:
		GameObject();

		void AddComponent(BaseComponent* pComp);
		Transform* GetTransform() const { return m_pTransform; }
		virtual ~GameObject();

		

		GameObject(const GameObject& other);
		GameObject(GameObject&& other);

		GameObject& operator=(const GameObject& other) = delete;
		GameObject& operator=(GameObject&& other) = delete;

		bool IsActive();
		void SwitchActive();
	
		template<class T> T* GetComponent(bool searchChildren = false)
		{
			const type_info& ti = typeid(T);
			for (auto *component : m_pComponents)
			{
				if (component && typeid(*component) == ti)
					return static_cast<T*>(component);
			}

			if (searchChildren)
			{
				for (auto *child : m_pChildren)
				{
					if (child->GetComponent<T>(searchChildren) != nullptr)
						return child->GetComponent<T>(searchChildren);
				}
			}

			return nullptr;
		}

	protected:
		virtual void Initialize() {};
		virtual void Update() {};
		virtual void Render() {};
	private:

		friend class Scene;

		void RootInitialize();
		void RootUpdate();
		void RootRender();

		bool m_active;

		Transform* m_pTransform;
		vector<GameObject*> m_pChildren;
		vector<BaseComponent*> m_pComponents;
		//std::shared_ptr<Texture2D> mTexture;
	};
}
