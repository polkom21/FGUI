#include <SFML\Graphics.hpp>
#include <FGUI\Gui.h>

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Fgui Test App");
	sf::Event event;

	// Create gui object
	Fgui::Gui * gui = new Fgui::Gui();

	// Create label
	Fgui::Label *label = new Fgui::Label("Test label", gui->GetFont());
	label->SetPadding(sf::Vector2f(0, 0));
	label->SetPosition(sf::Vector2f(10, 10));
	//label->SetAlignment(Fgui::HorizontalAlignment::Center, Fgui::VerticalAlignment::Center);
	gui->AddElement(label);

	// Create button
	Fgui::Button *button = new Fgui::Button("Close window", gui->GetFont());
	button->SetPadding(sf::Vector2f(50, 25));
	//button->SetAlignment(Fgui::HorizontalAlignment::Center, Fgui::VerticalAlignment::Center);
	button->SetPosition(sf::Vector2f(10, 34));

	button->Connect(Fgui::Signals::onClick, [&]() { window.close(); });
	
	gui->AddElement(button);

	// Create ChildWindow
	Fgui::ChildWindow *win = new Fgui::ChildWindow("Test window", gui->GetFont());
	win->SetPosition(sf::Vector2f(100, 100));

	gui->AddElement(win);

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

			gui->HandleInput(event);
		}

		window.clear(sf::Color::Black);

		gui->Draw(window);

		window.display();
	}
	
	return 0;
}