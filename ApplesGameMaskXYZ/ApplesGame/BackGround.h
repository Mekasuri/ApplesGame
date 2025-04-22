#pragma once
#include <SFML/Graphics.hpp>
#include "GameData.h"
namespace ApplesGame {
	struct GameBackGround {
		Position2D BackGroundPosition{};
		sf::Texture BackGroundTexture;
		sf::Sprite BackGroundSprite;
	};
	void GameBackGroundInitialization(GameBackGround& backGround);
	void BackGroundDraw(sf::RenderWindow& window, GameBackGround& backGround);
}