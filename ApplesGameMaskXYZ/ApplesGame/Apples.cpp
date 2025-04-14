#include "Apples.h"
#include "Math.h"
#include "Settings.h"
#include <cassert>
namespace ApplesGame {

	void ApplesInitialization(Apples& apples) {
		apples.numApples = 5 + rand() / (float)RAND_MAX * APPLES_NUM;
		apples.ApplesPosition.resize(apples.numApples);
		apples.isAppleEaten.resize(apples.numApples, false);
		apples.ApplesSprite.resize(apples.numApples);

		assert(apples.ApplesTexture.loadFromFile(RESOURCES_PATH + "/Apple.png"));
		apples.numApplesEaten = 0;

		for (int i = 0; i < apples.numApples; ++i) {
			apples.isAppleEaten[i] = false;
			apples.ApplesPosition[i].x = rand() / (float)RAND_MAX * SCREEN_WIDTH;
			apples.ApplesPosition[i].y = rand() / (float)RAND_MAX * SCREEN_HEIGHT;
			apples.ApplesSprite[i].setTexture(apples.ApplesTexture);
			apples.ApplesSprite[i].setPosition(apples.ApplesPosition[i].x, apples.ApplesPosition[i].y);
			SetSpriteSize(apples.ApplesSprite[i], APPLES_SIZE, APPLES_SIZE);
			SetSprieOrigin(apples.ApplesSprite[i], 0.5f, 0.5f);
		}
	}

	void ApplesDrawin(sf::RenderWindow& window, Apples& apples, GameState& gameState) {
		for (int i = 0; i < apples.numApples; ++i) {
			if (gameState.choice & 0b00001000) {
				if (!apples.isAppleEaten[i]) {
					window.draw(apples.ApplesSprite[i]);
					if (apples.numApplesEaten == apples.numApples) {
						gameState.state = State::Restart;
					}
				}
			}
			else {
				apples.ApplesSprite[i].setPosition(apples.ApplesPosition[i].x, apples.ApplesPosition[i].y);
				window.draw(apples.ApplesSprite[i]);
			}
		}
	}
}