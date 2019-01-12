#include "Button.h"



namespace Fgui {
	Button::Button(sf::String string, sf::Font font)
	{
		this->font = font;
		this->text.setFont(this->font);
		this->text.setCharacterSize(16);
		this->text.setString(string);
		this->Update();
	}


	Button::~Button()
	{
	}

	void Button::Draw(sf::RenderTexture & texture)
	{
		sf::RectangleShape shape;
		shape.setFillColor(this->backgroundColor);
		shape.setSize(sf::Vector2f(this->rect.width, this->rect.height));
		shape.setPosition(this->GetPosition());

		texture.draw(shape);

		this->text.setPosition(this->GetPosition() + this->padding);
		texture.draw(this->text);

	}

	void Button::Update()
	{
		sf::FloatRect localRect = this->text.getLocalBounds();
		this->rect.width = localRect.width + (this->padding.x * 2);
		this->rect.height = this->text.getCharacterSize() + (this->padding.y * 2);
	}


	void Button::SetFont(sf::Font font, unsigned int charSize)
	{
		this->font = font;
		this->text.setFont(this->font);
		this->text.setCharacterSize(charSize);
		this->Update();
	}
	void Button::SetString(sf::String string)
	{
		this->text.setString(string);
		this->Update();
	}
	void Button::SetTextColor(sf::Color color)
	{
		this->text.setFillColor(color);
		this->Update();
	}
	void Button::SetPadding(sf::Vector2f padding)
	{
		this->padding = padding;
		this->Update();
	}
}