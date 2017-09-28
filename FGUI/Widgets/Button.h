#pragma once

#include "../Config.h"
#include "../GuiElement.h"

namespace Fgui {
	class API Button : public GuiElement {
	private:
		sf::Text text;
		sf::RenderTexture texture;
		sf::Sprite sprite;
		sf::Color backgroundColor = sf::Color::White;
	public:

		Button(sf::String text, sf::Font font);
		~Button();

		// Odziedziczono za poœrednictwem elementu GuiElement
		virtual void AddElement(GuiElement * element, sf::String name) override;
		virtual void Draw(sf::RenderWindow & window, sf::Vector2f parentPosition) override;
		virtual void Draw(sf::RenderTexture & window, sf::Vector2f parentPosition) override;
		virtual void Update() override;

		void SetFont(sf::Font font, unsigned int charSize = 16);
	};
}