#include <graphics/texture_manager.h>

int main()
{
	mmgga::TextureManager textureManager;
	std::string texture_filename = "data/sprites/boss_01_dialog_pose_001_b.png";
	std::string bad_texture_filename = "bad_prout.png";

	sf::RenderWindow window(sf::VideoMode(800, 600), "Test Texture");
	textureManager.LoadTexture(bad_texture_filename);
	sf::Sprite sprite;
	sf::Texture* texture = textureManager.GetTexture(bad_texture_filename);
	if(texture != nullptr)
		sprite.setTexture(*texture);
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
		window.display();
	}

	return 0;
}
