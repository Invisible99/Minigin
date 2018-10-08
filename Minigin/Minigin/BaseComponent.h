#pragma once
namespace dae {
	class GameObject;
	class Transform;

	class BaseComponent
	{
	public:
		BaseComponent();
		virtual ~BaseComponent();
		GameObject* GetGameObject() const { return m_pGameObject; }
		Transform* GetTransform() const;

		bool IsActive();
		void SwitchActive();
	protected:

		virtual void Initialize() = 0;
		virtual void Update() = 0;
		virtual void Render() = 0;

		GameObject* m_pGameObject;

	private:
		friend class GameObject;

		void RootInitialize();

		bool active;
		//friend class GameObject;
	};
}


