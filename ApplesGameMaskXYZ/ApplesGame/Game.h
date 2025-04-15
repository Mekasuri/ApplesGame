#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <cassert>
#include <iostream>
#include "Settings.h"
#include "Math.h"
#include "GameData.h"
#include "Player.h"
#include "GoldApple.h"
#include "Apples.h"
#include "BadApples.h"
#include "BackGround.h"
#include "MainMenu.h"
#include "Hearts.h"
#include "Text.h"
#include "Restart.h"
#include "Sounds.h"
namespace ApplesGame {
	struct Game{
		Player player{};
		GoldApple goldApple{};
		Apples apples{};
		BadApples badApples{};
		GameState gameState{};
		GameBackGround backGround{};
		MainMenu mainMenu{};
		Hearts hearts{};
		Label LableSpeed{};
		Label LabelScore{};
		Restart restart{};
		Sound AppleEatSound{};
		Sound BadAppleEatSound{};
		Sound EatGoldAppleSound{};
	};
	void GameStateInitialization(Game& game);
	void GameInitialization(Game& game);
	void MakeGoldAppleEat(Game& game);
	void PlayerCollisionWithApples(Game& game, sf::RenderWindow& window);
	void PlayerCollisionWithBadApples(Game& game);
}