#pragma once
#include "GameData.h"
#include "Settings.h"
#include <SFML/Graphics.hpp>
#include <vector>
namespace ApplesGame {
	struct Apples{
		int numApples = 0;
		std::vector<Position2D> ApplesPosition;
		std::vector<bool> isAppleEaten{false};
		sf::Texture ApplesTexture;
		std::vector <sf::Sprite> ApplesSprite;
		int numApplesEaten = 0;
	};
	void ApplesInitialization(Apples& apples);
	void ApplesDrawin(sf::RenderWindow& window, Apples& apples, GameState& gameState);
}