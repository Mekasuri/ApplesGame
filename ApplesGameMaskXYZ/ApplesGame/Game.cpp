#include "Game.h"
namespace ApplesGame {
	void GameStateInitialization(Game& game) {
		game.gameState.state = State::MainMaiu;
		game.gameState.choice = 0b00000101;
	}

	void TextInitialization(Game& game) {
		game.LabelScore.position.x = 10;
		game.LabelScore.position.y = 80;
		LableInitialization(game.LabelScore);

		game.LableSpeed.position.x = 870;
		game.LableSpeed.position.y = 10;
		game.LableSpeed.textSize = 35;
		LableInitialization(game.LableSpeed);
	}

	void GameInitialization(Game& game) {
		PlayerInitialization(game.player);
		GoldAppleInitialization(game.goldApple);
		ApplesInitialization(game.apples);
		BadApplesInitialization(game.badApples);
		GameStateInitialization(game);
		GameBackGroundInitialization(game.backGround);
		MainMenuInitialization(game.mainMenu);
		HeartsInitialization(game.hearts);
		TextInitialization(game);
		RestartInitialisation(game.restart, game.apples);
		SoundInitialization(game.AppleEatSound, "/AppleEat.wav");
		SoundInitialization(game.BadAppleEatSound, "/BadAppleSound.wav");
		SoundInitialization(game.EatGoldAppleSound, "/EatGoldApple.wav");
	}

	void MakeGoldAppleEat(Game& game) {
		if (!game.goldApple.isGAppleEaten) {
			if (collision(game.player.playerPosition, PLAYER_SIZE / 2, game.goldApple.GoldApplePosition, GOLD_APPLE_SIZE / 2)) {
				game.EatGoldAppleSound.sound.play();
				game.goldApple.isGAppleEaten = true;
				if (game.badApples.lives < LIVES) {
					game.badApples.lives++;
				}
				if (game.player.playerSpeed >= 150) {
					if (game.gameState.choice & 0b00000001) {
						game.player.playerSpeed -= 100;
					}
				}
			}
		}
	}

	void PlayerCollisionWithApples(Game& game, sf::RenderWindow& window) {
		for (int i = 0; i < game.apples.numApples; ++i) {
			if (!game.apples.isAppleEaten[i]) {
				if (collision(game.player.playerPosition, PLAYER_SIZE, game.apples.ApplesPosition[i], APPLES_SIZE)) {
					game.AppleEatSound.sound.play();

					if (game.gameState.choice & 0b00000001) {
						game.player.playerSpeed += 25;
						game.goldApple.GoldAppleSpeed += 25;
					}
					
					if (game.gameState.choice & 0b00000100) {
						++game.apples.numApplesEaten;
						game.apples.ApplesPosition[i].x = rand() / (float)RAND_MAX * SCREEN_WIDTH;
						game.apples.ApplesPosition[i].y = rand() / (float)RAND_MAX * SCREEN_HEIGHT;
					}
					else if (game.gameState.choice & 0b00001000) {
						game.apples.isAppleEaten[i] = true;
						++game.apples.numApplesEaten;
					}
					Score++;
				}
			}
		}
	}

	void PlayerCollisionWithBadApples(Game& game) {
		for (int i = 0; i < BAD_APPLES_NUM; ++i) {
			if (collision(game.player.playerPosition, PLAYER_SIZE / 2, game.badApples.BadApplesPosition[i], BAD_APPLES_SIZE / 2)) {
				game.BadAppleEatSound.sound.play();

				game.badApples.lives--;
				Score -= 3;
				game.badApples.BadApplesPosition[i].x = rand() / (float)RAND_MAX * SCREEN_WIDTH;
				game.badApples.BadApplesPosition[i].y = rand() / (float)RAND_MAX * SCREEN_HEIGHT;
			}
		}
	}
}