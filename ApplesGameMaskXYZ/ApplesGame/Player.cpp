#include "Player.h"
#include <cassert>
#include "Math.h"
namespace ApplesGame {

	void PlayerInitialization(Player& player) {
		assert(player.PlayerTexture.loadFromFile(RESOURCES_PATH + "/Player.png"));
		player.PlayerSprite.setTexture(player.PlayerTexture);
		player.PlayerSprite.setPosition(player.playerPosition.x, player.playerPosition.y);
		SetSpriteSize(player.PlayerSprite, PLAYER_SIZE, PLAYER_SIZE);
		SetSprieOrigin(player.PlayerSprite, 0.5, 0.5);

		player.PlayerDirection = sf::Vector2f(1.f, 1.f);
		player.flipX = false;
	}

	void PlayerDraw(sf::RenderWindow& window, Player& player) {
		player.PlayerSprite.setPosition(player.playerPosition.x, player.playerPosition.y);
		window.draw(player.PlayerSprite);
	}

	void PlayerDirection(Player& player) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
			player.playerDirection = Direction::Right;
			player.PlayerSprite.setRotation(0);
			player.flipX = false;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
			player.playerDirection = Direction::Up;
			player.PlayerSprite.setRotation(-90);
			player.flipX = false;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
			player.playerDirection = Direction::Left;
			player.PlayerSprite.setRotation(0);
			player.flipX = true; 
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
			player.playerDirection = Direction::Down;
			player.PlayerSprite.setRotation(90); 
			player.flipX = false;
		}

		if (player.flipX) 
		{
			player.PlayerDirection.x = -1;
		}
		else
		{
			player.PlayerDirection.x = 1;
		}

		player.PlayerSprite.setScale(abs(player.PlayerSprite.getScale().x) * player.PlayerDirection.x, player.PlayerSprite.getScale().y);
	}

	void PlayerMove(Player& player, float deltaTime) {
		if (player.playerDirection == Direction::Right) {
			player.playerPosition.x += player.playerSpeed * deltaTime;
		}
		else if (player.playerDirection == Direction::Up) {
			player.playerPosition.y -= player.playerSpeed * deltaTime;
		}
		else if (player.playerDirection == Direction::Left) {
			player.playerPosition.x -= player.playerSpeed * deltaTime;
		}
		else if (player.playerDirection == Direction::Down) {
			player.playerPosition.y += player.playerSpeed * deltaTime;
		}
	}

	void PlayerCollisionWithWalls(Player& player) {
		if (player.playerPosition.x >= SCREEN_WIDTH + PLAYER_SIZE / 2) {
			player.playerPosition.x = 0.f - PLAYER_SIZE / 2;
		}
		else if (player.playerPosition.x <= 0.f - PLAYER_SIZE / 2) {
			player.playerPosition.x = SCREEN_WIDTH + PLAYER_SIZE / 2;
		}
		else if (player.playerPosition.y >= SCREEN_HEIGHT + PLAYER_SIZE / 2) {
			player.playerPosition.y = 0.f - PLAYER_SIZE / 2;
		}
		else if (player.playerPosition.y <= 0.f - PLAYER_SIZE / 2) {
			player.playerPosition.y = SCREEN_HEIGHT + PLAYER_SIZE / 2;
		}
	}
}