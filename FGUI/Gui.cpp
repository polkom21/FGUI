#include "Gui.h"

namespace Fgui
{
	Gui::Gui()
	{
		this->font.loadFromFile("arial.ttf");
	}

	Gui::~Gui()
	{
		this->elements.erase(this->elements.begin(), this->elements.end());
		this->names.erase(this->names.begin(), this->names.end());
	}

	void Gui::AddElement(GuiElement * element, sf::String name)
	{
		this->elements.push_back(element);
		this->names.push_back(name);
	}

	void Gui::HandleInput(sf::Event event)
	{
		for (size_t i = 0; i < elements.size(); i++)
		{
			elements.at(i)->HandleInput(event);
		}
	}

	void Gui::Draw(sf::RenderWindow & window) const
	{
		sf::Vector2f mousePos = sf::Vector2f(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);
		for (size_t i = 0; i < elements.size(); i++)
		{
			elements.at(i)->mousePos = mousePos;
			elements.at(i)->Draw(window);
		}
	}
	sf::Font & Gui::GetFont()
	{
		return this->font;
	}
}
