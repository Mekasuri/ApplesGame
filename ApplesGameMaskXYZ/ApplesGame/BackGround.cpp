#include "BackGround.h"
#include <cassert>
#include "Settings.h"
#include "Math.h"
namespace ApplesGame{

	void GameBackGroundInitialization(GameBackGround& backGround) {
		backGround.BackGroundPosition = { SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 };
		assert(backGround.BackGroundTexture.loadFromFile(RESOURCES_PATH + "/GameBackGround.jpg"));
		backGround.BackGroundSprite.setTexture(backGround.BackGroundTexture);
		backGround.BackGroundSprite.setPosition(backGround.BackGroundPosition.x, backGround.BackGroundPosition.y);
		SetSpriteSize(backGround.BackGroundSprite, SCREEN_WIDTH , SCREEN_HEIGHT);
		SetSpriteOrigin(backGround.BackGroundSprite, 0.5, 0.5);
	}

	void BackGroundDraw(sf::RenderWindow& window, GameBackGround& backGround) {
		window.draw(backGround.BackGroundSprite);
	}
}