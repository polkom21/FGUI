#include "ChildWindow.h"

Fgui::ChildWindow::ChildWindow(const sf::String name, sf::Font & font)
{
	this->windowName.setFont(font);
	this->windowName.setString(name);

	this->size = sf::Vector2f(300, 180);
}

Fgui::ChildWindow::~ChildWindow()
{
	this->elements.erase(this->elements.begin(), this->elements.end());
	this->names.erase(this->names.begin(), this->names.end());
}

void Fgui::ChildWindow::AddElement(GuiElement * element, sf::String name = "")
{
	this->elements.push_back(element);
	this->names.push_back(name);
}

void Fgui::ChildWindow::Draw(sf::RenderWindow & window, sf::Vector2f parentPosition = sf::Vector2f(0, 0))
{
}

void Fgui::ChildWindow::Draw(sf::RenderTexture & window, sf::Vector2f parentPosition)
{
}

void Fgui::ChildWindow::Update()
{
}

void Fgui::ChildWindow::SetSize(sf::Vector2f size)
{
	this->size = size;
}

const sf::Vector2f Fgui::ChildWindow::GetSize()
{
	return this->size;
}
