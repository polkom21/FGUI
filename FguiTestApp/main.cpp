#include <SFML\Graphics.hpp>
#include <FGUI\Gui.h>

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Fgui Test App");
	sf::Event event;

	// Create gui object
	Fgui::Gui * gui = new Fgui::Gui(window.getSize());

	Fgui::Label *label = new Fgui::Label("test label", gui->GetFont());
	label->SetPosition(sf::Vector2f(100, 300));
	gui->AddElement(label);

	Fgui::Label *title = new Fgui::Label("Fgui Test App", gui->GetFont());
	title->SetParent(label);
	gui->AddElement(title);

	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
				window.close();

			if (event.type == sf::Event::KeyPressed)
			{
				switch (event.key.code)
				{
				case sf::Keyboard::Space:
					title->SetParent(label);
					break;

				case sf::Keyboard::BackSpace:
					title->SetParent(NULL);
					break;

				case sf::Keyboard::Left:
					label->SetPosition(sf::Vector2f(0, 100));
					break;

				case sf::Keyboard::Right:
					label->SetPosition(sf::Vector2f(400, 100));
					break;

				default:
					break;
				}
			}
				

			gui->HandleInput(event);
		}

		window.clear(sf::Color::Black);

		gui->Draw(window);

		window.display();
	}
	
	return 0;
}