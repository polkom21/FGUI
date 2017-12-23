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
		virtual void Draw(sf::RenderTexture & texture) override;
		virtual void Update() override;

		void SetFont(sf::Font font, unsigned int charSize = 16);
		void SetString(sf::String string);
		void SetTextColor(sf::Color color);
	};


}