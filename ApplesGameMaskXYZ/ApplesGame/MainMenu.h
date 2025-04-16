#pragma once
#include "GameData.h"
#include "Settings.h"
#include <SFML/Graphics.hpp>
#include "Text.h"
#include "Sounds.h"
namespace ApplesGame {
	struct MainMenu {
		Position2D MainBackGrountPosition{ SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 };
		sf::Texture MainBackGroundTexture;
		sf::Sprite MainBackGroundSprite;

		sf::CircleShape SpeedChoiceShape;
		Position2D SpeedChoisePosition{265, 150};

		sf::CircleShape ApplesChoiceShape;
		Position2D ApplesChoisePosition{ 520, 310 };

		int online;

		Label OnlineLabel;
		Label question;

		Sound ClickSound{};
	};
	void MainMenuInitialization(MainMenu& mainMenuBackGround);
	void ExitDialog(sf::RenderWindow& window, MainMenu& mainMenuBackGround, GameState& gameState);
	void ChoiceTheMode(sf::RenderWindow& window, MainMenu& mainMenuBackGround, GameState& gameState);
	void MainMenuChoice(sf::RenderWindow& window, MainMenu& mainMenuBackGround, GameState& gameState);
}