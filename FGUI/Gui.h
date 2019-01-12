#pragma once

#include <SFML\Graphics.hpp>
#include <vector>

#include "Config.h"
#include "GuiElement.h"

#include "Widgets\Label.h"
#include "Widgets\Button.h"

namespace Fgui
{
	class API Gui
	{
	private:
		std::vector<GuiElement*> elements;
		std::vector<sf::String> names;
		sf::Font font;
		sf::Vector2u size;
	public:
		Gui(sf::Vector2u size);
		~Gui();

		void AddElement(GuiElement * element, sf::String name = "");
		void HandleInput(sf::Event event);
		void Draw(sf::RenderWindow & window) const;

		sf::Font & GetFont();
	};
}

