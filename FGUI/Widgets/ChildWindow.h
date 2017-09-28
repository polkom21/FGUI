#pragma once

#include "../Config.h"
#include "../GuiElement.h"

namespace Fgui {
	class API ChildWindow : public GuiElement
	{
	private:
		sf::Text windowName;

		// Style
		sf::Color backgroundColor = sf::Color::White;
		sf::Color headerBackgroundColor = sf::Color(40, 40, 40);
	public:
		ChildWindow(const sf::String name, sf::Font & font);
		~ChildWindow();

		// Odziedziczono za poœrednictwem elementu GuiElement
		virtual void AddElement(GuiElement * element, sf::String name) override;
		virtual void Draw(sf::RenderWindow & window, sf::Vector2f parentPosition) override;
		virtual void Draw(sf::RenderTexture & window, sf::Vector2f parentPosition) override;
		virtual void Update() override;

		void SetSize(sf::Vector2f size);
		const sf::Vector2f GetSize();
	};
}