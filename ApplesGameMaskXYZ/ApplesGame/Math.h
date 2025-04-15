#pragma once
#include <SFML/Graphics.hpp>
#include "GameData.h"
namespace ApplesGame {
	void SetSpriteSize(sf::Sprite& sprite, float desiredWidth, float desiredHeight);
	void SetSprieOrigin(sf::Sprite& sprite, float originX, float originY);
	bool collision(Position2D First, const float size1, Position2D Second, const float size2);
}