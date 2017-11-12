#pragma once

#include "../Config.h"
#include "../GuiElement.h"

namespace Fgui {
	class API ChildWindow : public GuiElement
	{
	private:
		sf::Text windowName;
		sf::RenderTexture widgetRenderer;
		sf::RectangleShape header, closeBox;

		sf::Vector2f diffPos = sf::Vector2f(0, 0);

		bool display = true;
		
		// Style
		sf::Color backgroundColor = sf::Color::White;
		sf::Color headerBackgroundColor = sf::Color(120, 120, 120);
		sf::Color closeBoxBackgroundColor = sf::Color::Red;
	public:
		ChildWindow(const sf::String name, sf::Font & font);
		~ChildWindow();

		// Odziedziczono za poœrednictwem elementu GuiElement
		virtual void AddElement(GuiElement * element, sf::String name) override;
		virtual void Draw(sf::RenderWindow & window, sf::Vector2f parentPosition) override;
		virtual void Draw(sf::RenderTexture & window, sf::Vector2f parentPosition) override;
		virtual void Update() override;
		virtual void HandleInput(sf::Event event);

		void SetSize(sf::Vector2f size);
		const sf::Vector2f GetSize();
	};
}