#pragma once
#pragma warning(push)
#pragma warning (disable:4201)
#include <glm/vec2.hpp>
#pragma warning(pop)
#include "BaseComponent.h"
namespace dae
{
	class Transform : public BaseComponent
	{
	public:
		const glm::vec2& GetPosition() const { return mPosition; }
		const float& GetRotation() const { return m_Rotation; }

		void SetPosition(float x, float y);
		void SetPosition(glm::vec2 pos);
		void SetRotation(float x);

		Transform();
		Transform(const Transform& other);
		Transform(Transform&& other);

	protected:

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render() override;
	private:
		glm::vec2 mPosition;
		float m_Rotation;
	};
}
