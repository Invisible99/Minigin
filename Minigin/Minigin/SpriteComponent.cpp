#include "stdafx.h"
#include "SpriteComponent.h"
#include "ResourceManager.h"
#include "Renderer.h"
#include "GameObject.h"
void dae::SpriteComponent::Initialize()
{

}

void dae::SpriteComponent::Update()
{
}

void dae::SpriteComponent::Render()
{
	if (m_texture != nullptr)
	{
		Renderer::GetInstance().RenderTexture(*m_texture, GetTransform()->GetPosition().x, GetTransform()->GetPosition().y, GetTransform()->GetRotation());
	}
}

dae::SpriteComponent::SpriteComponent(const string& filename)
{
	m_texture = ResourceManager::GetInstance().LoadTexture(filename);
}

dae::SpriteComponent::~SpriteComponent()
{
	SafeDelete(m_texture);
}
