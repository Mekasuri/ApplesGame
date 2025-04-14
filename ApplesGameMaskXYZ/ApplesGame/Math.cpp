#include "Math.h"
namespace ApplesGame {
	//TEXTURES
	void SetSpriteSize(sf::Sprite& sprite, float desiredWidth, float desiredHeight) {
		sf::FloatRect spriteRect = sprite.getLocalBounds();
		float originalWidth = spriteRect.width;
		float scaleFactor = desiredWidth / originalWidth;
		sf::Vector2f scale = { scaleFactor, scaleFactor };
		sprite.setScale(scale);
	}

	void SetSprieOrigin(sf::Sprite& sprite, float originX, float originY) {
		sf::FloatRect spriteRect = sprite.getLocalBounds();
		sprite.setOrigin(originX * spriteRect.width, originY * spriteRect.height);
	}

	//COLLISION
	bool collision(Position2D First, const float size1, Position2D Second, const float size2) {
		float squareDistance = (First.x - Second.x) * (First.x - Second.x) + (First.y - Second.y) * (First.y - Second.y);
		float squareRadiusSum = (size1 + size2) * (size1 + size2) / 4;
		if (squareDistance <= squareRadiusSum) {
			return true;
		}
		else {
			return false;
		}
	}
}