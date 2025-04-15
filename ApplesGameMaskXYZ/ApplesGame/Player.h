#pragma once
#include <SFML/Graphics.hpp>
#include "Settings.h"
#include "GameData.h"
namespace ApplesGame {
	struct Player {
		Position2D playerPosition{ SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 };
		int playerSpeed = START_SPEED;
		Direction playerDirection = Direction::Right;
		sf::Texture PlayerTexture;
		sf::Sprite PlayerSprite;
		sf::Vector2f PlayerDirection; // ADD
		bool flipX; // ADD
	};
	void PlayerInitialization(Player& player);
	void PlayerDraw(sf::RenderWindow& window, Player& player);
	void PlayerDirection(Player& player);
	void PlayerMove(Player& player, float deltaTime);
	void PlayerCollisionWithWalls(Player& player);
}