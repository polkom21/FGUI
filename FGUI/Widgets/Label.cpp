#include "Label.h"

namespace Fgui {

	Label::Label(sf::String string, sf::Font font)
	{
		this->font = font;
		this->text.setFont(this->font);
		this->text.setCharacterSize(16);
		this->text.setString(string);
		this->Update();
	}

	Label::~Label()
	{
	}

	void Label::Draw(sf::RenderTexture & texture)
	{
		this->text.setPosition(this->GetPosition());
		
		texture.draw(this->text);
	}

	void Label::Update()
	{
		sf::FloatRect localRect = this->text.getLocalBounds();
		this->rect.width = localRect.width;
		this->rect.height = localRect.height;
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