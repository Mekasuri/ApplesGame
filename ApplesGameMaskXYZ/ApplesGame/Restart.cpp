#include "Restart.h"
#include "Math.h"
#include <cassert>
namespace ApplesGame {
	bool operator<(const Players& a, const Players& b) {
		return a.score > b.score;
	}

	void RestartInitialisation(Restart& restart, Apples& apples) {
		assert(restart.RestartGroundTexture.loadFromFile(RESOURCES_PATH + "/RestartBackGround.png"));
		restart.RestartGroundSprite.setTexture(restart.RestartGroundTexture);
		restart.RestartGroundSprite.setPosition(restart.RestartBackGrountPosition.x, restart.RestartBackGrountPosition.y);
		SetSpriteSize(restart.RestartGroundSprite, SCREEN_WIDTH, SCREEN_HEIGHT);
		SetSprieOrigin(restart.RestartGroundSprite, 0.5, 0.5);

		restart.players = {
		{static_cast<int>(rand() / (float)RAND_MAX * apples.numApples), "Lily"},
		{static_cast<int>(rand() / (float)RAND_MAX * apples.numApples), "William"},
		{static_cast<int>(rand() / (float)RAND_MAX * apples.numApples), "Ava"},
		{static_cast<int>(rand() / (float)RAND_MAX * apples.numApples), "James"},
		{Score, "YOU"}
		};

		restart.PlayersText = {
		restart.Lily,
		restart.William,
		restart.Ava,
		restart.James,
		restart.YOU
		};

		SoundInitialization(restart.ClickSound, "/ClickSound.wav");
	}

	void RestartLoop(sf::RenderWindow& window, Restart& restart, GameState& gameState, Player& player, Apples& apples, GoldApple& goldApple, BadApples& badApples) {
		while (gameState.state == State::Restart) {
			//EVENT
			sf::Event event;
			while (window.pollEvent(event)) {
				if (event.type == sf::Event::Closed) {
					window.close();
					return;
				}
			}
			float distance = 0;
			restart.players[restart.PlayerPosition].score = Score;
			std::sort(restart.players.begin(), restart.players.end());
			for (int i = 0; i != restart.PlayersText.size(); ++i) {
				if (restart.players[i].name == "YOU") {
					restart.PlayerPosition = i;
				}
				restart.PlayersText[i].message = (std::to_string(restart.players[i].score) + " " + restart.players[i].name);
				restart.PlayersText[i].position.x = SCREEN_WIDTH / 2 - 80;
				restart.PlayersText[i].position.y = 220.f + distance;
				restart.PlayersText[i].textSize = 40;
				LableInitialization(restart.PlayersText[i]);
				distance += 45.f;
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
				restart.ClickSound.sound.play();
					gameState.state = State::Game;

					//UPDATE STATE
					for (int i = 0; i < apples.numApples; ++i) {
						apples.ApplesPosition[i].x = rand() / (float)RAND_MAX * SCREEN_WIDTH;
						apples.ApplesPosition[i].y = rand() / (float)RAND_MAX * SCREEN_HEIGHT;
						apples.ApplesSprite[i].setPosition(apples.ApplesPosition[i].x, apples.ApplesPosition[i].y);
						apples.isAppleEaten[i] = false;
					}
					apples.numApplesEaten = 0;
					player.playerPosition.x = SCREEN_WIDTH / 2;
					player.playerPosition.y = SCREEN_HEIGHT / 2;
					player.PlayerSprite.setPosition(player.playerPosition.x, player.playerPosition.y);
					badApples.lives = LIVES;
					player.playerSpeed = START_SPEED;
					goldApple.GoldAppleSpeed = GOLD_APPLE_SPEED;
					goldApple.isGAppleEaten = false;
					goldApple.GoldApplePosition.x = 1000;
					goldApple.GoldApplePosition.y = 100;
					goldApple.GoldAppleSprite.setPosition(goldApple.GoldApplePosition.x, goldApple.GoldApplePosition.y = 100);
					Score = 0;
			
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace)) {
				restart.ClickSound.sound.play();
				gameState.state = State::MainMaiu;

				//UPDATE STATE
				for (int i = 0; i < apples.numApples; ++i) {
					apples.ApplesPosition[i].x = rand() / (float)RAND_MAX * SCREEN_WIDTH;
					apples.ApplesPosition[i].y = rand() / (float)RAND_MAX * SCREEN_HEIGHT;
					apples.ApplesSprite[i].setPosition(apples.ApplesPosition[i].x, apples.ApplesPosition[i].y);
					apples.isAppleEaten[i] = false;
				
				
				}
				apples.numApplesEaten = 0;
				player.playerPosition.x = SCREEN_WIDTH / 2;
				player.playerPosition.y = SCREEN_HEIGHT / 2;
				player.PlayerSprite.setPosition(player.playerPosition.x, player.playerPosition.y);
				badApples.lives = LIVES;
				player.playerSpeed = START_SPEED;
				goldApple.GoldAppleSpeed = GOLD_APPLE_SPEED;
				goldApple.isGAppleEaten = false;
				goldApple.GoldApplePosition.x = 1000;
				goldApple.GoldApplePosition.y = 100;
				goldApple.GoldAppleSprite.setPosition(goldApple.GoldApplePosition.x, goldApple.GoldApplePosition.y = 100);
				Score = 0;

			}
			window.clear();
			window.draw(restart.RestartGroundSprite);
			for (int i = 0; i != restart.PlayersText.size(); ++i) {
				window.draw(restart.PlayersText[i].text);
			}
			window.display();
		}
	}
}