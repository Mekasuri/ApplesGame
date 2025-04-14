#pragma once
#include "GameData.h"
#include "Settings.h"
#include <SFML/Graphics.hpp>
namespace ApplesGame {
	struct GoldApple {
		bool isGAppleEaten = false;
		bool GoldSpeedUp = false;
		Position2D GoldApplePosition{ 1000, 100 };
		float GoldAppleSpeed = GOLD_APPLE_SPEED;
		Direction GoldAppleDirection = Direction::Down;
		sf::Texture GoldAppleTexture;
		sf::Sprite GoldAppleSprite;
	};
	void GoldAppleInitialization(GoldApple& goldApple);
	void GoldAppleDrawing(sf::RenderWindow& window, GoldApple& goldApple);
	void GoldAppleDirectionVoid(GoldApple& goldApple);
	void GoldAppleMove(GoldApple& goldApple, float deltaTime);
}