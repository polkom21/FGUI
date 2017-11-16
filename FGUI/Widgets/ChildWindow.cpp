#include "ChildWindow.h"

Fgui::ChildWindow::ChildWindow(const sf::String name, sf::Font & font)
{
	this->font = font;
	this->windowName.setCharacterSize(16);
	this->windowName.setFont(this->font);
	this->windowName.setString(name);

	this->size = sf::Vector2f(300, 180);

	this->header.setPosition(0.f, 0.f);
	this->header.setFillColor(this->headerBackgroundColor);
	this->header.setSize(sf::Vector2f(this->size.x, this->windowName.getCharacterSize() * 1.25));

	this->closeBox.setSize(sf::Vector2f(this->windowName.getCharacterSize() * 1.25, this->windowName.getCharacterSize() * 1.25));
	this->closeBox.setFillColor(this->closeBoxBackgroundColor);
	this->closeBox.setPosition(sf::Vector2f(this->size.x - this->closeBox.getLocalBounds().width, 0));
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
	if (!display)
		return;
	
	widgetRenderer.create(this->size.x, this->size.y);
	widgetRenderer.clear(sf::Color::White);

	widgetRenderer.draw(this->header);
	widgetRenderer.draw(this->closeBox);

	this->windowName.setPosition(sf::Vector2f(padding.x, 0));
	this->windowName.setFillColor(sf::Color::Black);
	widgetRenderer.draw(this->windowName);

	for (size_t i = 0; i < this->elements.size(); i++)
	{
		this->elements.at(i)->mousePos = this->mousePos;
		this->elements.at(i)->margin = sf::Vector2f(this->padding.x, this->padding.y + header.getSize().y);
		this->elements.at(i)->Draw(widgetRenderer, this->position);
	}

	widgetRenderer.display();

	sf::Sprite sprite;
	sprite.setTexture(widgetRenderer.getTexture());
	sprite.setPosition(this->position);

	window.draw(sprite);
}

void Fgui::ChildWindow::Draw(sf::RenderTexture & window, sf::Vector2f parentPosition)
{
}

void Fgui::ChildWindow::Update()
{
	for (size_t i = 0; i < this->elements.size(); i++)
	{
		this->elements.at(i)->Update();
	}
}

void Fgui::ChildWindow::HandleInput(sf::Event event)
{
	GuiElement::HandleInput(event);

	if (!this->rect.contains(this->mousePos)) return;

	if (this->clicked && this->diffPos == sf::Vector2f(0, 0))
		this->diffPos = this->position - this->clickedPos;

	if (this->released)
		this->diffPos = sf::Vector2f(0, 0);

	if (this->closeBox.getGlobalBounds().contains(this->mousePos - this->position) && this->clicked)
		this->display = false;

	if (this->header.getGlobalBounds().contains(this->mousePos - this->position) && this->dragged)
	{
		this->SetPosition(draggedPos + this->diffPos);
	}
}

void Fgui::ChildWindow::SetSize(sf::Vector2f size)
{
	this->size = size;
}

const sf::Vector2f Fgui::ChildWindow::GetSize()
{
	return this->size;
}
