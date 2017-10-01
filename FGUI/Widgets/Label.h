#pragma once

#include "../Config.h"
#include "../GuiElement.h"

namespace Fgui {
	class API Label : public GuiElement
	{
	private:
		sf::Text text;
	public:
		Label(sf::String string, sf::Font font);
		~Label();

		// Odziedziczono za poœrednictwem elementu GuiElement
		virtual void AddElement(GuiElement * element, sf::String name) override;
		virtual void Draw(sf::RenderWindow & window, sf::Vector2f parentPosition) override;
		virtual void Draw(sf::RenderTexture & window, sf::Vector2f parentPosition) override;
		virtual void Update() override;

		void SetFont(sf::Font font, unsigned int charSize = 16);
		void SetString(sf::String string);
		void SetTextColor(sf::Color color);
	};


}