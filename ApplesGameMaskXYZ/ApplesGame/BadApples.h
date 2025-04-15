#pragma once
#include "GameData.h"
#include "Settings.h"
#include <SFML/Graphics.hpp>
namespace ApplesGame {
	struct BadApples{
		Position2D BadApplesPosition[BAD_APPLES_NUM]{};
		int numBadApplesEaten = 0;
		int lives = LIVES;
		sf::Texture BadApplesTexture;
		sf::Sprite BadApplesSprite[BAD_APPLES_NUM];
	};
	void BadApplesInitialization(BadApples& badApples);
	void BadApplesDrawing(sf::RenderWindow& window, BadApples& badApples);
}