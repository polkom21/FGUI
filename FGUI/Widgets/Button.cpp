#include "Button.h"


namespace Fgui {
	Button::Button(sf::String text, sf::Font font)
	{
		this->font = font;
		this->text.setFont(this->font);
		this->text.setCharacterSize(16);
		this->text.setString(text);
		this->size.x = this->text.getLocalBounds().width;
		this->size.y = this->text.getLocalBounds().height + (this->font.getLineSpacing(this->text.getCharacterSize()) / 2);
	}
	Button::~Button()
	{
		this->elements.erase(this->elements.begin(), this->elements.end());
		this->names.erase(this->names.begin(), this->names.end());
	}
	void Button::AddElement(GuiElement * element, sf::String name)
	{
		this->elements.push_back(element);
		this->names.push_back(name);
	}
	void Button::Draw(sf::RenderWindow & window, sf::Vector2f parentPosition)
	{
		/*printf("Button size \tx:%f\ty:%f \tButtonPos \tx:%f\ty:%f \n", this->size.x, this->size.y, this->position.x + this->parentPosition.x, this->position.y + this->parentPosition.y);*/
		this->parentPosition = parentPosition;

		this->text.setFont(this->font);
		texture.create(this->size.x, this->size.y);
		texture.clear(this->backgroundColor);
		texture.draw(this->text);
		texture.display();

		sprite.setTexture(texture.getTexture());
		sprite.setPosition(this->position + this->margin);

		window.draw(sprite);
	}
	void Button::Draw(sf::RenderTexture & window, sf::Vector2f parentPosition)
	{
		//printf("Button size \tx:%f\ty:%f \tButtonPos \tx:%f\ty:%f \n", this->size.x, this->size.y, this->position.x + this->parentPosition.x, this->position.y + this->parentPosition.y);
		this->parentPosition = parentPosition;
		this->text.setFont(this->font);
		texture.create(this->size.x, this->size.y);
		texture.clear(this->backgroundColor);
		texture.draw(this->text);
		texture.display();

		sprite.setTexture(texture.getTexture());
		sprite.setPosition(this->position + this->margin);

		window.draw(sprite);
	}
	void Button::Update()
	{
		this->size.x = this->text.getLocalBounds().width + padding.x;
		this->size.y = this->text.getLocalBounds().height + padding.y;

		this->text.setPosition(sf::Vector2f(0, 0));
		this->text.setFillColor(sf::Color::Black);

		switch (horizontalAlign)
		{
		case Fgui::HorizontalAlignment::Center:
			this->text.move(sf::Vector2f(padding.x / 2, 0));
			break;
		case Fgui::HorizontalAlignment::Right:
			this->text.move(sf::Vector2f(padding.x, 0));
			break;
		}

		switch (verticalAlign)
		{
		case Fgui::VerticalAlignment::Center:
			this->text.move( sf::Vector2f(0, (padding.y / 2) - this->text.getLocalBounds().height / 2) );
			break;
		case Fgui::VerticalAlignment::Bottom:
			this->text.move(sf::Vector2f(0, padding.y));
			break;
		}
		
		sprite.setPosition(this->position);
	}
	void Button::SetFont(sf::Font font, unsigned int charSize)
	{
		this->font = font;
		this->text.setFont(font);
		this->text.setCharacterSize(charSize);
		
		this->Update();
	}
}