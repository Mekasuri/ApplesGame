#include "GoldApple.h"
#include <cassert>
#include "Math.h"
namespace ApplesGame {

	void GoldAppleInitialization(GoldApple& goldApple) {
		//INITIALIZATION OF GOLDEN APPLE TEXURE
		assert(goldApple.GoldAppleTexture.loadFromFile(RESOURCES_PATH + "/GoldApple.png"));
		goldApple.GoldAppleSprite.setTexture(goldApple.GoldAppleTexture);
		goldApple.GoldAppleSprite.setPosition(goldApple.GoldApplePosition.x, goldApple.GoldApplePosition.y);
		SetSpriteSize(goldApple.GoldAppleSprite, GOLD_APPLE_SIZE, GOLD_APPLE_SIZE);
		SetSprieOrigin(goldApple.GoldAppleSprite, 0.5, 0.5);
	}

	void GoldAppleDrawing(sf::RenderWindow& window, GoldApple& goldApple) {
		goldApple.GoldAppleSprite.setPosition(goldApple.GoldApplePosition.x, goldApple.GoldApplePosition.y);
		if (!goldApple.isGAppleEaten) {
			window.draw(goldApple.GoldAppleSprite);
		}
	}

	void GoldAppleDirectionVoid(GoldApple& goldApple) {
		if (goldApple.GoldApplePosition.x >= 990.f && goldApple.GoldApplePosition.x <= 1010.f && goldApple.GoldApplePosition.y >= 90.f && goldApple.GoldApplePosition.y <= 110.f) {
			goldApple.GoldAppleDirection = Direction::Down;
		}
		else if (goldApple.GoldApplePosition.x >= 990.f && goldApple.GoldApplePosition.x <= 1010.f && goldApple.GoldApplePosition.y >= 660.f && goldApple.GoldApplePosition.y <= 680.f) {
			goldApple.GoldAppleDirection = Direction::Left;
		}
		else if (goldApple.GoldApplePosition.x >= 90.f && goldApple.GoldApplePosition.x <= 110.f && goldApple.GoldApplePosition.y >= 660.f && goldApple.GoldApplePosition.y <= 680.f) {
			goldApple.GoldAppleDirection = Direction::Up;
		}
		else if (goldApple.GoldApplePosition.x >= 90.f && goldApple.GoldApplePosition.x <= 110.f && goldApple.GoldApplePosition.y >= 90.f && goldApple.GoldApplePosition.y <= 110.f) {
			goldApple.GoldAppleDirection = Direction::Right;
		}
	}

	void GoldAppleMove(GoldApple& goldApple, float deltaTime) {
		if (goldApple.GoldAppleDirection == Direction::Down) {
			goldApple.GoldApplePosition.y += goldApple.GoldAppleSpeed * deltaTime;
		}
		else if (goldApple.GoldAppleDirection == Direction::Left) {
			goldApple.GoldApplePosition.x -= goldApple.GoldAppleSpeed * deltaTime;
		}
		else if (goldApple.GoldAppleDirection == Direction::Up) {
			goldApple.GoldApplePosition.y -= goldApple.GoldAppleSpeed * deltaTime;
		}
		else if (goldApple.GoldAppleDirection == Direction::Right) {
			goldApple.GoldApplePosition.x += goldApple.GoldAppleSpeed * deltaTime;
		}
	}
}