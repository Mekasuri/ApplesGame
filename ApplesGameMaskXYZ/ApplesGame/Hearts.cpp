#include "Hearts.h"
#include "Math.h"
#include <cassert>
namespace ApplesGame {
	void HeartsInitialization(Hearts& hearts) {
		hearts.HeartSprite.resize(LIVES);
		assert(hearts.HeartTexture.loadFromFile(RESOURCES_PATH + "/Heart.png"));
		for (int i = 0; i < LIVES; ++i) {
			hearts.HeartSprite[i].setTexture(hearts.HeartTexture);
			hearts.HeartSprite[i].setPosition(hearts.HeartPosition.x, hearts.HeartPosition.y);
			hearts.HeartPosition.x += 65;
			SetSpriteSize(hearts.HeartSprite[i], 80, 80);
			SetSprieOrigin(hearts.HeartSprite[i], 0.5, 0.5);
		}
	}
}