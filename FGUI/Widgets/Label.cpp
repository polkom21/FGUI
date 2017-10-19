#include "Label.h"

namespace Fgui {

	Label::Label(sf::String string, sf::Font font)
	{
		this->font = font;
		this->text.setFont(this->font);
		this->text.setCharacterSize(16);
		this->text.setString(string);
		this->size.x = this->text.getLocalBounds().width;
		this->size.y = this->text.getLocalBounds().height + (this->font.getLineSpacing(this->text.getCharacterSize()) / 2);
	}

	Label::~Label()
	{
		this->elements.erase(this->elements.begin(), this->elements.end());
		this->names.erase(this->names.begin(), this->names.end());
	}

	void Label::AddElement(GuiElement * element, sf::String name)
	{
		this->elements.push_back(element);
		this->names.push_back(name);
	}

	void Label::Draw(sf::RenderWindow & window, sf::Vector2f parentPosition)
	{
		this->parentPosition = parentPosition;
		this->text.setPosition(this->position);
		this->text.move(parentPosition);
		
		window.draw(this->text);
	}
	void Label::Draw(sf::RenderTexture & window, sf::Vector2f parentPosition)
	{
		this->parentPosition = parentPosition;
		this->text.setPosition(this->position);

		window.draw(this->text);
	}
	void Label::Update()
	{
		this->size.x = this->text.getLocalBounds().width + this->padding.x;
		this->size.y = this->text.getLocalBounds().height + this->padding.y;

		switch (verticalAlign)
		{
		case VerticalAlignment::Center:
			this->position.y += this->padding.y / 2;
			break;
		case VerticalAlignment::Bottom:
			this->position.y += this->padding.y;
			break;
		}

		switch (horizontalAlign)
		{
		case HorizontalAlignment::Center:
			this->position.x += this->padding.x / 2;
			break;
		case HorizontalAlignment::Right:
			this->position.x += this->padding.x;
			break;
		}

		this->text.setPosition(this->position);
	}
	void Label::SetFont(sf::Font font, unsigned int charSize)
	{
		this->font = font;
		this->text.setFont(this->font);
		this->text.setCharacterSize(charSize);
		this->Update();
	}
	void Label::SetString(sf::String string)
	{
		this->text.setString(string);
		this->Update();
	}
	void Label::SetTextColor(sf::Color color)
	{
		this->text.setFillColor(color);
		this->Update();
	}
}