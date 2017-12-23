#pragma once

#include <functional>
#include "Config.h"

namespace Fgui {

	enum class API Signals {
		onClick,
		onRelease,
		onDrag,
		onDrop
	};

	class API GuiElement {
	protected:
		std::map<Signals, std::function<void()>> signals;
		sf::FloatRect rect = sf::FloatRect(0, 0, 0, 0);
		sf::Font font;

		GuiElement *parent = NULL;

		bool clicked = false,
			released = false,
			dragged = false,
			dropped = false;

		sf::Vector2f clickedPos = sf::Vector2f(0, 0),
					releasedPos = sf::Vector2f(0, 0),
					draggedPos = sf::Vector2f(0, 0),
					droppedPos = sf::Vector2f(0, 0);
	public:
		sf::Vector2f mousePos;

		virtual void Draw(sf::RenderTexture & texture) = 0;
		virtual void Update() = 0;
		virtual void HandleInput(sf::Event event)
		{
			
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

			//printf("Clicked %d\t Released %d\t Dragged %d\t Dropped %d\n", this->clicked, this->released, this->dragged, this->dropped);
		}

		void SetPosition(sf::Vector2f pos) {
			this->rect.left = pos.x;
			this->rect.top = pos.y;
			this->Update();
		}

		sf::Vector2f GetPosition() {
			sf::Vector2f pos = sf::Vector2f(this->rect.left, this->rect.top);

			if (this->parent != NULL) {
				pos.x += this->parent->GetPosition().x;
				pos.y += this->parent->GetPosition().y;
			}

			return pos;
		}

		void SetParent(GuiElement *element) {
			this->parent = element;
		}

		void Connect(Signals singal, std::function<void()> fun) {
			this->signals.insert_or_assign(singal, fun);
		}
	};
}
