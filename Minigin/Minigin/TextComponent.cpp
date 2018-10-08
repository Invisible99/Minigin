#include "stdafx.h"
#include <SDL.h>
#include <SDL_ttf.h>
#include "TextComponent.h"
#include "Renderer.h"
#include "ResourceManager.h"

dae::TextComponent::TextComponent(const std::string& text, int size)
	: mNeedsUpdate(true), mText(text), mTexture(nullptr)
{ 
	mFont = dae::ResourceManager::GetInstance().LoadFont("Lingua.otf", size);
}

dae::TextComponent::~TextComponent()
{
	SafeDelete(mFont);
	SafeDelete(mTexture);
}

void dae::TextComponent::Initialize()
{
}

void dae::TextComponent::Update()
{
	if (mNeedsUpdate)
	{
		SafeDelete(mTexture);
		const SDL_Color color = { 255,255,255 }; // only white text is supported now
		const auto surf = TTF_RenderText_Blended(mFont->GetFont(), mText.c_str(), color);
		if (surf == nullptr) {
			std::stringstream ss; ss << "Render text failed: " << SDL_GetError();
			throw std::runtime_error(ss.str().c_str());
		}
		auto texture = SDL_CreateTextureFromSurface(Renderer::GetInstance().GetSDLRenderer(), surf);
		if (texture == nullptr) {
			std::stringstream ss; ss << "Create text texture from surface failed: " << SDL_GetError();
			throw std::runtime_error(ss.str().c_str());
		}
		SDL_FreeSurface(surf);
		mTexture = new Texture2D(texture);
		mNeedsUpdate = false;
	}
}

void dae::TextComponent::Render()
{
	if (mTexture != nullptr)
	{
		Renderer::GetInstance().RenderTexture(*mTexture, GetTransform()->GetPosition().x, GetTransform()->GetPosition().y, GetTransform()->GetRotation());
	}
}

void dae::TextComponent::SetText(const std::string& text)
{
	mText = text;
	mNeedsUpdate = true;
}


