#pragma once
#include "Game.h"
namespace ApplesGame {
	void PlayerLogic(sf::RenderWindow& window, Game& game, float deltaTime);
	void GoldAppleLogic(Game& game, float deltaTime);
	void BadApplesLogic(Game& game);
	void InterfaceUpdate(Game& game);
	void Drawing(sf::RenderWindow& window, Game& game);
	void GeneralGameLogic(sf::RenderWindow& window, Game& game, float deltaTime);
}