#include <SFML/Graphics.hpp>
#include <engine/game_object.h>
#include <engine/log.h>
#include <engine/scene.h>
#include <iostream>

//External includes
#include "json.hpp"
using json = nlohmann::json;
//STL includes
#include <experimental/filesystem>
#include <fstream>


int main()
{
	mmgga::SceneManager sceneManagerTest;
	mmgga::Scene* sceneTest = sceneManagerTest.LoadScene("data/scenes/scene_Test.json");
	
	if (sceneTest == nullptr)
	{
		mmgga::Log().GetInstance()->Error("Erreur de lecture du fichier");
		system("pause");
		return EXIT_FAILURE;
	}

	sceneManagerTest.SaveScene(sceneTest);

	system("pause");
	return EXIT_SUCCESS;
}
