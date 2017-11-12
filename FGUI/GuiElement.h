#pragma once

#include <functional>
#include "Config.h"

namespace Fgui {

	enum class API HorizontalAlignment {
		Left,
		Center,
		Right
	};

	enum class API VerticalAlignment {
		Top,
		Center,
		Bottom
	};

	enum class API Signals {
		onClick,
		onRelease,
		onDrag,
		onDrop
	};

	class API GuiElement {
	protected:
		std::map<Signals, std::function<void()>> signals;
		sf::Vector2f padding = sf::Vector2f(0, 0);
		sf::Vector2f position = sf::Vector2f(0, 0);
		sf::Vector2f parentPosition = sf::Vector2f(0, 0);
		sf::Vector2f size = sf::Vector2f(0, 0);
		sf::FloatRect rect = sf::FloatRect(0, 0, 0, 0);
		HorizontalAlignment horizontalAlign = HorizontalAlignment::Center;
		VerticalAlignment verticalAlign = VerticalAlignment::Center;
		sf::Font font;

		std::vector<GuiElement*> elements;
		std::vector<sf::String> names;
		bool clicked = false,
			released = false,
			dragged = false,
			dropped = false;

		sf::Vector2f clickedPos = sf::Vector2f(0, 0),
					releasedPos = sf::Vector2f(0, 0),
					draggedPos = sf::Vector2f(0, 0),
					droppedPos = sf::Vector2f(0, 0);
	public:
		sf::Vector2f mousePos,
					margin = sf::Vector2f(0, 0);

		virtual void AddElement(GuiElement * element, sf::String name = "") = 0;
		virtual void Draw(sf::RenderWindow & window, sf::Vector2f parentPosition = sf::Vector2f(0, 0)) = 0;
		virtual void Draw(sf::RenderTexture & window, sf::Vector2f parentPosition = sf::Vector2f(0, 0)) = 0;
		virtual void Update() = 0;
		virtual void HandleInput(sf::Event event)
		{
			this->rect = sf::FloatRect(position.x + parentPosition.x + margin.x, position.y + parentPosition.y + margin.y, size.x, size.y);
			
			if (!this->rect.contains(this->mousePos))
				return;

			switch (event.type)
			{
			case sf::Event::MouseButtonPressed:
			{
				if (event.mouseButton.button == sf::Mouse::Left) {
					this->clickedPos = sf::Vector2f(event.mouseButton.x, event.mouseButton.y);

					this->clicked = true;
					this->released = false;
					this->dragged = false;
					this->dropped = false;
				}
				break;
			}
			case sf::Event::MouseButtonReleased:
			{
				if (event.mouseButton.button == sf::Mouse::Left) {
					this->releasedPos = sf::Vector2f(event.mouseButton.x, event.mouseButton.y);

					this->clicked = false;
					this->released = true;
					if (this->dragged)
					{
						this->dropped = true;
						this->droppedPos = this->releasedPos;
					}
					this->dragged = false;
				}
				break;
			}
			case sf::Event::MouseMoved:
			{
				if (this->clicked) {
					this->draggedPos = sf::Vector2f(event.mouseMove.x, event.mouseMove.y);

					this->dragged = true;
					this->dropped = false;
					break;
				}
				this->dragged = false;
				this->dropped = false;
				break;
			}
			default:
			{
				this->clicked = false;
				this->released = false;
				this->dragged = false;
				this->dropped = false;
			}
			}

			if (this->clicked && signals.find(Signals::onClick) != signals.end()) {
				signals.at(Signals::onClick)();
			}
			if (this->released && signals.find(Signals::onRelease) != signals.end()) {
				signals.at(Signals::onRelease)();
			}
			if (this->dragged && signals.find(Signals::onDrag) != signals.end()) {
				signals.at(Signals::onDrag)();
			}
			if (this->dropped && signals.find(Signals::onDrop) != signals.end()) {
				signals.at(Signals::onDrop)();
			}

			for (size_t i = 0; i < this->elements.size(); i++)
			{
				//printf("Start element: %s\n", this->names.at(i).toAnsiString().c_str());
				this->elements.at(i)->HandleInput(event);
				//printf("End element: %s\n", this->names.at(i).toAnsiString().c_str());
			}
			//printf("Clicked %d\t Released %d\t Dragged %d\t Dropped %d\n", this->clicked, this->released, this->dragged, this->dropped);
		}

		void SetPosition(sf::Vector2f pos) {
			this->position = pos;
			this->Update();
		}
		void SetPadding(sf::Vector2f padding) {
			this->padding = padding;
			this->Update();
		}
		void SetAlignment(HorizontalAlignment horizontal, VerticalAlignment vertical) {
			this->horizontalAlign = horizontal;
			this->verticalAlign = vertical;
			this->Update();
		}

		void Connect(Signals singal, std::function<void()> fun) {
			this->signals.insert_or_assign(singal, fun);
		}
	};
}
