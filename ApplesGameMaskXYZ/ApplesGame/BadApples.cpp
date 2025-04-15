#include "BadApples.h"
#include "Math.h"
#include "Settings.h"
#include <cassert>
namespace ApplesGame {

	void BadApplesInitialization(BadApples& badApples) {
		badApples.numBadApplesEaten = 0;
		badApples.lives = LIVES;
		badApples.BadApplesTexture;
		assert(badApples.BadApplesTexture.loadFromFile(RESOURCES_PATH + "/BadApple.png"));

		for (int i = 0; i < BAD_APPLES_NUM; ++i) {
			badApples.BadApplesPosition[i].x = rand() / (float)RAND_MAX * SCREEN_WIDTH;
			badApples.BadApplesPosition[i].y = rand() / (float)RAND_MAX * SCREEN_HEIGHT;
			badApples.BadApplesSprite[i].setTexture(badApples.BadApplesTexture);
			badApples.BadApplesSprite[i].setPosition(badApples.BadApplesPosition[i].x, badApples.BadApplesPosition[i].y);
			SetSpriteSize(badApples.BadApplesSprite[i], BAD_APPLES_SIZE, BAD_APPLES_SIZE);
			SetSprieOrigin(badApples.BadApplesSprite[i], 0.5f, 0.5f);
		}
	}

	void BadApplesDrawing(sf::RenderWindow& window, BadApples& badApples) {
		for (int i = 0; i < BAD_APPLES_NUM; ++i) {
			badApples.BadApplesSprite[i].setPosition(badApples.BadApplesPosition[i].x, badApples.BadApplesPosition[i].y);
			window.draw(badApples.BadApplesSprite[i]);
		}
	}
}