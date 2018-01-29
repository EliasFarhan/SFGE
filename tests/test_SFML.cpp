#include <SFML/Graphics.hpp>

int main()
{
	sf::Sprite sprite;
	sf::Texture texture;
	texture.loadFromFile("data/sprites/boss_01_dialog_pose_001_b.png");
	sprite.setTexture(texture);
	sf::CircleShape circle(50.f);
	sf::RenderWindow window(sf::VideoMode(800, 600), "Test Texture");
	
	// run the program as long as the window is open
	while (window.isOpen())
	{
		// check all the window's events that were triggered since the last iteration of the loop
		sf::Event event;
		while (window.pollEvent(event))
		{
			// "close requested" event: we close the window
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(sprite);
		window.draw(circle);
		window.display();
	}

	return EXIT_SUCCESS;
}
