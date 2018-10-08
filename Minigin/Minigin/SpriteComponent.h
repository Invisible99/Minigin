#pragma once
#include "BaseComponent.h"
#include "Texture2D.h"
#include "Transform.h"
namespace dae
{
	class SpriteComponent : public BaseComponent
	{
	public:
		void Initialize() override;
		void Update() override;
		void Render() override;

		SpriteComponent(const string& filename);
		~SpriteComponent();
	private:
		Texture2D* m_texture;
	};

}