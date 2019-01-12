#pragma once
#include "../GuiElement.h"
#include "../Config.h"

namespace Fgui {
	class API Button :
		public GuiElement
	{
	private:
		sf::Text text;
		sf::Vector2f padding = sf::Vector2f(0, 0);
		sf::Color backgroundColor = sf::Color::Magenta;
	public:
		Button(sf::String string, sf::Font font);
		~Button();

		// Odziedziczono za poœrednictwem elementu GuiElement
		virtual void Draw(sf::RenderTexture & texture) override;
		virtual void Update() override;

		void SetFont(sf::Font font, unsigned int charSize = 16);
		void SetString(sf::String string);
		void SetTextColor(sf::Color color);
		void SetPadding(sf::Vector2f padding);
	};


}