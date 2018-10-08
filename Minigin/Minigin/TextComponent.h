#pragma once
#include "BaseComponent.h"
#include "Transform.h"
#include "Texture2D.h"
#include "Font.h"
namespace dae
{

	class TextComponent : public BaseComponent
	{
	public:

		void Initialize() override;
		void Update() override;
		void Render() override;

		void SetText(const std::string& text);

		TextComponent(const std::string& text, int size);
		~TextComponent();
	private:


		bool mNeedsUpdate;
		std::string mText;
		Font* mFont;
		Texture2D* mTexture;
	};

}
