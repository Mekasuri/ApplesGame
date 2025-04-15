#pragma once
#include "GameData.h"
#include "Settings.h"
#include <iostream>
#include <SFML/Graphics.hpp>
namespace ApplesGame {
	struct Hearts {
		Position2D HeartPosition{ 30, 35 };
		std::vector<sf::Sprite>HeartSprite;
		sf::Texture HeartTexture;
	};
	void HeartsInitialization(Hearts& hearts);
}