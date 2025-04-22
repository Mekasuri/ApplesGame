#pragma once
#include <vector>
#include <string>
#include <SFML/Graphics.hpp>
#include "Settings.h"
#include "GameData.h"
#include "Text.h"
#include "Player.h"
#include "Apples.h"
#include "GoldApple.h"
#include "BadApples.h"
#include "Sounds.h"
namespace ApplesGame {
	struct Players {
		int score;
		std::string name;
	};
	bool operator<(const Players& a, const Players& b);
	struct Restart {

		std::vector<Players>players;

		Position2D RestartBackGrountPosition{ SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 };
		sf::Texture RestartGroundTexture;
		sf::Sprite RestartGroundSprite;

		Label Lily;
		Label William;
		Label Ava;
		Label James;
		Label YOU;

		std::vector<Label>PlayersText;

		float distance = 0;
		int PlayerPosition = 4;

		Sound ClickSound{};
	};
	void RestartInitialisation(Restart& restart, Apples& apples);
	void UpdateState(Apples& apples, GoldApple& goldApple, Player& player, BadApples& badApples);
	void RestartLoop(sf::RenderWindow& window, Restart& restart, GameState& gameState, Player& player, Apples& apples, GoldApple& goldApple, BadApples& badApples);
}