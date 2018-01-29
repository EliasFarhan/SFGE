#include <SFML/Graphics.hpp>
#include <engine/game_object.h>
#include <engine/log.h>
#include <iostream>

//External includes
#include "json.hpp"
using json = nlohmann::json;
//STL includes
#include <experimental/filesystem>
#include <fstream>


int main()
{
	mmgga::GameObject* gb1;
	std::string gb1FileName = "data/gameObjects/gameObject_test.json";
	
	std::ifstream gb1File(gb1FileName);
	if (gb1File.peek() == std::ifstream::traits_type::eof())
	{
		mmgga::Log::GetInstance()->Error("The " + gb1FileName + " is empty");
		system("pause");
		return EXIT_FAILURE;
	}

	json gb1JSon;
	try
	{
		gb1File >> gb1JSon;
	}
	catch (json::parse_error& e)
	{
		mmgga::Log::GetInstance()->Error("The " + gb1FileName + " is not a JSon File");
		system("pause");
		return EXIT_FAILURE;
	}

	gb1 = mmgga::GameObject::LoadGameObject(gb1JSon);

	system("pause");
	return EXIT_SUCCESS;
}
