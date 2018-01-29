#include <graphics/sprite.h>
#include <json.hpp>
// for convenience
using json = nlohmann::json;

int main()
{
	json sprite_json;
	sprite_json["path"] = "data/sprites/boss_01_dialog_pose_001_b.png";

	sf::RenderWindow window(sf::VideoMode(800, 600), "My window");

	mmgga::Sprite* sprite = mmgga::Sprite::LoadSprite(sprite_json);
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

		window.display();
	}
#ifdef WIN32
	system("pause");
#endif
	return 0;
}
